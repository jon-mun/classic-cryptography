#include <iostream>
#include <string>
using namespace std;

string asciiToBinary(string key)
{
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
    return binaryKey;
}

void splitKeys(string *key_blocks, string binaryKey, int blocks)
{
    for (int i = 0; i < blocks; i++)
    {
        key_blocks[i] = binaryKey.substr(i * 8, 8);
    }
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
