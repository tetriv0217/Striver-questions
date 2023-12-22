#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *back;

    node(int data1, node *next1, node *back1)
    {
        data = data1;
        back = back1;
        next = next1;
    }
    node(int data1)
    {
        data = data1;
        back = nullptr;
        next = nullptr;
    }
};
node *convertArrTo2LL(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void traversal(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *insertAtHead(node *head, int val)
{
    if (head == NULL)
    {
        return new node(val);
    }
    node *temp = new node(val, head, nullptr);
    head->back = temp;
    return temp;
}
node *insertAtTail(node *head, int val) // after tail
{
    node *tail = head;
    if (head == NULL)
    {
        return new node(val);
    }
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    node *newNode = new node(val, nullptr, tail);
    tail->next = newNode;
    return head;
}
node *insertBeforeKElement(node *head, int k, int val)
{
    if (k == 1)
    {
        return insertAtHead(head, val);
    }
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    node* prev = temp->back;
    node* newNode = new node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
node *insertBeforeNode(node *head, int element, int val)
{
    if (element == head->data)
    {
        return insertAtHead(head, val);
    }
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == element)
            break;
        temp = temp->next;
    }
    node* prev = temp->back;
    node* newNode = new node(val,temp,prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
int main()
{
    vector<int> arr{1, 2, 3, 4};
    node *head = convertArrTo2LL(arr);
    // head = insertAtHead(head, 10);
    // head = insertAtTail(head, 10);
    // head = insertBeforeKElement(head,2,14);
    head = insertBeforeNode(head,2,14);
    traversal(head);
    return 0;
}