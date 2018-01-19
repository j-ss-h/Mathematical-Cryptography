#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

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