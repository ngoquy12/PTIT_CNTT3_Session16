#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH_TITLE 100

// Tạo cấu trúc cho một khóa học
typedef struct Course {
    int id;
    char title[MAX_LENGTH_TITLE];
    int credit;
} Course;

// Khai báo danh sách liên kết đơn để chứa danh sách khóa học đang theo học
typedef struct SinglyNode{
    Course course; // Dữ liệu của khóa học
    struct SinglyNode* next; // Con trỏ mà trỏ đến Node tiếp theo
} SinglyNode;

// Khai báo danh sách liên kết đôi để chứa danh sách khóa học đã hoàn thành
typedef struct DoubleNode{
    Course course;
    struct DoubleNode* next;
    struct DoubleNode* prev;
} DoubleNode;

// Hàm khởi tạo Singly Node
SinglyNode* createNode(Course course){
    // Cấp phát bộ nhớ cho danh sách liên kết
    SinglyNode* newNode = (SinglyNode*) malloc(sizeof (SinglyNode));
    newNode->course = course; // Gán lại dữ liêu cho Node
    newNode->next = NULL;

    return newNode;
}

// Hàm khởi tạo một DouleNode
DoubleNode* createDoubleNode(Course course){
    // Cấp phát bộ nhớ cho danh sách liên kết đôi
    DoubleNode* newNode  = (DoubleNode*) malloc(sizeof (DoubleNode));
    newNode->course = course;
    newNode->prev = newNode->next =  NULL;

    return newNode;
}

// Hàm thêm khóa học
SinglyNode* createCourse(SinglyNode* head){
    Course course;

    // Lấy dữ liệu từ người dùng
    printf("Nhap id: ");
    scanf("%d", &course.id);
    getchar();

    printf("Nhap tieu de: ");
    fgets(course.title, MAX_LENGTH_TITLE, stdin);
   course.title[strcspn(course.title, "\n")] = 0;

    printf("Nhap so tin chi: ");
    scanf("%d", &course.credit);

    // Lưu trữ thông tin khóa học vừa lấy vào trong Node
    SinglyNode* newNode = createNode(course);
    newNode->next = head; // Cần xem lại sao

    return newNode;
}

// Hiển thị danh sách các phần tử có trong danh sách liên kết
void displayCourse(SinglyNode* head){
    SinglyNode* temp = head;

    printf("Danh sach khoa hoc: \n");

    while (temp != NULL){
        printf("Id: %d | Title: %s | Credit: %d \n", temp->course.id, temp->course.title, temp->course.credit);
        temp = temp->next; // Bước nhảy
    }
}

// Hàm xóa khóa học theo id
SinglyNode* deleteCourse(SinglyNode* head){
    // Lấy id cần xóa
    int idDelete;

    printf("Nhap id can xoa: ");
    scanf("%d", &idDelete);

    SinglyNode* temp = head;
    SinglyNode* prev = NULL;

    // Tìm kếm khóa học theo id
    while (temp && temp->course.id != idDelete){
        prev = temp;
        temp = prev->next;
    }

    // Nếu không tìm thấy sẽ bắn ra thông báo và kết thúc chương trình
    if (!temp){
        printf("Khong tim thay khoa hoc!!!");
        return temp;
    }

    // Nếu tìm thấy sẽ xóa node khỏi danh sách liên kết và giải phóng bộ nhớ
    if (!prev){
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    // Giải phóng node vừa xóa
    free(temp);

    printf("Xoa khoa hoc thanh cong\n");

    // Trả về 1 danh sách liên kết mới
    return head;
}

// Hàm cập nhật thông tin khóa học
void updateCourse(SinglyNode* head){
    // Lấy id và dữ liệu mới cần cập nhật
    int idUpdate;

    printf("Nhap id can cap nhat: ");
    scanf("%d", &idUpdate);

    SinglyNode* temp = head;

    while (temp && temp->course.id != idUpdate){
        temp = temp->next;
    }

    // Tìm kếm khóa học theo id
    if (!temp){
        // Nếu không c sẽ băn thông báo và ết thúc chương trinh
        printf("Khoa hoc khong ton tai");
        return;
    }
    getchar();

    // Nếu có thì tiến hành đi lấy thông tin mơ và cập nhật
    printf("Nhap ten khoa hoc moi: ");
    fgets(temp->course.title, MAX_LENGTH_TITLE, stdin);
    temp->course.title[strcspn(temp->course.title, "\n")] = 0;

    printf("Nhao tin chi moi: ");
    scanf("%d", &temp->course.credit);

    printf("Cap nhat khoa hoc thanh cong");
    printf("\n");
}

// Hàm đánh dấu hoàn thành khóa học
void markCompletedCourse(SinglyNode* head, DoubleNode* dHead ){
    // 1. Lấy id cần chuyển đổi
    // 2. Kiểm tra xem khóa học đã cos trong danh sách liên kết đơn chưa
    // 3. Kiểm tra xem id có tồn tại trong danh sách liên kết đơn không?
    // 4. Thêm khóa học đó vào trong danh sách liên kết đôi
    // 5. Xóa khóa học đó khỏi danh sách liên kết đơn
    // 6. Hiển thị thông báo thành công
}

// Giải phóng bộ nhớ
void freeMemory(SinglyNode* head, DoubleNode* dHead){
    // Giải phóng bộ nhớ cho danh sách lien kết đơn
    SinglyNode* temp = head;
    while (temp != NULL){
        // Khai báo 1 biến trung gian đại diện cho node
        SinglyNode* curentNode = temp;
        temp = temp->next;
        free(curentNode);
    }

    // Giải phóng bộ nhớ cho danh sách lien kết đôi
    DoubleNode * dTemp = dHead;
    while (dTemp != NULL){
        // Khai báo 1 biến trung gian đại diện cho node
        DoubleNode* curentDNode = dTemp;
        dTemp = dTemp->next;
        free(curentDNode);
    }
}

// Hàm hiển thị menu
void showMenu(){
    printf("===== COURSE MANAGER =====\n");
    printf("1. Them khoa hoc\n");
    printf("2. Hien thi danh sach khoa hoc dang theo hoc\n");
    printf("3. Xoa khoa hoc\n");
    printf("4. Cap nhat thong tin khoa hoc\n");
    printf("5. Danh dau khoa hoc da hoan thanh\n");
    printf("6. Sap xep khoa hoc theo so tin chi\n");
    printf("7. Tim kiem khoa hoc theo tenn\n");
    printf("8. Thoat chuong trinh\n");
    printf("\n");
}

int main(){
    int choice;
    SinglyNode* head = NULL;
    DoubleNode* dHead = NULL;

    do {
        // Hiển thị menu chức năng
        showMenu();

        printf("Vui long nhap lua chon:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                 head = createCourse(head);
                break;
            case 2:
                displayCourse(head);
                break;
            case 3:
                deleteCourse(head);
                break;
            case 4:
                updateCourse(head);
                break;
            case 5:
                markCompletedCourse(head, dHead);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Lua chon khong hop le");
                break;
        }


    } while (choice != 8);

    // Gọi hàm để giải phóng bộ nhớ
    freeMemory(head, dHead);

    return 0;
}