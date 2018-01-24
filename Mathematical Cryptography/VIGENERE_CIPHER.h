vector<vector<char> > encryptVIGENERE(vector<vector<char> > input, string keyWord) // returns encrypted 2-D char vector
{
	// encryption block. 
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i][j]))
			{
				input[i][j] = MOD26char[(MOD26int[input[i][j]] + MOD26int[keyWord[j % keyWord.size()]]) % 26]; // performs vigenere encryption
			}
		}
	}
	return input;
}

vector<vector<char> > decryptVIGENERE(vector<vector<char> > input, string keyWord) // returns decrypted 2-D char vector
{
	// decryption block. 
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i][j]))
			{
				input[i][j] = MOD26char[(MOD26int[input[i][j]] + 26 - MOD26int[keyWord[j % keyWord.size()]]) % 26]; // performs vigenere decryption. 
																					  // added 26 to account for negative values. 
			}
		}
	}
	return input;
}

void cipherVigenere(vector<vector<char> > text)
{
	keyset = false;
	string keyWord;
	cipher = text;
	answer = text; // in case the original text needs decrypted. 
	choice = -1;
	while (choice != 0)
	{
		cout << "***Vigenere Cipher Menu***\n"
			<< "1.) Set key word.\n"
			<< "2.) Encrypt string: " << (keyset ? "key word is " : "set key first") << keyWord << "\n"
			<< "3.) Decrypt string: " << (keyset ? "key word is " : "set key first") << keyWord << "\n"
			<< "4.) Decrypt string: key unknown (currently unavailable)\n"
			<< "0.) Return to previous menu.\n\n"
			<< "Selection: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nEnter key word (alphabetic only): ";
			cin >> keyWord;
			for (int i = 0; i < keyWord.size(); i++)
			{
				if (islower(keyWord[i]))
				{
					keyWord[i] = toupper(keyWord[i]);
				}
			}
			keyset = true;
			break;
		case 2:
			cout << "\nEncrypted string:\n";
			cipher = encryptVIGENERE(text, keyWord);
			displayToScreen(cipher);
			break;
		case 3:
			cout << "\nDecrypted string:\n";
			answer = decryptVIGENERE(cipher, keyWord);
			displayToScreen(answer);
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