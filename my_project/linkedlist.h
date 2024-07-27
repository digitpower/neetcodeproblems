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
private:
    Node* m_head = nullptr;
};