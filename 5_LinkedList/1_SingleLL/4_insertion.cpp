#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
};
node *convertArraytoLL(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void llTraversal(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *insertAtHead(node *head, int val)
{
    // if (head == NULL)
    // {
    //     node *newNode = new node(val);
    //     head = newNode;
    //     return head;
    // }
    // node *temp = new node(val);
    // temp->next = head;
    // return temp;
    return new node(val, head);
}
node *insertAtTail(node *head, int val)
{
    if (head == NULL)
    {
        return new node(val, head);
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(val);
    return head;
}
node *insertAtpostion(node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new node(val);
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        return new node(val, head);
    }
    int counter = 0;
    node *temp = head;
    while (temp != NULL)
    {
        counter++;
        if (counter == k - 1)
        {
            node *x = new node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
// Here val is the value you want to insert
// element is the node you v=want the val to be before
node *insertBeforeElement(node *head, int val, int element)
{
    if (head == NULL)
    {
        return NULL;
        
    }
    if (head->data == element)
    {
        return new node(val, head);
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == element)
        {
            node *x = new node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 3, 8, 100};
    node *head = convertArraytoLL(arr);
    // head = insertAtHead(head,10);
    // head = insertAtTail(head,10);
    // head = insertAtpostion(head, 10, 4);
    head = insertBeforeElement(head, 4, 100);
    llTraversal(head);
    return 0;
}