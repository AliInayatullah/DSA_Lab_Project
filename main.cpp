#include <iostream>
#include <string>
using namespace std;
#include "mapping_bst.h"
#include "queue.h" //queue is used as a transmission medium
#include <fstream>

void encrypt(char arr[], bst mapping_tree)
{
    int i = 0;
    fstream encrypted_file("encrypted.txt", ios::out);
    queue message_queue;
    // std::cout << arr;
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
        {
            message_queue.enqueue(encryptedWord);
            encryptedWord = "";
        }
        i++;
    }
    message_queue.enqueue(encryptedWord);
    while(!message_queue.isEmpty()){
        encrypted_file<<message_queue.dequeue()<<" ";
    }

}

void decrypt(char arr[], bst mapping_treeEnc)
{
    int i = 0;
    fstream decrypted_file("decrypted.txt", ios::out);
    queue message_queue;
    // std::cout << arr;
    string decryptedWord = "";
    std::cout << endl;
    while (arr[i] != '\0')
    {
        if (arr[i] != ' ')
        {
            char decryptedLetter = mapping_treeEnc.getDecrypted(arr[i]);
            decryptedWord += decryptedLetter;
            
        }
        else
        {
            message_queue.enqueue(decryptedWord);
            decryptedWord = "";
        }
        i++;
    }
    message_queue.enqueue(decryptedWord);
    while(!message_queue.isEmpty()){
        decrypted_file<<message_queue.dequeue()<<" ";
    }
}

int main()
{
    bst mapping_tree;
    bst mapping_treeEnc;
    fstream mapping_file;
    mapping_file.open("mapping.txt", ios::in);
    string line;
    while (1)
    {
        mapping_file >> line;
        std::cout << line;
        mapping_tree.InsertNode(line);
        mapping_treeEnc.InsertNodeEnc(line);
        std::cout << endl;
        if (mapping_file.eof())
            break;
    }
    char str[100];
    std::cout << "\nenter the encrypted string: ";
    cin.get(str, 100);
    decrypt(str, mapping_treeEnc);
}