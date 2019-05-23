#include "TextHandlerFletcher.h"

TextHandlerFletcher::TextHandlerFletcher(std::string fname)
{
	filename = fname;
}

TextHandlerFletcher::~TextHandlerFletcher() {}

uint TextHandlerFletcher::word_checksum(std::string word)
{
	uint sum1 = 0, sum2 = 0;
	for (uint i = 0; i < word.size(); ++i)
	{
		sum1 = (sum1 + word[i]) % 255;
		sum2 = (sum2 + sum1) % 255;
	}
	return (sum2 << 8) | sum1;
}