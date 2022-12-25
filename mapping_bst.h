#include <iostream>
using namespace std;

/**
 * @brief Class for Binary Search Tree
 *
 */
class bst
{
private:
    /**
     * @brief Struct For a BST Node
     *
     */
    struct node
    {
        node *left;
        node *right;
        char normal;
        char encrpyt;
    };

    node *root;

public:
    /**
     * @brief Construct a new bst object
     *
     */
    bst()
    {
        root = NULL;
    }

    /**
     * @brief Insert Node for encryption mapping tree
     *
     */
    void InsertNode(string);

    /**
     * @brief insert Node for Decryption mapping tree
     *
     */
    void InsertNodeEnc(string);

    /**
     * @brief Get the Encrypted object
     *
     * @return char Normal char
     */
    char getEncrypted(char);

    /**
     * @brief Get the Decrypted object
     *
     * @return char Encrypted char
     */
    char getDecrypted(char);
};

void bst::InsertNode(string data)
{
    node *newnode = new node;
    node *traverse;

    if (this->root == NULL)
    {
        newnode->normal = data[0];
        newnode->encrpyt = data[2];
        newnode->left = newnode->right = NULL;
        root = newnode;
    }
    else
    {
        traverse = root;
        newnode->normal = data[0];
        newnode->encrpyt = data[2];
        newnode->left = newnode->right = NULL;
        while (traverse != NULL)
        {
            if (data[0] < traverse->normal)
            {
                if (traverse->left != NULL)
                {
                    traverse = traverse->left;
                }
                else
                {
                    traverse->left = newnode;
                    break;
                }
            }
            else if (data[0] > traverse->normal)
            {
                if (traverse->right != NULL)
                {
                    traverse = traverse->right;
                }
                else
                {
                    traverse->right = newnode;
                    break;
                }
            }
            else
            {
                cout << "\nduplicate values cant be stored\n";
            }
        }
    }
}

void bst::InsertNodeEnc(string data)
{
    node *newnode = new node;
    node *traverse;

    if (this->root == NULL)
    {
        newnode->normal = data[0];
        newnode->encrpyt = data[2];
        newnode->left = newnode->right = NULL;
        root = newnode;
    }
    else
    {
        traverse = root;
        newnode->normal = data[0];
        newnode->encrpyt = data[2];
        newnode->left = newnode->right = NULL;
        while (traverse != NULL)
        {
            if (data[2] < traverse->encrpyt)
            {
                if (traverse->left != NULL)
                {
                    traverse = traverse->left;
                }
                else
                {
                    traverse->left = newnode;
                    break;
                }
            }
            else if (data[2] > traverse->encrpyt)
            {
                if (traverse->right != NULL)
                {
                    traverse = traverse->right;
                }
                else
                {
                    traverse->right = newnode;
                    break;
                }
            }
            else
            {
                cout << "\nduplicate values of encrypted data cant be stored\n";
            }
        }
    }
}

char bst::getEncrypted(char nor)
{
    node *traverse = root;
    if (traverse == NULL)
    {
        cout << "\nthe tree is empty\n";
        return false;
    }
    else
    {
        while (traverse != NULL)
        {
            if (traverse->normal == nor)
            {
                return traverse->encrpyt;
            }
            else if (nor < traverse->normal)
            {
                traverse = traverse->left;
            }
            else
            {
                traverse = traverse->right;
            }
        }
        return false;
    }
}

char bst::getDecrypted(char enc)
{
    node *traverse = root;

    if (traverse == NULL)
    {
        cout << "\nthe tree is empty\n";
        return false;
    }
    else
    {
        while (traverse != NULL)
        {
            if (traverse->encrpyt == enc)
            {
                return traverse->normal;
            }
            else if (enc < traverse->encrpyt)
            {
                traverse = traverse->left;
            }
            else
            {
                traverse = traverse->right;
            }
        }
        return enc;
    }
}