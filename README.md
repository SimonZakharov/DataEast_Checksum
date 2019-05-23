# DataEast_Checksum
Solution of the test task from DataEast

--------------------Structure of the solution--------------------

FileHandler.h - in this header file an abstract class FileHandler is being introduced. The class contains 
four pure virtual functions corresponding to the subtasks:
count() - to count the number of occurrences of some word in a text file;
word_checksum() - to calculate a checksum for a word given as the argument;
checksum() - to calculate a file checksum;
set_filename() - to change the name of the file we're working with.
Any class inherited directly from FileHandler (e.g. TextFileHandler) must override all of these methods somehow.

A programmer should inherit one's class from FileHandler directly in case of:
 - the one wants the program to work with some other formats of files (e.g. binary files of archieves)
 - the one wants to use some different method of acceccing a text file (e.g. with fopen() instead of ifstream)
 - the one wants to use some different algorithm of calculating checksumes for a single word as well as for a whole file
 
TextFileHandler.h + TextFileHandler.cpp - this is an example of realization of the functions introduced in FileHandler.
Also TextFileHandler class has a default constructor, any object of this class should be constructed with a textfile name.

  count(filename) - function creates an ifstream and uses it to read the textfile with the name given
as the argument. The returned value is equal to the number of words which have been read from the file. In case of any
troubles with opening the file for reading (e.g. invalid filename) the returned value will be under 0.
 
  word_checksum(word) - function returns the number of letters in the word given as the argument.
  
  checksum() - function calculates the file checksum; the file name is a protected field of the current object of the
TextFileHandler class, so the function takes no arguments. The returned value is equal to the sum of checksumes of
every word in the text file.

A programmer is able to extend the solution if the one wants the program e.g. to use another algorithm of calculating
a checksum for a word without overriding count() and checksum() functions. In this case one should create a class
inherited from TextFileHandler.

TextHandlerFletcher.h + TextHandlerFletcher.cpp - this is an example class inherited from TextFileHandler with the only
function word_checksum(word) overrided. In this example a naive algorithm of calculating Fletcher's checksum of a single
word is introduced (block length is 1 byte, checksum length is 2 bytes).
