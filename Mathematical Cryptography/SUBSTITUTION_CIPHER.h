/*
File Name: SUBSTITUTION_CIPHER.h
Programming: Jesse A. Hankins
	Southeast Missouri State University
	Course: MA464-01
	Semester: Sprint 2018
	Date Last Modified: 2/2/2018

Description:
	This file contains the interface and methods to perform the substitution cipher.

encryptSUBSTITUTION():
	Accepts a 2-dimensional character vector "input", and a string "keyWord".
	Converts each value from "input" through map "encryptKey" found in GLOBAL_VARIABLES.h. 
	Returns an encrypted 2-dimensional character vector.

decryptSUBSTITUTION():
	Accepts a 2-dimensional character vector "input", and a string "keyWord".
	Converts each value from "input" through map "decryptKey" found in GLOBAL_VARIABLES.h. 
	Returns a decrypted 2-dimensional character vector.

setKey():
	Accepts nothing.
	Creates a 1 to 1 substitution mapping of the English alphabet in Z-26 starting from A and accepting input from the user. 
	Returns a map of characters keyed by characters. 

setOtherKey():
	Accepts a map of characters keyed with characters. 
	Inverts the keys and values found in the map created by either the "setKey()" or "setKeyFromFile()" methods. 
	Returns a map of characters keyed with characters. 

setKeyFromFile():
	Accepts a map of characters keyed with characters. 
	Creates a 1 to 1 substitution mapping of the English alphabet in Z-26 starting from A and accepting input from a user specified text file.
	Returns a map of characters keyed with characters. 

cipherSubstitution():
	Accepts a 2-dimensional character vector "text".
	Provides a menu to accept input for a key value "encryptKey" or "decryptKey" found in GLOBAL_VARIABLES.h 
		(then automatically sets the others value), and options to encrypt/decrypt using the substitution cipher method.
	Encrypting/Decrypting will show the result on screen.
	Returns nothing.
*/

vector<vector<char> > encryptSUBSTITUTION(vector<vector<char> > input) // returns encrypted 2-D char vector
{
	// encryption block. 
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i][j]))
			{
				input[i][j] = encryptKey[input[i][j]]; // performs substituion encryption
			}
		}
	}
	return input;
}

vector<vector<char> > decryptSUBSTITUTION(vector<vector<char> > input) // returns decrypted 2-D char vector
{
	// encryption block. 
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i][j]))
			{
				input[i][j] = decryptKey[input[i][j]]; // performs substituion encryption
			}
		}
	}
	return input;
}

map<char, char> setKey()
{
	char entry;
	map<char, char> key;
	bool duplicate;
	for (int i = 65; i < 91; )
		// ASCII for 'A' is 65, 'Z' is 90.
	{
		duplicate = false;
		cout << (char)i << " should be substituted with: ";
		cin >> entry;
		if (islower(entry))
		{
			entry = toupper(entry);
		}
		if (key.empty()) // empty case. 
		{
			key.insert(pair<char, char> ((char)i, entry));
			i++; // increment of "for loop" variable. 
		}
		else
		{
			for (map<char, char>::iterator it = key.begin(); it != key.end() && !duplicate; it++) // checking for duplicates. 
			{
				if (it->second == entry)
				{
					duplicate = true;
					cout << endl << entry << " already substitutes for " << it->first << "\n\n";
				}
			}
			if (!duplicate)
			{
				key.insert(pair<char, char> ((char)i, entry));
				i++; // increment of "for loop" variable. 
			}
		}
	}
	return key;
}

map<char, char> setOtherKey(map<char, char> input)
{
	map<char, char> key;
	for (map<char, char>::iterator it = input.begin(); it != input.end(); it++) // inverts keys and values. 
	{
		key.insert(pair<char, char>(it->second, it->first));
	}
	return key;
}

map<char, char> setKeyFromFile()
{
	char entry;
	map<char, char> key;
	ifstream fin;
	string inputS;
	cout << "\nFile to retrieve: ";
	cin >> inputS;
	fin.open(inputS + ".txt");
	if (fin.is_open())
	{
		for (int i = 65; i < 91; )
			// ASCII for 'A' is 65, 'Z' is 90.
		{
			fin >> entry;
			if (islower(entry))
			{
				entry = toupper(entry);
			}
			cout << (char)i << " -> " << entry << endl;
			if (key.empty()) // empty case. 
			{
				key.insert(pair<char, char>((char)i, entry));
				i++; // increment of for loop variable. 
			}
			else
			{
				key.insert(pair<char, char>((char)i, entry));
				i++; // increment of for loop variable. 
			}
		}
	}
	return key;
}

void cipherSubstitution(vector<vector<char> > text)
{
	keyset = false;
	cipher = text;
	answer = text; // in case the original text needs decrypted. 
	choice = -1;
	while (choice != 0)
	{
		cout << "***Substitution Cipher Menu***\n"
			<< "1.) Set keys.\n"
			<< "2.) Encrypt string: " << (keyset ? "key is set" : "set key first") << "\n"
			<< "3.) Decrypt string: " << (keyset ? "key is set" : "set key first") << "\n"
			<< "0.) Return to previous menu.\n\n"
			<< "Selection: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			keyset = false;
			cout << "Which key is provided?\n"
				<< "1.) Encryption key.\n"
				<< "2.) Decryption key.\n"
				<< "Selection: ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "\nKey is provided from:\n"
					<< "1.) Keyboard.\n"
					<< "2.) File.\n"
					<< "Selection: ";
				cin >> choice;
				if (choice == 1)
				{
					encryptKey = setKey();
					decryptKey = setOtherKey(encryptKey);
					keyset = true;
				}
				else if (choice == 2)
				{
					encryptKey = setKeyFromFile();
					decryptKey = setOtherKey(encryptKey);
					keyset = true;
				}
				else cout << "Invalid input...\n";
			}
			else if (choice == 2)
			{
				cout << "\nKey is provided from:\n"
					<< "1.) Keyboard.\n"
					<< "2.) File.\n"
					<< "Selection: ";
				cin >> choice;
				if (choice == 1)
				{
					decryptKey = setKey();
					encryptKey = setOtherKey(decryptKey);
					keyset = true;
				}
				else if (choice == 2)
				{
					decryptKey = setKeyFromFile();
					encryptKey = setOtherKey(decryptKey);
					keyset = true;
				}
				else cout << "Invalid input...\n";
			}
			else cout << "Invalid input...\n";
			break;
		case 2:
			if (keyset)
			{
				cout << "\nEncrypted string:\n";
				cipher = encryptSUBSTITUTION(text);
				displayToScreen(cipher);
			}
			else
			{
				cout << "Set key first.\n";
			}
			break;
		case 3:
			if (keyset)
			{
				cout << "\nDecrypted string:\n";
				answer = decryptSUBSTITUTION(cipher);
				displayToScreen(answer);
			}
			else
			{
				cout << "Set key first.\n";
			}
			break;
		case 0:
			cout << "Returning to previous menu...";
			break;
		default:
			cout << "Invalid input...\n";
			break;
		}
		puts("");
	}
}