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

node *deleteMiddleElement(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    node *slow = head;
    node *fast = head;
    fast = head->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5,6};
    node *head = convertArrToLL(arr);
    llTraversal(head);
    head = deleteMiddleElement(head);
    llTraversal(head);
    // cout<<head->data;

    return 0;
}