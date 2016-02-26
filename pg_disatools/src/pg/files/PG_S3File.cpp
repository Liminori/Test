/*
 * The MIT License (MIT)
 *
 *	Copyright (c) 2016 ProgSys
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 */

/*
 * PG_S3File.cpp
 *
 *  Created on: 25.02.2016
 *      Author: ProgSys
 */

#include <pg/files/PG_S3File.h>
#include <algorithm>
#include <type_traits>

#include <pg/util/PG_BinaryFileTokenizer.h>
#include <pg/util/PG_BinaryFileWriter.h>
#include <pg/util/PG_Array.h>
#include <pg/util/PG_Base.h>
#include <pg/files/PG_S3Compression.h>
#include <pg/files/PG_ImageFiles.h>

namespace PG {
namespace FILE {

using namespace UTIL;

S3File::S3File(const std::string& filename): m_filename(filename) {
	m_width = 0;
	m_height = 0;

	std::string extention = filename.substr(filename.find_last_of(".") + 1);
	std::transform(extention.begin(), extention.end(), extention.begin(), ::tolower);

	if(extention == "vtf"){
		PG::UTIL::BinaryFileTokenizer reader(m_filename);
		if(reader.getString(3) != "VTF"){
			PG_ERROR_STREAM("Magic number is not VTF!");
			m_filetype = INVALID;
			return;
		}

		reader.skip(13);
		m_width = reader.getShort();
		m_height = reader.getShort();
		if(m_width == 0 || m_height == 0){
			PG_ERROR_STREAM("Image width or height is zero!");
			m_filetype = INVALID;
			return;
		}

		m_filetype = VTF;
	}else if(extention == "tx2"){
		PG::UTIL::BinaryFileTokenizer reader(m_filename);
		m_width = reader.getUnsignedShort();
		m_height = reader.getUnsignedShort();
		if(m_width == 0 || m_height == 0){
			PG_ERROR_STREAM("Image width or height is zero!");
			m_filetype = INVALID;
			return;
		}
		m_filetype = TX2;
	}else{
		PG_ERROR_STREAM("Unknown file extension'"<<extention<< "'. Only vtf and tx2 (Disgaea) is supported.")
	}

}

unsigned int S3File::getWidth() const{
	return m_width;
}

unsigned int S3File::getHeight() const{
	return m_height;
}

bool S3File::save(const std::string& outfilename, outFormat out) const{
	std::vector<RGBA> data;
	if(!m_filetype) return false;
	else if(m_filetype == VTF){
		if( !readVTF(data) )
			return false;
	}else if(m_filetype == TX2){
		if( !readTX2(data) )
			return false;
	}

	switch (out) {
		case PGM:
		{
			PG_INFO_STREAM("Writing PGM. (RGB)");
			savePGM(outfilename, m_width, m_height, data);
		}
			break;
		case TGA:
		{
			PG_INFO_STREAM("Writing TGA. (RGBA)");
			saveTGA(outfilename, m_width, m_height, data);
		}
			break;
		default:
			return false;
			break;
	}

	return false;
}

bool S3File::readVTF(std::vector<RGBA>& outRGBAData) const{
	PG::UTIL::BinaryFileTokenizer reader(m_filename);

	if(reader.getString(3) != "VTF"){
		PG_ERROR_STREAM("Magic number is not VTF!");
		return false;
	}

	reader.skip(13);
	if(m_width != reader.getShort() || m_height != reader.getShort()){
		PG_ERROR_STREAM("The image has different size then expected!");
		return false;
	}
	reader.skip(60);

	if(m_width >= 32 || m_height >= 32)
		reader.skip(4 * 4 *8 );


	const unsigned int number_of_blocks_width = (m_width/4);
	const unsigned int number_of_blocks_height =(m_height/4);
	const unsigned int number_of_blocks_4x4 = number_of_blocks_width*number_of_blocks_height;

	std::vector<DXT1block> blocks(number_of_blocks_4x4);
	reader.read((char*)&blocks[0], number_of_blocks_4x4*sizeof(DXT1block) );
	reader.close();

	PG::FILE::uncompressS3<PG::FILE::DXT1block>(m_width,m_height, blocks, outRGBAData);
	//uncompressDXT1(m_width,m_height, blocks, outRGBAData);

	return true;
}

bool S3File::readTX2(std::vector<RGBA>& outRGBAData) const{
	PG::UTIL::BinaryFileTokenizer reader(m_filename);
	if(m_width != reader.getUnsignedShort() || m_height != reader.getUnsignedShort()){
		PG_ERROR_STREAM("The image has different size then expected!");
		return false;
	}

	reader.skip(12);

	const unsigned int number_of_blocks_width = (m_width/4);
	const unsigned int number_of_blocks_height = (m_height/4);
	const unsigned int number_of_blocks_4x4 = number_of_blocks_width*number_of_blocks_height;

	std::vector<DXT5block> blocks(number_of_blocks_4x4);
	reader.read((char*)&blocks[0], number_of_blocks_4x4*sizeof(DXT5block));
	reader.close();

	uncompressDXT5(m_width,m_height, blocks, outRGBAData);

	return true;


}


S3File::~S3File() {
	// TODO Auto-generated destructor stub
}

} /* namespace FILE */
} /* namespace PG */
