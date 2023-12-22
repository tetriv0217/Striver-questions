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
node *oddEven(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *odd = head;
    node *even = head->next;
    node *evenHead = head->next;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    cout << endl;
    return head;
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    node *head1 = convertArrToLL(arr1);
    llTraversal(head1);
    head1 = oddEven(head1);
    llTraversal(head1);
    return 0;
}


/*

Code dont run

segregating 0s 1s and 2s

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
node *zeros_1s_2s(node *head)
{
    if(head==NULL || head->next == NULL ){
        return NULL;
    }
    node *dummyNode0 = new node(-1);
    node *dummyNode1 = new node(-1);
    node *dummyNode2 = new node(-1);
    node *zero = dummyNode0;
    node *one = dummyNode1;
    node *two = dummyNode2;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (dummyNode1->next)?dummyNode1->next:dummyNode2->next;
    one->next = dummyNode2->next;
    dummyNode2->next = NULL;

    node*newHead = dummyNode0->next;
    delete dummyNode0;
    delete dummyNode1;
    delete dummyNode2;
    return newHead;
}
int main()
{
    vector<int> arr1 = {1,1,0,2,1,2,0,0};
    node *head1 = convertArrToLL(arr1);
    llTraversal(head1);
    head1 = zeros_1s_2s(head1);
    llTraversal(head1);
    return 0;
}



*/