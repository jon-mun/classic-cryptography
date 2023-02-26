#include "operation.h"
#include <iostream>
using namespace std;


string swapForward(string inputText, int startIndex, int value)
{
    int endIndex = (startIndex + value) % inputText.length();

    string outputText = inputText;
    outputText[startIndex] = inputText[endIndex];
    outputText[endIndex] = inputText[startIndex];

    return outputText;
}

unsigned polyMultiplication(unsigned char input1, unsigned char input2) 
{
    wchar_t result = 0b00000000;
    for (int i = 0; i < 8; i++) 
    {
        if (input2 & 0b0000001) 
        {
            result ^= input1;
        }
        bool carry = input1 & 0b10000000;
        input1 <<= 1;
        if (carry) 
        {
            input1 ^= 0b00011011;
        }
        input2 >>= 1;
    }
    return result;
}

unsigned char multiplicativeInverse(unsigned char input) {
    unsigned char result = input;
    for (int i = 0; i < 7; i++) {
        result = polyMultiplication(result, result);
        result ^= input;
    }
    return result;
}

/**
 * @@operations
*/
void operationEncryptController(operationDetails details, string& inputText, int index)
{
    operation op = details.op;
    int value = details.value;
    switch (op)
    {
    case SWAP:
        inputText = swapForward(inputText, index, value);
        cout << inputText << " " << "SWAP" << " " << value << endl;
        break;
    case ADD:
        inputText[index] = (inputText[index] + value) % 256;
        cout << inputText << " " << "ADD" << " " << value << endl;
        break;
    case MULTIPLY:
        inputText[index] = polyMultiplication(inputText[index], value);
        cout << inputText << " " << "MULTIPLY" << " " << value << endl;
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
        cout << inputText << " " << "SWAP" << " " << value << endl;
        break;
    case ADD:
        inputText[index] = (inputText[index] - value) % 256;
        cout << inputText << " " << "ADD" << " " << value << endl;
        break;
    case MULTIPLY:
        inputText[index] = polyMultiplication(multiplicativeInverse(inputText[index]), inputText[index]);
        cout << inputText << " " << "MULTIPLY" << " " << value << endl;
        break;
    default:
        break;
    }
}

// function to enumerate operations
operation getOperation(unsigned char operationBlock)
{
    switch (operationBlock)
    {
    case 0b00000000:
        return SWAP;
    case 0b00000010:
        return ADD;
    case 0b00000011:
        return MULTIPLY;
    default:
        return SWAP;
    }
}
