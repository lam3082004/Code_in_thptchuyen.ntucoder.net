// CLOCK1 - ĐỒNG HỒ 1
// Tháng 3, có ngày Quốc tế Phụ nữ, nên chúng ta sẽ tiếp tục kể những câu chuyện đầy bi hài của
// ARSENAL1886
// Nhân ngày 8-3, ARSENAL1886 ngày hôm nay đã set một kèo đi chơi với bạn gái
// Vào h1 giờ m1 phút, ARSENAL1886 đã "hạ cánh" trước cổng nhà bạn gái và gọi điện thoại. Tuy
// nhiên, chờ mãi không thấy bạn gái trả lời, anh ấy gọi đi gọi lại nhiều lần. Cuối cùng, vào h2 giờ m2
// phút thì bạn ấy mới trả lời lại. Câu chuyện tiếp theo mình không muốn kể tiếp, đại khái nó như thế này
// Trong lúc ngồi chờ bạn gái trả lời điện thoại, ARSENAL1886 ngồi ngắm đồng hồ và chú ý đến
// việc kim giờ và kim phút hợp với nhau một góc là alpha. Anh ấy muốn đếm xem trong khoảng thời
// gian từ h1 giờ m1 phút đến h2 giờ m2 phút, có bao nhiêu lần mà kim giờ và kim phút hợp với
// nhau một góc là alpha

// Chú ý: Trong bài tập này, chúng ta sẽ sử dụng đồng hồ kim như hình vẽ trên
// • Kim phút quay liên tục và mất 60 phút để quay một vòng
// • Kim giờ quay liên tục và mất 12 giờ để quay một vòng
// Input
// • Dòng đầu tiên là số nguyên t - số test
// • t dòng tiếp theo, mỗi dòng có định dạng h1 : m1 h2 : m2 alpha
// Output
// • In ra t dòng, dòng thứ i là kết quả của test thứ i
// Giới hạn
// • 1 ≤ t ≤ 100
// • 0 ≤ h1, h2 ≤ 23, 0 ≤ m1, m2 ≤ 59
// • alpha = 0, 90, 180
/// hhoangcpascal

#include <cstdio>
#include <iostream>
#include <algorithm>
#define file_name "CLOCK1"

using namespace std;

const int limit[3] = {22, 44, 22};

struct Cal
{
    int a, N, b;
} P[3];

string S;

int main()
{
    P[0] = {720, 1, 0};
    P[1] = {180, 2, 180};
    P[2] = {720, 1, 360};

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 0;
    cin >> t;
    while (t--)
    {
        cin >> S;
        int A = (((S[0] - '0') * 10 + (S[1] - '0')) * 60 + ((S[3] - '0') * 10 + (S[4] - '0'))) * 11;

        cin >> S;
        int B = (((S[0] - '0') * 10 + (S[1] - '0')) * 60 + ((S[3] - '0') * 10 + (S[4] - '0'))) * 11;

        int angle, res = 0;
        cin >> angle;
        angle /= 90;

        for (int i = 0; i < limit[angle]; ++i)
        {
            int del = P[angle].a * (i * P[angle].N) + P[angle].b;

            if (A <= del && del <= B)
                ++res;
        }

        cout << res << '\n';
    }

    return 0;
}
