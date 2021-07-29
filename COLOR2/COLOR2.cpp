// COLOR – TÔ MÀU
// Cho bảng kích thước 3 × n, đếm số cách tô mỗi ô của bảng bằng một trong k màu, sao cho không có
// hai ô nào chung cạnh được tô cùng màu
// Input:
//  Một dòng duy nhất là hai số nguyên n, k
// Output:
//  Một dòng duy nhất là số cách tô màu theo module 109 + 7
// Giới hạn:
//  Subtask 1 (10% số điểm): n ≤ 1018
// , k ≤ 2
//  Subtask 2 (40% số điểm): n ≤ 105
// , k ≤ 5
//  Subtask 3 (20% số điểm): n ≤ 1018
// , k ≤ 5
//  Subtask 4 (20% số điểm): n ≤ 105
// , k ≤ 109
//  Subtask 5 (10% số điểm): n ≤ 1018
// , k ≤ 109
#include <bits/stdc++.h>
#define ll long long
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int mod=1e9+7;
struct matrix
{
    ll x[5][5];
};
matrix nhan(matrix a,matrix b)
{
    matrix c;
    fo(i,1,2)
    fo(j,1,2)
    {
        c.x[i][j]=0;
        fo(t,1,2)
        c.x[i][j]=(c.x[i][j]+(a.x[i][t]*b.x[t][j])%mod)%mod;
    }
    return c;
}
matrix mu(matrix a,ll n)
{
    if(n==1) return a;
    matrix t=mu(a,n/2);
    t=nhan(t,t);
    if(n%2==1) t=nhan(t,a);
    return t;
}
ll ti(ll a,ll b)
{
    return (a*b)%mod;
}
ll n,k;
matrix A,B;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    A.x[1][1]=(ti(k-1,k-3)+k)%mod;
    A.x[1][2]=(ti(k-1,k-3)+2)%mod;
    A.x[2][1]=(ti(k-1,ti(k-2,k-3))+ti(2,k-2))%mod;
    A.x[2][2]=(ti(k-1,ti(k-2,k-3))+ti(3,k-2)-1)%mod;
    B.x[1][2]=ti(k,k-1);
    B.x[2][2]=ti(k,ti(k-1,k-2));
    if(k==2)
    {
        cout<<2;return 0;
    }
    if(n==1) cout<<(B.x[1][2]+B.x[2][2])%mod;
    else
    {
        A=mu(A,n-1);
        B=nhan(A,B);
        cout<<(B.x[1][2]+B.x[2][2])%mod;
    }
}
    