#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    // Node of the doubly linked list
    class Node
    {
    public:
        int key, value;
        Node *prev;
        Node *next;
        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node *> mp; // Map to store key -> node

    Node *head = new Node(-1, -1); // Dummy head
    Node *tail = new Node(-1, -1); // Dummy tail

    // Constructor to initialize cache capacity
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Helper to delete a node from the doubly linked list
    void deleteNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper to insert a node right after head (most recently used)
    void insertAtHead(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    // Get the value of the key if it exists, else return -1
    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        Node *currNode = mp[key];
        deleteNode(currNode);   // Remove from current position
        insertAtHead(currNode); // Move to head (most recently used)
        return currNode->value;
    }

    // Add or update the key-value pair in the cache
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *currNode = mp[key];
            currNode->value = value;
            deleteNode(currNode);
            insertAtHead(currNode);
        }
        else
        {
            if (mp.size() == capacity)
            {
                Node *toDelete = tail->prev; // Least recently used
                mp.erase(toDelete->key);
                deleteNode(toDelete);
                delete toDelete;
            }
            Node *newNode = new Node(key, value);
            insertAtHead(newNode);
            mp[key] = newNode;
        }
    }
};

// Sample usage
int main()
{
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // returns 1
    lru.put(3, 3);              // evicts key 2
    cout << lru.get(2) << endl; // returns -1 (not found)
    lru.put(4, 4);              // evicts key 1
    cout << lru.get(1) << endl; // returns -1 (not found)
    cout << lru.get(3) << endl; // returns 3
    cout << lru.get(4) << endl; // returns 4
    return 0;
}
