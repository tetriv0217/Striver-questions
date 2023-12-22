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

node *reverseBruteForce(node *head)
{
    node *temp = head;
    stack<int> st;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
node *reversalOptimized(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *curr = head;
    node *last;
    while (curr != NULL)
    {
        last = curr->back;
        curr->back = curr->next;
        curr->next = last;
        curr = curr->back;
    }
    return last->back;
}
int main()
{
    vector<int> arr = {12, 1, 3, 8};
    node *head = convertArrTo2LL(arr);
    traversal(head);
    // head = reverseBruteForce(head);
    head = reversalOptimized(head);
    traversal(head);
    return 0;
}