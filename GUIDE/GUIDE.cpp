// Hệ thống hang động ở một khu bảo tàng thiên nhiên của một tỉnh miền Trung rất nổi tiếng
// và thu hút một lượng đông đảo khách du lịch tới tham quan, khám phá cảnh đẹp huyền bí
// dưới lòng đất.
// Để du khách không phải lòng vòng trong một khu vực nào đó, ở một số hang người ta ngăn
// bớt lối ra, đảm bảo sao cho giữa 2 hang bất kỳ trong chương
// trình “Khám phá thế giới của Hades” (Hades – chúa tể của
// cõi âm) có không quá một đường đi tới nhau. Ngoài ra, ở
// mỗi hang đều có đặt máy hướng dẫn. Ở tại hang s, khách
// chỉ cần nhập vào số nguyên d – hang mình muốn tới, máy sẽ
// hiển thị số nguyên t – hang trực tiếp nối với s và là nơi tiếp
// theo khách phải di chuyển tới; t nhận giá trị −1 nếu đường
// đi hiện tại từ s đến d đang bị gián đoạn do ngập nước. Ví
// dụ, với sơ đồ hang ở hình bên, tại hang số 5 nếu khách
// muốn tới hang 4 thì máy sẽ chỉ là cần đi tới hang 3. Tới hang
// mới (hang 3), tiếp tục tra cứu dần dần khách sẽ tới được hang mình muốn đến (hang 4).
// Cho n – là số hang động, k cặp số ai

// ,bi cho biết hiện đang có đường đi không bị ngập nối

// trực tiếp 2 hang ai và bi (1 ≤ ai

// , bi ≤ n, ai ≠ bi

// , i = 1 ÷ n) và m truy vấn, mỗi truy vấn
// là một cặp số s và d, trong đó s – hang nơi khách đang đứng, d nơi khách muốn đến. Hãy
// xác định số hiển thị trên màn hình ứng với mỗi truy vấn.
// Input:
// Dòng đầu tiên chứa 2 số nguyên n, k (2 ≤ k < n ≤ 2 × 105
// ),
// Dòng thứ i trong k dòng tiếp theo chứa 2 số nguyên ai và bi
// Dòng k + 2 chứa số nguyên m (1 ≤ m ≤ 105
// ),

// Dòng thứ j trong m dòng tiếp theo chứa 2 số nguyên sjvà dj (1 ≤ sj ≤ dj ≤ n, sj ≠ dj)
// Kết quả: Đưa ra m số nguyên, mỗi số trên một dòng – kết quả của các lần tra cứu.