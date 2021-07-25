// Yêu cầu:

// Cho một hình chữ nhật a × b, nhiệm vụ của bạn là cắt nó thành các hình vuông. Mỗi bước, bạn có thể chọn một hình chữ nhật và cắt nó thành hai hình chữ nhật sao cho tất cả độ dài các cạnh là số nguyên. Số bước tối thiểu để thu về các hình vuông là bao nhiêu?

// Input: Một dòng duy nhất chứa 2 số nguyên dương a,b. (1≤a,b≤500).

// Output: Số bước tối thiểu để thỏa mãn đề bài.
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b, f[505][505];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
                f[i][j] = 0;
            else if (i == 1)
                f[i][j] = j - 1;
            else if (j == 1)
                f[i][j] = i - 1;
            else
            {
                f[i][j] = 1e9;
                for (int k = 1; k < j; k++)
                    f[i][j] = f[j][i] = min(f[i][j], f[i][k] + f[i][j - k] + 1);
                for (int k = 1; k < i; k++)
                    f[i][j] = f[j][i] = min(f[i][j], f[k][j] + f[i - k][j] + 1);
            }
        }
    }
    cout << f[a][b];
}
