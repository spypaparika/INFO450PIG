// pigLatin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int translateToPigLatin();

int translateToPigLatin(char userInput[50])
{
	char pigLatinTranslate[50] = "";
	char firstLetter[2] = "";
	char wordBody[100] = "";
	char ending[3] = "ay";
	int stringLength;
	int i = 0;
	int leave = 0;
		
		stringLength = strlen(userInput);
		if (userInput[0] == '0' || userInput[0] == '1' || userInput[0] == '2' || userInput[0] == '3' || userInput[0] == '4' || userInput[0] == '5'
			|| userInput[0] == '6' || userInput[0] == '7' || userInput[0] == '8' || userInput[0] == '9')
		{
			leave = -1;
			cout << "error" << endl;
		}
		else if (stringLength <= 2 || !strcmp(userInput, "an") || !strcmp(userInput, "a") || !strcmp(userInput, "and") || !strcmp(userInput, "but")
			|| !strcmp(userInput, "for") || !strcmp(userInput, "so") || !strcmp(userInput, "nor") || !strcmp(userInput, "the") || !strcmp(userInput, "yet")
			|| !strcmp(userInput, "or"))
		{
			strcpy_s(pigLatinTranslate, userInput);
			cout << "2" << endl;
			cout << "Your text in pig latin is: " << pigLatinTranslate << endl;
		}
		//if letter starts with vowel
		else if (userInput[0] == 'a' || userInput[0] == 'e' || userInput[0] == 'i' || userInput[0] == 'o' || userInput[0] == 'u' || userInput[0] == 'y')
		{
			strcat_s(pigLatinTranslate, userInput);
			strcat_s(pigLatinTranslate, ending);
			cout << "1" << endl;
			cout << "Your text in pig latin is: " << pigLatinTranslate << endl;
		}
		
		else{
			firstLetter[0] = userInput[0];
			while (i <= stringLength)
			{
				wordBody[i] = userInput[i + 1];
				i++;
			}
			strcat_s(pigLatinTranslate, wordBody);
			strcat_s(pigLatinTranslate, firstLetter);
			strcat_s(pigLatinTranslate, ending);
			cout << "Your text in pig latin is: " << pigLatinTranslate << endl;
		}
		

	return leave;
}

int main()
{
	char newInput[50] = "";
	int end = 0;
	//input string
		cout << "Please enter text" << endl;
		gets_s(newInput);
		while (strcmp(newInput, "quit") && end > 0){
			end = translateToPigLatin(newInput);
			cout << "Please enter text" << endl;
			gets_s(newInput);
		}
	


	return 0;
}

