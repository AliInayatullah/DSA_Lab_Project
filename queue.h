#include <iostream>
#include "string"
using namespace std;

class queue
{
private:
    struct node
    {
        node *next;
        string data;
    };

    node *front;
    node *rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(string data)
    {
        node *newnode;
        newnode->data = data;
        newnode->next = NULL;
        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            newnode->next = front;
            front = newnode;
        }
    }

    // string dequeue_everything(){
    //     node *leaving = front;
    //     while(leaving != NULL){
    //         string returnData = leaving->data;
    //         delete leaving;
    //         front = front->next;
    //         return returnData;
    //     }
    // }
    void print()
    {
        node *traverse = front;
        while (traverse != NULL)
        {
            cout << traverse->data << " ";
            traverse = traverse->next;
        }
    }
};