#pragma once
using namespace std;

void randomArr(int * arr, int size, int from, int to);
int randomInt(int from, int to);
void printArr(int * arr, int size);
size_t getFileSize(ifstream & f);
size_t getFileSize(ofstream & f);
#define SWAP(a, b, temp) {temp = a; a = b; b = temp;}