// Cho tập hợp 𝑆 gồm 𝑛 đoạn [𝑙1, 𝑟1
// ],[𝑙2, 𝑟2
// ], … , [𝑙𝑛, 𝑟𝑛
// ].
// Định nghĩa hàm 𝐺(𝑥) với 𝑥 là một giá trị nguyên dương là số lượng đoạn [𝑙𝑖
// , 𝑟𝑖
// ] (trong tập hợp 𝑆)
// chứa 𝑥. Hay nói cách khác 𝐺(𝑥) là số lượng đoạn [𝑙𝑖
// , 𝑟𝑖
// ] trong tập hợp 𝑆 mà 𝑙𝑖 ≤ 𝑥 ≤ 𝑟𝑖
// .
// Cho số nguyên dương 𝑘.
// Yêu cầu: Hãy xóa khỏi tập hợp 𝑆 ít đoạn nhất sao cho 𝐺(𝑥) ≤ 𝑘 (∀𝑥 ∈ 𝑁∗).
// Input:
//  Dòng đầu tiên chứa hai số nguyên dương 𝑛 và 𝑘 (1 ≤ 𝑘 ≤ 𝑛 ≤ 2.105).
//  Trong 𝑛 dòng tiếp theo, dòng thứ 𝑖 gồm hai số nguyên dương 𝑙𝑖 và 𝑟𝑖
// (1 ≤ 𝑙𝑖 ≤ 𝑟𝑖 ≤ 2.105).
// Output:
//  Dòng đầu chứa số nguyên 𝑚 (0 ≤ 𝑚 ≤ 𝑛) − số lượng đoạn ít nhất cần xóa.
//  Dòng thứ hai chứa 𝑚 chỉ số phân biệt 𝑝1, 𝑝2, … , 𝑝𝑚 (1 ≤ 𝑝𝑖 ≤ 𝑛) − là vị trí của các đoạn
// cần xóa đi. Nếu có nhiều bộ (𝑝1, 𝑝2, … , 𝑝𝑚) thỏa mãn, hãy in ra một bộ bất kì.
#include <bits/stdc++.h>
#define ll long long
#define II pair<int, int>
#define fi first
#define se second
#define task "test"
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n, k, N, p;
int l[200001];
int r[200001];
II c[400001], t;
vector<int> res;
set<II, greater<II>> S;

void Solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
        if (l[i] > r[i])
            swap(l[i], r[i]);
        c[++N] = {l[i], i};
        c[++N] = {r[i] + 1, -i};
    }
    sort(c + 1, c + N + 1);
    for (int i = 1; i <= N; ++i)
    {
        //cout<<c[i].fi<<' '<<c[i].se<<'\n';
        if (c[i].se > 0)
        {
            p = c[i].se;
            S.insert({r[p] + 1, -p});
            if (S.size() > k)
            {
                //cout<<i<<endl;
                t = *S.begin();
                res.push_back(-t.se);
                S.erase(t);
            }
        }
        else
            S.erase(c[i]);
    }

    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
}

int main()
{
    Init();
    Solve();
}
