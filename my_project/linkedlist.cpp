#include <iostream>
#include <sstream>
#include "linkedlist.h"

LinkedList::LinkedList()
{
}

void LinkedList::Add(int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;

    if(m_head == nullptr)
        m_head = node;
    else
    {
        Node *p = m_head;
        while (p->next != nullptr)
            p = p->next;
        p->next = node;
    }
}

std::string LinkedList::ToStr()
{
    Node* p = m_head;
    std::ostringstream out;
    while(p != nullptr)
    {
        out << p->data << " ";
        p = p->next;
    }
    return out.str();
}