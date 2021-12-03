#include <bits/stdc++.h>
using namespace std;

long long x;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b >> x;
        if (a == x || b == x)
        {
            cout << "YES" << endl;
            continue;
        }

        if (a < b)
        {
            swap(a, b);
        }
        long long diff = a - b;
        if (x >= a)
        {
            cout << "NO" << endl;
            continue;
        }
        bool flag = 0;
        while (true)
        {
            if (x >= diff && (a - x) % diff == 0)
            {
                cout << "YES" << endl;
                flag = 1;
                break;
            }
            if (x >= a)
            {
                break;
            }
            a = a - (((a - diff) / diff) * diff);
            b = diff;
            diff = a - b;
        }
        if (flag == 0)
        {
            cout << "NO" << endl;
        }
    }
}