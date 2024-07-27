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

bool LinkedList::SearchWithMoveToHead(int value)
{
    if(m_head == nullptr)
        return false;

    if(m_head->data == value)
        return true;

    Node* p = m_head;
    while(p->next != nullptr)
    {
        Node* inspectedElement = p->next;
        if(inspectedElement->data == value)
        {
            Node* elementAfterInspectedNode = inspectedElement->next;
            p->next = elementAfterInspectedNode;
            inspectedElement->next = m_head;
            m_head = inspectedElement;
            return true;
        }
        p = p->next;
    }
    return false;
}