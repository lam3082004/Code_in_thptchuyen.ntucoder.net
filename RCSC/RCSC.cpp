// RCSC
// Cho dãy số nguyên gồm 2N phần tử a1, a2, ..., a2N . Bạn hãy tìm cấp số cộng độ dài N gồm N
// phần tử trong 2N phần tử cho trước. Dữ liệu đảm bảo luôn tồn tại một cấp số cộng độ dài N.
// Dữ liệu
// • Dòng đầu tiên gồm một số nguyên dương N (N ≤ 105
// );
// • Dòng thứ hai gồm 2N số nguyên a1, a2, ..., a2N (|ai
// | ≤ 109
// ).
// Kết quả
// • Bạn hãy tìm phần tử đầu tiên và công sai của cấp số cộng. Nếu có nhiều kết quả hãy in ra
// một kết quả bất kì.
#include <bits/stdc++.h>
#define lo long long
#define KKH "RCSC"
#define fi first
#define se second
#define BIT(x, k) ((x>>k)&1)
using namespace std;
void START()
{
    #ifdef toilagun2004
    freopen(KKH".inp","r",stdin);
    freopen(KKH".out","w",stdout);
    #endif // toilagun2004
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n,a[2000006],kq,dau;
mt19937 Rand;
bool check(int id,int tmp)
{
    int kc=a[id+tmp]-a[id],kq=1;
    int idt=id;
    for (int i=id;i>0;--i)
    {
        if (a[idt]-a[i]>kc) break;
        if (a[idt]-a[i]==kc){
            idt=i;
            kq++;
        }
    }
    dau=a[idt];
    idt=id;
    for (int i=id;i<=2*n;i++)
    {
        if (a[i]-a[idt]>kc) break;
        if (a[i]-a[idt]==kc){
            idt=i;
            kq++;
        }
    }
    if (kq>=n) return true;
    return false;
}
int main()
{
    START();
    srand(time(NULL));
    Rand.seed(time(nullptr));
    cin>>n;
    for (int i=1;i<=2*n;i++)
        cin>>a[i];
    sort(a+1,a+1+2*n);
    for (int h=1;h<=100;h++)
    {
        int vt=Rand()%(2*n);
        vt++;
        //cout<<vt<<'\n';
        for (int j=1;j<=3;++j)
            if (vt+j<=2*n && check(vt,j)) {
                cout<<dau<<' '<<a[vt+j]-a[vt];
                return 0;
            }
    }
}
    