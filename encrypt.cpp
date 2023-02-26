#include<iostream>
#include"operation.h"

using namespace std;

string encrypt(string inputText, string key)
{
    int blocks = key.length();
    // 2. store operations on each block
    operationDetails operations[blocks];
    for (int i = 0; i < blocks; i++)
    {
        unsigned char block = key[i];
        
        // 2.1. get the last two bits
        unsigned char operationBlock = block & 0b00000011;

        // 2.2. get the first 6 bits
        unsigned char valueBlock = block & 0b11111100;

        // 2.3. get operation and value
        int value = int(valueBlock);
        operation op = getOperation(operationBlock);

        // 2.4. store operation and value
        operations[i] = { op, value };
    }

    // 3. perform operations on text input
    string encryptedText = inputText;
    for (int i = 0; i < blocks; i++)
    {
        cout << operations[i].op << " " << operations[i].value << endl;
        for(int j = 1; j < encryptedText.length(); j++)
        {
            operationEncryptController(operations[i], encryptedText, j);
        }
    }
    
    return encryptedText;
}

string decrypt(string inputText, string key)
{
   int blocks = key.length();
    // 2. store operations on each block
    operationDetails operations[blocks];
    for (int i = 0; i < blocks; i++)
    {
        unsigned char block = key[i];
        
        // 2.1. get the last two bits
        unsigned char operationBlock = block & 0b00000011;
        
        // 2.2. get the first 6 bits
        unsigned char valueBlock = block & 0b11111100;
        
        // 2.3. get operation and value
        int value = int(valueBlock);
        operation op = getOperation(operationBlock);
        
        // 2.4. store operation and value
        operations[i] = { op, value };
    }

    // 3. perform operations on reverse order
    string decryptedText = inputText;
    for (int i = blocks - 1; i >= 0; i--)
    {   
        cout << operations[i].op << " " << operations[i].value << endl;
        for(int j = decryptedText.length()-1; j > 0 ; j--)
        {
            operationDecryptController(operations[i], decryptedText, j);
        }
    }

    return decryptedText;
}
    