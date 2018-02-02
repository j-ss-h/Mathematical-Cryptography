vector<vector<char> > encryptHILL(vector<vector<char> > input, vector<vector<int> > key)
{
	return input; // place holder. 
}

vector<vector<char> > decryptHILL(vector<vector<char> > input, vector<vector<int> > key)
{
	return input; // place holder. 
}

/*
void multiplyMatrices(vector<vector<char> > A, vector<vector<char> > B, bool & valid)
{
	if (A.col == B.row)
		//dimension validation
	{
		Matrix tempM;
		tempM.setSizeMatrix(A.row, B.col);
		tempM.fillMatrix();

		for (int x = 0; x < A.row; x++)
			//places solution in tempM
		{
			for (int y = 0; y < B.col; y++)
			{
				int tempI = 0;
				for (int z = 0; z < A.col; z++)
				{
					tempI = tempI + (A.matrix[x][z] * B.matrix[z][y]);
				}
				tempM.matrix[x][y] = tempI;
			}
		}
		matrix = tempM.matrix;
		setSizeMatrix(tempM.row, tempM.col);
		valid = true;
	}
	else
	{
		cout << "The deminsions of second Matrix's rows and the first Matrix's columns must match. " << endl;
	}
}
*/

vector<vector<int> > transposeMatrix(vector<vector<int> > matrix)
// this is used to convert the plaintext into the appropriate nXm matrix. 
{
	vector<vector<int> > tempM;
	for (int i = 0; i < matrix.size(); i++)
	{
		vector<int> tempV;
		for (int j = 0; j < matrix[i].size(); j++)
		{
			tempV.push_back(matrix[j][i]);
		}
		tempM.push_back(tempV);
	}
	return tempM;
}

int determinantOfMatrix(vector<vector<int> > matrix)
// this is used to determine the determinant of the key matrix in Z-26. 
{
	int add = 0, mulP = 1, sub = 0, mulN = 1, det;
	// sums all diagonals starting from main diagonal. 
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
					if ((x != i) && (y != j)) // ignores subsequent columns and rows. 
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

void cipherHill(vector<vector<char> > text) // interface for Hill cipher
{
	keyset = false;
	int detInverse;
	vector<vector<int> > keyMatrix;
	vector<vector<int> > keyInverseMatrix;
	cipher = text;
	answer = text; // in case the original text needs decrypted. 
	choice = -1;
	while (choice != 0)
	{
		cout << "***Hill Cipher Menu***\n"
			<< "1.) Set key.\n"
			<< "2.) Encrypt string: " << (keyset ? "key is set " : "set key first") << "\n"
			<< "3.) Decrypt string: " << (keyset ? "key is set " : "set key first") << "\n"
			<< "4.) Decrypt string: key unknown (currently unavailable)\n"
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

					keyset = true;

					// test block!!!!!!!!!!!!!!!!!!!!!!!!!
					puts("Key:");
					displayToScreen(keyMatrix);
					puts("Key inverted:");
					displayToScreen(keyInverseMatrix);
				}
				else cout << "Key matrix is not invertible...\n";
			}else cout << "Invalid input...\n";
			break;
		case 2:
			cout << "\nEncrypted string:\n";
			cipher = encryptHILL(text, keyMatrix);
			displayToScreen(cipher);
			break;
		case 3:
			cout << "\nDecrypted string:\n";
			answer = decryptHILL(cipher, keyInverseMatrix);
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
