#include <string>
#include "HuffmanTree.h"
using namespace std;

int main()
{
    map<char, int> freq;
    string text="khiem";
    string text_encode = "011011111000";
    for(auto x:text)
    {
        freq[x]++;
    }
    buildHuffmanTree_decode(freq,text_encode);
}

