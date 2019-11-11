#include <stdio.h>
#include "fileInput.h"

// Reads a text file into a char array (string).
// 'fileName' is the name of the text file to read.
// 'textStr' returns the text from the file as a string. You must pass
//           a char array that is large enough to hold the entire file.

int readFile(const char fileName[], char textStr[])
{
	FILE *fptr;
	char ch;
	int size = 0;
	
	if ((fptr = fopen(fileName, "r")) == NULL) {
		fprintf(stderr, "Error, failed to open %s: ", fileName);
		perror("");
		return -1;
	}
	
	while ((ch = fgetc(fptr)) != EOF) {
	    if (size == MAX_FILE - 1)
	        break;
		textStr[size++] = ch;
    }
		
	textStr[size] = '\0';
	
	return size;	
}

