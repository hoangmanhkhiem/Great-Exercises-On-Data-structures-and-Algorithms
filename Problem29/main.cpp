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
    buildHuffmanTree_encode(text);

    map<char, int> text2 = { {'a',2 }, {'h', 3}, {'o', 1},
                             {'n', 2}, {'g', 1}, {'m', 2},
                             {'e', 1}, {'k', 1}, {'i', 1},
                             {' ', 2}};
    buildHuffmanTree_decode(text2,"1110001101001011001011110100111001101011101010100011");
}


