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
        node(){
            next = NULL;
        }
    };

    node *head;

public:
    queue()
    {
        head = NULL;
    }

    void enqueue(string key)
    {
      node *newnode = new node;
      newnode->data = key;
      if(head == NULL){
        head = newnode;
      }
      else{
        node *traverse = head;
        while(traverse->next != NULL){
            traverse = traverse->next;
        }
        traverse->next = newnode;
      }
    }

    string dequeue(){
        // node *traverse = head;
        string returndata = head->data;
        head = head->next;
        return returndata;

    }
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void print(){
        node *traverse = head;
        while(traverse->next != NULL){
            cout<<traverse->data<<" ";
            traverse = traverse->next;
        }
        cout<<traverse->data;
    }

};