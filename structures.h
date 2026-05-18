#pragma once

struct CPIO_HEADER {
	int ID;
	unsigned int numberofFiles;
	unsigned int* sizes;
};

struct CPIO_SECTION {
	char filename[32];
	char* content;
};