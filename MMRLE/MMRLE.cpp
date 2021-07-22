// MMRLE
// Xét xâu S chỉ gồm các ký tự ‘a’ đến ’z’ được mã hoá thành xâu SE (chỉ gồm các ký tự ‘a’ đến
// ‘z’ và ký tự ‘0’ đến ‘9’) như sau: Đi từ trái qua phải, mã hoá dãy các ký tự liên tiếp bằng nhau
// trong S thành ký tự đại diện và số lượng. Độ dài các xâu mã hoá không vượt quá 1000.
// Ví dụ, xâu S=aaabbbbaaaaaaaaaaz thì SE=a3b4a10z1
// Yêu cầu: Cho xâu S được mã hoá thành SE và số nguyên k, hãy xoá bỏ k ký tự trong xâu S
// để nhận được xâu Smax có thứ tự từ điển lớn nhất, Smin nhỏ nhất. Đưa ra xâu mã hoá của Smin,
// Smax.
// Ví dụ: XE=b1a1b10, k=1 thì xâu mã hoá của Smax là b11, còn xâu mã hoá của Smin là a1b10
// Input
// - Dòng 1: chứa số nguyên k;
// - Dòng 2: chứa xâu SE là mã hóa của S.
// Output
// - Dòng 1: ghi Smax có thứ tự từ điển lớn nhất;
// - Dòng 2: ghi Smin có thứ tự từ điển nhỏ nhất.
#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

long long k;
char s[maxn];
int n;

template <typename T, typename U>
void solve(const T &s, U comp)
{
    long long k = ::k;
    T ans;
    for (auto &x : s)
    {
        while (ans.size() && k && comp(ans.back().first, x.first))
        {
            if (k >= ans.back().second)
            {
                k -= ans.back().second;
                ans.pop_back();
            }
            else
            {
                ans.back().second -= k;
                k = 0;
            }
        }
        if (ans.size() && x.first == ans.back().first)
        {
            ans.back().second += x.second;
        }
        else
        {
            ans.push_back(x);
        }
    }
    while (k >= ans.back().second)
    {
        k -= ans.back().second;
        ans.pop_back();
    }
    ans.back().second -= k;
    for (auto &x : ans)
    {
        printf("%c%lld", x.first, x.second);
    }
    putchar('\n');
}

int main()
{
    scanf("%lld", &k);
    scanf("%s", s);
    n = strlen(s);
    vector<pair<char, long long>> S;
    for (int i = 0, j = 0; i < n; i = j)
    {
        auto is_number = [](char x)
        { return x >= '0' && x <= '9'; };
        long long cnt = 0;
        while (is_number(s[++j]))
        {
            cnt = cnt * 10 + s[j] - '0';
        }
        S.push_back({s[i], cnt});
    }
    solve(S, less<char>());
    solve(S, greater<char>());
    return 0;
}
