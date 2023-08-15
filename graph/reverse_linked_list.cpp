#include <bits/stdc++.h>
using namespace std;

struct Node{
int data;
Node* next;
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
Node* head  = new Node;
Node* node1 = new Node;
Node* node2 = new Node;
Node* node3 = new Node;
Node* node4 = new Node;
Node* node5 = new Node;

head->data = NULL;
node1->data = 1;
node2->data = 2;
node3->data = 3;
node4->data = 4;
node5->data = 5;

head->next = node1;
node1->next = node2;
node2->next = node3;
node3->next = node4;
node4->next = node5;
node5->next = NULL;

Node* curr = head->next;
Node* prev = NULL;
Node* next = NULL;
while(curr!=NULL){
   next = curr->next;
   curr->next = prev;
   prev = curr;
   curr = next; 
}

head->next = prev;

curr = head->next;
while(curr!=NULL){
    
    cout<<curr->data<<" ";
    curr = curr->next;
}

delete head;
delete node1;
delete node2;
delete node3;
delete node4;
delete node5;
return 0;










}