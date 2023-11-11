//
// Created by admin on 09/11/2023.
//

#ifndef PROBLEM29_HUFFMANTREE_H
#define PROBLEM29_HUFFMANTREE_H

#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<fstream>
#include<algorithm>
using namespace std;

struct Node
{
    char c;
    int freq;  // tần suất
    Node *left, *right; // con trỏ trái, phải
};

Node *newNode(char c, int freq, Node *left, Node *right) // tạo node mới
{
    Node *node = new Node(); // cấp phát động
    node->c = c; // kí tự
    node->freq = freq; // tần suất
    node->left = left; // con trái
    node->right = right; // con phải
    return node; // trả về node
}

struct comp // so sánh
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void encode(Node *root, string str, map<char, string> &huffmanCode) // mã hóa
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right)
    {
        huffmanCode[root->c] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

//giải thích hàm encode: hàm encode sẽ duyệt cây huffman từ gốc đến lá,
// mỗi khi đi qua một nút nào đó thì nó sẽ thêm vào chuỗi str
// một bit 0 nếu đi qua nút trái và 1 nếu đi qua nút phải,
// nếu nút đó là lá thì nó sẽ thêm vào map huffmanCode
// một cặp key-value là kí tự và chuỗi str

void decode(Node *root, int &index, string str) // giải mã
{
    if (root == nullptr)
    {
        return;
    }

    if (!root->left && !root->right)
    {
        cout << root->c;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

// giải thích hàm decode: hàm decode sẽ duyệt cây huffman từ gốc đến lá,
// mỗi khi đi qua một nút nào đó thì nó sẽ tăng biến index lên 1,
// nếu bit thứ index trong chuỗi str là 0 thì nó sẽ đi qua nút trái,
// nếu bit thứ index trong chuỗi str là 1 thì nó sẽ đi qua nút phải,
// nếu nút đó là lá thì nó sẽ in ra kí tự của nút đó

void buildHuffmanTree(string text)
{
    map<char, int> freq;
    for (char c : text)
    {
        freq[c]++;
    }

    priority_queue<Node *, vector<Node *>, comp> pq;


    for (auto pair : freq)
    {
        pq.push(newNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(newNode('\0', sum, left, right));
    }

    Node *root = pq.top();

    map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are :\n"
         << '\n';
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nOriginal string was :\n"
         << text << '\n';

    string str;
    for (char c : text)
    {
        str += huffmanCode[c];
    }

    cout << "\nEncoded string is :\n"
         << str << '\n';

    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}

// giải thích hàm buildHuffmanTree: hàm buildHuffmanTree sẽ tạo cây huffman,
// đầu tiên nó sẽ tạo một map freq để lưu tần suất của các kí tự trong chuỗi text,
// sau đó nó sẽ tạo một priority_queue pq để lưu các node,
// mỗi node sẽ có các thuộc tính là kí tự, tần suất, con trái, con phải,
// sau đó nó sẽ duyệt map freq để thêm các node vào priority_queue pq,
// mỗi node sẽ có kí tự là key của map freq, tần suất là value của map freq,
// con trái và con phải sẽ là nullptr,
// sau đó nó sẽ lấy ra 2 node có tần suất nhỏ nhất trong priority_queue pq,
// tạo một node mới có kí tự là '\0', tần suất là tổng tần suất của 2 node trên,
// con trái là node có tần suất nhỏ nhất, con phải là node có tần suất nhỏ thứ 2,
// sau đó nó sẽ thêm node mới này vào priority_queue pq,
// lặp lại cho đến khi priority_queue pq chỉ còn 1 node,
// node này chính là gốc của cây huffman,
// sau đó nó sẽ tạo một map huffmanCode để lưu mã huffman của các kí tự,
// sau đó nó sẽ gọi hàm encode để mã hóa cây huffman,
// sau đó nó sẽ in ra mã huffman của các kí tự,
// sau đó nó sẽ tạo một chuỗi str để lưu mã huffman của chuỗi text,
// sau đó nó sẽ duyệt chuỗi text để lấy mã huffman của từng kí tự,
// sau đó nó sẽ in ra chuỗi str,
// sau đó nó sẽ tạo một biến index để lưu vị trí của bit trong chuỗi str,
// sau đó nó sẽ gọi hàm decode để giải mã chuỗi str,
// sau đó nó sẽ in ra chuỗi text đã được giải mã

#endif //PROBLEM29_HUFFMANTREE_H
