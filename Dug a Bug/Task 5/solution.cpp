#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    map<string, int> m;
    int d = 0, mo = 0, y =0, ans = 0; // y is unused
    string res="";
    for (int i = 0; i <= n - 10; i++) // i should run till i<=n-10
    {
        d=0,mo=0;
        if (s[i] - '0' >= 0 && s[i + 1] - '0' >= 0)
        {
            d += (s[i] - '0');
            d *= 10;
            d += (s[i + 1] - '0');
            if (d > 0)
            {
                if (s[i + 2] == '-' && s[i + 5] == '-') // i+2 and i+5 should be used here
                {
                    if ((s[i + 3] - '0' >= 0 && s[i + 4] - '0' >= 0))
                    {
                        mo += (s[i + 3] - '0');
                        mo *= 10;
                        mo += (s[i + 4] - '0');
                        if (mo <= 12 && mo >= 1)
                        {
                        	
                            if ((d <= 31 && (mo == 1 || mo == 3 || mo == 5 || mo == 7 || mo == 8 || mo == 10 || mo == 12)) || (d <= 28 && mo == 2) ||(d <= 30)) // proper paranthesis with correct usage of && and || 
                            
                            {

                                if (s[i + 6]== '2' && s[i + 7]== '0' && s[i + 8]== '1' && (s[i + 9]>= '3' && s[i + 9] <= '5')) // proper paranthesis and using number as literal i.e s[i+6] == '2' and not s[i+6]==2
                                {
                                    string st = "";
                                    st += s[i];
                                    st += s[i + 1];
                                    st += s[i + 2];
                                    st += s[i + 3];
                                    st += s[i + 4];
                                    st += s[i + 5];
                                    st += s[i + 6];
                                    st += s[i + 7];
                                    st += s[i + 8];
                                    st += s[i + 9];
                                    m[st]++;
                                    if (ans < m[st])
                                    {                                    
                                        res = st;
                                        ans = m[st];
                                       
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << res;
}
