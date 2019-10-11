#include <stdio.h>
#include <iostream>
#include "../NodeStructure.h"
using namespace std;
void insertAtBeginning(Node **head, char data)
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

void swapNodes(Node *head)
{

    Node *temp = head;

    if (temp && temp->next != NULL)
    {

        int t = temp->data;
        temp->data = temp->next->data;
        temp->next->data = t;

        swapNodes(temp->next->next);
    }
}

int main()
{

    Node *head = NULL;
    insertAtBeginning(&head, 23);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 13);
    //insertAtBeginning(&head, 12);
    insertAtBeginning(&head, 15);
    insertAtBeginning(&head, 10);
    displayList(&head);

    swapNodes(head);
    displayList(&head);
    return 0;
}