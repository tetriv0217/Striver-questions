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
    cout << endl;
}

node *iterativeReversal(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = nullptr;
    node *temp = head;
    while (temp != NULL)
    {
        node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
node *recursiveReversal(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* newHead = recursiveReversal(head->next);
    node*front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    node *head = convertArrToLL(arr);
    llTraversal(head);
    head = iterativeReversal(head);
    // head = recursiveReversal(head);
    llTraversal(head);

    return 0;
}