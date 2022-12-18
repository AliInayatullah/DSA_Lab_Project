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
    void displayInOrder(node *);
    void displayPreOrder(node *);
    void displayPostOrder(node *);

    public:

    bst(){
        root = NULL;
    }

    void InsertNode(string);
    char getEncrypted(char);
    void remove(int);
    void ShowInOrder()
    {
        displayInOrder(root);
    }
    void ShowPreOrder()
    {
        displayPreOrder(root);
    }
    void ShowPostOrder()
    {
        displayPostOrder(root);
    }
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

void bst::displayInOrder(node *nodeptr)
{
    if (nodeptr)
    {
        displayInOrder(nodeptr->left);
        
        cout << nodeptr->normal<<", "<<nodeptr->encrpyt << endl;
        
        displayInOrder(nodeptr->right);
    }
}

void bst::displayPreOrder(node *nodeptr)
{
    if (nodeptr)
    {
         cout << nodeptr->normal<<", "<<nodeptr->encrpyt << endl;
        displayPreOrder(nodeptr->left);
        displayPreOrder(nodeptr->right);
    }
}

void bst::displayPostOrder(node *nodeptr)
{
    if (nodeptr)
    {
        displayPreOrder(nodeptr->left);
        displayPreOrder(nodeptr->right);
        cout << nodeptr->normal<<", "<<nodeptr->encrpyt << endl;    }
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

