#include "DocWriter.h"
#include <iostream>
#include <fstream>
using namespace std;
DocWriter::DocWriter() :fileName("noninfo"),content("noinfo")
{
	cout << "docwriter���� ���� ������ ����" << endl;
}

DocWriter::~DocWriter()
{
	cout << "�Ҹ��� ����" << endl;
}

DocWriter::DocWriter(const string& fileName, const string& content) :fileName(fileName), content(content)
{
	cout << "DocWriter ���� �ִ� ������" << endl;
}

void DocWriter::setFileName(const string& fileName)
{
	this->fileName = fileName;
}

void DocWriter::setContent(const string& content)
{
	this->content = content;
}

void DocWriter::write()
{
	ofstream fout( fileName.c_str());
	fout << "###Content##\n\n";
	fout << content;

}
