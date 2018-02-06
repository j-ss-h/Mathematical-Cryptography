/*
Program Name: Mathematical Cryptography
Programming: Jesse A. Hankins
	Southeast Missouri State University
	Course: MA464-01
	Semester: Sprint 2018
	Date Last Modified: 2/2/2018

Description:
	This program is intended to contain all encryption/decryption methods studied in SEMO course MA464.

	1. Modulus: these methods use the English alphabet represented by Z-26.

	2. Input: taken from the "input.txt" file.

	3. Ouput: displayed to screen unless the method has the option of decrypting with an unknown key. 
		By default this will be sent to the file "ouput.txt".

	4. Keys: Most methods permit the assignment of a key from the keyboard, but some have the option of 
		setting the key from another text file which you can specify (omitting the file extension).

	***NOTE: If the input text file needs to be decrypted, DO NOT encrypt it before attempting to do so. 
*/
#include "INTERFACE.h"
void main(void)
{
	cipherInterface();
}