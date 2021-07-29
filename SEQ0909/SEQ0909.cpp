// Dãy con
// Xét dãy các số nguyên gồm n phần tử a1, a2, ..., an. Một dãy con liên tiếp của dãy a1,
// a2, ..., an là dãy số nguyên có dạng ai, ai+1, ai+2, ..., aj (1≤ i ≤ j ≤ n).
// Cho số nguyên dương n, dãy số nguyên a1, a2, …, an và số nguyên k.
// Yêu cầu: Tìm dãy con liên tiếp khác rỗng dài nhất sao cho giá trị trung bình cộng các phần
// tử của dãy con đó lớn hơn hoặc bằng giá trị k cho trước.
// Dữ liệu vào: từ file văn bản SEQ.INP có cấu trúc:
// - Dòng 1: chứa 2 số nguyên n, k (1 ≤ n ≤ 105
// ; |k| ≤ 106
// ).
// - Dòng 2: chứa n số nguyên a1, a2, ..., an (|ai| ≤ 106
// ).
// Dữ liệu ra: ghi ra file văn bản SEQ.OUT có cấu trúc:
// - Gồm một dòng: ghi một số nguyên duy nhất là độ dài lớn nhất của dãy con tìm được.
// (Nếu không tìm được dãy con thỏa mãn thì ghi số -1)
#include <bits/stdc++.h>
using namespace std;
int n;
pair <long long,long long> p[100008];
long long mina = 1e18, maxa = -1e18, k, a[100008];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        a[i] -= k;
        p[i].first = p[i - 1].first + a[i];
        p[i].second = i;
    }
    sort(p,p + 1 + n);
    for(int i = 0;i<=n;i++)
    {
        mina = min(mina,p[i].second + 1);
        if(p[i].second + 1 - mina > maxa)
        {
            maxa = p[i].second + 1 - mina;
        }
    }
    cout<<maxa;
    return 0;
}
    