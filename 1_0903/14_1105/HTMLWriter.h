#pragma once
#include "DocWriter.h"
class HTMLWriter :
	public DocWriter
{
protected:
	string fontName;
	int fontSize;
	string fontColor;
public:
	HTMLWriter();
	~HTMLWriter();
	HTMLWriter(const string& fileName, const string& content);
	void write();

	void SetFont(const string& fontName, int fontSize, const string& fontColor);
};

