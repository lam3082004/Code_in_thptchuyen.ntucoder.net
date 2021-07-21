// Bowling là một trò chơi giải trí mà người chơi ném một quả bóng nặng cho chạy trên một đường
// băng dài và phẳng để làm đổ những chai gỗ đứng ở cuối đường. Ngày nay, Bowling được xem là
// một môn thể thao. Trong bài toán này chúng ta sẽ xét trò chơi Bowling cải biên như sau:
// • Cuối đường băng người ta đặt n chai gỗ được xếp thành một hàng ngang, các chai gỗ được
// đánh số từ 1 đến n từ trái qua phải. Chai gỗ thứ i ghi số nguyên ai tương ứng là điểm thưởng
// (nếu ai ≥ 0) hoặc phạt (nếu ai < 0) khi ném bóng mà làm đổ chai gỗ này.
// • Người chơi phải ném ít nhất một lần và không giới hạn số lần ném bóng. Mỗi lần ném bóng,
// người chơi sẽ ném bóng hướng vào một trong n vị trí đặt chai gỗ, nếu ném bóng hướng vào
// vị trí đặt chai gỗ thứ i thì nó sẽ làm đổ những chai đặt ở vị trí có khoảng cách với vị trí chai
// thứ i không vượt quá r. Khoảng cách giữa vị trí hai chai thứ i và thứ j được tính là |i − j|.
// Tổng điểm mà người chơi đạt được là tổng các số ghi trên các chai gỗ mà người chơi làm đổ
// được. Muốn đạt được nhiều điểm người chơi không những phải có khả năng thực hiện việc
// ném bóng chính xác mà còn phải biết lựa chọn hướng ném bóng trong mỗi lượt chơi.
// Yêu cầu: Cho r và a1, a2, . . . , an, hãy tính tổng điểm lớn nhất mà người chơi có thể đạt được
// với giả thiết người chơi có khả năng thực hiện chính xác việc ném bóng
// Input
// • Dòng đầu là số nguyên dương K - số lượng bộ dữ liệu. Tiếp theo là K nhóm dòng, mỗi nhóm
// tương ứng với một bộ dữ liệu có cấu trúc như sau:
// • Dòng thứ nhất ghi hai số nguyên dương n và r (r ≤ n);
// • Dòng thứ hai chứa n số nguyên a1, a2, . . . , an, số ai tương ứng là số ghi trên chai gỗ thứ i
// Output
// • Gồm K dòng, mỗi dòng ghi một số nguyên là tổng điểm mà người chơi có thể đạt được tương
// ứng với bộ dữ liệu trong input
// Giới hạn
// • 1 ≤ N ≤ 200000
// • |ai
// | ≤ 109
