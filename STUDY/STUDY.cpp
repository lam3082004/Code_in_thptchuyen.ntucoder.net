// Một buổi chiều đẹp trời mà đội tuyển không học , sau khi tự học A , B và C ngồi lại chơi game “Ai thông minh hơn D”.  Trò chơi đơn giản như sau ở mỗi lượt chơi 3 người chơi hiện có số điểm ở các lượt chơi trước, lượt chơi này người chơi sẽ đưa ra số điểm cược trong khoảng 0 đến số điểm đang có, nếu trả lời đúng sẽ được số điểm cược này, trả lời sai sẽ bị trừ đúng bằng số điểm đã cược. Đây là lượt chơi cuối cùng quyết định ai thông minh hơn D nhất! A và D luôn cà khịa nhau nên A muốn mình phải là người thông minh hơn D nhất. Để chiến thắng A phải có số điểm lớn nhất sau lượt chơi này (vì đây là turn cuối). Hỏi A nên cược bao nhiêu để xác suất thắng là lớn nhất.

// Input : 3 số nguyên dương a,b,c không vượt quá 10^6 lần lượt là điểm lượt trước của (A , B , C);

//            2 số d , e (0 <= d <= b ; 0 <= e <= c) là điểm cược lượt này của B và C.

// Output: Số tiền A cược để có xác suất thắng là cao nhất.

// Nếu có nhiều giá trị thoả mãn thì đưa ra số tiền nhỏ nhất
#include <bits/stdc++.h>
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define ll long long
#define nmax 1000005
using namespace std;
const int mod=1e9+7;
ll n,k[nmax],p,t=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    fo(i,0,a)
    {
        if(a+i>max(b+d,c+e)) k[i]++;
        if(a+i>max(b+d,c-e)) k[i]++;
        if(a+i>max(b-d,c+e)) k[i]++;
        if(a+i>max(b-d,c-e)) k[i]++;
        if(a-i>max(b+d,c+e)) k[i]++;
        if(a-i>max(b+d,c-e)) k[i]++;
        if(a-i>max(b-d,c+e)) k[i]++;
        if(a-i>max(b-d,c-e)) k[i]++;
        if(k[i]>t)
        {
            t=k[i];
            p=i;
        }
    }
    cout<<p;
}
    