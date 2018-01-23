/* 
	This stores multiple global items for the ciphers:
	1.) maps with the values needed for modulus 26.
	2.) map with the multiplicative inverse of each int in modulus 26.
	3.) global variables used by each cipher menu and function. 
*/
#include <map>

// int and char refer to the return value type. 
std::map<char, int> MOD26int = { { 'A', 0 },{ 'B', 1 },{ 'C', 2 },{ 'D', 3 },{ 'E', 4 },{ 'F', 5 },
{ 'G', 6 },{ 'H', 7 },{ 'I', 8 },{ 'J', 9 },{ 'K', 10 },{ 'L', 11 },{ 'M', 12 },{ 'N', 13 },{ 'O', 14 },
{ 'P', 15 },{ 'Q', 16 },{ 'R', 17 },{ 'S', 18 },{ 'T', 19 },{ 'U', 20 },{ 'V', 21 },{ 'W', 22 },{ 'X', 23 },
{ 'Y', 24 },{ 'Z', 25 }, };

std::map<int, char> MOD26char = { { 0, 'A' },{ 1, 'B' },{ 2, 'C' },{ 3, 'D' },{ 4, 'E' },{ 5, 'F' },
{ 6, 'G' },{ 7, 'H' },{ 8, 'I' },{ 9, 'J' },{ 10, 'K' },{ 11, 'L' },{ 12, 'M' },{ 13, 'N' },{ 14, 'O' },
{ 15, 'P' },{ 16, 'Q' },{ 17, 'R' },{ 18, 'S' },{ 19, 'T' },{ 20, 'U' },{ 21, 'V' },{ 22, 'W' },{ 23, 'X' },
{ 24, 'Y' },{ 25, 'Z' }, };

// this returns the multiplicative inverse of the input int, for modulus 26. 
std::map<int, int> MULinverse = { { 1, 1 },{ 3, 9 },{ 5, 21 },{ 7, 15 },{ 9, 3 },{ 11, 19 },
{ 15, 7 },{ 17, 23 },{ 19, 11 },{ 21, 5 },{ 23, 17 },{ 25, 25 }, };

// global items used throughout these ciphers
std::vector<vector<char> > cipher, answer;
std::map<char, char> encryptKey, decryptKey;
bool keyset, done;
int choice = -1, factor = 1, shift = 1;
std::ofstream fout;