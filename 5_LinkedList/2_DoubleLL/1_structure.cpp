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
    cout<<endl;
}
int main()
{
    vector<int> arr = {12, 1, 3, 8};
    node *head = convertArrTo2LL(arr);
    traversal(head);
    return 0;
}