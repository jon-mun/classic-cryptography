#include<iostream>
#include"operation.h"
#include"encrypt.h"
using namespace std;

int main()
{
    string key, inputText;
    cout << "Classic Cryptography" << endl;
    cout << "Insert key (string)" << endl;
    cin >> key;

    cout << "Insert a text to encrypt" << endl;
    cin >> inputText;

    string encryptedText = encrypt(inputText, key);
    cout << "Encrypted Text: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, key);
    cout << "Decrypted Text: " << decryptedText << endl;
    
    return 0;
}

// g++ operation.cpp encrypt.cpp main.cpp -o main.out && ./main.out