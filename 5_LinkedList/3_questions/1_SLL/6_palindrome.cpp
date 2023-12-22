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

node *reversal(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *temp = head;
    node *prev = nullptr;
    while (temp != NULL)
    {
        node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
bool checkPalindrome(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* newHead = reversal(slow->next);
    node* first = head;
    node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            reversal(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reversal(newHead);
    return true;
}
int main()
{
    vector<int> arr = {1, 2, 3,3, 2, 1};
    node *head = convertArrToLL(arr);
    llTraversal(head);
    cout<<checkPalindrome(head);

    return 0;
}