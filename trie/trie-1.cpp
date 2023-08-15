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
        flag = true;
        for(int i=0;i<s.length();i++){
            if(node->isContain(s[i])){
               Node* ref = node->getnode(s[i]);
               flag = flag && ref->flag;
            }
            if(!flag)return false;
            node = node->getnode(s[i]);
        }
        return true;
    }


    
};

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Trie trie;
    Node *root = trie.root;
    trie.insert(root, "apple");
    trie.insert(root, "app");
    bool ans = trie.search(root, "app");
    bool ans1 = trie.startswith(root, "ad");
    cout << ans<<"\n"<<ans1;
    return 0;
}
