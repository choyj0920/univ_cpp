#pragma once
#include <string>
using namespace std;
class DocWriter
{
protected:
	string fileName;
	string content;
public:
	DocWriter();
	~DocWriter();
	DocWriter(const string& fileName, const string& content);
	void setFileName(const string& fileName);
	void setContent(const string& content);
	void write();
};

