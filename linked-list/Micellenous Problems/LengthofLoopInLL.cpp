#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{

    int data, position;
    Node *next;
    bool flag = false;
};
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

void detectLoop(Node *head)
{

    Node *temp = head;
    int pos = 0;
    while (temp->next != NULL)
    {
        if (temp->flag)
        {
            cout << "Loop found" << endl;
            cout << "Length of Loop is " << pos - temp->position << endl;
            return;
        }
        temp->position = pos++;
        temp->flag = true;
        temp = temp->next;
    }
    cout << "No loop detected" << endl;
}

int main()
{
    Node *head = NULL;
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    Node *temp = head;
    temp->next->next->next->next->next = temp->next->next; //Loop Creation  For checking comment and uncomment respectivelys
    detectLoop(head);
    return 0;
}