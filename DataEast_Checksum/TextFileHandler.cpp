#include "TextFileHandler.h"

TextFileHandler::TextFileHandler() {}

TextFileHandler::TextFileHandler(std::string fname)
{
	filename = fname;
}

TextFileHandler::~TextFileHandler() {}

uint TextFileHandler::count(std::string word)
{
	std::ifstream file(filename);
	if (!file || !file.is_open())
		return -1;
	uint result = 0;
	for (std::string w; file >> w; )
	{
		if (w.compare(word) == 0)
			result++;
	}
	file.close();
	return result;
}

uint TextFileHandler::word_checksum(std::string word)
{
	return word.size();
}

uint TextFileHandler::checksum()
{
	std::ifstream file(this->filename);
	if (!file || !file.is_open())
		return -1;
	uint result = 0;
	for (std::string w; file >> w; )
		result += word_checksum(w);
	file.close();
	return result;
}

void TextFileHandler::set_filename(std::string fname) { filename = fname; }