/*
	Calvin Aduma
	September 22, 2019
	CPSC 1110
	Project #1
	This code reads the contents of a user specified file and prints those contents
	onto the screen. It also shows the total number of characters in the file and 
	searches for a specific user identified character along with the frequency of 
	the character.
*/

#include <stdio.h>
#define SIZE 8000

int main(void){
	// initialize variables and creates array
	char textArray[SIZE] = "0";
	int count, i, numChar, charCount;
	char  userCharacter;
	
	// loop to create array, read text, and place text in array
	for(i=0; i<SIZE; i++){

		// gathers text from stdin file
		scanf("%c", &textArray[i]);

		// prints text from stdin file
		printf("%c", textArray[i]);

		// counter for characters
		count++;

		// a way to end count.
		// it checks if the char element after the first empty space is empty.
		// therefore it will have a count +1 more than the normal  count.
		if(textArray[i] == '\0'  && textArray[i-1] == '\0'){
			i = SIZE;
			count--;
		}
	}
	// the count is -1 because the normal count includes the space after the last word
	printf("\nThe count is %d\n", count-1);

	// User character input
	printf("\nEnter a character to search for in the text: ");

	// Adding a space before %c does not fix the code
	freopen("/dev/tty","r",stdin);
	scanf("%c", &userCharacter);
	numChar = userCharacter;

	// search for character in text
	for(i=0; i<=count; i++){
		if(numChar < 97){
			if(textArray[i] == numChar){
				charCount++;
			}
			if(textArray[i] == numChar+32){
				charCount++;
			}
		}
		if(numChar >= 97){
			if(textArray[i] == numChar){
				charCount++;
			}
			if(textArray[i] == numChar-32){
				charCount++;
			}
		}
	}
	//prints statement
	printf("\nThe character %c appears a total of %i times.\n", userCharacter, charCount);
}	
