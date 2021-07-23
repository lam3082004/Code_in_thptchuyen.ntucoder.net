//
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1515;

int m, n, k;
int d[MAXN][MAXN], f[MAXN][MAXN], g[MAXN][MAXN], s[MAXN][MAXN], row[MAXN][MAXN], col[MAXN][MAXN];

int sum(int i, int j)
{
    return s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k];
}

void print_arr(int arr[MAXN][MAXN])
{
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }

    for (int i = k; i <= m; i++)
        for (int j = k; j <= n; j++)
        {
            int cur = sum(i, j);
            d[i][j] = max(max(d[i - 1][j], d[i][j - 1]), cur);
            row[i][j] = max(cur, row[i][j - 1]);
            col[i][j] = max(cur, col[i - 1][j]);
        }

    //print_arr(h);

    for (int i = k; i <= m; i++)
        for (int j = k; j <= n; j++)
        {
            f[i][j] = max(max(f[i - 1][j], f[i][j - 1]), max(d[i][j - k] + col[i][j], d[i - k][j] + row[i][j]));
        }

    memset(d, 0, sizeof(d));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    for (int i = m - k + 1; i >= 1; i--)
        for (int j = n - k + 1; j >= 1; j--)
        {
            int cur = sum(i + k - 1, j + k - 1);
            d[i][j] = max(max(d[i + 1][j], d[i][j + 1]), cur);
            row[i][j] = max(cur, row[i][j + 1]);
            col[i][j] = max(cur, col[i + 1][j]);
        }

    for (int i = m - k + 1; i >= 1; i--)
        for (int j = n - k + 1; j >= 1; j--)
        {
            g[i][j] = max(max(g[i + 1][j], g[i][j + 1]), max(d[i][j + k] + col[i][j], d[i + k][j] + row[i][j]));
        }

    int ans = 0;
    for (int i = k; i <= m; i++)
        for (int j = k; j <= n; j++)
        {
            int cur = sum(i, j);
            ans = max(ans, f[i - k][n] + cur);
            ans = max(ans, f[m][j - k] + cur);
            ans = max(ans, g[i + 1][1] + cur);
            ans = max(ans, g[1][j + 1] + cur);
        }

    cout << ans;
}
