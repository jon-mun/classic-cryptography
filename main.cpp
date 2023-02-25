#include<iostream>
using namespace std;

enum operation
    {
        SWAP,
        ADD,
        MULTIPLY
    };

struct operationDetails {
    operation op;
    int value;
};
void operationController(operationDetails details, string& inputText, int index);
void operationDecryptController(operationDetails details, string& inputText, int index);
operation getOperation(string operationBlock);
int binaryToDecimal(string n);

int main()
{
    string key, inputText;
    cout << "Classic Cryptography" << endl;
    cout << "Insert a random binary string (mulitple of 8)" << endl;
    // cin >> key;
    // if (key.length() % 8 != 0)
    // {
    //     cout << "Key length must be a multiple of 8" << endl;
    //     return 0;
    // }

    // cout << "Insert a inputText to encrypt" << endl;
    // cin >> inputText;


    key = "}'/+-";
    // TODO never reaches 1*******
    inputText = "HelloWorld!";

    cout << key << endl;
    // 0. convert key to 8 bit binary string
    string binaryKey = "";
    for (int i = 0; i < key.length(); i++)
    {
        int ascii = key[i];
        string binary = "";
        while (ascii > 0)
        {
            binary = (ascii % 2 == 0 ? "0" : "1") + binary;
            ascii /= 2;
        }
        while (binary.length() < 8)
        {
            binary = "0" + binary;
        }
        binaryKey += binary;
    }
    cout << binaryKey << endl;

    // 1. split key into 8 bit blocks
    int blocks = binaryKey.length() / 8;
    string key_blocks[blocks];

    for (int i = 0; i < blocks; i++)
    {
        key_blocks[i] = binaryKey.substr(i * 8, 8);
    }

    operationDetails operations[blocks];
    // 2. perform operations on each block
    for (int i = 0; i < blocks; i++)
    {
        // 2.1. get the first two bits
        string operationBlock = key_blocks[i].substr(0, 2);
        // 2.2. get the last 6 bits
        string block = key_blocks[i].substr(2, 6);
        // 2.3. convert the last 6 bits to decimal
        int value = binaryToDecimal(block);
        operation op = getOperation(operationBlock);
        cout << op << endl;
        cout << value << endl;
        operations[i] = { op, value };
    }

    // 3. perform operations on inputText
    string encryptedText = inputText;
    for (int i = 0; i < blocks; i++)
    {
        cout << operations[i].op << " " << operations[i].value << endl;
        for(int j = 1; j < encryptedText.length(); j++)
        {
            operationController(operations[i], encryptedText, j);
        }
    }
    cout << encryptedText << endl;

    for (int i = 0; i < encryptedText.length(); i++)
    {
        cout << (int)encryptedText[i] << " ";
    }

    cout << endl;

    string decryptedText = encryptedText;
    for (int i = blocks - 1; i >= 0; i--)
    {   
        cout << operations[i].op << " " << operations[i].value << endl;
        for(int j = decryptedText.length()-1; j > 0 ; j--)
        {
            operationDecryptController(operations[i], decryptedText, j);
        }
    }

    return 0;
}

// function to convert binary to decimal
int binaryToDecimal(string n)
{
    string binary = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int len = binary.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
};


// function to swap characters
string swapChar(string inputText, int startIndex, int endIndex)
{
    string outputText = inputText;
    outputText[startIndex] = inputText[endIndex];
    outputText[endIndex] = inputText[startIndex];

    return outputText;
}

string swapForward(string inputText, int startIndex, int value) 
{
    int endIndex = (startIndex + value) % inputText.length();
    return swapChar(inputText, startIndex, endIndex);
}

// function to enumerate operations
operation getOperation(string operationBlock)
{
    /**
     * operations:
     * 0* -> swap
     * 10 -> add
     * 11 -> multiply
    */
    if (operationBlock == "00" || operationBlock == "01")
    {
        return SWAP;
    }
    else if (operationBlock == "10")
    {
        return ADD;
    }
    else // operationBlock == "11"
    {
        return MULTIPLY;
    }
}

void operationController(operationDetails details, string& inputText, int index)
{
    operation op = details.op;
    int value = details.value;
    switch (op)
    {
    case SWAP:
        inputText = swapForward(inputText, index, value);
        cout << inputText << " " << op << value << endl;
        break;
    case ADD:
        inputText[index] = (inputText[index] + value) % 256;
        cout << inputText << endl;
        break;
    case MULTIPLY:
        inputText[index] = (inputText[index] * value) % 256;
        cout << inputText << endl;
        break;
    default:
        break;
    }
}

void operationDecryptController(operationDetails details, string& inputText, int index)
{
    operation op = details.op;
    int value = details.value;
    switch (op)
    {
    case SWAP:
        inputText = swapForward(inputText, index, value);
        cout << inputText << " " << op << " " << value << endl;
        break;
    case ADD:
        inputText[index] = (inputText[index] - value) % 256;
        cout << inputText << endl;
        break;
    case MULTIPLY:
        inputText[index] = (inputText[index] / value) % 256;
        cout << inputText << endl;
        break;
    default:
        break;
    }
}

