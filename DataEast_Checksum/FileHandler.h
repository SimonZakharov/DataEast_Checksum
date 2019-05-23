#pragma once
#include <string>

#define uint uint16_t

class FileHandler
{
public:
	virtual uint count(std::string word) = 0;
	virtual uint word_checksum(std::string word) = 0;
	virtual uint checksum() = 0;
	virtual void set_filename(std::string fname) = 0;
};