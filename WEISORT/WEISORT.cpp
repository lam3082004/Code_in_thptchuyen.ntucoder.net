// Cho dãy số nguyên dương gồm 𝑛 phần tử 𝑎1, 𝑎2, … , 𝑎𝑛.
// Cho dãy số nguyên dương 𝑝1, 𝑝2, … , 𝑝𝑚 đôi một khác nhau trong đó 𝑝𝑖 được xem như là một vị trí
// trên dãy 𝐴.
// Trong một thao tác, bạn có thể chọn một vị trí 𝑖 ∈ [1, 𝑚] bất kì và thực hiện 𝑠𝑤𝑎𝑝(𝑎𝑝𝑖
// , 𝑎𝑝𝑖+1
// ).
// Lưu ý rằng bạn có thể lựa chọn mỗi vị trí 𝑖 ∈ [1, 𝑚] với số lần tùy thích và thời điểm tùy thích.
// Yêu cầu: Bạn hãy kiểm tra xem có thể sắp xếp dãy 𝐴 thành dãy không giảm với dãy [𝑝1, 𝑝2, … , 𝑝𝑚]
// cho trước hay không? Nếu có in ra 𝑌𝐸𝑆, ngược lại in ra 𝑁𝑂.
// Input:
//  Dòng đầu chứa số nguyên dương 𝑡 (𝑡 ≤ 100) − số lượng testcase.
//  Mỗi bộ test trong 𝑡 bộ tiếp theo gồm:
// o Dòng đầu chứa hai số nguyên dương 𝑛, 𝑚 (1 ≤ 𝑚 < 𝑛 ≤ 100).
// o Dòng thứ hai chứa 𝑛 số nguyên dương 𝑎1, 𝑎2, … , 𝑎𝑛
// (𝑎𝑖 ≤ 100).
// o Dòng thứ ba chứa 𝑚 số nguyên dương 𝑝1, 𝑝2, …, 𝑝𝑚 (𝑝𝑖 < 𝑛).
// Output: Gồm 𝑡 dòng, mỗi dòng gồm 𝑌𝐸𝑆 hoặc 𝑁𝑂 trả lời cho bộ test tương ứng
#include <bits/stdc++.h>
#define l2 long long
using namespace std;
l2 t, n, p, a[105], m;
bool P[105];
bool check()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < n; j++)
        {
            if (a[j] > a[j + 1])
            {
                if (P[j] == false)
                    return false;
                swap(a[j], a[j + 1]);
            }
        }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(P, false, sizeof(P));
        for (int i = 1; i <= m; i++)
        {
            cin >> p;
            P[p] = true;
        }

        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
