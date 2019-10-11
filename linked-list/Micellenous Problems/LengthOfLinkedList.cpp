#include <iostream>
#include <stdio.h>
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

int ListLength(Node **head)
{

    Node *temp = *head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

int ListLengthRecursive(Node **head)
{

    int c = 0;
    Node *temp = *head;
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + ListLengthRecursive(&temp->next);
    }
}

int main()
{

    Node *head = NULL;
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    cout << ListLength(&head) << endl;
    cout << ListLengthRecursive(&head) << endl;
    return 0;
}