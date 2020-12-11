//pluralize program
//Mac Consolabe COP2220
//fall 2020 program 7


#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include<stdio.h>
#include<ctype.h>
#include<string.h>


//function prototypes go here

//A function that greets the user and gets the first name of the user
void Greeting(char name[]);

//A function that gets the word from the user and makes a copy of the word
void GetWord(char word[], char plural[]); //character arrays

//changes a string (character arraywith '\0') to all uppercase 
void Uppercaseword(char plural[]);


//A function that determines which rule applies to the word.
void WhichRule(char plural[]);

//add 3 more functions, one for each rule
void ApplyRuleOne(char plural[]);

void ApplyRuleTwo(char plural[]);

void ApplyRuleThree(char plural[]);
//main function

int main()
{
	//declare a character for the while loop
	char again;
	//declare 3 character arrays, around size 25: word, plural, name
	char firstName[30];
	char originalWord[25];
	char pluralWord[25];
	//call the greeting function to greet and get the name
	Greeting(firstName);

	printf("\n----------------------------------------\n");

	//ask and get input, doe the user want to enter a (loop initialization)
	printf("\n %s,  Do you want to pluralize a word? (y or n)\n",firstName);
	scanf(" %c", &again);
	///begin while loop (loop test)
	while(again=='y'|| again=='Y')
	{
		//Ask, get, and copy the word (GetWord function call)
		GetWord(pluralWord, originalWord);
		//make the plural word all uppercase letters(Uppercaseword function call) 
		Uppercaseword(pluralWord);
		//determine which rule 
		WhichRule(pluralWord);
		printf("\n%s, Printing both words in the main function:\n\n",firstName);
		//print name, word, and plural onto the screen
		printf("\nOriginal word : %s,plural word : %s\n\n", originalWord,pluralWord);
		printf("\n----------------------------------------\n");
		//again? (loop update)
		printf("\n Do you want to pluralize another word? (y or n)\n");
		scanf(" %c", &again);
	}

	//printf("\nThank you for trying out the Pluralizer, %s!\n",firstName);
	return 0;
}

//FUNCTION DEFINITION:  greets the user
//A function that greets the user and gets the first name of the user
void Greeting(char name[])
{
	printf("\n Enter Your First Name : \n");
	scanf(" %s", name);

	printf("\n%s, Welcome to the pluralizer!", name);
}

//FUNCTION DEFINITION: gets the word from the user and makes a copy
void GetWord(char word[], char plural[]) //character arrays
{
	int len;
	printf("\n Enter a word : \n");
	scanf(" %s", word);
	len = strlen(word);
	/*printf("\nlenght is %d", len);
	
	for (i = 0; i < len; i++)
	{
		plural[i] = word[i];
	}
	plural[len] = '\0';*/
	strcpy(plural, word);

}

//FUNCTION DEFINITION: changes a string (character arraywith '\0') to all uppercase 
//changes a string (character arraywith '\0') to all uppercase 
void Uppercaseword(char plural[])
{
	int i, len;
	len = strlen(plural);
	printf("\nlenght is %d", len);

	for (i = 0; i < len; i++)
	{
		plural[i] = toupper(plural[i]);
	}
	
}

//FUNCTION DEFINITION: determines which rule applies and calls the correct function
void WhichRule(char plural[])
{
	int len;
	len = strlen(plural);

	if (plural[len - 1] == 'Y')
	{
		printf("\nRule is 1");
		//call the function to apply Rule 1
		ApplyRuleOne(plural);
	}
	else if (plural[len - 1] == 'S')
	{
		printf("\nRule is 2");
		//call the function to apply Rule 2
		ApplyRuleTwo(plural);
	}
	else if (plural[len - 1] == 'H'&& plural[len - 2]=='C')
	{
		printf("\nRule is 2");
		//call the function to apply Rule 2
		ApplyRuleTwo(plural);
	
	}
	else if (plural[len - 1] == 'H' && plural[len - 2] == 'S')
	{
		printf("\nRule is 2");
		//call the function to apply Rule 2
		ApplyRuleTwo(plural);

	}
	else if (plural[len - 1] == 'X' || plural[len - 1] == 'Z')
	{
		printf("\nRule is 2");
		//call the function to apply Rule 2
		ApplyRuleTwo(plural);

	}
	else
	{
		printf("\nRule is 3");
		//call the function to apply Rule 3
		ApplyRuleThree(plural);
	}
	//add the rest of the conditions



}

//FUNCTION DEFINITION: applies rule one
void ApplyRuleOne(char plural[])
{
	int len = strlen(plural);
	plural[len - 1] = '\0';
	srtcat(plural, "IES");

}


//FUNCTION DEFINITION: applies rule 2
void ApplyRuleTwo(char plural[])
{
	srtcat(plural, "ES");
}

//FUNCTION DEFINITION: applies rule 3
void ApplyRuleThree(char plural[])
{
	strcat(plural, "S");
}

