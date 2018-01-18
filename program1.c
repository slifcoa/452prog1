/**********************************************
**Programming Assignment 1
**Done By Adam Slifco
**January 18th 2018
**********************************************/

#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {

	//String Variable for user input
	char input[100];

	//Struct will hold current terminal parameters
	struct termios  curParameters;
	
	//retrieve current terminal parameters
	tcgetattr(STDIN_FILENO, &curParameters);

	//Disable the echo value initially
       	 printf("Disabling Echo... \n");
       	 curParameters.c_lflag &= ~ECHO;

	//Update the terminal attributes
	tcsetattr(STDIN_FILENO, TCSANOW, &curParameters);

	//Prompt user to enter phrase
	printf("Enter secret word/phase: ");
	scanf("%[^\n]s", input);
	printf("\n");

	//Display what user entered
	printf("You entered: %s\n\n", input);

	//Enable the Echo & Notify User
	curParameters.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &curParameters);
	printf("Default behavior restored. \n");

	//Prompt user for visible input
	printf("Enter visible word/phrase: ");
	scanf("%s", input); 
}
