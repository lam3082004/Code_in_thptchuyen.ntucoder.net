// Hiện tại soái ca TA đang bận tâm tới rất nhiều vấn đề trong cuộc sống. Nhưng do là người không thích sống ảo nên TA rất quan tâm tới việc mình có nổi tiếng trên mạng xã hội không. Độ quan tâm của người khác với mình thì TA lấy giá trị |x-a| với x là giá trị của người đó và a là giá trị của bản thân TA. Anh ta có thể thay đổi giá trị bản thân nên muốn tính toán với một giá trị bản thân xác định thì trong phạm vi cho trước độ nổi tiếng anh ấy là bao nhiêu? Biết độ nổi tiếng là tổng các độ quan tâm của người khác trong phạm vi. Ngoài ra TA là 1 người không được chỉn chu nên anh ta sẽ sắp xếp sẵn dãy số để lúc bạn tính toán không bị rối (TA tốt không? smiley)

// Dữ liệu vào:

// Dòng đầu tiên là 1 số nguyên dương n (n ≤ 106).
// Dòng thứ 2 gồm n số nguyên a1,a2,… an (ai≤109).
// Dòng thứ 3 là một số t (t≤106).
// t dòng tiếp theo gồm 3 số l,r,x(l≤x≤r) – phạm vi quan tâm từ l -> r và giá trị bản thân TA là ax.
// Dữ liệu ra:

// t dòng tương ứng là độ nổi tiếng của TA trong phạm vi l -> r.
// Cho n phần tử. Có q truy vấn l,r,x tính tổng |al-ax| + |al+1-ax| + …  + |ar-ax|
#include <bits/stdc++.h>
#define maxn 1000006
#define F first
#define S second
#define pii pair<int, int>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define Task ""
using namespace std;
int a[maxn];
long long s[maxn];
int n, t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //   freopen(Task".inp","r",stdin);
    //    freopen(Task".out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    cin >> t;
    long long ans;
    while (t--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        ans = 1ll * a[x] * (x - l + 1) - (s[x] - s[l - 1]) + (s[r] - s[x - 1]) - 1ll * a[x] * (r - x + 1);
        cout << ans << '\n';
    }
    return 0;
}
