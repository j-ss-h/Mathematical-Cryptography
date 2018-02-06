/*
File Name: HILL_CIPHER.h
Programming: Jesse A. Hankins
	Southeast Missouri State University
	Course: MA464-01
	Semester: Sprint 2018
	Date Last Modified: 2/2/2018

Description:
	This file contains the interface and methods to perform the hill cipher.

multiplyMatrices():
	Accepts a 2-dimensional character vector "input", and a 2-dimensional integer vector "key".
	Uses matrix multiplication method to find the solution of "key * input" in Z-26, while evaluating the characters as the 
		integer values returned when passing each character through the MOD26int map found in GLOBAL_VARIABLES.h.
	Returns the product 2-dimensional character vector.

transposeMatrix():
	Accepts a 2-dimensional character vector "input".
	Uses a temporary 2-dimensional character vector to store the values from "input" where the row and column locations of the 
		values have been swapped. 
	Returns the new 2-dimensional character vector.

determinantOfMatrix():
	Accepts a 2-dimensional character vector "input".
	Uses the Linear Algebra method for finding the determinant of a matrix, with special cases for 1x1, 2x2, and larger.
	Returns the integer determinant of "input" matrix, in Z-26.

invertMatrix(): 
	Accepts a 2-dimensional character vector "input", and integer "factor".
	The factor is the inverse of the determinant of "input" in Z-26. Then it uses Linear Algebra methods to create the inverse of "input". 
	Returns the inverse of "input" matrix, in Z-26.

formatFromHill():
	Accepts a 2-dimensional character vector "input".
	Places the characters in a 2-dimensional character vector in groups of 5 characters, which are seperated by a space entry, 
		and limits each row to a maximum of 10 groups. 
	Returns a formatted 2-dimensional character vector.

formatToHill():
	Accepts a 2-dimensional character vector "input", and integer "keyColSize". 
	This reformats the text so that every index has a character value (no spaces) and uses "keyColSize" to align the dimension 
		so that the resulting matrix can be multiplied against the key matrix. 
	Returns a formatted 2-dimensional character vector.

encryptHILL():
	Accepts a 2-dimensional character vector "input", and a 2-dimensional integer vector "key".
	Calls the "multiplyMatrices()" function to perform encryption. 
	Returns an encrypted 2-dimensional character vector.

decryptHILL():
	Accepts a 2-dimensional character vector "input", and a 2-dimensional integer vector "key".
	Calls the "multiplyMatrices()" function to perform decryption.
	Returns an encrypted 2-dimensional character vector.

cipherHill():
	Accepts a 2-dimensional character vector "text".
	Provides a menu to accept input for a key integer matrix "key", automatically assigns the inverse matrix of that key, 
		and options to encrypt/decrypt using the hill cipher method.
	Encrypting/Decrypting will show the result on screen.
	Returns nothing.
*/

vector<vector<char> > multiplyMatrices(vector<vector<char> > A, vector<vector<int> > B)
{
	vector<vector<char> > answerM = A;
	for (int i = 0; i < B.size(); i++)
		//places solution in tempM
	{
		for (int j = 0; j < A[0].size(); j++)
		{
			int tempI = 0;
			for (int x = 0; x < B[i].size(); x++)
			{
				tempI = tempI + (B[i][x] * MOD26int[A[x][j]]);
			}
			answerM[i][j] = MOD26char[(tempI % 26)];
		}
	}
	return answerM;
}

vector<vector<char> > transposeMatrix(vector<vector<char> > matrix)
// this is used to convert the plaintext into the appropriate nXm matrix. 
{
	vector<vector<char> > tempM;
	for (int i = 0; i < matrix[0].size(); i++)
	{
		vector<char> tempL;
		for (int j = 0; j < matrix.size(); j++)
		{
			tempL.push_back(matrix[j][i]);
		}
		tempM.push_back(tempL);
	}
	return tempM;
}

int determinantOfMatrix(vector<vector<int> > matrix)
// this is used to determine the determinant of the key matrix in Z-26. 
{
	int add = 0, mulP = 1, sub = 0, mulN = 1, det;
	// sums all diagonals starting from main diagonal. 
	if (matrix.size() > 2)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0, n = i; j < matrix.size(); j++, n++)
			{
				mulP *= matrix[j][n % matrix[j].size()];
			}
			add += mulP;
			mulP = 1;
		}
		// sums all diagonals starting from other diagonal. 
		for (int i = (matrix.size() - 1); i >= 0; i--)
		{
			for (int j = (matrix.size() - 1), n = (matrix.size() - (i + 1)); j >= 0; j--, n++)
			{
				mulN *= matrix[j][n % matrix[j].size()];
			}
			sub += mulN;
			mulN = 1;
		}
	}
	else if (matrix.size() == 2) // if 2 by 2
	{
		add = matrix[0][0] * matrix[1][1];
		sub = matrix[0][1] * matrix[1][0];
	}
	else // if only 1 value. 
	{
		add = matrix[0][0];
		sub = 0;
	}
	det = add - sub;
	while (det < 0)
	{
		det += 26; // to account for negative values. 
	}
	return (det % 26);
}

