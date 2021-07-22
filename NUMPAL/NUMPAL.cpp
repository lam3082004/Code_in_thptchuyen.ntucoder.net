// Cho hai số A, B. Đếm số các số x thoả mãn
//  A ≤ x ≤ B
//  Nếu coi x là một xâu, không tồn tại một xâu con nào của x có độ dài lớn hơn 1 và đối xứng
// Input:
//  Một dòng duy nhất là hai số nguyên A, B
// Output:
//  Một dòng duy nhất là số lượng số cần tìm
// Giới hạn:
//  1 ≤ A ≤ B ≤ 1018
//  50% số test có 1 ≤ A ≤ B ≤ 105
#include <bits/stdc++.h>
using namespace std;
const int nmax = 25;
string A, B, s;
int pos, n;
long long dp[nmax][11][11][2];
long long f(int i, int j, int k, bool c, bool c2)
{
    if (i == s.size() - 1)
        return c2;
    long long &res = dp[i][j][k][c];
    if (res != -1)
        return res;
    res = 0;
    if (c == 0)
    {
        for (int t = 0; t <= 9; t++)
            if (t != j && t != k)
                if (c2 == 0 && t == 0)
                    res += f(i + 1, 10, 10, 0, 0);
                else
                    res += f(i + 1, k, t, 0, 1);
    }
    else
    {
        for (int t = 0; t < s[i + 1] - '0'; t++)
            if (t != j && t != k)
            {
                if (c2 == 0 && t == 0)
                    res += f(i + 1, 10, 10, 0, 0);
                else
                    res += f(i + 1, k, t, 0, 1);
            }
        if (s[i + 1] - '0' != j && s[i + 1] - '0' != k)
            res += f(i + 1, k, s[i + 1] - '0', 1, 1);
    }
    return res;
}
long long get(string P)
{
    if (P.size() == 1)
        return P[0] - '0';
    s = " " + P;
    memset(dp, -1, sizeof dp);
    return f(0, 10, 10, 1, 0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    pos = A.size() - 1;
    while (A[pos] == '0')
        pos--;
    A[pos]--;
    for (int i = pos + 1; i < A.size(); i++)
        A[i] = '9';
    if (A.size() > 1 && A[0] == '0')
        A.erase(0, 1);
    cout << get(B) - get(A);
}
