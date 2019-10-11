#include <stdio.h>
#include <iostream>
#include "NodeStructure.h"
using namespace std;

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
        do
        {
            cout << temp->data << "-->";
            temp = temp->next;
        } while (temp != *head);
        cout << endl;
    }
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;

        cout << "Inserted at the beginning" << endl;
    }
    else
    {

        Node *current = *head;
        while (current->next != *head)
        {
            current = current->next;
        }

        current->next = newNode;

        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node **head, int data)
{

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {

        Node *temp = *head;
        while (temp->next != *head)
        {

            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void insertAfterGivenNode(Node **head, int data, int posData)
{

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *temp = *head;
        while (temp->data != posData && temp->next != *head)
        {

            temp = temp->next;
        }

        if (temp == *head)
        {
            cout << "Element provided not present in list" << endl;
        }
        else if (temp->next == *head)
        {
            newNode->next = *head;
            temp->next = newNode;
        }
        else
        {

            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteAtBeginning(Node **head)
{

    if (*head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        Node *temp = *head;
        Node *current = *head;
        if (temp->next == *head)
        {
            *head = NULL;
        }
        else
        {
            while (current->next != *head)
            {

                current = current->next;
            }
            *head = temp->next;
            current->next = *head;
            free(temp);
        }
    }
}

void deleteAtEnd(Node **head)
{

    Node *temp = *head;

    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {

        if (temp->next == *head)
        {
            *head = NULL;
        }
        else
        {

            Node *temp1 = temp;
            while (temp->next != *head)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = *head;
            free(temp);
        }
    }
}

void deleteAGivenNode(Node **head, int posData)
{
    if (*head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {

        Node *temp = *head;
        Node *temp1 = *head;
        if (temp->data == posData)
        {
            deleteAtBeginning(head);
        }
        else
        {
            while (temp->next != *head && temp->data != posData)
            {
                temp1 = temp;
                temp = temp->next;
            }
            if (temp->next == *head)
            {
                if (posData == temp->data)
                {
                    deleteAtEnd(head);
                }
                else
                {
                    cout << "Element is not present in the list" << endl;
                }
            }
            else
            {
                temp1->next = temp->next;
                free(temp);
            }
        }
    }
}

int main()
{
    Node *head = NULL;

    insertAtBeginning(&head, 10);
    displayList(&head);

    deleteAtEnd(&head);
    displayList(&head);
    insertAtBeginning(&head, 20);
    displayList(&head);

    insertAtEnd(&head, 40);
    displayList(&head);
    insertAtBeginning(&head, 30);
    displayList(&head);
    insertAfterGivenNode(&head, 123, 20);
    displayList(&head);
    insertAfterGivenNode(&head, 1234, 40);
    displayList(&head);

    deleteAtBeginning(&head);
    displayList(&head);
    deleteAtEnd(&head);
    displayList(&head);
    deleteAGivenNode(&head, 123);
    displayList(&head);

    return 0;
}