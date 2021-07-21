// Cho một dãy hoán vị của 1 … 𝑛 : 𝑎1, 𝑎2, … , 𝑎𝑛. Mỗi bước chúng ta có thể chọn
// một đoạn liên tiếp trên dãy 𝑎, bốc nó ra khỏi vị trí ban đầu (Cut), chèn nó vào
// một vị trí bất kì trên dãy 𝑎 còn lại (Paste).
// Yêu cầu: Cho một hoán vị bất kì, hỏi số bước nhỏ nhất để sắp xếp hoán vị về
// một dãy tăng dần.
// Input
// - Dòng đầu chứa số nguyên dương 𝑡 là số test của bài toán.
// - 𝑡 cặp dòng tiếp theo có định dạng như sau:
// o Dòng đầu chứa 1 số nguyên dương 𝑛 là độ dài dãy hoán vị.
// o Dòng 2 chứa 𝑛 số nguyên dương biểu thị hoán vị.
// Output
// - 𝑡 dòng, mỗi dòng chứa một số nguyên biểu thị kết quả bài toán.
// Giới hạn: 0 < 𝑡 ≤ 10; 0 < 𝑛 < 10; 0 < 𝑎𝑖 ≤ 𝑛.
// Input
// 1
// 4
// 3 4 1 2
// Output
// 1
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

const int N = 10;
const int M = 600000;

int dist_s[M], dist_t[M];
queue<int> queue_s, queue_t;
int res = -1, n, test, sum = 0;
int de[N], ck[N];
vector<int> hv;

void backtrack(int i)
{
    if (i > n)
    {
        hv.push_back(sum);
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (ck[j] == 0)
        {
            sum += j * de[n - i];
            ck[j] = 1;
            backtrack(i + 1);
            sum -= j * de[n - i];
            ck[j] = 0;
        }
}

void init()
{
    de[0] = 1;
    memset(ck, 0, sizeof(ck));
    for (int i = 1; i < N; ++i)
        de[i] = de[i - 1] * 10;
}

void change_para(int i, int j, int k, int &a)
{
    int u, v, t, w;
    u = a / de[n - i + 1];
    v = (a / de[n - i - j + 1]) % de[j];
    t = (a / de[n - i - j - k + 1]) % de[k];
    w = a % de[n - i - j - k + 1];
    // printf("%d %d %d %d\n", u, v, t, w);
    a = u * de[n - i + 1] + t * de[n - i - k + 1] + v * de[n - i - j - k + 1] + w;
}

int get(int u)
{
    auto it = lower_bound(all(hv), u);
    return distance(hv.begin(), it);
}

void bfs(queue<int> *q, int *dist)
{
    int m = q->size();
    for (int i = 0; i < m; ++i)
    {
        int u = q->front();
        q->pop();
        for (int i = 1; i < n; ++i)
            for (int j = 1; j <= n - i; ++j)
                for (int k = 1; k <= n + 1 - i - j; ++k)
                {
                    int v = hv[u];
                    change_para(i, j, k, v);
                    v = get(v);
                    if (dist[v] < 0)
                        dist[v] = dist[u] + 1, q->push(v);
                }
    }
}

int bidirect(int s, int t)
{
    memset(dist_s, -1, sizeof(dist_s));
    memset(dist_t, -1, sizeof(dist_t));
    while (!queue_s.empty())
        queue_s.pop();
    while (!queue_t.empty())
        queue_t.pop();
    queue_s.push(get(s));
    queue_t.push(get(t));
    dist_s[get(s)] = 0, dist_t[get(t)] = 0;
    int res = 5;
    for (int i = 0; i < 2; ++i)
    {
        bfs(&queue_s, dist_s);
        bfs(&queue_t, dist_t);
        for (int j = 0; j < (int)hv.size(); ++j)
        {
            if (dist_s[j] >= 0 && dist_t[j] >= 0)
                res = min(res, dist_s[j] + dist_t[j]);
        }
        if (res < 5)
            return res;
    }
    return 5;
}

int main(int argc, char const *argv[])
{
    init();
    cin >> test;
    int s, t, u;
    while (test--)
    {
        cin >> n;
        s = t = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> u;
            s = s * 10 + u;
            t = t * 10 + i;
        }
        hv.clear();
        backtrack(1);
        cout << bidirect(s, t) << endl;
    }
    return 0;
}
