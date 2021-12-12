### Topic name - GRAPHS
### Sub-topic - Finding Strongly Connected Components by Kosaraju's algorithm.
<br>
<br>
 ### <b><u><i>Comparison with undirected graph and explanation:</i></u></b>
<br>
<br>
You would already be knowing what a connected component means...But let's iterate it again for sake of completeness... In the undirected graph, a subgraph in which you can reach every node from every other node, that subgraph is termed as a single connected component. The image below illustrates this effectively.

<br>
 
![image](https://user-images.githubusercontent.com/62798923/144748067-47ff5d30-bb12-45b6-9730-e7332e9d6b64.png)

<br>

But, in the case of directed graphs things are not that      
straightforward, as you may be having an edge from a---->b but not from   b---->a.
So, a subgraph in a directed graph is termed as a strongly connected component if you can reach every other node from any node in that subgraph.
An image here illustrated this beautifully.
<br>
 
![image](https://user-images.githubusercontent.com/62798923/144748067-47ff5d30-bb12-45b6-9730-e7332e9d6b64.png)

<br>
Here you could see that in component –>(A, B, C, D) you can reach every other node from every node and similarly in component →(F, G, H) but not to one another. So, these 2 subgraphs are termed SCC's.
<br>
<br>
Now, for finding connected components in an undirected graph you could simply run aDFS, but to find SCC it may not be sufficient as ultimately you could reach other nodes also which are not a part of SC.
Like from the above image you could see that if you start DFSfrom A you would cover F,G, and H also, but they are not part of SCC’s. But if you start your DFS from F you would traverse only F, G, H and then after that doing from A you would cover A, B, C, and D which should be our answer. So, we found out that we need to somehow smartly do DFS so that it solves our purpose.
<br>
<br>
Now, as we know from the definition in an SCC if there exists a path from A to B then if we reverse all the edges then conditions should be satisfied. We would use this property only and define an order for DFS traversal by storing all nodes in a stack after their DFS traversal is completed in a normal DFS. This way we ensured that after reversing all the edges when we would do DFS by taking out nodes from the stack it would be ensured that after completing traversal from that node all the nodes lying in that SCC would come to us and only those would come as the stack is maintained like that only.
<br>
<br>
<b><u><i>Algorithm Detailed Explanation</i></u></b>
<br>
<br>

#### 1. Perform a normal DFS traversal on the graph and push nodes in the stack before and after completing its traversal and before returning from that node.
 <br>
 
 ![image](https://user-images.githubusercontent.com/62798923/144748067-47ff5d30-bb12-45b6-9730-e7332e9d6b64.png)

Suppose we have this graph and after traversal, we get a stack like this.

<br>
 2. Then make a transposed graph with the same nodes and all directions reversed.
 <br>
 
 ![image](https://user-images.githubusercontent.com/62798923/144748067-47ff5d30-bb12-45b6-9730-e7332e9d6b64.png)

<br>

3. After that use nodes from the stack, one by one and do DFS in the reversed graph and pop the nodes after they are visited.

<br>
<b>Now performing DFS as per the stack we see that we would get SCC’s as follows:</b>
<br>
1. 7
<br>
2. 6 5 4
<br>
3. 3
<br>
4. 2 1 0
<br>
And hence our algorithm completes and provides us desired answer.
<br>
<br>
<b><u><i>Explanation and Code</i></u></b>
<br>
<br>
Now, let’s see a question:
<br>
Q.You are given a directed graph, find : <b><i>SIGMA F(i,j) for all i,j where j>i.</i></b> <b>where <i> F(i,j)</i> gives us profuct of size of ith SCC multiplied by jth SCC.
<br>
Constraints: 1<=N<=1,00,000 and 0<=M<=1,00,000 where N is number of nodes and M is number of edges.
<br>
Example: Suppose you have SCC’s of size 2,3,4 then ans=(2*3+2*4+3*4)=26
<br>
<b><u>Solution:</u></b>
<br>
<b>You just need to firstly find size of all SCC’s by Kosaraju’s algo and then after that maintain a prefix array and do: size[i]*(prefix_sum[total num of SCC’s]-prefix_sum[i]) for all i from 1 to n where n is total number of SCC’s.</b>
<br>
<b><u>Implementation</u></b>

<br>

```
/* Aman Agrawal */

#include <bits/stdc++.h>
#define int long long
using namespace std;
#define Y cout << "YES" \
               << "\n"
#define N cout << "NO" \
               << "\n"
#define pb push_back
#define endl "\n"
#define lowestbit(x) __builtin_ffs(x)           //returns 1+index of(lowest bit)
#define numberofbits(x) __builtin_popcountll(x) //returns number of set bits
#define highestbit(x) __builtin_clz(x)          //returns number of 0's to left of MST
#define is(x) cerr << #x << " is " << x << "\n";
#define full(v1) v1.begin(), v1.end()
#define loop(i, a, b) for (int i = (a); i < (b); i++)
vector<int> adj[100001];
vector<int> rev[100001];
vector<int> sz; //stores size of all SCC's
vector<int> scc;
int ct;
int n;
stack<int> st;
bool vis[100001];
void dfs(int s)
{
    vis[s] = 1;
    for (auto i : adj[s])
    {
        if (!vis[i])
            dfs(i);
    }
    //Traversal os s gets completed so add into the stack before returning.
    st.push(s);
}
void rev_graph()
{
    loop(i, 1, n + 1)
    {
        for (auto j : adj[i])
        {
            rev[j].pb(i);
        }
    }
}
void final_dfs(int s)
{
    scc.pb(s);
    vis[s] = 1;
    for (auto i : rev[s])
    {
        if (!vis[i])
            final_dfs(i);
    }
}
void findans()
{
    int m = sz.size();
    int pre[m + 1] = {0};
    loop(i, 1, m + 1)
        pre[i] = pre[i - 1] + sz[i];
    int ans = 0;
    loop(i, 1, m + 1)
        ans += (sz[i] * (pre[m] - pre[i]));
    cout <<"Ans = "<<ans;
}
void solve()
{
    int i, j, t, q, a, b, m, k, ct = 0, sum = 0, flag = 0;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    loop(i, 1, n + 1)
    {
        if (!vis[i])
            dfs(i);
    }
    //resetting visited array;
    memset(vis, 0, sizeof(vis));
    rev_graph();
    //To make sz vector 1 indexed;
    sz.pb(0);
    while (!st.empty())
    {
        i = st.top();
        if (!vis[i])
        {
            final_dfs(i);
            sz.pb(scc.size());
            for (auto j : scc)
            {
                 cout << j << " ";
            }
            cout<<endl;
            scc.clear();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }
    //Here our main SCC code gets completed, below function is to solve the given problem.
    findans();
}
signed main()
{
    //freopen("lineup.in","r",stdin);
    //freopen("lineup.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
        cout << "\n";
    }

    cerr << clock() * 1000.0 / CLOCKS_PER_SEC << 'm' << 's';
    return 0;
}
```
<br>
<b><u>Practice Problems: (Sorted in increasing order of difficulty)</u></b>
<br>
<br>
https://www.spoj.com/problems/LEGO/
<br>
https://cses.fi/problemset/task/1683/
<br>
https://cses.fi/problemset/task/1686/
<br>
https://codeforces.com/contest/22/problem/E



