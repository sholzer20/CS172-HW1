// SHolzerHW1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <stdio.h> //NULL
#include <stdlib.h> //srand, rand
#include <time.h> //time
#include <math.h> //pow, sqrt
#include <iostream> 
#include <string>
using namespace std;

void ex02();
void ex03();
void ex04();
void ex05();

int doubleInt(int);
int add(int, int);
int addOne(int &numb);
void readArray(int[], int);
void arrayContain(int[], int);

int main()
{
	ex02(); //Function for EX01_01
	ex03(); //Function for EX01_02
	ex04(); //Function for EX01_03
	ex05(); //Function for EX01_04

    return 0;
}

void ex02()
{
	//EX01_01 ----------------------------------------------------------------------------

	//Part a 
	bool hasPassedTest = true;

	//Part b
	srand(time(NULL)); //Seeding a random generator
	int x, y;
	x = rand(); //Generating random numbers
	y = rand();
	cout << "Two random numbers have been generated (x and y). The following statement explains their relationship." << endl;
	if (x >= y) //Statement to test which number is greater
	{
		cout << "Variable x is greater than or equal to variable y." << endl;
	}
	else
	{
		cout << "Variable x is less than variable y." << endl;
	}

	//Part c
	int numberOfShares;
	cout << "Please enter any number: "; //Prompts user input
	cin >> numberOfShares; //User input
	if (numberOfShares < 100) //Compares the entered number to 100
	{
		cout << "The number you entered is less than 100." << endl;
	}
	else
	{
		cout << "The number you entered is greater than 100." << endl;
	}

	//Part d
	int boxWidth, bookWidth;
	cout << "Please enter the width of a box (in inches): "; //Prompts user for inputs
	cin >> boxWidth;
	cout << "Please enter the width of a book (in inches): ";
	cin >> bookWidth;
	if (boxWidth%bookWidth == 0) //Modulo to see if boxWidth is evenly divided by bookWidth
	{
		cout << "The box width is evenly divided by the book width. A whole number of books fit inside the box." << endl;
	}
	else
	{
		cout << "The box width is not evenly divided by the book width." << endl;
	}

	//Part e
	int shelfLife, outsideTemp;

	cout << "Please enter the shelf life of a box of chocolates (in days): "; //Prompts user for shelf life and outside temperature
	cin >> shelfLife;
	cout << "Please enter the outside temperature (in degrees Fahrenheit): ";
	cin >> outsideTemp;

	if (outsideTemp > 90) //If outsideTemp excedes 90 degrees, shelfLife is decreased by 4 days
	{
		cout << "The shelf life of the chocolates is: " << shelfLife - 4 << endl;
	}
	else
	{
		cout << "The shelf life of the chocolates is: " << shelfLife << endl;
	}
	cout << endl;
}

void ex03()
{
	//EX01_02 ------------------------------------------------------------------------------------

	//Part a
	double area;
	cout << "Enter the area of a square: ";
	cin >> area;
	cout << "The diagonal of the square is: " << sqrt(2*area) << endl; //Diagonal is equal to sqrt of 2*area

	//Part b
	char yn;
	cout << "Enter either yes or no using \"y\" or \"n\": "; //Promts user for char input
	cin >> yn;
	if (yn == 'y') //Appropriate answers for user input
	{
		cout << "You entered yes." << endl;
	}
	else if (yn == 'n')
	{
		cout << "You entered no." << endl;
	}
	else
	{
		cout << "You didn't follow the directions." << endl;
	}

	//Part c
	char tab = '\t'; //Tab is initialized to a horizontal tab

	//Part d
	string mailingAddress;
	cout << "Please enter you mailing address: "; 
	cin.ignore();
	getline(cin, mailingAddress); //User input stored in the string mailingAddress

	//Part e
	string Empty = ""; //Empty is initialized to an empty string

	cout << endl;
}

void ex04()
{
	//EX01_03 ------------------------------------------------------------------------------------

	//Part a
	int userIn = 0;
	do // Do while loop to only accept an integer between 1 and 10
	{
		cout << "Enter a number between 1 and 10: ";
		cin >> userIn;
	} while (userIn < 1 || userIn >10);


	//Part b
	int sum = 0;
	for (int k = 1; k <= userIn; k++) //For loop gets each int between 1 and userIn
	{
		sum += (int)(pow(k, 3)); //cubes the int k and adds it to sum
	}
	cout << "The sum of the cubes of all the integers between 1 and your number is: " << sum << endl;

	//Part c
	int loopInt = userIn; //Receives the int from userIn
	do  //Prints an asterisk and decreases loopInt. While loop stops when loopInt reaches 0
	{
		cout << "*"; 
		loopInt--;
	} while (loopInt != 0);
	cout << endl;

	//Part d
	for (int k = 0; k <= 40; k += 2) //Increments the forloop by 2s
	{
		cout << k; //Outputs the integer
 		if (k < 40)
		{
			cout << " "; //Adds a space between integers for all but the last one
		}
	}
	cout << endl;
	
	//Part e
	cout << "The double of the integer from before is: " << doubleInt(userIn) << endl; //Calls doubleInt using the int from (a)

	//Part f
	int r1 = rand(); //Initializes two random numbers
	int r2 = rand();
	cout<< "The sum of two random numbers is: " << add(r1, r2) << endl; //calls add with the random numbers

	//Part g
	int numb;
	cout << "Enter any number: "; //User inputs any number
	cin >> numb;
	cout << "The number you entered plus one is: " << addOne(numb) << endl; //Calls addOne using pass by reference

	cout << endl;
}

void ex05()
{
	//EX01_04 -----------------------------------------------------------------------------

	//Part a
	int intArray[5]; //Initializes an empty array
	for (int k = 0; k < 5; k++) //Loops 5 times to retrieve 5 integers
	{
		cout << "Enter an integer: ";
		cin >> intArray[k]; //Entered integer goes in index k
	}

	//Part b
	int arraySum = 0;
	int	arrayProduct = 1; //Needs to be 1 because if 0, it will remain 0
	for (int k = 0; k < 5; k++) //Loops grabs each index and does the appropriate operation
	{
		arraySum += intArray[k];
		arrayProduct *= intArray[k];
	}
	cout << "The sum of all the integers in the array is: " << arraySum << endl;
	cout << "The product of all the integers in the array is: " << arrayProduct << endl;

	//Part c
	cout << "The numbers in the array are: ";
	readArray(intArray, 5); //Calls readArray using the intArray

	//Part d
	arrayContain(intArray, 5); //Calls arrayContain with the intArray


}

int doubleInt(int a)
{
	return 2 * a; //Returns the parameter * 2
}

int add(int a, int b)
{
	return a + b; //Adds the two parameters
}

int addOne(int &numb)
{
	return numb + 1; //Modifies the parameter by adding one
}

void readArray(int reading[], int length) 
{
	for (int k = 0; k < length; k++) //Checks each index
	{
		cout << reading[k]; //Outputs the integer
		if (k < length - 1) //If the index is the last, does not include the ,
		{
			cout << ", ";
		}
	}
	cout << endl;
}
void arrayContain(int passedArray[], int length)
{
	int intCheck = 0;
	cout << "Please enter an integer to see if it's in the array: ";
	cin >> intCheck; //User inputs an integer
	for (int k = 0; k < length; k++)
	{
		if (passedArray[k] == intCheck) //If the integer matches any of the numbers in the array, output says so
		{
			cout << "The array contains your guess!" << endl;
			return;
		}
	}
	cout << "The array does not contain your guess." << endl; //If the integer does not match any in the array, this message is outputted
}