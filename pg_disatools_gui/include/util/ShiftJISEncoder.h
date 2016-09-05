/*
 * ShiftJISEncoder.h
 *
 *  Created on: 05.09.2016
 *      Author: ProgSys
 */

#ifndef INCLUDE_UTIL_SHIFTJISENCODER_H_
#define INCLUDE_UTIL_SHIFTJISENCODER_H_

#include <QString>
#include <QByteArray>
#include <QDebug>

inline short encodeToShiftJIS(const QChar& c){
	//http://unicode-table.com/de/#arabic-presentation-forms-b
	//http://www.rtpro.yamaha.co.jp/RT/docs/misc/kanji-sjis.html
	switch (c.row() << 8 | c.cell()) {
		//numbers
		case ' ':
		case 0x3000:
			return 0x8140;
			break;
		case '0':
		case 0xFF10: // 0
			return 0x824f;
			break;
		case '1':
		case 0xFF11: // 1
			return 0x8250;
			break;
		case '2':
		case 0xFF12: // 2
			return 0x8251;
			break;
		case '3':
		case 0xFF13: // 3
			return 0x8252;
			break;
		case '4':
		case 0xFF14: // 4
			return 0x8253;
			break;
		case '5':
		case 0xFF15: // 5
			return 0x8254;
			break;
		case '6':
		case 0xFF16: // 6
			return 0x8255;
			break;
		case '7':
		case 0xFF17: // 7
			return 0x8256;
			break;
		case '8':
		case 0xFF18: // 8
			return 0x8257;
			break;
		case '9':
		case 0xFF19: // 9
			return 0x8258;
			break;
		//Capital letters
		case 'A':
		case '�':
		case 0x00C1: //Spain A
		case 0xFF21: //A
			return 0x8260;
			break;
		case 'B':
		case 0xFF22: //B
			return 0x8261;
			break;
		case 'C':
		case 0xFF23: //C
			return 0x8262;
			break;
		case 'D':
		case 0xFF24: //D
			return 0x8263;
			break;
		case 'E':
		case 0x00C9: //Spain E
		case 0xFF25: //E
			return 0x8264;
			break;
		case 'F':
		case 0xFF26: //F
			return 0x8265;
			break;
		case 'G':
		case 0xFF27: //G
			return 0x8266;
			break;
		case 'H':
		case 0xFF28: //H
			return 0x8267;
			break;
		case 'I':
		case 0x00CD: //Spain I
		case 0xFF29: //I
			return 0x8268;
			break;
		case 'J':
		case 0xFF2a: //J
			return 0x8269;
			break;
		case 'K':
		case 0xFF2b:
			return 0x826a;
			break;
		case 'L':
		case 0xFF2c:
			return 0x826b;
			break;
		case 'M':
		case 0xFF2d:
			return 0x826c;
			break;
		case 'N':
		case 0x00D1: //Spain N
		case 0xFF2e:
			return 0x826d;
			break;
		case 'O':
		case '�':
		case 0x00D3: //Spain O
		case 0xFF2f:
			return 0x826e;
			break;
		case 'P':
		case 0xFF30:
			return 0x826f;
			break;
		case 'Q':
		case 0xFF31:
			return 0x8270;
			break;
		case 'R':
		case 0xFF32:
			return 0x8271;
			break;
		case 'S':
		case 0xFF33:
			return 0x8272;
			break;
		case 'T':
		case 0xFF34:
			return 0x8273;
			break;
		case 'U':
		case '�':
		case 0x00DA: //Spain U
		case 0xFF35:
			return 0x8274;
			break;
		case 'V':
		case 0xFF36:
			return 0x8275;
			break;
		case 'W':
		case 0xFF37:
			return 0x8276;
			break;
		case 'X':
		case 0xFF38:
			return 0x8277;
			break;
		case 'Y':
		case 0xFF39:
			return 0x8278;
			break;
		case 'Z':
		case 0xFF3a:
			return 0x8279;
			break;

		//small letters
		case 'a':
		case '�':
		case 0x00E1:
		case 0xFF41:
			return 0x8281;
			break;
		case 'b':
		case 0xFF42:
			return 0x8282;
			break;
		case 'c':
		case 0xFF43:
			return 0x8283;
			break;
		case 'd':
		case 0xFF44:
			return 0x8284;
			break;
		case 'e':
		case 0xFF45:
			return 0x8285;
			break;
		case 'f':
		case 0xFF46:
			return 0x8286;
			break;
		case 'g':
		case 0xFF47:
			return 0x8287;
			break;
		case 'h':
		case 0xFF48:
			return 0x8288;
			break;
		case 'i':
		case 0x00ED: //Spain i
		case 0xFF49:
			return 0x8289;
			break;
		case 'j':
		case 0xFF4a:
			return 0x828a;
			break;
		case 'k':
		case 0xFF4b:
			return 0x828b;
			break;
		case 'l':
		case 0xFF4c:
			return 0x828c;
			break;
		case 'm':
		case 0xFF4d:
			return 0x828d;
			break;
		case 'n':
		case 0x00F1: //Spain n
		case 0xFF4e:
			return 0x828e;
			break;
		case 'o':
		case '�':
		case 0x00F3: //Spain o
		case 0xFF4f:
			return 0x828f;
			break;
		case 'p':
		case 0xFF50:
			return 0x8290;
			break;
		case 'q':
		case 0xFF51:
			return 0x8291;
			break;
		case 'r':
		case 0xFF52:
			return 0x8292;
			break;
		case 's':
		case 0xFF53:
			return 0x8293;
			break;
		case 't':
		case 0xFF54:
			return 0x8294;
			break;
		case 'u':
		case '�':
		case 0x00FA: //Spain u
		case 0xFF55:
			return 0x8295;
			break;
		case 'v':
		case 0xFF56:
			return 0x8296;
			break;
		case 'w':
		case 0xFF57:
			return 0x8297;
			break;
		case 'x':
		case 0xFF58:
			return 0x8298;
			break;
		case 'y':
		case 0xFF59:
			return 0x8299;
			break;
		case 'z':
		case 0xFF5a:
			return 0x829a;
			break;
		//special
		case '�':
			return 0x8142;
			break;
		case ',':
			return 0x8143;
			break;
		case '.':
		case 0xFF0E:  //Fullwidth Full Stop
			return 0x8144;
			break;
		case ':':
		case  0xFF1A:
			return 0x8146;
			break;
		case '?':
		case 0x00BF: //Spain ?
		case  0xFF1F:
			return 0x8148;
			break;
		case '!':
		case 0x00A1: //Spain !
		case 0xFF01:
			return 0x8149;
			break;
		case '"':
		case 0xFF02:
			return 0x8150;
			break;
		case '(':
		case  0xFF08: //Fullwidth Left Parenthesis
			return 0x8169;
			break;
		case ')':
		case  0xFF09: //Fullwidth Left Parenthesis
			return 0x816a;
			break;
		case '{':
		case 0xFF5B:
			return 0x816f;
			break;
		case '}':
		case 0xFF5D:
			return 0x8170;
			break;

		case 0x2018:  //Left single quotation mark
			return 0x8165;
			break;
		case 0x2019:  //Right single quotation mark
			return 0x8166;
			break;
		case '-':
		case 0xFF0D:  //Fullwidth Hyphen-Minus
			return 0x817c;
			break;
		case '+':
		case 0xFF0B:  //Fullwidth Hyphen-Minus
			return 0x817b;
			break;
		case '@':
		case 0xFF97:
			return 0x816f;
			break;
		case 0x266A: //Eighth note
			return 0x81f4;
			break;
		case 0x2605: //Start full black
			return 0x819a;
			break;
		case '$':
		case 0xFF04: //Fullwidth dolar
			return 0x8190;
			break;
		//case '\n':
		//case 0x2424:
			//break;
		default:
		{
			qDebug() <<"Unknown ShiftJIS conversion of: '"<<c<<"' ("<<(c.row() << 8 | c.cell())<<")";
			return 0x8140;
		}
			break;
	}
}

inline QByteArray encodeToShiftJIS(const QString& str){
	QByteArray bytes;
	for(const QChar& c: str){
		short s = encodeToShiftJIS(c);
		s = ((s >> 8) & 0x00FF) | (s << 8) ;
		bytes.append((char*) &s, 2);
	}
	return bytes;
}




#endif /* INCLUDE_UTIL_SHIFTJISENCODER_H_ */
