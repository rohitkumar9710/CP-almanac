#include <bits/stdc++.h>
using namespace std;

vector<int> res;
vector<int> adj[100001];
int in[100001];

void kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr = q.top();
        q.pop();
        res.push_back(curr);
        for (auto x: adj[curr])
        {
            in[x]--;
            if (in[x] == 0)
            {
                q.push(x);
            }
        }
    }

    for (auto x: res)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
       // adj[y].push_back(x);
       // in[x]++;
        in[y]++;
    }
    kahn(n);
}
