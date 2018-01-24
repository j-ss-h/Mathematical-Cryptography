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

vector<vector<char> > decryptSUBSTITUTION(vector<vector<char> > input) // returns encrypted 2-D char vector
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

map<char, char> setOtherKey(map<char, char> input)
{
	map<char, char> key;
	for (map<char, char>::iterator it = input.begin(); it != input.end(); it++) // inverts keys and values. 
	{
		key.insert(pair<char, char> (it->second, it->first));
	}
	return key;
}

map<char, char> setKey()
{
	// ASCII for 'A' is 65, 'Z' is 90.
	char entry;
	map<char, char> key;
	bool duplicate;
	for (int i = 65; i < 91; )
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
			i++; // increment of for loop variable. 
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
				i++; // increment of for loop variable. 
			}
		}
	}
	return key;
}

map<char, char> setKeyFromFile()
{
	// ASCII for 'A' is 65, 'Z' is 90.
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
			<< "4.) Decrypt string: key unknown (currently unavailable)\n"
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
		case 4:
			cout << "This function is not currently available.\n";
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