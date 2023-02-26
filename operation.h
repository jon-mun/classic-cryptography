#ifndef OPERATION_H
#define OPERATION_H
#include <string>
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
void operationEncryptController(operationDetails details, string& inputText, int index);
void operationDecryptController(operationDetails details, string& inputText, int index);
operation getOperation(unsigned char operationBlock);

#endif