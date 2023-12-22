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
node *convertArrToLL(vector<int>&arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1;i<arr.size();i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
void llTraversal(node *head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int llLength(node* head){
    node* temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int llSearching(node* head,int num){
    node* temp = head;
    int search = 0;
    while (temp)
    {
        if(temp->data == num){
            search = 1;
            return search;
        }
        temp = temp->next;
    }
    return search;
}
int main()
{
    vector<int> arr = {12, 1, 3, 8};
    node* head = convertArrToLL(arr);
    // cout<<head->next;
    // llTraversal(head);
    // cout<<llLength(head);
    cout<<llSearching(head,121);
    return 0;
}