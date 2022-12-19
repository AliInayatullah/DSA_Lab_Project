#include<iostream>
using namespace std;

class bst{
    private:

    struct node{
        node *left;
        node *right;
        char normal;
        char encrpyt;
    };

    node *root;
    public:

    bst(){
        root = NULL;
    }

    void InsertNode(string);
    void InsertNodeEnc(string);
    char getEncrypted(char);
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
            else{
                cout<<"\nduplicate values cant be stored\n";
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
            else{
                cout<<"\nduplicate values of encrypted data cant be stored\n";
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

