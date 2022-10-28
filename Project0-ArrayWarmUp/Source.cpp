/*  
	Ian Fletcher
	CST-201
	9/9/2022
	Project 0: Array Warm-Up
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//creates ifStream object myFile to store text.txt
	ifstream myFile("text.txt");
	//creates int arraySize to keep controll loops
	int arraySize = 100;
	//creates array of strings with an index of 100
	string words[100];
	//creates string to store values temporarily
	string bubble = "";
	int num = 0;
	//imports all words from text.txt to words and increases num everytime
	while (!myFile.eof())
	{
		myFile >> words[num];
		num++;
	}
	//displays array before sorting
	cout << "Array before sorting: " << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << words[i] << " ";
	}
	cout << "" << endl;
	//nested for loop that uses bubble sorting to sort array in order of ascii values
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize - 1; j++)
		{
			if (words[j] > words[j + 1])
			{
				bubble = words[j + 1];
				words[j + 1] = words[j];
				words[j] = bubble;
			}
		}
	}
	//displays array after sorting
	cout << "Array after sorting: " << endl;
	for (int i = 0; i < arraySize; i++)
	{
		cout << words[i] << " ";
	}
	cout << "" << endl;
	//creates string input to store user's input
	string input;
	//creates ints max, min, and place to run binary search
	int max = arraySize;
	int min = 0;
	int place = arraySize / 2;
	//creates boolean to keep track of if the word has been found or not
	bool found = false;
	//while loop for search that runs as long as the user doesn't input 0
	while (input != "0")
	{
		//prompts user to enter word for search
		cout << "Type the word you want to search, or 0 to exit " << endl;
		cin >> input;
		//stops code if input is 0
		if (input == "0")
		{
			break;
		}
		//resets values of max, min, place, and found for each new search
		max = arraySize;
		min = 0;
		place = arraySize / 2;
		found = false;
		//runs while found is false and max and min are more than 1 value apart
		while (found == false && (max - min) != 1)
		{
			//if input is the correct value, sets found to true and prints out index
			if (input == words[place])
			{
				cout << "The word was at index " << place << endl;
				found = true;
			}
			//if the ascii value of input < ascii value of the word at index place
			//sets max equal to place and place equal to ((max - min)/2) + min
			else if (input < words[place])
			{
				max = place;
				place = ((max - min) / 2) + min;
			}
			//if the ascii value of input > ascii value of the word at index place
			//sets min equal to place and place equal to ((max - min)/2) + min
			else if (input > words[place])
			{
				min = place;
				place = ((max - min) / 2) + min;
			}
		}
		//if the word is not found prints out that it was not found 
		if (!found)
		{
			cout << "-1: Your word was not found" << endl;
		}
	}
	}
	