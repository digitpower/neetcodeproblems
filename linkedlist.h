#pragma once

class LinkedList 
{

public:
    struct Node {
        int data;
        Node* next;
    };
    Node* m_head = nullptr;
    LinkedList();
private:
};