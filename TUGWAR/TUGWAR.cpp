// Anh Kiên cùng với N người bạn của mình cùng nhau chơi trò chơi Kéo co, trò chơi dành cho N + 1 người tham gia.Mỗi người có một lượng sức mạnh là một số nguyên dương.Trò chơi có N + 1 hiệp đấu, mỗi hiệp sẽ có một người đứng ra làm trọng tài cho N người còn lại được chia làm 2 đội để chơi mà mỗi người chỉ thuộc một đội và mỗi đội đều có tổi thiểu một người.Mỗi người chỉ được làm trọng tại đúng một hiệp duy nhất.Một hiệp đấu được gọi là hoà nếu tổng số sức mạnh của hai đội bằng nhau.Và toàn bộ trận đấu sẽ được gọi là vui vẻ nếu tất cả các hiệp đều có kết quả hoà.Anh Kiên biết được chỉ số sức mạnh của N người bạn của mình và anh có thể cho mình một chỉ số sức mạnh bất kì.Anh Kiên muốn biết là mình cần chỉ số sức mạnh là bao nhiêu để có thể có được một trận đấu vui vẻ.Dữ liệu
// • Dòng đầu tiên chứ số nguyên N là số người bạn của anh Kiên.
// • Dòng thứ hai gồn N số nguyên dương ai là chỉ số sức mạnh của người bạn thứ i của anh Kiên.Kết quả
// • Dòng đầu tiên ghi ra số nguyên dương T - số lượng chỉ số sức mạnh anh Kiên có thể có để đạt được một trận đấu vui vẻ.
// • Dòng thứ hai ghi ra T số nguyên dương là các chỉ số sức mạnh thoã mãn theo thứ tự tăng dần
#include <bits/stdc++.h>
using namespace std;
const int MAX = 500 * 506;
unsigned long long n, f[MAX], ch[MAX + 500 * 20], F[MAX], a[506];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("TUGWAR.inp","r",stdin);
    int k, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= a[i]; j--)
        {
            f[j] += f[j - a[i]];
        }
    }
    //for(int i=1;i<=s;i++)cout<<f[i]<<'\n';
    if (s % 2 != 0 || f[s / 2] == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int S = s - a[i];

        memset(F, 0, sizeof F);
        for (int j = a[i]; j <= s; j++)
        {
            F[j] = f[j - a[i]] - F[j - a[i]];
        }
        for (int j = (S + 1) / 2; j <= s; j++)
        {
            if (f[j] != F[j])
            {
                ch[2 * j - S]++;
            }
        }
    }

    vector<int> res;
    for (int i = 0; i <= s; i++)
    {
        if (ch[i] == n)
            res.push_back(i);
    }
    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
}
