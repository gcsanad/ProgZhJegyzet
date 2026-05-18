#include "CPIO_Handler.h"

CPIO_Handler::CPIO_Handler(int numberofSections) {
	this->Header = new CPIO_HEADER();
	this->Sections = new CPIO_SECTION[numberofSections];
	this->numberofSections = numberofSections;
}

CPIO_Handler::~CPIO_Handler() {
	delete this->Header;
	delete[] this->Sections;
}

int CPIO_Handler::getFileSize(const char* filename) {
	std::ifstream input;
	input.open(filename, std::ios::in | std::ios::binary);
	int size = -1;
	if (input.is_open()) {
		input.seekg(0, std::ios::end);
		size = input.tellg();
		input.close();
	}

	return size;
}

void CPIO_Handler::readFileContent(const char* filename, char* content, unsigned int size)
{
	std::ifstream input;
	input.open(filename, std::ios::in | std::ios::binary);

	if (input.is_open()) {
		input.read(content, size);
		input.close();
	}
}

void CPIO_Handler::createHeader() {
	this->Header->ID = rand();
	this->Header->numberofFiles = this->numberofSections;
	this->Header->sizes = new unsigned int[numberofSections]();
}

void CPIO_Handler::fillContent(std::string *filenames) {
	this->createHeader();
	int size = -1;

	for (int i = 0; i < this->numberofSections; i++) {
		size = this->getFileSize(filenames[i].c_str());
		this->Header->sizes[i] = size;
		
		if (size != -1) {
			strncpy_s(this->Sections[i].filename, filenames[i].c_str(),32);
			this->readFileContent(filenames[i].c_str(), Sections[i].content, size);
		}
	}
}

void CPIO_Handler::writeContent()
{
	std::ofstream out;
	out.open("data.bin", std::ios::out | std::ios::binary);

	if (out.is_open()) {
		out.write((char*)this->Header, sizeof(this->Header));
		out.write((char*)this->Sections, sizeof(this->Sections)*3);
		out.close();
	}
}