#include <cstdio>
#include "TextFileHandler.h"
#include "TextHandlerFletcher.h"

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		///	help
		std::string arg = argv[1];
		if (arg.compare("-h") == 0)
		{
			printf("%s\n", TextFileHandler::HELP);
			return 0;
		}
		printf("%s\n", TextFileHandler::ERROR_MSG);
		return 1;
	}
	if (argc == 5)
	{
		///	count checksum
		std::string f = argv[1], filename = argv[2], m = argv[3], mode = argv[4];
		if (f.compare("-f") == 0 && m.compare("-m") == 0 && mode.compare("checksum") == 0)
		{
			FileHandler *handler = new TextHandlerFletcher(filename);
			uint res = handler->checksum();
			if (res != -1)
				printf("Calculated checksum = %ld\n", res);
			else
			{
				delete handler; 
				printf("%s\n", TextHandlerFletcher::ERROR_HANDLE);
				return 1;
			}
			delete handler;
			return 0;
		}
		printf("%s\n", TextHandlerFletcher::ERROR_MSG);
		return 1;
	}
	if (argc == 7)
	{
		///	count word occurrences
		std::string f = argv[1], filename = argv[2], m = argv[3], mode = argv[4], w = argv[5], word = argv[6];
		if (f.compare("-f") == 0 && m.compare("-m") == 0 && mode.compare("count") == 0 && w.compare("-w") == 0)
		{
			FileHandler *handler = new TextFileHandler(filename);
			uint res = handler->count(word);
			if (res != -1)
				printf("%ld words %s found\n", res, argv[6]);
			else
			{
				delete handler;
				printf("%s\n", TextFileHandler::ERROR_HANDLE);
				return 1;
			}
			delete handler;
			return 0;
		}
		printf("%s\n", TextFileHandler::ERROR_MSG);
		return 1;
	}
	printf("%s\n", TextFileHandler::ERROR_MSG);
	return 1;
}