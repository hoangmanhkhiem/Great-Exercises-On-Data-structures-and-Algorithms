#include <string>
#include "HuffmanTree.h"
using namespace std;

int main()
{
    string text;
    ifstream file("../data.txt");
    if (file.is_open())
    {
        getline(file, text);
        file.close();
    }
    buildHuffmanTree(text);
    return 0;
}


