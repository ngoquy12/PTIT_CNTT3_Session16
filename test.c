//YÊU CẦU
//Viết chương trình quản lý khóa học cá nhân (Course Manager) bằng ngôn ngữ lập trình C, với các chức năng quản lý như sau:
//MENU CHỨC NĂNG:
//Thêm khóa học
//        Hiển thị danh sách khóa học
//        Xóa khóa học
//Cập nhật thông tin khóa học
//Đánh dấu khóa học đã hoàn thành
//        Sắp xếp khóa học theo số tín chỉ
//        Tìm kiếm khóa học theo tên
//        Thoát chương trình
//YÊU CẦU CHUNG:
//Sử dụng cấu trúc dữ liệu tuyến tính:
//Danh sách liên kết đơn để quản lý các khóa học đang học
//        Danh sách liên kết đôi để lưu trữ các khóa học đã hoàn thành
//        CẤU TRÚC DỮ LIỆU THAM KHẢO:
//Cấu trúc Course (Khóa học):
//id (int): Id khóa học
//title (string): tên khóa học
//credit (int): số tín chỉ
//        Danh sách khóa học đang học:
//Dùng danh sách liên kết đơn (Singly Linked List)
//Mỗi node chứa 1 khóa học đang học
//Danh sách lịch sử khóa học đã hoàn thành:
//Dùng danh sách liên kết đôi (Doubly Linked List)
//Mỗi node chứa 1 khóa học đã hoàn thành
