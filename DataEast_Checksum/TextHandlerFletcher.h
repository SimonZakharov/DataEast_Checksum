#pragma once
#include "TextFileHandler.h"
class TextHandlerFletcher : public TextFileHandler
{
public:
	TextHandlerFletcher(std::string fname);
	~TextHandlerFletcher();
	uint word_checksum(std::string word) override;
};