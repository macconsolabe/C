/*COP 2220  (program6.c) - larger program
//Mac Consolabe, 10/26/2020 */


#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler

#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes DO NOT REMOVE THE COMMENTS
void Greeting(void);
//welcome the user to the coffee shop

char OptionList();
//Display the program choices (S, O, B, A, Q)
//declare, ask, get, and return the users choice

double ProcessOption(char choice, double balance);
//input: the user's choice and the account balance
//return the updated balance

void DisplayMenu();
//displays the beverage/food options and prices

double OrderPrice();
//declare, ask, and get the item number from the user
//determine and return the price of the item
void ViewBalance(double balance);
//input: the balance in the account
//displays the current account balance of user

double Reload(double balance);
//input: the current balance in the account
//declare, ask, and get the amount to add 
//add the amount to the local copy of the balance and return the new balance
int CheckForEnoughMoney(double balance, double price);
//input: the account balance and the item price
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough 

//main function
int main()
{
	char choiceInMain;
	double balanceInMain = 0.00;
	FILE* inPtr;
	//connect to the file use fopen
	inPtr = fopen("accountBalance.txt", "r");
	//use fscanf to read the balance from the file
	fscanf(inPtr, "%lf", &balanceInMain);
	ViewBalance(balanceInMain);

	//greet the user - Greeting function call
	Greeting();

    //call OptionList 
	choiceInMain = OptionList();
	//change the choiceInMain to lowercase //INITIALIZATION
	choiceInMain = tolower(choiceInMain);
	
	while (choiceInMain != 'q')//TEST
	
	{
		//ProcessOption function call
		balanceInMain = ProcessOption(choiceInMain, balanceInMain);
		//UPDATE OF THE WHILE LOOP

		//call OptionList 
		choiceInMain = OptionList();
		//change the choiceInMain to lowercase 
		choiceInMain = tolower(choiceInMain);
	}
	
FILE* outPtr;
//connect to the file use fopen
outPtr = fopen("accountBalance.txt", "w"); 
//use fprintf to write the balance to the file
fprintf(outPtr, "%.2f", balanceInMain);
printf("\nHave a great day!\n\n");
//close both file pointers use fclose
fclose(inPtr);
fclose(outPtr);
return 0;

}
//function definitions
void Greeting(void)
//welcome the user to the coffee shop
{
	//write a welcome message to the user
	printf("\n Welcome To Ayti Cafe\n");

}
char OptionList()
//Display the program choices (S, O, B, A, Q)
//declare, ask, get, and return the users choice
{
	char option;
	//display the program options, get, and return the option
	printf("---------------------------------------------------");
	printf("\nPlease select from the following options:\n");
	printf("\n'S' to view the snack and beverages available for purchase\n"
		"\n'O' to order coffee or a snack\n"
		"\n'B' to view your account balance\n"
		"\n'A' to add money to your account\n"
		"\n'Q' to Quit\n");

	//('S', 'O', 'B', 'A', 'Q')
	printf("\nEnter:");
	scanf(" %c", &option);
	return option;
}
double ProcessOption(char choice, double balance)
//input: the user's choice and the account balance
//return the updated balance
{
	//declare local variables
	double price;
	int enough;

	if (choice == 's')
	{
		//printf("\nDisplay the menu\n");
		//display the menu (snack and coffee choices)
		DisplayMenu();
		//cll DisplayMeny function
		DisplayMenu();
	}
	else if (choice == 'o')
	{
		
		//Display the balance (call the function)
		ViewBalance(balance);
		// DisplayMenu Function
		DisplayMenu();
		
		//call the OrderPrice function
		price = OrderPrice();
		

		//call the  CheckForEnoughMoney function
		enough = CheckForEnoughMoney(balance, price);
		//add conditions(if/else): enough money, not enough money
		
			if (enough == 1)
			{
				balance = balance - price;
				printf("\n Enjoy your purchase!\n");
			}
			else
			{
				printf("\nPlease reload\n");
				balance = balance + Reload(balance);
			}
	}
	else if (choice == 'b')
	{
		ViewBalance(balance);

	}

	else if (choice == 'a')
	{
	
		ViewBalance(balance);
		balance = Reload(balance);
		ViewBalance(balance);

	}
	else
	{
		printf("\n Input Not Recognized");
	}

	return balance;
}
	void DisplayMenu()
		//displays the beverage/food options and prices
	{
		printf("Here are the coffee and snack options:");
		printf("\n1. Hot coffee           $2.35\n"
			"\n2. Iced coffee          $2.35\n"
			"\n3. Hot Latte            $4.68\n"
			"\n4. Iced Latte           $4.68\n"
			"\n5. Butter Croissant     $3.50\n"
			"\n6. Almond Croissant     $4.50\n"
			"\n7. Blueberry muffin top  $3.25\n");
	
	}
	double OrderPrice()
		//declare, ask, and get the item number from the user
		//determine and return the price of the item
	{
		int item; 
		double price = 0.0;
		printf("\n Enter your selection number :");
		scanf("%d", &item);
		if (item == 1)
		{
			printf("You selected Hot Coffee, the price is $2.35\n");
			price = 2.35;
		}

		else if (item == 2)
		{
			printf("You selected  Iced coffee, the price is $2.35\n");
			price = 2.35;

		}

		else if (item == 3)
		{
			printf("You selected  Hot Latte, the price is $4.68\n");
			price = 4.68;
		}

		else if (item == 4)
		{
			printf("You selected  Iced Latte, the price is $4.68\n");
			price = 4.68;
		}

		else if (item == 5)
		{
			printf("You selected  Butter Croissant, the price is $3.50\n");
			price = 3.50;
		}

		else if (item == 6) {
			printf("You selected  Almond Croissant, the price is $4.50\n");
			price = 4.50;
		}

		else if (item == 7)
		{
			printf("You selected  Blueberry Muffin Top, the price is $3.25\n");
			price = 3.25;
		}
		else {
			printf("That is not a valid selection");
			price = 0.0;
		};

		return price;
	
	}
	
	void ViewBalance(double balance)
		//input: the balance in the account
		//displays the current account balance of user
	{
		printf("\nYour current balance in your account is $%.2f\n", balance);
	
	}
	double Reload(double balance)
		//input: the current balance in the account
		//declare, ask, and get the amount to add 
		//add the amount to the local copy of the balance and return the new balance
	{
		double reloadBalance;

		printf("Please add reload amount: ");
		scanf("%lf", &reloadBalance);
		return (reloadBalance + balance);	
	}
	int CheckForEnoughMoney(double balance, double price)
		//input: the account balance and the item price
		//return 1 if the balance is enough to cover the price
		//return 0 if it is not enough
	{
		if (balance >= price)
		{
			return 1;
		}
		else
		{
			printf("\nYou do not have enough money for the purchase\n");
			OptionList();
			return 0;
		}
	}