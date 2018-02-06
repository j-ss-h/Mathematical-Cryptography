# Mathematical Cryptography
###### This program is intended to contain all encryption/decryption methods studied in SEMO course MA464. 
___
1. **Modulus:** these methods use the English alphabet represented by Z-26. 
2. **Input:** taken from the "input.txt" file. 
3. **Ouput:** displayed to screen unless the method has the option of decrypting with an unknown key. By default this will be sent to the file "ouput.txt". 
4. **Keys:** Most methods permit the assignment of a key from the keyboard, but some have the option of setting the key from another text file which you can specify (omitting the file extension). 
>NOTE: If input needs to be decrypted, **DO** **NOT** encrypt it before attempting to do so. 
___
| Cipher method  | Encryption    | Decryption (*key known*) | Decryption (*key unknown*) |
| -------------- | :-----------: | :-------------------: | :---------------------: |
| Shift          | complete      | complete              | complete                |
| Multiplicative | complete      | complete              | complete                |
| Affine         | complete      | complete              | complete                |
| Substitution   | complete      | complete              | not coded               |
| Vigenere       | complete      | complete              | not coded               |
| Auto-Key       | complete      | complete              | not coded               |
| Hill           | complete      | complete              | not coded               |
