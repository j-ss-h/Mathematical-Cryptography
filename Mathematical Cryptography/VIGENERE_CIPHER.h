/*
File Name: VIGENERE_CIPHER.h
Programming: Jesse A. Hankins
	Southeast Missouri State University
	Course: MA464-01
	Semester: Sprint 2018
	Date Last Modified: 2/2/2018

Description:
	This file contains the interfaces and methods to perform vigenere and auto-key ciphers.

encryptVIGENERE():
	Accepts a 2-dimensional character vector "input", and a string "keyWord".
	Converts each value from "input" and "keyWord" to a Z-26 integer, adds the pairs of values then converts that value 
		back to a Z-26 character. If "input" is longer than "keyWord" then "keyWord" will cycle through its values until 
		the end of "input" is reached.
	Returns an encrypted 2-dimensional character vector.

decryptVIGENERE():
	Accepts a 2-dimensional character vector "input", and a string "keyWord".
	Converts each value from "input" and "keyWord" to a Z-26 integer, subtracts "keyWord" values from "input" values in 
		pairs then converts that value back to a Z-26 character. If "input" is longer than "keyWord" then "keyWord" will 
		cycle through its values until the end of "input" is reached.
	Returns a decrypted 2-dimensional character vector.

cipherVigenere():
	Accepts a 2-dimensional character vector "text".
	Provides a menu to accept input for a key value "keyWord", and options to encrypt/decrypt using the vigenere cipher method.
	Encrypting/Decrypting will show the result on screen. 
	Returns nothing.

cipherAutokey():
	Accepts a 2-dimensional character vector "text".
	Provides a menu to accept input for a key value "keyWord", and options to encrypt/decrypt using the vigenere cipher method.
	"keyWord" is backfilled starting from the front of "text" until it has the same character length as "text".
	Encrypting/Decrypting will show the result on screen. 
	Returns nothing.
*/

vector<vector<char> > encryptVIGENERE(vector<vector<char> > input, string keyWord) 
// returns encrypted 2-D char vector
{
	// encryption block. 
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i][j]))
			{
				input[i][j] = MOD26char[(MOD26int[input[i][j]] + MOD26int[keyWord[j % keyWord.size()]]) % 26]; 
				// performs vigenere/autokey encryption
			}
		}
	}
	return input;
}

vector<vector<char> > decryptVIGENERE(vector<vector<char> > input, string keyWord) 
// returns decrypted 2-D char vector
{
	// decryption block. 
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i][j]))
			{
				input[i][j] = MOD26char[(MOD26int[input[i][j]] + 26 - MOD26int[keyWord[j % keyWord.size()]]) % 26]; 
				// performs vigenere/autokey decryption. added 26 to account for negative values. 
			}
		}
	}
	return input;
}

void cipherVigenere(vector<vector<char> > text) // interface for Vigenere cipher
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

void cipherAutokey(vector<vector<char> > text) // interface for Auto-key cipher
{
	keyset = false;
	string keyWord;
	cipher = text;
	answer = text; // in case the original text needs decrypted. 
	choice = -1;
	while (choice != 0)
	{
		cout << "***Auto-key Cipher Menu***\n"
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
			for (int i = 0; keyWord.size() < counter; i++)
			{
				for (int j = 0; ((j < text[i].size()) && (keyWord.size() < counter)); j++)
				{
					if (isalpha(text[i][j]))
					{
						keyWord.push_back(text[i][j]);
					}
				}
			}
			cout << "Key is appended using subsequent values from plaintext until it's length is equal to the length of the plaintext.\n";
			keyset = true;
			break;
		case 2:
			cout << "\nEncrypted string:\n";
			cipher = encryptVIGENERE(text, keyWord);
			// uses Vigenere methods because plaintext length equals key length. 
			displayToScreen(cipher);
			break;
		case 3:
			cout << "\nDecrypted string:\n";
			answer = decryptVIGENERE(cipher, keyWord);
			// uses Vigenere methods because plaintext length equals key length. 
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