#include <iostream>
#include "HTMLWriter.h"

int main()
{
    std::cout << "201810754 조윤직\n";
	
	DocWriter doc1;
	DocWriter doc2("test.txt", "Greenjoa");

	doc2.setContent("Bluejoa");
	doc2.setFileName("greenjoa.txt");

	doc1.write();
	doc2.write();
	
	HTMLWriter htm1;
	HTMLWriter htm2("test.html", "konkuk");
	htm2.SetFont("궁서체", 20, "blue");
	htm1.write();
	htm2.write();
}

