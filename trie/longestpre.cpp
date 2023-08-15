#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool isContain(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void insertchar(char ch)
    {
        Node *ref = new Node();
        links[ch - 'a'] = ref;
    }

    Node *getnode(char ch)
    {
        return links[ch - 'a'];
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    

    void insert(Node *root, string s)
    {
        int n = s.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->isContain(s[i]))
            {
                node->insertchar(s[i]);
            }
            node = node->getnode(s[i]); // Fix: Assign the returned node to 'node'
        }
        node->flag = true; // set end
    }

    bool search(Node *root, string s)
    {
        int n = s.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->isContain(s[i]))
            {
                return false;
            }
            node = node->getnode(s[i]); // Fix: Assign the returned node to 'node'
        }
        if (node->flag)
        {
            return true;
        }
        return false;
    }

    bool startswith(Node *root, string s)
    {
        int n = s.length();
        Node *node = root;
        for (int i = 0; i < n; i++)
        {
            if (!node->isContain(s[i]))
            {
                return false;
            }
            node = node->getnode(s[i]); // Fix: Assign the returned node to 'node'
        }
        return true;
    }

    bool checkallprefix(string s){
        Node* node = root;
        bool flag = true;
        for(int i=0;i<s.size();i++){
            if(node->isContain(s[i])){
               node = node->getnode(s[i]);
               flag = flag & node->flag;
            }
            else return false;
        }
        return flag;
    }

    bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        bool flag = true; 
        for(int i = 0;i<word.size();i++) {
            if(node->isContain(word[i])) {
                node = node->getnode(word[i]); 
                flag = flag & node->flag; 
            }
            else {
                return false; 
            } 
        }
        return flag; 
    }


    
};


string completeString(int n, vector<string>& a)
{
    string s;
    int maxi = INT_MIN;
    string res="";
    Trie* trie = new Trie();
    Node* root = trie->root;
    for (int i = 0; i < n; i++)
    {
        s = a[i];
        trie->insert(root, s);
    }
    bool test = trie->checkIfAllPrefixExists("abcd");
    cout<<test;
    // for (int i = 0; i < n; i++)
    // {
    //     s = a[i];
    //     if(trie.checkallprefix(s)){
    //         if(maxi<s.length()){
    //             maxi = s.length();
    //             res = s;
    //         }
    //         else if(maxi==s.length() && s<res){
    //                maxi = s.length();
    //                res = s;
    //         }
    //     }
    // }
     return "";
}

int main(){
     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> arr;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            arr.push_back(s);
        }
        string res = completeString(n,arr);
        cout<<res;
        return 0;
    }
}