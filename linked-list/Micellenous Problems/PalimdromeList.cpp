#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{

    char data;
    Node *next;
};

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

void checkPalindrome(Node *head)
{

    Node *temp = head;
    vector<char> newList;
    while (temp != NULL)
    {
        newList.push_back(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (temp->data != newList.back())
        {
            cout << "Not a palindrome" << endl;
            return;
        }
        temp = temp->next;
        newList.pop_back();
    }
    cout << "List is palimdrome" << endl;
}

int main()
{

    Node *head = NULL;

    insertAtBeginning(&head, 'n');
    insertAtBeginning(&head, 'i');
    insertAtBeginning(&head, 't');
    insertAtBeginning(&head, 'i');
    insertAtBeginning(&head, 'n');

    checkPalindrome(head);
    return 0;
}