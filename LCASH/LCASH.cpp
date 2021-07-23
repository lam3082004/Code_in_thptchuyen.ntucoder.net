// Bước vào thời kỳ Cách mạng Công nghiệp 4.0, cả Chính phủ và các doanh nghiệp đều thực hiện
// quá trình số hóa các hoạt động và dịch vụ. Trước bối cảnh đó, các ngân hàng cũng phải thực hiện
// việc chuyển đổi, và hầu hết các ngân hàng hiện nay đều đã và đang xây dựng chiến lược phát triển
// dịch vụ theo hướng số hóa. Một số phương thức thanh toán số hiện nay như: Mobile Banking,
// ví điện tử, công nghệ thẻ phi tiếp xúc hay công nghệ thanh toán 1 chạm đang dần thay đổi thói
// quen thanh toán của người dân, làm cho việc thanh toán bằng tiền mặt không còn phổ biến.
// Tuy vậy, Rogers vẫn chưa thể thích nghi được với việc thanh toán không sử dụng tiền mặt như
// hiện nay. Vì việc thanh toán bằng tiền mặt không còn phổ biến, nhiều lần Rogers đi mua đồ
// nhưng cửa hàng không có tiền mặt để trả lại. Rogers quyết định rằng khi đi mua hàng sẽ mang
// vừa đủ số tiền mà anh ấy cần để mua sản phẩm và không nhận lại tiền thừa. Việc mang tiền như
// vậy khá khó vì Rogers chỉ biết sản phẩm sẽ có mức giá không vượt quá mức S, chứ không biết
// giá cụ thể của sản phẩm.
// Rogers có n mệnh giá tiền a1, a2, ..., an. Anh ấy có rất nhiều tờ tiền cho mỗi mệnh giá, có thể coi
// như là vô hạn. Rogers muốn mang ít tờ tiền nhất có thể sao cho vẫn có thể chắc chắn mua được
// sản phẩm mong muốn mà không cần nhận lại tiền thừa. Bạn hãy giải quyết bài toán này giúp
// Rogers nhé.
// Dữ liệu
// • Dòng đầu tiên chứa 2 số nguyên dương n, S lần lượt là số lượng mệnh giá
// tiền mà Rogers sở hữu và giá cao nhất có thể của sản phẩm Rogers muốn mua
// (1 ≤ n ≤ 100000, 1 ≤ s, ai ≤ 109
// ).
// • Dòng tiếp theo chứa n số nguyên dương phân biệt a1, a2, ..., an.
// Kết quả
// • Đưa ra kết quả gồm một số nguyên là số lượng đồng tiền ít nhất Rogers cần mang. Trong
// trường hợp không có cách mang tiền nào thỏa mãn điều kiện đầu bài, đưa ra −1
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005, mod = 1e9 + 7, inf = 0x3f3f3f3f;
#define X first
#define Y second
#define pb push_back
using ll = long long;
typedef pair<int, int> ii;
//typedef pair < ii , int > iii;
//vector < int > pr[MAX];
int n, m;
int a[MAX];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("LCASH.inp","r",stdin);
    //freopen("LCASH.out","w",stdout);
    int S, n;
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > S)
        {
            i--;
            n--;
        }
    }
    sort(a + 1, a + 1 + n);
    if (a[1] != 1)
    {
        cout << -1;
        return 0;
    }
    int now = 0;
    a[n + 1] = S + 1;
    int ans = 0;
    for (int i = 1, x; i <= n; i++)
    {
        if (a[i + 1] > now + 1)
        {
            x = (a[i + 1] - 2 - now + a[i]) / a[i];
            now += x * a[i];
            ans += x;
        }
    }
    cout << ans;
}
