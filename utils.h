#ifndef UTILS_H
#define UTILS_H
#include <string>
using namespace std;

string asciiToBinary(string key);
void splitKeys(string *key_blocks, string binaryKey, int blocks);
int binaryToDecimal(string n);
string swapForward(string inputText, int startIndex, int value);

#endif