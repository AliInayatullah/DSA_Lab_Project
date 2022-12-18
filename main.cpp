#include <iostream>
#include <string>
using namespace std;
#include "mapping_bst.h"
#include "queue.h" //queue is used as a transmission medium
#include <fstream>

void encrypt(char arr[], bst mapping_tree)
{
    int i = 0;
    // fstream encrypted_file("encypted.txt", ios::out);
    queue message_queue;
    std::cout << arr;
    string encryptedWord = "";
    std::cout << endl;
    while (arr[i] != '\0')
    {
        if (arr[i] != ' ')
        {
            char encryptedLetter = mapping_tree.getEncrypted(arr[i]);
            encryptedWord += encryptedLetter;
            
        }
        else
        { // zaid muzammil
            // cout << encryptedWord << " ";
            message_queue.enqueue(encryptedWord);
            encryptedWord = "";
        }
        i++;
    }
    message_queue.enqueue(encryptedWord);
    // cout << encryptedWord;
    message_queue.print();
}

int main()
{
    bst mapping_tree;
    fstream mapping_file;
    mapping_file.open("mapping.txt", ios::in);
    string line;
    while (1)
    {
        mapping_file >> line;
        std::cout << line;
        mapping_tree.InsertNode(line);
        std::cout << endl;
        if (mapping_file.eof())
            break;
    }
    char str[100];
    std::cout << "\nenter the string: ";
    cin.get(str, 100);
    encrypt(str, mapping_tree);
}
