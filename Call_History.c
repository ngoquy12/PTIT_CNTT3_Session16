#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH__PHONE 15
#define MAX_LENGTH_TIME 50

// Cấu trúc lưu trữ thông tin của một cuộc gọi
typedef struct Call{
    char phoneNumber[MAX_LENGTH__PHONE]; // Số diện thoại
    char time[MAX_LENGTH_TIME]; // Thời gian mà chúng ta gọi
} Call;

// Khai báo Node chung cho Stack và Queue
typedef struct Node {
    Call data;
    struct Node* next;
} Node;

// Khai báo ra Stack
typedef struct Stack {
    Node* top;
} Stack;

// Khai báo ra Queue
typedef struct Queue{
    Node* front;
    Node* rear;
} Queue;

// Khởi tạo 1 node mới từ dữ liệu cuộc gọi
Node* createNode(Call call){
    // Cấp phát bộ nhớ
    Node* newNode = (Node*)  malloc(sizeof (Node));

    newNode->data = call;
    newNode->next = NULL;

    return newNode;
}

// Hàm lấy ra thời gian hiện tại
void getCurrentTime(char* timeBuffer){
    time_t now = time(NULL);

    struct tm* t = localtime(&now);

    strftime(timeBuffer, MAX_LENGTH_TIME, "%d-%m-%Y %H-%M-%S", t);
}

// Push phần tử vào trong Stack
void push (Stack* stack, Call call){
    // Khởi tạo ra một node
    Node* node = createNode(call);

    // Liên kết cac node lại với nhau
    node->next = stack->top;

    // Gán giá trị (phần tủ) cho phần top
    stack->top = node;
}


// Pop phần tử treen cùng ra khỏi Stack
Call pop(Stack* stack){
    Node* temp = stack->top; // Lấy ra phần top của stack
    Call call = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return call;
}

// Peek phần tử trên cùng của Stack
Call peekStack(Stack* stack){
    return stack->top->data;
}

// Hàm hiển thị menu của chương trình
void showMenu (){
    printf("==== Call history manager ====\n");
    printf("1. CALL - Goi so moi\n");
    printf("2. BACK - Quay lai so truoc do\n");
    printf("3. REDIAL - Goi lai so vua quay lai\n");
    printf("4. HISTORY - Hien thi toan bo so da goi\n");
    printf("5. Thoat chuong trinh");
}

int main(){
    Stack backStack = {NULL}; //Lưu truwx  lịch sử gọi lùi lại (undo)
    Stack forwardStack = {NULL}; // Lưu goi lại (redo)

    int choice;
    char phoneNumber[MAX_LENGTH__PHONE];

    do {
        showMenu();
        printf("\n");
        printf("Vui long nhap lua chon: ");
        scanf("%d", &choice);
        getchar(); // Xoá ký tự '\n' khỏi bọ nhớ đệm

        Call call;

        switch (choice) {
            case 1:
                // Lấy dữ liệu t người dùng (số điện thoại gọi mới)
                printf("Nhap so dien thoai: ");
                fgets(phoneNumber, sizeof (phoneNumber), stdin);
                phoneNumber[strcspn(phoneNumber, "\n")] = '\0'; // Loại bỏ được ký tự '\n ở cuối

                // Gán thời gian hiện tại vào call
                strcpy(call.phoneNumber, phoneNumber);
                getCurrentTime(call.time);

                // Lưu số điện thoại vào trong Stack
                push(&backStack, call);
                break;
            case 2:

                // Kim tra xem Stack có rỗng không
                if (backStack.top != NULL){
                    // Lấy ra số gọi gần nhất
                    Call recent =  pop(&backStack);

                    // Chuyển qua forward
                    push(&forwardStack, recent);

                    // Lấy ra phần tử trên đàu của Stack
                    Call phoneNumberFirst = peekStack(&backStack); // Lấy ra số hiện tại
                    printf("Phan tu top: %s\n", phoneNumberFirst.phoneNumber);
                } else {
                    printf("Khong co so dien thoai nao de quay lai:");
                }


                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Lua chon khong hop le:");
                break;
        }

    } while (choice != 5);

    return 0;
}