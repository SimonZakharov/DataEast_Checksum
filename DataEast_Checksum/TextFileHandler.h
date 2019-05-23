#pragma once

#include "FileHandler.h"
#include <fstream>
class TextFileHandler :	public FileHandler
{
public:
	///	constant values
	static constexpr char HELP[] = "\n -f <filename> -m checksum\tuse these parameters to calculate the checksum of the file\n -f <filename> -m count -w <word>\tuse these parameters to count the number of occurrences of the <word> in the textfile\n";
	static constexpr char ERROR_MSG[] = "Incorrect commandline arguments. Use -h argument for help";
	static constexpr char ERROR_HANDLE[] = "Error while handling the file. Make sure the filename is correct";
	///	constructors + destructor
	TextFileHandler();
	TextFileHandler(std::string fname);
	~TextFileHandler();
	///	override virtual methods
	uint count(std::string word) override;
	virtual uint word_checksum(std::string word) override;
	virtual uint checksum() override;
	void set_filename(std::string filename) override;

protected:
	std::string filename;
};