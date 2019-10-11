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

void Reverse(Node **head)
{
    Node *current = *head, *prev = NULL;
    Node *succ = current->next;

    if (*head == NULL)
        return;

    while (succ != NULL)
    {
        current->next = prev;
        prev = current;
        current = succ;
        succ = succ->next;
    }
    current->next = prev;
    *head = current;
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
    Reverse(&head);
    displayList(&head);

    return 0;
}