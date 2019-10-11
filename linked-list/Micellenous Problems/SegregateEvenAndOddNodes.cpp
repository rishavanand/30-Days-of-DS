#include <stdio.h>
#include <iostream>
#include "../NodeStructure.h"

using namespace std;

void insertAtBeginning(Node **head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
        cout << "Inserted at the beginning" << endl;
    }
    else
    {
        temp->next = *head;
        *head = temp;
        cout << "Inserted at the beginning" << endl;
    }
}

void insertAtEnd(Node **head, int data)
{
    Node *temp = new Node();
    temp->next = NULL;
    temp->data = data;

    Node *trav = *head;

    if (*head == NULL)
    {
        *head = temp;
        cout << "Inserted at the end" << endl;
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = temp;
        cout << "Inserted at the end" << endl;
    }
}

void displayList(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        cout << "The List is" << endl;
        Node *temp = *head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
}

void SegregateNodes(Node *head)
{

    Node *temp = head;
    Node *evenHead = NULL;
    Node *oddHead = NULL;

    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            insertAtEnd(&evenHead, temp->data);
        }
        else
        {
            insertAtEnd(&oddHead, temp->data);
        }
        temp = temp->next;
    }

    Node *t = evenHead;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = oddHead;

    displayList(&evenHead);
}

int main()
{

    Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 21);
    insertAtBeginning(&head, 43);
    insertAtBeginning(&head, 44);
    insertAtBeginning(&head, 11);

    displayList(&head);
    SegregateNodes(head);
    return 0;
}