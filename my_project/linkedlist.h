#pragma once

#include <string>

class LinkedList 
{

public:
    struct Node {
        int data;
        Node* next;
    };
    
    LinkedList();
    void Add(int data);
    std::string ToStr();
    bool SearchWithMoveToHead(int value);
private:
    Node* m_head = nullptr;
};