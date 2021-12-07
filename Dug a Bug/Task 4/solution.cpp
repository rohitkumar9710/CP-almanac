#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long a, b;
    cin >> a >> b;
    long long sum = a + b;
    long long n = sqrt(2 * sum);
    if (n * (n + 1) > 2 * sum)
    {
        n--;
    }
    if (a <= b)
    {
        set<long long> s;
        vector<long long> v1, v2;
        long long p = n;
        while (a > 0)
        {
            if (a <= p)
            {
                v1.push_back(a);
                a = 0;
                s.insert(p);
                p--;
            }
            else
            {
                v1.push_back(p);
                a -= p;
                s.insert(p);
                p--;
            }
        }
        cout << v1.size() << endl;
        for (long long i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
        cout << n - v1.size() << endl;
        for (long long i = 1; i <= n; i++)
        {
            if (s.find(i) == s.end())
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    else
    {
        set<long long> s;
        vector<long long> v1, v2;
        long long p = n;
        while (b > 0)
        {
            if (b <= p)
            {
                v1.push_back(b);
                b = 0;
                s.insert(p);
                p--;
            }
            else
            {
                v1.push_back(p);
                b -= p;
                s.insert(p);
                p--;
            }
        }
        cout << n - v1.size() << endl;
        for (long long i = 1; i <= n; i++)
        {
            if (s.find(i) == s.end())
            {
                cout << i << " ";
            }
        }
        cout << endl;
        cout << v1.size() << endl;
        for (long long i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << endl;
    }
}