vector<vector<int> > invertMatrix(vector<vector<int> > matrix, int factor)
// this is used to invert a matrix
{
	int temp;
	bool added = false;
	vector<vector<int> > answerMatrix;
	for (int i = 0; i < matrix.size(); i++)
	{
		vector<int> answerList;
		for (int j = 0; j < matrix[i].size(); j++)
		{
			vector<vector<int> > subMatrix;
			for (int x = 0; x < matrix.size(); x++)
			{
				vector<int> subList;
				for (int y = 0; y < matrix[x].size(); y++)
				{
					temp = matrix[x][y];
					if ((x != j) && (y != i)) // ignores subsequent columns and rows. 
					{
						subList.push_back(temp);
						added = true;
					}
				}
				if (added) // ignores subsequent columns and rows. 
				{
					subMatrix.push_back(subList);
					added = false;
				}
			}
			temp = pow(-1, (i + j)) * factor * determinantOfMatrix(subMatrix);
			while (temp < 0)
			{
				temp += 26; // to account for negative values. 
			}
			answerList.push_back(temp % 26);
		}
		answerMatrix.push_back(answerList);
	}
	return answerMatrix;
}

vector<vector<char> > formatFromHill(vector<vector<char> > input)
{
	vector<char> tempL;
	//vector<vector<char> > tempM = transposeMatrix(input);
	input = transposeMatrix(input);
	vector<char> answerL;
	vector<vector<char> > answerM;
	for (int i = 0; i < input.size(); i++)
		// this places all characters from tempM into tempL. 
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			tempL.push_back(input[i][j]);
		}
	}

	for (int i = 0; i < tempL.size(); i++)
		// this formats everything from tempL into answerL, then pushes answerL back into answerM.
	{
		if ((i % 50 == 0) && (i != 0))
		{
			answerM.push_back(answerL);
			answerL.clear();
			answerL.push_back(tempL[i]);
		}
		else if ((i % 5 == 0) && (i != 0))
		{
			answerL.push_back(' ');
			answerL.push_back(tempL[i]);
		}
		else
		{
			answerL.push_back(tempL[i]);
		}
	}
	answerM.push_back(answerL); // pushes last line of answerL into answerM. 
	return answerM;
}

vector<vector<char> > formatToHill(vector<vector<char> > input, int keyColSize)
{
	int rowSize = 0, index = 0;
	vector<char> tempL;
	vector<vector<char> > answerM;
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i][j]))
			{
				tempL.push_back(input[i][j]);
				rowSize++;
			}
		}
	}
	// calculates the number of rows needed for matrix multiplication. 
	rowSize = ceil((double)rowSize / (double)keyColSize); 

	for (int i = 0; i < rowSize; i++)
	{
		vector<char> answerL;
		for (int j = 0; j < keyColSize; j++)
		{
			if (index < tempL.size())
			{
				answerL.push_back(tempL[index]);
				index++;
			}
			else answerL.push_back('Q');
		}
		answerM.push_back(answerL);
	}
	return transposeMatrix(answerM);
}

vector<vector<char> > encryptHILL(vector<vector<char> > input, vector<vector<int> > key)
{
	return multiplyMatrices(input, key); // performs Hill cipher encryption. 
}

vector<vector<char> > decryptHILL(vector<vector<char> > input, vector<vector<int> > key)
{
	return multiplyMatrices(input, key); // performs Hill cipher decryption. 
}

void cipherHill(vector<vector<char> > text) // interface for Hill cipher
{
	keyset = false;
	int detInverse;
	vector<vector<int> > keyMatrix;
	vector<vector<int> > keyInverseMatrix;
	// assignment in last line of "set key".
	choice = -1;
	while (choice != 0)
	{
		cout << "***Hill Cipher Menu***\n"
			<< "1.) Set key.\n"
			<< "2.) Encrypt string: " << (keyset ? "key is set " : "set key first") << "\n"
			<< "3.) Decrypt string: " << (keyset ? "key is set ('Q' used as trailing filler)" : "set key first") << "\n"
			<< "0.) Return to previous menu.\n\n"
			<< "Selection: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\nWhich key is provided?\n"
				<< "1.) Encryption key.\n"
				<< "2.) Decryption key.\n"
				<< "Selection: ";
			cin >> choice;
			cout << "\nHow many rows in the key matrix: ";
			cin >> row;
			cout << "How many columns in the key matrix: ";
			cin >> col;
			keyset = false;
			if (choice == 1 || choice == 2)
			{
				for (int i = 0; i < row; i++)
				{
					vector<int> keyTemp;
					for (int j = 0; j < col; j++)
					{
						cout << "Enter value for key[" << i << "][" << j << "]: ";
						cin >> detInverse;
						keyTemp.push_back(detInverse);
					}
					(choice == 1) ? keyMatrix.push_back(keyTemp) : keyInverseMatrix.push_back(keyTemp);
				}

				// This block verifies that the key is invertible. 
				if (choice == 1)
				{
					detInverse = determinantOfMatrix(keyMatrix);
				}
				else detInverse = determinantOfMatrix(keyInverseMatrix);

				if (MULinverse.find(detInverse) != MULinverse.end())
				{
					detInverse = MULinverse[detInverse];
					if (choice == 1)
					{
						keyInverseMatrix = invertMatrix(keyMatrix, detInverse);
					}
					else keyMatrix = invertMatrix(keyInverseMatrix, detInverse);
					cipher = formatToHill(text, col); 
					answer = formatToHill(text, col); // in case the original text needs decrypted. 
					keyset = true;
				}
				else cout << "Key matrix is not invertible...\n";
			}else cout << "Invalid input...\n";
			break;
		case 2:
			cout << "\nEncrypted string:\n";
			cipher = encryptHILL(formatToHill(text, col), keyMatrix);
			displayToScreen(formatFromHill(cipher));
			break;
		case 3:
			cout << "\nDecrypted string:\n";
			answer = decryptHILL(cipher, keyInverseMatrix);
			displayToScreen(formatFromHill(answer));
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