#include "HTMLWriter.h"
#include <fstream>
using namespace std;

//22_5 부모 클래스의 생성자 지정하기
//초기화 리스트를 사용해서 부모 클래스의 생성자를 호출한다.
//포함의 경우에는 객체의 이름을 사용했지만, 여기선 부모 클래스의 이름을 사용한다.
HTMLWriter::HTMLWriter(const string& fileName, const string& content)
	:DocWriter(fileName, content) {
	//디폴트 폰트를 지정한다.
	_fontName = "굴림";
	_fontSize = 3;
	_fontColor = "black";
}

HTMLWriter::HTMLWriter() {
	//디폴트 파일 이름만 바꾼다.
	_fileName = "NoName.html";

	//디폴트 폰트를 지정한다.
	_fontName = "굴림";
	_fontSize = 3;
	_fontColor = "black";
}

HTMLWriter::~HTMLWriter() {

}

//파일에 텍스트를 저장시킨다.
void HTMLWriter::Write() {
	//파일을 연다.
	ofstream of(_fileName.c_str());

	//HTML 헤더 부분을 저장한다.
	of << "<HTM><HEAD><TITLE>This document was generated by HTMLWriter"
		"</TITLE></HEAD><BODY>";
	of << "<H1>Content</H1>";

	//폰트 태그를 시작한다.
	of << "<Font name='" << _fontName << "' size='" << _fontSize <<
		"' color='" << _fontColor << "'>";

	//텍스트를 저장한다.
	of << _content;

	//폰트 태그를 닫는다.
	of << "</FONT>";

	//HTML을 마무리 한다.
	of << "</BODY></HTML>";
}

//폰트를 지정한다.
void HTMLWriter::SetFont(const string& fontName, int fontSize, 
	const string& fontColor) {
	_fontName = fontName;
	_fontSize = fontSize;
	_fontColor = fontColor;
}