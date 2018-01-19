#include "DISPLAY.h"
#include "AFFINE_CIPHER.h"

void cipherInterface(void)
{
	vector<vector<char> > text;
	string inputS;
	char input;
	bool data = false;
	ifstream fin;
	int shift = 0, choice = -1;
	while (choice != 0)
	{
		cout << "***Mathematical Cryptography Menu***\n"
			<< "1.) Fetch input data\n"
			<< "2.) Shift cipher\n"
			<< "3.) Multiplicative cipher\n"
			<< "4.) Affine cipher\n"
			// additions will be made when more material is introduced. 
			<< "0.) Exit.\n\n"
			<< "Selection: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "File to retrieve: ";
			cin >> inputS;
			fin.open(inputS + ".txt");
			if (fin.is_open())
			{
				while (getline(fin, inputS))
				{
					vector<char> temp;
					for (int i = 0; i < inputS.length(); i++)
					{
						temp.push_back(inputS[i]);
					}
					text.push_back(temp);
					inputS = "";
				}
				data = true;
				fin.close();
			}
			else
			{
				cout << "Error opening input file!\n";
			}
			break;
		case 2:
			if (!data)
			{
				cout << "Fetch input data first.\n";
			}
			else
			{
				puts("");
				cipherShift(text);
			}
			break;
		case 3:
			if (!data)
			{
				cout << "Fetch input data first.\n";
			}
			else
			{
				puts("");
				cipherMultiplicative(text);
			}
			break;
		case 4:
			if (!data)
			{
				cout << "Fetch input data first.\n";
			}
			else
			{
				puts("");
				cipherAffine(text);
			}
			break;
		case 0:
			cout << "Exiting application...\n";
			break;
		default:
			cout << "Invalid input...\n";
			break;
		}
		puts("");
	}
}