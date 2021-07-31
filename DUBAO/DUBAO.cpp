// Thuở xa xưa, khi con người sống hài hòa với thiên nhiên, thời tiết rất ấm áp, không quá lạnh cũng
// không quá nóng. Theo thời gian, với công cuộc công nghiệp hóa, hiện đại hóa, thiên nhiên bị tàn phá
// nghiêm trọng do hiệu ứng nhà kính, do khí thải công nghiệp, do ô nhiễm môi trường... khí hậu cũng
// dần dần khắc nghiệt hơn, có những ngày thời tiết rất nóng và rất lạnh. Để đối phó với thời tiết khắc
// nghiệt đó con người tìm cách dự báo thời tiết. Ta gọi ngày lạnh giá là ngày có nhiệt độ dưới 0 độ C, T
// ngày lạnh giá liên tiếp giữa những ngày không lạnh giá gọi là một giai đoạn lạnh giá T. Theo tính toán
// thì ta có thể dự báo giai đoạn lạnh giá nhiều nhất 2T ngày trước khi nó diễn ra. Ngoại lệ, với giai đoạn
// lạnh giá độ dài T dài nhất thì có thể dự báo nhiều nhất 3T ngày trước khi nó bắt đầu. Nếu có nhiều
// giai đoạn lạnh giá cùng độ dài lớn nhất thì chỉ được chọn một giai đoạn theo quy tắc 3T. Trong những
// ngày lạnh giá thì không thể nói là dự báo cho những ngày lạnh giá này vì nó đang diễn ra, nhưng bạn
// có thể dự báo về giai đoạn lạnh giá trong tương lai theo quy tắc trên.
// Yêu cầu: Cho nhiệt độ N ngày (theo độ C) liên tiếp, tìm số ngày tối đa trong thời gian đó mà có thể dự
// báo về giai đoạn lạnh giá.
// Input:
//  Dòng đầu tiên chứa số nguyên N (1 < N ≤ 105
// ).

//  Dòng tiếp theo chứa N số nguyên (có giá trị tuyệt đối không quá 100) thể hiện nhiệt độ của N
// ngày.
// Output:
//  Một số duy nhất là số ngày dự báo tìm được
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
bool a[100001];
int b[100001];
int c[100001];

void Solve()
{
    int x;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        a[i] = (x < 0);
    }
    int t = 0, d = 0, Max = 0;
    for (int i = n; i >= 1; --i)
    {
        t += a[i];
        if (a[i] == 0 && t)
        {
            b[i]++;
            b[max(0, i - 2 * t)]--;
            //cout<<i<<' '<<max(0,i-2*t-1)<<endl;
            Max = max(Max, t);
            t = 0;
        }
        d += b[i];
        if (d)
            b[i] = 1;
        else
            b[i] = 0;
        c[i] = c[i + 1] + b[i];
    }
    //for(int i=1;i<=n;++i)cout<<b[i]<<' ';cout<<endl;
    //for(int i=1;i<=n;++i)cout<<c[i]<<' ';cout<<endl;
    t = 0;
    int Max2 = 0;
    for (int i = n; i >= 1; --i)
    {
        t += a[i];
        if (a[i] == 0 && t)
        {
            if (t == Max)
            {
                Max2 = max(Max2, min(i, 3 * t) - c[max(1, i - 3 * t + 1)] + c[i + 1]);
                //cout<<i<<' '<<t<<' '<<Max2<<' '<<c[max(1,i-3*t+1)]-c[i+1]<<endl;
            }
            t = 0;
        }
    }
    cout << c[1] + Max2 << endl;
}

int main()
{
    Init();
    Solve();
}
