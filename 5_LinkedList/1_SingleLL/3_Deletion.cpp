/*
    4 Methods :-
                Head
                Postion
                Value
                Last
*/

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
};
node *convertArrToLL(vector<int> &arr)
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
}

node *deleteHead(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

node *deleteTail(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}
node *deletePosition(node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    int count = 0;
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
node* deleteElement(node *head, int val)
{
    if (head == NULL)
        return NULL;
    if (val == head->data)
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    node *temp = head;
    node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {12, 8, 5, 3, 100};
    node *head = convertArrToLL(arr);
    // head = deleteHead(head);
    // cout<<head->data;
    // head = deleteTail(head);
    // head = deletePosition(head,3);
    head = deleteElement(head,1000);
    llTraversal(head);
    return 0;
}