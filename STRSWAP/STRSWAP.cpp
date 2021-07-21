// Cho một xâu vòng tròn, các kí tự thuộc tập [A, B, C]. Mỗi lượt được đổi chỗ 2 kí tự bất kì.
// Yêu cầu: Tính số phép đổi chỗ ít nhất để đưa các kí tự giống nhau liền kề nhau.
// Input
// - Gồm một dòng chứa một xâu môt tả xâu vòng tròn.
// Output
// - Ghi ra một số nguyên là số phép đổi chỗ ít nhất cần thực hiện.
#include <bits/stdc++.h>

#define pb(a) push_back(a)

using namespace std;

const int oo = 100000000;

string s;
vector<int> a[3];
int res = oo, n;
int x[3];
int dem[3], chk[3];

void cnt()
{
    int tmp = 0;
    for (int i = 1; i <= dem[x[0]]; ++i)
    {
        tmp = dem[x[0]] - (a[x[0]][i] + (a[x[0]][n] - a[x[0]][n - (dem[x[0]] - i)]));

        int xb, ta, tc;

        xb = a[x[1]][i] + a[x[1]][n] - a[x[1]][n - dem[x[0]] + i];

        ta = a[x[0]][i + dem[x[1]]] - a[x[0]][i];
        tc = a[x[2]][i + dem[x[1]]] - a[x[2]][i];

        tmp += tc + (xb >= ta ? 0 : ta - xb);
        // tp = dem[x[1]] - (a[x[1]][i + dem[x[1]]] - a[x[1]][i]);
        // tmp += dem[x[2]] - (a[x[2]][i + dem[x[1]] + dem[x[2]]] - a[x[2]][i + dem[x[1]]]);
        res = min(res, tmp);
    }
}

void backtrack(int i)
{
    if (i == 3)
    {
        cnt();
        return;
    }
    for (int j = 0; j < 3; ++j)
        if (chk[j] == 0)
        {
            x[i] = j;
            chk[j] = 1;
            backtrack(i + 1);
            chk[j] = 0;
        }
}
int main(int argc, char const *argv[])
{
    cin >> s;
    n = s.length();
    for (int i = 0; i < 3; ++i)
        a[i].pb(0);
    dem[0] = dem[1] = dem[2] = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        dem[(int)s[i] - 'A']++;
        for (int j = 0; j < 3; ++j)
            a[j].pb(dem[j]);
    }
    chk[0] = chk[1] = chk[2] = 0;
    backtrack(0);
    cout << res;
    return 0;
}
