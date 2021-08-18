#include <bits/stdc++.h>
#define ll long long
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define nmax 1005
using namespace std;
char a[nmax][nmax];
string s;
int m, n, k, dem1 = 1e9, t = 0, z = 0;
int x[nmax], y[nmax];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("l.inp", "r", stdin);
    freopen("l.out", "w", stdout);
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    cin >> s;
    fo(i, 1, m)
    {
        fo(j, 1, n)
        {
            cin >> a[i][j];
        }
    }
    //    cout<<a[1][1]<<' '<<a[1][2];
    fo(i, 1, m)
    {
        fo(j, 1, n)
        {
            if (a[i][j] == s[0])
            {
                x[++t] = i;
                y[++z] = j;
            }
        }
    }
    //    cout<<x[1]<<' '<<y[1];
    int i = 1;
    while (i <= t)
    {

        int dem = 1;
        int j = 1;
        int a1 = x[i];
        int a2 = y[i];
        //        cout<<a1<<' '<<a2;
        //        cout<<a[a1+1][a2];
        while (j <= s.size() - 1)
        {
            if (s[j] == a[a1][a2 + 1])
            {
                j++;
                dem++;
                a1 = a1;
                a2++;
                //                cout<<dem;
                //                break;
            }
            else if (s[j] == a[a1 + 1][a2])
            {
                j++;
                dem++;
                a1++;
                a2 = a2;
                //            cout<<a[a1][a2];
                //            break;
            }
            else if (s[j] == a[a1 - 1][a2])
            {
                j++;
                dem++;
                a1--;
                a2 = a2;
            }
            else if (s[j] == a[a1][a2 - 1])
            {
                j++;
                dem++;
                a2--;
                a1 = a1;
                ////                cout<<dem;
                //                return 0;
            }
            else
            {
                dem++;
                a1 = a1;
                a2++;
                if (s[j] == a[a1][a2 + 1])
                {
                    j++;
                    dem++;
                    a1 = a1;
                    a2++;
                    //                cout<<dem;
                    //                break;
                }
                else if (s[j] == a[a1 + 1][a2])
                {
                    j++;
                    dem++;
                    a1++;
                    a2 = a2;
                    //            cout<<a[a1][a2];
                    //            break;
                    //                    cout<<dem<<' ';
                    //                    cout<<a1<<' '<<a2;
                    //                    return 0;
                }
                else if (s[j] == a[a1 - 1][a2])
                {
                    j++;
                    dem++;
                    a1--;
                    a2 = a2;
                }
                else if (s[j] == a[a1][a2 - 1])
                {
                    j++;
                    dem++;
                    a2++;
                    a1 = a1;
                }
                else
                {
                    dem++;
                    a2 = a2;
                    a1--;
                    if (s[j] == a[a1][a2 + 1])
                    {
                        j++;
                        dem++;
                        a1 = a1;
                        a2--;
                        //                cout<<dem;
                        //                break;
                    }
                    else if (s[j] == a[a1 + 1][a2])
                    {
                        j++;
                        dem++;
                        a1++;
                        a2 = a2;
                        //            cout<<a[a1][a2];
                        //            break;
                    }
                    else if (s[j] == a[a1 - 1][a2])
                    {
                        j++;
                        dem++;
                        a1--;
                        a2 = a2;
                    }
                    else if (s[j] == a[a1][a2 - 1])
                    {
                        j++;
                        dem++;
                        a2--;
                        a1 = a1;
                    }
                    else
                    {
                        dem++;
                        a1++;
                        a2 = a2;
                        //     if (s[j] == a[a1][a2 + 1])
                        //     {
                        //         j++;
                        //         dem++;
                        //         a1 = a1;
                        //         a2++;
                        //         //                cout<<dem;
                        //         //                break;
                        //     }
                        //     else if (s[j] == a[a1 + 1][a2])
                        //     {
                        //         j++;
                        //         dem++;
                        //         a1++;
                        //         a2 = a2;
                        //         //            cout<<a[a1][a2];
                        //         //            break;
                        //     }
                        //     else if (s[j] == a[a1 - 1][a2])
                        //     {
                        //         j++;
                        //         dem++;
                        //         a1--;
                        //         a2 = a2;
                        //     }
                        //     else if (s[j] == a[a1][a2 - 1])
                        //     {
                        //         j++;
                        //         dem++;
                        //         a2--;
                        //         a1 = a1;
                        //     }
                        //     else
                        //     {

                        //         dem++;
                        //         a1 = a1;
                        //         a2--;
                        //         if (s[j] == a[a1][a2 + 1])
                        //         {
                        //             j++;
                        //             dem++;
                        //             a1 = a1;
                        //             a2++;
                        //             //                cout<<dem;
                        //             //                break;
                        //         }
                        //         else if (s[j] == a[a1 + 1][a2])
                        //         {
                        //             j++;
                        //             dem++;
                        //             a1++;
                        //             a2 = a2;
                        //             //            cout<<a[a1][a2];
                        //             //            break;
                        //         }
                        //         else if (s[j] == a[a1 - 1][a2])
                        //         {
                        //             j++;
                        //             dem++;
                        //             a1--;
                        //             a2 = a2;
                        //         }
                        //         else if (s[j] == a[a1][a2 - 1])
                        //         {
                        //             j++;
                        //             dem++;
                        //             a2--;
                        //             a1 = a1;
                        //         }
                        //         else
                        //         {
                        //             j++;
                        //             dem++;
                        //             a2++;
                        //             a1 = a1;
                        //         }
                        //     }
                    }
                }
            }
            if (j == s.size() - 1)
            {
                i++;
                dem1 = min(dem1, dem);
            }
        }
    }
    cout << dem1;
}
