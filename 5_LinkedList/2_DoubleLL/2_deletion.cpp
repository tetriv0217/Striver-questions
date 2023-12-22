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
node *deleteAtHead(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    node *prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;
    return head;
}
node *deleteAtTail(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    node *prev = head;
    while (prev->next->next != NULL)
    {
        prev = prev->next;
    }
    node *temp = prev->next;
    // cout<<temp->data<<endl;
    prev->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
}
node *deleteAtPostiton(node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        if(k==1)
        return NULL;
        else
        return head;
    }
    if (k == 1)
    {
        node* prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }
    int cnt = 0;
    node *temp = head;
    node *prev;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = temp->next;
            temp->next->back = prev;
            temp->next = nullptr;
            temp->back = nullptr;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
node *deleteElement(node *head, int val)
{
    // if only one element is present or not present 
    if (head == NULL || head->next == NULL)
    {
        if(head->data==val)
        return NULL;
        else
        return head;
    }
    if (head->data == val)
    {
        node* prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        return head;
    }
    node *temp = head;
    node *prev;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = temp->next;
            temp->next->back = prev;
            temp->next = nullptr;
            temp->back = nullptr;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4};
    node *head = convertArrTo2LL(arr);
    // head = deleteAtHead(head);
    // head = deleteAtTail(head);
    head = deleteAtPostiton(head, 3);
    // head = deleteElement(head, 12);
    traversal(head);
    return 0;
}