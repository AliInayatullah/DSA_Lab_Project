#include <iostream>
#include "string"
using namespace std;

/**
 * @brief class for Queue
 *
 */
class queue
{
private:
    /**
     * @brief Struct for a Queue Node
     *
     */
    struct node
    {
        node *next;
        string data;
        /**
         * @brief Construct a new node object
         *
         */
        node()
        {
            next = NULL;
        }
    };

    node *head;

public:
    /**
     * @brief Construct a new queue object
     *
     */
    queue()
    {
        head = NULL;
    }

    /**
     * @brief Insert data in queue
     *
     * @param key string
     */
    void enqueue(string key)
    {
        node *newnode = new node;
        newnode->data = key;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *traverse = head;
            while (traverse->next != NULL)
            {
                traverse = traverse->next;
            }
            traverse->next = newnode;
        }
    }

    /**
     * @brief remove data from queue
     *
     * @return string
     */
    string dequeue()
    {
        // node *traverse = head;
        string returndata = head->data;
        head = head->next;
        return returndata;
    }

    /**
     * @brief check if queue is empty
     *
     * @return true if empty
     * @return false if not empty
     */
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /**
     * @brief print the data in queue
     *
     */
    void print()
    {
        node *traverse = head;
        while (traverse->next != NULL)
        {
            cout << traverse->data << " ";
            traverse = traverse->next;
        }
        cout << traverse->data;
    }
};