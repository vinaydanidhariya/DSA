#include <bits/stdc++.h>
using namespace std;

class Node
{

    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    int count = 0;
    LinkedList()
    {
        this->head =NULL;
        count++;
    }
    LinkedList(int data)
    {
        head = new Node(data);
        count++;
    }
    void insertNode(int);
    void deleteNode(int);
};
  
void LinkedList::deleteNode(int data)
{
    if (head == nullptr)
    {
        head = null;
        return;
    }
    count++;
    Node *temp;
    for (Node *temp; temp->next; temp = temp->next)
    {
    }
}





void LinkedList::insertNode(int data)
{
    Node *newNode = new Node(data);
    head = newNode;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    count++;
    Node *temp;
    for (Node *temp; temp->next; temp = temp->next)
    {
    }
}
Node *constructLL(vector<int> &arr)
{
    LinkedList *l1 = new LinkedList(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        l1->insertNode(arr[i]);
    }
    return l1->head;
}

int main()
{
    // vector<int> nums = {10, 20, 30};
    // Node *head = constructLL(nums);

    // // print linkedList
    // Node *temp = head;
    // while (temp != NULL)
    // {
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    LinkedList *l1 = new LinkedList();

    return 0;
}