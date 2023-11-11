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
    int freq;
    Node *left, *right;
};

Node *newNode(char c, int freq, Node *left, Node *right) // tạo node mới
{
    Node *node = new Node();
    node->c = c;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct comp
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

void buildHuffmanTree_encode(string text)
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

    cout << "Huffman Codes are :\n";
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << '\n';
    }

    string str;
    for (char c : text)
    {
        str += huffmanCode[c];
    }
    cout << "\nEncoded string is :\n" << str << '\n';
}

void buildHuffmanTree_decode(map<char, int> freq, string str)
{
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
    cout << "Huffman Codes are :\n";
    for (auto pair : freq)
    {
        cout << pair.first << " " << pair.second << '\n';
    }
    Node *root = pq.top();
    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}

#endif //PROBLEM29_HUFFMANTREE_H
