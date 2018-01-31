/*
This stores methods for ouput and formatting.
	1.) Display to screen. 
	2.) Display to file. 
	3.) Format plaintext (format carries over to ciphertext). 
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