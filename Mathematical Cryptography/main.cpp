/*
Program Name: Mathematical Cryptography
Programming: Jesse A. Hankins
	Southeast Missouri State University
	Course: MA464-01
	Semester: Sprint 2018
	Date Last Modified: 1/31/2018
Description:
	This program is intended to contain all encryption/decryption methods studied in class. 

	1.) Modulus: the methods use the English alphabet represented by Z-26. 

	2.) Input: input is only taken from the "input.txt" file. 

	3.) Ouput: output is only displayed to screen unless the method has the option of decrypting with an unknown key. By default
		this will be sent to the file "ouput.txt". 

	4.) Keys: Most methods permit the assignment of a key from the keyboard, but some have the option of setting the key
		from another text file which you can specify the name of (omitting ".txt"). 

	***NOTE: If the input text file needs to be decrypted, DO NOT encrypt it before attempting to do so. 
*/
#include "INTERFACE.h"
void main(void)
{
	cipherInterface();
}