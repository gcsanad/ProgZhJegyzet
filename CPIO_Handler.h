#pragma once
#include "structures.h"
#include <iostream>
#include <fstream>
#include <string>

class CPIO_Handler
{
public:
	CPIO_Handler(int numberofSections = 1);
	~CPIO_Handler(); 

	int getFileSize(const char* filename);
	void readFileContent(const char* filename,char* content, unsigned int size);
	void createHeader();
	void fillContent(std::string* filenames);
	void writeContent();
private:
	CPIO_HEADER *Header;
	CPIO_SECTION *Sections;
	int numberofSections;
};

