#include<iostream>
#include"operation.h"
#include"utils.h"

using namespace std;

string encrypt(string inputText, string key)
{
    // 0. convert key to 8 bit binary string
    string binaryKey = asciiToBinary(key);
    cout << binaryKey << endl;

    // 1. split key into 8 bit blocks
    int blocks = binaryKey.length() / 8;
    string key_blocks[blocks];
    splitKeys(key_blocks, binaryKey, blocks);

    // 2. store operations on each block
    operationDetails operations[blocks];
    for (int i = 0; i < blocks; i++)
    {
        // 2.1. get the first two bits
        string operationBlock = key_blocks[i].substr(0, 2);
        // 2.2. get the last 6 bits
        string block = key_blocks[i].substr(2, 6);
        // 2.3. convert the last 6 bits to decimal
        int value = binaryToDecimal(block);
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
    cout << encryptedText << endl;

    return encryptedText;
}

string decrypt(string inputText, string key)
{
    // 0. convert key to 8 bit binary string
    string binaryKey = asciiToBinary(key);
    cout << binaryKey << endl;

    // 1. split key into 8 bit blocks
    int blocks = binaryKey.length() / 8;
    string key_blocks[blocks];
    splitKeys(key_blocks, binaryKey, blocks);

    // 2. store operations on each block
    operationDetails operations[blocks];
    for (int i = 0; i < blocks; i++)
    {
        // 2.1. get the first two bits
        string operationBlock = key_blocks[i].substr(0, 2);
        // 2.2. get the last 6 bits
        string block = key_blocks[i].substr(2, 6);
        // 2.3. convert the last 6 bits to decimal
        int value = binaryToDecimal(block);
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
    