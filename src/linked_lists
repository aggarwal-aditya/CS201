//What is implemnted?
//Linked Lists
//Add Node at beginning 
//Add node at ending
//Reverse the linked lists
#include<bits/stdc++.h>
using namespace std;
typedef struct node {
    struct node* next;
    int key;

} node;
int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    node * head = NULL;
    node * second = NULL;
    node * tail = NULL;
    head = new node();
    second = new node();
    tail = new node();
    head->next = second;
    second->next = tail;
    tail->next = NULL;
    head->key = 1;
    head->next->key = 9;
    tail->key = -4;
    // while (ptr != NULL)
    // {
    //     cout << ptr->key << endl;
    //     ptr = ptr->next;
    // }
    int n; cin >> n;
    node * new_node = new node();
    new_node->key = n;
    new_node->next = head;
    head = new_node;
    node * ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->key << " ";
        ptr = ptr->next;
    }
    cout << endl;
    int k;  cin >> k;
    node * ins = new node();
    ins->key = k;
    tail->next = ins;
    ins->next = NULL;
    tail = ins;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->key << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Reverse Linked List" << endl;
    node * p1 = NULL;
    node * p2 = head;
    while (p2 != NULL)
    {
        node*p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    while (p1 != NULL)
    {
        cout << p1->key << " ";
        p1 = p1->next;
    }






}
