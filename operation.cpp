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
