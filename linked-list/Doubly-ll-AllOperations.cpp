#include <iostream>
#include <stdio.h>
#include "NodeStructure.h"
using namespace std;
void deleteAtBegining(Node **head)
{
    Node *temp = *head;
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
    }
    else
    {
        *head = temp->next;
        temp->next->prev = NULL;
        free(temp);
    }
}

void deleteAGivenNode(Node **head, int data)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *temp = *head;
        while (temp->data != data && temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Data given not present in List" << endl;
            return;
        }

        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            free(temp);
        }
        else if (temp->prev == NULL)
        {
            Node *temp1 = *head;
            *head = temp->next;
            temp->next->prev = NULL;
            free(temp1);
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            free(temp);
        }
    }
}

void deleteAtEnd(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {

        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void insertAtBeginning(Node **head, int data)
{

    Node *newNode = new Node();

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        cout << "Inserted at Beginning" << endl;
    }
    else
    {

        Node *temp = *head;
        temp->prev = newNode;
        newNode->next = *head;
        *head = newNode;
        cout << "Inserted at begining" << endl;
    }
}

void insertAtEnd(Node **head, int data)
{

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {

        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAfterANode(Node **head, int data, int posData)
{

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;

        while (temp->data != posData && temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            temp->next = newNode;
            newNode->prev = temp;
        }
        else if (temp == NULL)

        {
            cout << posData << " Does not Exist" << endl;
            return;
        }
        else
        {

            newNode->next = temp->next;
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
}

void displayList(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {

        Node *temp = *head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Node *head = NULL;

    insertAtBeginning(&head, 3);
    displayList(&head);

    insertAtBeginning(&head, 2);
    displayList(&head);

    insertAtBeginning(&head, 1);
    displayList(&head);
    insertAtBeginning(&head, 0);
    displayList(&head);

    deleteAtEnd(&head);
    displayList(&head);
    insertAtEnd(&head, 10);
    displayList(&head);

    insertAfterANode(&head, 5034, 1);
    displayList(&head);

    insertAtEnd(&head, 20);
    displayList(&head);

    deleteAtBegining(&head);
    displayList(&head);
    insertAtEnd(&head, 30);
    displayList(&head);

    deleteAGivenNode(&head, 1);
    displayList(&head);
    return 0;
}
