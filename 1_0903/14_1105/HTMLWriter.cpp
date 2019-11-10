#include "HTMLWriter.h"
#include <iostream>
#include <fstream>
using namespace std;
HTMLWriter::HTMLWriter() :HTMLWriter("Noninfo.html", "greenjoa")
{
	cout << "����Ʈ ������ HTML\n";
}

HTMLWriter::~HTMLWriter()
{
	cout << "HTML�Ҹ��� ȣ��\n";
}

HTMLWriter::HTMLWriter(const string& fileName, const string& content):DocWriter(fileName,content),fontName("����ü"), fontSize(15), fontColor("black")
{
	cout << "HTML���� �ִ� ������ ȣ��\n";

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
