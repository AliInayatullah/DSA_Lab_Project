#include <iostream>
#include <string>
using namespace std;
#include "mapping_bst.h"
#include "queue.h" //queue is used as a transmission medium
#include <fstream>

/**
 * @brief Encrypts the string using mapping tree
 *
 * @param arr character array (string)
 * @param mapping_tree  BST for mappings
 */
void encrypt(char arr[], bst mapping_tree)
{
    int i = 0;
    // fstream encrypted_file("encypted.txt", ios::out);
    queue message_queue;
    // std::cout << arr;
    string encryptedWord = "";
    std::cout << endl;
    while (arr[i] != '\0')
    {
        if (arr[i] != ' ')
        {
            // Encrypting the word letter by letter
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
    // enqueuing the Encrypted words
    message_queue.enqueue(encryptedWord);

    // printing the Encrypted message
    cout << "Decrypted Message: ";
    message_queue.print();
}

/**
 *
 * @param arr character array (string)
 * @param mapping_tree BST for mappings
 */
void decrypt(char arr[], bst mapping_tree)
{
    int i = 0;
    queue message_queue;
    // std::cout << arr;
    string decryptedWord = "";
    std::cout << endl;
    while (arr[i] != '\0')
    {
        if (arr[i] != ' ')
        {
            // decrypting the word letter by letter
            char decryptedLetter = mapping_tree.getDecrypted(arr[i]);
            decryptedWord += decryptedLetter;
        }
        else
        {
            message_queue.enqueue(decryptedWord);
            decryptedWord = "";
        }
        i++;
    }
    // enqueuing the Decrypted words
    message_queue.enqueue(decryptedWord);

    // printing the Decrypted message
    cout << "Decrypted Message: ";
    message_queue.print();
}

/**
 * @brief Menu for user interface
 *
 */
void menu()
{
    cout << "**** MENU ****" << endl
         << "1-Encrypt Text" << endl
         << "2-Decrypt Text" << endl;
}

int main()
{
    bst encryption_mapping_tree;
    bst decryption_mapping_tree;
    fstream mapping_file;
    mapping_file.open("mapping.txt", ios::in);
    string line;

    // creating the mapping BSTs from mappings.txt
    while (1)
    {
        mapping_file >> line;
        // std::cout << line;
        encryption_mapping_tree.InsertNode(line);
        decryption_mapping_tree.InsertNodeEnc(line);
        if (mapping_file.eof())
            break;
    }

    char str[100];
    menu();
    int input;
    cout << "Select an option: ";
    cin >> input;

    switch (input)
    {
    case 1:
    {
        std::cout << "\nEnter Message to encrypt: ";
        cin.ignore();
        cin.get(str, 100);
        encrypt(str, encryption_mapping_tree);
        break;
    }
    case 2:
    {
        std::cout << "\nEnter Message to decrypt: ";
        cin.ignore();
        cin.get(str, 100);
        decrypt(str, decryption_mapping_tree);
        break;

        break;
    }
    default:
        cout << "Invalid input!";
    }
}
