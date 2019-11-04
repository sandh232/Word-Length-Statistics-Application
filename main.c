/**
* Programmer: Manpreet Sandhu
* 
**/

#include <stdio.h>
#include "fileInput.h"
#include <string.h>
#include "main.h"

/** Function prototype for 'displayHistogram' **/
void displayHistogram(const int count[],double scalingFactor);

/**
* Main method
* @param argc
* @param argv
**/
int main(int argc, char** argv) {

	/** Word Length Counter Variable **/
	int wordLengthCounter = 0;
	/** Array of int(arr) with size 21 **/
	int arr[21]= {0};
	/** Array of char(textStr) **/
	char textStr[MAX_FILE];
	/** len Variable**/
	int len = readFile("wonder.txt", textStr);

	/** if-else Statement to check the number of characters read, or -1 on errors **/
	if (len == -1) {

		printf("An error occurred\n");

	} else {

		/** forloop to iterate within the text file **/
		for(int i =0; i<strlen(textStr); i++) {

			/** if-else Statement to check upper or lower case letter **/
			if (textStr[i] >= 'A' && textStr[i] <= 'Z') {

				wordLengthCounter++;//incrementing the wordLengthCounter variable

			} else if(textStr[i] >= 'a' && textStr[i] <= 'z') {

				wordLengthCounter++;//incrementing the wordLengthCounter variable

			} else {

				//arr[wordLengthCounter] +=1;
				wordLengthCounter = 0;//setting the wordLengthCounter variable to 0
			}
			
		}
	}

	/**Calculating the statistics **/

	/** Longest Word Length variable **/
	int longestWordLength = 1;
	/** Shortest Word Length variable **/
	int shortestWordLength = 1;
	/** Max Count variable **/
	int max_count= arr[1];
	/** Common Length variable **/
	int commonLength=0;
	/** Scaling Factor variable **/
	double scalingFactor = 0;

	/** forloop to iterate within the arr[21] Array **/
	for (int i = 1; i < 21; i++) {

		/** if-else statement to check that no elements in arr[21] is equal to 0 **/
		if(arr[i] != 0) {


			/** if-else statement to find the longestWordLength **/
			if(i > longestWordLength) {
				longestWordLength = i;
			}
			/** if -else statement to find the shortestWordLength **/
			if(i < shortestWordLength) {
				shortestWordLength = i;
			}
			/** if -else statement to find the commonLength **/
			if(arr[i] > max_count) {

				max_count = arr[i];
				commonLength =i;
			}
		}
	}
	/** if-else statement to check max_count is greater than 70 and less than or equal to 70 **/
	if(max_count > 70) {

		scalingFactor = (double)70/max_count;//calculating scaling factor by 70 ÷ max_count

	} else if(max_count <= 70) {

		scalingFactor =1;//setting scaling factor to 1
	}

	/** Invoke the displayHistogram method **/
	displayHistogram(arr,scalingFactor);

	/** Print Statements **/
	printf("\n");
	printf("Most common word length: %d letters\n",commonLength);
	printf("Length of the shortest word: %d letter\n",shortestWordLength);
	printf("Length of the longest word: %d letters\n",longestWordLength);

	return 0;

}//end of the main method


/**
* displayHistogram method to display the histogram
* @param count
* @param scalingFactor
**/
void displayHistogram(const int count[], double scalingFactor) {

	/** forloop to iterate b/w 1 to 20 elements **/
	for (int i = 1; i<=20; i++) {

		printf("%d ",i);

		for(int j=1; j<=(double)(count[i] * scalingFactor); j++) {

			printf("X");

		}
		printf(" %d\n",count[i]);
	}

}//end of the displayHistogram method














