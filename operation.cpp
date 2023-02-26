#include "operation.h"
#include "utils.h"
#include <iostream>
using namespace std;

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
        inputText[index] = (inputText[index] * value) % 256;
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
        inputText[index] = (inputText[index] / value) % 256;
        cout << inputText << " " << "MULTIPLY" << " " << value << endl;
        break;
    default:
        break;
    }
}

// function to enumerate operations
operation getOperation(string operationBlock)
{
    if (operationBlock == "00")
    {
        return SWAP;
    }
    else if (operationBlock == "01")
    {
        return ADD;
    }
    else // operationBlock == "11"
    {
        return MULTIPLY;
    }
}
