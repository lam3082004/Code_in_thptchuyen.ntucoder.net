// Cho xâu 𝑠 chỉ gồm các chữ cái latinh thường từ 𝑎 đến 𝑡 (20 chữ cái).
// Với một thao tác xoay bạn có thể chọn một đoạn 𝑠𝑙𝑠𝑙+1 … 𝑠𝑟 (1 ≤ 𝑙 < 𝑟 ≤ 𝑛) và đảo ngược đoạn
// đó tức là thay thể bởi 𝑠𝑟𝑠𝑟−1 … 𝑠𝑙
// .
// Giá trị niềm tin của một xâu được định nghĩa là độ dài lớn nhất của đoạn con chỉ gồm các chữ cái
// phân biệt.
// Yêu cầu: Bạn hãy thực hiện xoay nhiều nhất một lần trên xâu 𝑠 để giá trị niềm tin của xâu 𝑠 đạt
// giá trị lớn nhất. In ra giá trị đó.
// Input: Gồm một dòng duy nhất chứa xâu 𝑠 (|𝑠| ≤ 105).
// Output: In ra kết quả bài toán
#include <bits/stdc++.h>
#define ll long long
#define task "test"
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string s;
int n;
int a[100001];
int F[1048576];
int P[21];

void convex()
{
    for (int i = 0; i < s.size(); ++i)
    {
        a[++n] = s[i] - 'a';
        //cout<<a[n]<<' ';
    } //cout<<'\n';
}

string See(int x)
{
    string res = "";
    for (int i = 1; i <= 20; ++i, x >>= 1)
        res += (char)(x % 2 + '0');
    return res;
}

void Solve()
{
    P[0] = 1;
    for (int i = 1; i <= 20; ++i)
        P[i] = P[i - 1] * 2;
    cin >> s;
    convex();
    for (int i = 1; i <= n; ++i)
        for (int j = i, mask = 0; j >= 1; mask = mask + P[a[j]], --j)
            if ((mask & P[a[j]]) == 0)
            {
                F[mask + P[a[j]]] = max(F[mask + P[a[j]]], i - j + 1);
            }
            else
                break;

    for (int i = 0; i < 20; ++i)
        for (int mask = 0; mask < P[20]; ++mask)
            if ((mask & P[i]) == 0)
                F[mask + P[i]] = max(F[mask + P[i]], F[mask]);

    int res = 0;
    for (int mask = 0; mask < P[20]; ++mask)
    {
        int s = F[mask] + F[(P[20] - 1) - mask];
        res = max(res, s);
    }
    cout << res;
}

int main()
{
    Init();
    Solve();
}
