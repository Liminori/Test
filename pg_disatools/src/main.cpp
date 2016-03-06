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


#include <iostream>
#include <string>
#include <pg/files/PG_IMY.h>
#include <pg/files/PG_ImageFiles.h>
#include <pg/files/PG_PSPFS.h>
#include <algorithm>

#define OUTSTR(x) std::cout << x << std::endl

struct testStr{
	testStr(const std::string& str): name(str){}
	std::string name;
};

/*!
 * @brief Testing main method, just for testing.
 */
int main(int argc, char* argv[]){
	OUTSTR("Start");

	std::vector<testStr> vec;
	vec.push_back(testStr("NA03"));
	vec.push_back(testStr("NA02"));
	vec.push_back(testStr("NA01"));
	vec.push_back(testStr("NA04"));
	vec.push_back(testStr("NA00"));

	std::sort(vec.begin(), vec.end(), [](const testStr& A, const testStr& B){
		return A.name < B.name;
	});

	for(const testStr& s: vec){
		OUTSTR(s.name);
	}

	//PG::UTIL::RGBAImage image;
	//PG::FILE::uncompressIMY("C:/Users/ProgSys/Desktop/Disgaea/PC/IMY/test.imy",image);
	//PG::FILE::saveTGA("C:/Users/ProgSys/Desktop/Disgaea/PC/IMY/test.tga", image);

	PG::FILE::PSPFS pspfile;

	OUTSTR("Done");

	return 0;
}
