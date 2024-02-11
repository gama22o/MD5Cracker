/*
Applied Cryptography Project
CIS4362.01

Group 3
Justine Saylor
Veronica Spitnale
Georgette Amancha
*/


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "md5.h"

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::string;

void hashFile() {
string pass;
string hashPass;

//read the cracking dictionary
ifstream inputFile;
inputFile.open("realhuman_phill.txt");
ofstream outputFile;
outputFile.open("hashedPasswords.txt");

//reads the input file
while(!inputFile.eof()) {
    inputFile >> pass;
    //hash the password
    hashPass = md5(pass);
    //writes the hashed password and original plaintext to the output file
    outputFile << hashPass << pass << "\n";
}

inputFile.close();
outputFile.close();


}




int main() {
string inputHash;
string line;
string plaintext, hashtext;
int flag;

//hashes the passwords from the input to the output file
hashFile();


//get user input hash
cout << "Enter the MD5 hash: ";
cin >> inputHash;
cout << "Please wait...";


//opens the hashed file as an input file
ifstream input;
input.open("hashedPasswords.txt");


while(!input.eof()) {
    input >> line;

    //separates the input line into the hash and plaintext parts
    hashtext = line.substr(0,32);
    plaintext = line.substr(33);

    //compares the hashtext to the input hash
    int comparison = inputHash.compare(hashtext);
    //if they are the same, the plaintext is printed
    if(comparison == 0) {
        flag=1;
        cout << "\nThe plaintext is: " << plaintext;
        break;
    }

}

//prints a message if the input hash was not matched with the file's hashes
if(flag == 0) {
    cout << "\nThe plaintext was not found." << endl;
}


input.close();

return 0;
}

