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
node *sumOf2LinkedList(node *head1, node *head2)
{
    node *dummyNode = new node(-1);
    node *curr = dummyNode;
    int carry = 0;
    node *t1 = head1;
    node *t2 = head2;

    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;
        if (t1)
            sum += t1->data;
        if (t2)
            sum += t2->data;

        node *newNode = new node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }
    if (carry)
    {
        node *newNode = new node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;
}

int main()
{
    vector<int> arr1 = {1,0,2,5,0};
    vector<int> arr2 = {2,2,2,4,5,0};
    node *head1 = convertArrToLL(arr1);
    node *head2 = convertArrToLL(arr2);
    node *head3 = sumOf2LinkedList(head1, head2);
    llTraversal(head3);
    return 0;
}