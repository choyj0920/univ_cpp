#include "DocWriter.h"
#include <iostream>
#include <fstream>
using namespace std;
DocWriter::DocWriter() :fileName("noninfo"),content("noinfo")
{
	cout << "docwriter인자 없는 생성자 실행" << endl;
}

DocWriter::~DocWriter()
{
	cout << "소멸자 실행" << endl;
}

DocWriter::DocWriter(const string& fileName, const string& content) :fileName(fileName), content(content)
{
	cout << "DocWriter 인자 있는 생성자" << endl;
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
