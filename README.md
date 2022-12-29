MEMBERS:
Zaid Bin Muzammil(2021718)
Ali Innayatullah(2021081)


Language Used:
•	C++ 20
Data Structures and Concepts Used:
•	Binary Search Trees
•	Queue data structure using singly linked list
•	Text file handling
•	OOP
Project Description:
The purpose of the project is to encrypt any normal text entered by the user and decrypt any cipher text.
All the English characters (A-Z and a-z) and numerical digits (0-9) along with equivalent encrypted characters are stored in a text file.
The program reads this text file and loads the encrypted and decrypted characters and digits in a Binary Search Tree such that each node of the tree contains a normal character as well as its ciphered version.
Upon the input from the user, the binary search tree is traversed to find the cipher character in the case of encryption and normal character in the case of decryption. BST is used because its time complexity is O(logN) which is a lot better than O(N). the characters are combined to form the encrypted or decrypted string until space is encountered. Once a string word is formed, it is enqueued into a queue. Once whole message is present in the queue, it is dequeued in the final text file (receiver of the message). Therefore, we can say that the queue acts as a transmission medium between the sender and the receiver.
