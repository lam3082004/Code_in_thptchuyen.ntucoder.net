// Một số chắc chắn có thể phân tích thành tổng của không quá 4 bình phương của các số nguyên dương
#include <bits/stdc++.h>
using namespace std;
long long Q = 0;
int S;
int main()
{
    int n;
    //freopen("SQR4.inp","r",stdin);
    //freopen("SQR4.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i * i <= n; ++i)
    {
        for (int j = i; j * j <= n; ++j)
        {
            for (int k = j; k * k <= n; ++k)
            {
                S = n - i * i - j * j - k * k;
                if (S >= k * k)
                {
                    int tmp = sqrt(S);
                    if (tmp * tmp == S)
                    {
                        ++Q;
                    }
                }
            }
        }
    }
    cout << Q;

    return 0;
}
