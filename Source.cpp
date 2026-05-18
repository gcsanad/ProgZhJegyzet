#include "CPIO_Handler.h"

int main()
{
	CPIO_Handler Handler(3);
	std::string filenames[3];

	for (int i = 0; i < 3; i++) {
		std::cin >> filenames[i];
	}

	Handler.createHeader();
	Handler.fillContent(filenames);
	Handler.writeContent();
	return 0;
}