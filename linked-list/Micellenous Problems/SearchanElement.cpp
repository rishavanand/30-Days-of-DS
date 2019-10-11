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

void searchElement(Node *head, int x)
{
    int flag = 0;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    else
    {

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == x)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 1)
        {
            cout << "found" << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }
}

void searchElementRecursive(Node *head, int x)
{
    if (head == NULL)
        return;
    else
    {

        Node *temp = head;
        if (temp->data == x)
        {
            cout << "Found " << endl;
            return;
        }
        else
        {
            searchElementRecursive(temp->next, x);
        }
    }
}
int main()
{

    Node *head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);
    searchElement(head, 23);
    searchElement(head, 40);
    searchElementRecursive(head, 30);
    return 0;
}