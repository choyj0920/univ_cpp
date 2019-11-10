#include "HTMLWriter.h"
#include <iostream>
#include <fstream>
using namespace std;
HTMLWriter::HTMLWriter() :HTMLWriter("Noninfo.html", "greenjoa")
{
	cout << "디폴트 생성자 HTML\n";
}

HTMLWriter::~HTMLWriter()
{
	cout << "HTML소멸자 호출\n";
}

HTMLWriter::HTMLWriter(const string& fileName, const string& content):DocWriter(fileName,content),fontName("굴림체"), fontSize(15), fontColor("black")
{
	cout << "HTML인자 있는 생성자 호출\n";

}

void HTMLWriter::write()
{
	ofstream of(fileName.c_str());

	of << "<HTML><HEAD><TITLE>this document_1105</TITLE></HEAD><BODY>";
	of << "<H1>Content</H1>";

	of << "<FONT name='" << fontName << "'size='" << fontSize << "'color='" << fontColor << "'>";

	of << content;
	of << "</FONT>";
	of << "</BODY></HTML>";
}

void HTMLWriter::SetFont(const string& fontName, int fontSize, const string& fontColor)
{
	this->fontName = fontName;
	this->fontColor = fontColor;
	this->fontSize = fontSize;
}
