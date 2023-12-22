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
    cout<<endl;
}

node* deleteNthNodeFromBack(node* head,int n){
    node* fast = head;
    node* slow = head;
    for(int i = 0;i<n;i++){
        fast = fast->next;
    }
    if(fast == NULL){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    return head;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    node *head = convertArrToLL(arr);
    llTraversal(head);
    head = deleteNthNodeFromBack(head,5);
    llTraversal(head);
    return 0;
}