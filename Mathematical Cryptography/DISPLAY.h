/*
File Name: DISPLAY.h
Programming: Jesse A. Hankins
	Southeast Missouri State University
	Course: MA464-01
	Semester: Sprint 2018
	Date Last Modified: 2/2/2018

Description:
	This file contains the methods for displaying to screen, printing to file, and formatting text from "input.txt".

displayToScreen():
	Accepts a 2-dimensional character vector "input".
	Prints the contents of "input" to screen, retaining only the order and row placement of values. 
	Returns nothing. 

displayToFile():
	Accepts a 2-dimensional character vector "input" and an output file stream "fout".
	Prints the contents of "input" to the filestream "fout", retaining only the order and row placement of values. 
	Returns nothing. 

formatText():
	Accepts an input file stream "fin". 
	Places the characters (omitting non-character values) in a 2-dimensional character vector in groups of 5 characters, 
		which are seperated by a space entry, and limits each row to a maximum of 10 groups. 
	Returns a 2-dimensional character vector.

*/
void displayToScreen(vector<vector<char> > input)
{
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			cout << input[i][j];
		}
		puts("");
	}
}

void displayToFile(vector<vector<char> > input, ofstream & fout)
{
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			fout << input[i][j];
		}
		fout << endl;
	}
}

vector<vector<char> > formatText(ifstream & fin)
{
	string str;
	vector<char> input, temp;
	vector<vector<char> > answer;
	while (getline(fin, str))
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isalpha(str[i])) // skips spaces and punctuation. 
			{
				if (islower(str[i])) // converts to upper case. 
				{
					str[i] = toupper(str[i]); 
				}
				input.push_back(str[i]);
				counter++; // keeps track of number of characters in plaintext matrix.
			}
		}
		str = "";
	}
	for (int i = 0; i < input.size(); i++)
	{
		if ((i % 50 == 0) && (i != 0))
		{
			answer.push_back(temp);
			temp.clear();
			temp.push_back(input[i]);
		}
		else if ((i % 5 == 0) && (i != 0))
		{
			temp.push_back(' ');
			temp.push_back(input[i]);
		}
		else
		{
			temp.push_back(input[i]);
		}
	}
	answer.push_back(temp);
	return answer;
}