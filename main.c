#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

//1. Thêm khóa học
//2. Hiển thị danh sách khóa học
//3. Xóa khóa học
//4. Cập nhật thông tin khóa học
//5. Đánh dấu khóa học đã hoàn thành
//6. Sắp xếp khóa học theo số tín chỉ
//7. Tìm kiếm khóa học theo tên
//8. Thoát chương trình

typedef struct Cource{
    int id; // Id khóa học
    char title[MAX_LENGTH]; // Tên khóa học
    int credit; // Số tín chỉ

} Cource;

typedef struct NodeSingly{
    Cource cource; // Dữ liệu của khóa học
    struct NodeSingly* next;
} NodeSingly;

typedef struct NodeDoubly{
    Cource cource;
    struct NodeDoubly* prev;
    struct NodeDoubly* next;
} NodeDoubly;

// Hàm hiển thị menu chức năng
void showMenu(){
    printf("---- MENU QUAN LY KHOA HOC ----\n");
    printf("1. Them khoa hoc\n");
    printf("2. Hien thi danh sach khoa hoc \n");
    printf("3. Xoa khoa hoc\n");
    printf("4. Cap nhat thong tin khoa hoc \n");
    printf("5. Danh dau khoa hoc da hoan thanh \n");
    printf("6. Sap xep khoa hoc theo so tin chi\n");
    printf("7. Tim kiem khoa hoc theo ten \n");
    printf("8. Thoat chuong trinh");
    printf("\n");
}

// Hàm lấy thông tin khóa học từ người dùng
Cource importCource(){
    Cource cource;
    printf("Nhap Id khoa hoc: ");
    scanf("%d", &cource.id);

    getchar(); // Xóa ký tự '\n' sau scanf

    printf("Nhap ten khoa hoc: ");
    fgets(cource.title, MAX_LENGTH, stdin);
    cource.title[strcspn(cource.title, "\n")] = '\0';

    printf("Nhap so tin chi: ");
    scanf("%d", &cource.credit);

    return cource;
}

// Hàm thêm mới khóa học
void addCource(NodeSingly** head){
    // Cấp phát bộ nhớ dành cho danh sách liên kết
    NodeSingly* newNode = (NodeSingly*) malloc(sizeof (NodeSingly));

    // Lấy dữ liệu từ người dùng
    newNode->cource = importCource();
    newNode->next = NULL;

    // Xác định nơi mà dữ liệu sẽ được lưu vào

    // Nếu danh sách liên kết bị rỗng
    if (*head == NULL){
        *head = newNode;
    } else {
        NodeSingly* temp = *head;
        while (temp-> next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Them khoa hoc thanh cong!!!\n");
}

// Hàm hiển thị danh sách khóa học đang theo học
void printListCource(NodeSingly* head){
    printf("Danh sach khoa hoc: \n");
    while (head != NULL){
        printf("Id khoa hoc: %d | Ten khoa hoc: %s | So tin chi: %d\n", head->cource.id, head->cource.title, head->cource.credit);
        head = head->next;
    }

}

// Hàm xóa khóa học theo id
void deleteCource(NodeSingly** head, int idDelete){
    NodeSingly *temp = *head, *prev = NULL;

    while (temp != NULL && temp->cource.id != idDelete){
        prev = temp;
        temp = temp->next;
    }

    // Kiểm tra xem khóa học có tồn tại không?
    if (temp == NULL){
        printf("Khoa hoc khong ton tai!");
        return;
    }

    if (prev == NULL){
        *head = temp->next;
    } else {
        // Nếu tìm thấy khóa học thì tiến hành xóa và giải phóng bộ nhớ
        prev->next = temp->next;
        free(temp);
    }

    printf("Xoa khoa hoc thanh cong\n");
}


// Hàm giải phóng bộ nhớ
void freeNodeSingly(NodeSingly* head){
    NodeSingly* temp;

    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Hàm đánh dấu các khóa học đã hoàn thành
// Nhập vào id của khóa học cần đánh dấu
// Lấy ra id của khóa học trên từ NodeSingly
// Thêm khóa học vừa lấy ra từ NodeSingly và thêm vào NodeDoubly
// Nếu như trong NodeDoubly đã có rồi thì không thêm vào nữa (Ít xảy ra)
// Xóa khóa học từ NodeSingly
void markCompletedCources(){

}

int main(){
    int choice, idDelete;
    NodeSingly* studyingList = NULL;

    do {
        showMenu();
        printf("Vui long nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCource(&studyingList);
                break;
            case 2:
                printListCource(studyingList);
                break;
            case 3:
                printf("Nhap id khoa hoc can xoa:");
                scanf("%d", &idDelete);

                deleteCource(&studyingList, idDelete);
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:
                printf("Thoat chuong trinh");
                break;
            default:

                break;
        }

    } while (choice != 8);

    freeNodeSingly(studyingList);
    return 0;
}