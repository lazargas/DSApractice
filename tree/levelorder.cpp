#include <bits/stdc++.h> 
using namespace std;

struct Node{
   int data;
   Node* left;
   Node* right;
   
   Node(){
    data=0;
    left=NULL;
    right=NULL;
   }

   Node(int n){
    data = n;
    left=NULL;
    right=NULL;
   }
};

class Tree{
   private:
   Node* root;

   
   public:
   Tree(){
    root = new Node();
   }
   void insert(int n){
      if(root->data==0 and root->left==NULL and root->right==NULL){root->data=n;return;}
      Node* node = root;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left==NULL){
            curr->left = new Node(n);
            return;
        }
        else{
            q.push(curr->left);
        }
        if(curr->right==NULL){
            curr->right = new Node(n);
            return;
        }
        else{
            q.push(curr->right);
        }
      }
   }

   void print(){
      if(root==NULL)return;
      
      queue<Node*> q;
      q.push(root);

      while(!q.empty()){
         Node* curr = q.front();
         q.pop();
         cout<<curr->data<<" ";
         
         if(curr->left!=NULL){
            q.push(curr->left);
         }
         if(curr->right!=NULL){
            q.push(curr->right);
         }
      }
   }

};


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
   //  Tree tree;
   //  int n;
   //  cin>>n;
   //  while(n--){
   //    int temp;
   //    cin>>temp;
   //    tree.insert(temp);
   //  }
    
   //  tree.print();
    
    string s  = "fox";
    cout<<"5"*s;
    return 0;
}