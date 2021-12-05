#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int q, a, b;

    set<int> s;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if ((arr[i - 1][j] == 'X') && (arr[i][j - 1] == 'X'))
            {
                s.insert(j + 1);
            }
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        auto it = s.upper_bound(a);
        if (it == s.end())
        {
            cout << "YES" << endl;
        }
        else if (*it <= b)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}
