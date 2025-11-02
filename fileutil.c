// Thomas Eastwood
// 10-26-2025 - CS46 Prof. Brown

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"
#include "ansi-colors.h"

#define STR_MAX 100

//Displays an array of strings from a 2D array 
void print2DStrArray(char arr[][STR_MAX], int len){
	if(len==0){printf("No Array!");}
	int width = 1;
	for (int tmp = len - 1; tmp >= 10; tmp /= 10){width++;}
    for (int i = 0; i < len; i++){printf("Row [%0*d]: %s \n", width, i, arr[i]);}
    printf("\n");
}

//Prints in a color
void printColor(char str[], char color[]){
    printf("%s%s%s", color, str, CRESET);
}

//Custom exit command with more helpful error codes
void errorOut(int code){
    printColor("[!]ERROR! Exit code (", RED);
    printf("%d",code);
    printColor(")\n", RED);
    /*
    1   : File Not Found
    2   : Incorrect amount of runtime arguments
	3	: Incorrect Loop iteration
    */
    exit(1);
}

//Ensure argument count is acceptable
void checkArgC(int argC, int min, int max){
    if (!(min <= argC <= max))
	{
		fprintf(stderr, "Must supply valid argument\n");
		errorOut(2);
	}
}

//Trims the newline off the end of a string
void trimNL(char *str) {
    if (strlen(str) > 0 && str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
}


// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.


// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array of strings.
	return NULL;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	int MAXLINES = 100;

	// Allocate memory for an 2D array, using COLS as the width.
	char (*arr)[COLS] = malloc(MAXLINES * sizeof(char[COLS]));
	*size = 0;

	// Read the file line by line into a buffer.
	char line[COLS];
	while(fgets(line, sizeof(line), in)){
		
		//   Trim newline.
		trimNL(line);

		//   Expand array if necessary (realloc).
		char (*tmp)[COLS] = realloc(arr, (*size+1) * sizeof(char[COLS]));
		if(!tmp){free(arr); errorOut(3);}
		arr = tmp;
		
		//   Copy each line from the buffer into the array (use strcpy).
		strcpy(arr[*size], line);
		*size = *size + 1;
    
    }
    // Close the file.
	fclose(in);
	
	// The size should be the number of entries in the array.
	
	// Return pointer to the array.
	return arr;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{
	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
	
	for(int i=0; i < size; i++){
		if(!strcmp(target,lines[i])){return lines[i];}
	}

    return NULL;
}

// Free the memory used by the array
void freeAA(char ** arr, int size)
{

}

void free2D(char (*arr)[COLS])
{
	free(arr);
}