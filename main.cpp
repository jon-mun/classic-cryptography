// create cpp boiler plate

#include<iostream>
using namespace std;
enum operation
    {
        SWAP,
        ADD,
        MULTIPLY
    };
int binaryToDecimal(string n);
operation getOperation(string operationBlock);
void operationController(operation op, string& inputText, int value);

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


    key = "1000000100000010";
    inputText = "HelloWorld!";

    // 1. split key into 8 bit blocks
    int blocks = key.length() / 8;
    string key_blocks[blocks];

    for (int i = 0; i < blocks; i++)
    {
        key_blocks[i] = key.substr(i * 8, 8);
    }

    string encryptedText = inputText;
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

        // 2.4. perform operation on input text
       operationController(op, encryptedText, value);
       cout << encryptedText << " " << encryptedText.length() << endl;
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

// function to swap characters
string swapChar(string inputText, int startIndex, int value)
{
    int endIndex = startIndex + value % inputText.length();

    string outputText = inputText;
    outputText[startIndex] = inputText[endIndex];
    outputText[endIndex] = inputText[startIndex];

    return outputText;
}

void operationController(operation op, string& inputText, int value)
{
    switch (op)
    {
    case SWAP:
        for (int i = 1; i < inputText.length(); i++)
        {
            inputText = swapChar(inputText, i, value);
            cout << inputText << endl;
        }
        break;
    case ADD:
        for (int i = 1; i < inputText.length(); i++)
        {
            inputText[i] = (inputText[i] + value) % 256;
            cout << inputText << endl;
        }
        break;
    case MULTIPLY:
        for (int i = 1; i < inputText.length(); i++)
        {
            inputText[i] = (inputText[i] * value) % 256;
            cout << inputText << endl;
        }
        break;
    default:
        break;
    }
}