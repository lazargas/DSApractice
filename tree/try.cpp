#include <bits/stdc++.h>
using namespace std;

bool bfs(int a, int b, int e, vector<int> &vis, vector<vector<pair<int, int>>> adj)
{
    queue<pair<int, int>> q;
    vis[a] = 1;
    q.push({a,e});

    while (!q.empty())
    {
        int currnode = q.front().first;
        int energy = q.front().second;
        q.pop();

        if (currnode == b and energy >= 0)
        {
            return true;
        }
        else if (currnode == b and energy < 0)
        {
            return false;
        }

        for (auto it : adj[currnode])
        {
            int nextnode = it.first;
            int dist = it.second;

            if (vis[nextnode] != 1 and energy - dist >= 0)
            {
                vis[nextnode] = 1;
                q.push({nextnode, energy - dist});
            }
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        vector<int> h(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            h[i] = temp;
        }
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, h[v] - h[u]});
            adj[v].push_back({u, h[u] - h[v]});
        }

        int q;
        cin >> q;
        map<vector<int>, string> hashmap;
        while (q--)
        {
            int a, b, e;
            cin >> a >> b >> e;
            vector<int> vis(n + 1, 0);
            if (hashmap[{a, b, e}] == "YES")
            {
                cout << "YES"
                     << "\n";
                continue;
            }
            if (bfs(a, b, e, vis, adj))
            {
                hashmap[{a, b, e}] = "YES";
                cout << "YES"
                     << "\n";
            }
            else
            {
                hashmap[{a, b, e}] = "NO";
                cout << "NO"
                     << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
