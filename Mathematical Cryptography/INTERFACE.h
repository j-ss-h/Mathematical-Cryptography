#include "DISPLAY.h"
#include "MAPS.h"
#include "AFFINE_CIPHER.h"
#include "SUBSTITUTION_CIPHER.h"
#include "VIGENERE_CIPHER.h"

void cipherInterface(void)
{
	vector<vector<char> > text;
	string inputS;
	char input;
	bool data = false;
	ifstream fin;
	int selection = -1;
	while (selection != 0)
	{
		cout << "***Mathematical Cryptography Menu***\n"
			<< "1.) Fetch input data\n"
			<< "2.) Shift cipher\n"
			<< "3.) Multiplicative cipher\n"
			<< "4.) Affine cipher\n"
			<< "5.) Substitution cipher\n"
			<< "6.) Vigenere cipher\n"
			//<< "7.) Hill cipher\n"
			// additions will be made when more material is introduced. 
			<< "0.) Exit.\n\n"
			<< "Selection: ";
		cin >> selection;
		switch (selection)
		{
		case 1:
			cout << "File to retrieve: ";
			cin >> inputS;
			fin.open(inputS + ".txt");
			if (fin.is_open())
			{
				text = formatText(fin);
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
		case 5:
			if (!data)
			{
				cout << "Fetch input data first.\n";
			}
			else
			{
				puts("");
				cipherSubstitution(text);
			}
			break;
		case 6:
			if (!data)
			{
				cout << "Fetch input data first.\n";
			}
			else
			{
				puts("");
				cipherVigenere(text);
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