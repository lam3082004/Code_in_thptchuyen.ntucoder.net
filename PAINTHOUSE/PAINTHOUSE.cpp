// .Bựa trước đã sơn tường xong rồi khá ưng ý nên hôm nay các bạn tiếp tục giúp mình sơn nhà nha :).

// Hôm nay mình muốn sơn gạch trên sàn nhà theo đường thẳng trước. Nhà mình thì chỉ có chiều dài bằng 10^100 viên thôi.Mình muốn các bạn sơn theo 2 màu( các viên gạch sơn từ trái sang phải và bắt đầu từ 0)

// - Nếu chỉ số viên gạch chia hết cho r (0,r,2r,..) thì sơn màu đỏ

// - Nếu chỉ số viên gạch chia hết cho b (0,b,2b,..) thì sơn màu cam

// - Nếu chỉ số viên gạch chia hết cho r và b thì có thể chọn 1 trong 2 nha

// - Mặt khác nếu chỉ số viên gạch không chia hết cho cả r và b thì không được sơn viên gạch ấy

// Nếu vậy thì quá dễ đúng không nào :)) Vì vậy mình quyết định tăng độ khó cho game tí. Hãy liệt kê chỉ số các viên gạch được tô theo thứ tự tăng dần. Nếu có k viên cùng màu hoặc không làm theo yêu cầu của mình bạn sẽ được mình đánh giá là không hoàn thành nhiệm vụ.

// Input : Dòng đầu tiên chứa T ( 1 <= T <= 1000 )  số lượng test

// T dòng tiếp chứa các test là các số r,b,k(1<=r,b<=109,2 <= k <= 109

// Output In ra T dòng. Mỗi dòng tương ứng cho mỗi test là UNSUCCESSFUL nếu không hoàn thành nhiêm vụ ngược lại in ra SUCCESSFUL
#include <bits/stdc++.h>

#define file ""
#define el cout << "\n"
#define f0(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define maxn

using namespace std;
int t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///freopen(file".inp","r",stdin);
    ///freopen(file".out","w",stdout);
    cin >> t;
    while (t--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int g = __gcd(a, b);
        a /= g, b /= g;
        if (a > b)
            swap(a, b);
        int d = (b + a - 2) / a;
        if (d >= k)
            cout << "UNSUCCESSFUL";
        else
            cout << "SUCCESSFUL";
        el;
    }
    return 0;
}
