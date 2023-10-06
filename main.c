#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cleanInput() {
    while (getchar() != '\n')
        ;
}

void inputFloatNumber(float* input, char message[]) {
reInput:
    printf("%s", message);
    if (!scanf("%f", input)) {
        cleanInput();
        goto reInput;
    }
}

void inputIntNumber(int* input, char message[]) {
reInput:
    printf("%s", message);
    if (!scanf("%d", input)) {
        cleanInput();
        goto reInput;
    }
}

void inputString(char* input, char message[]) {
    printf("%s", message);
    scanf(" %[^\n]", input);
}

void getMaxNumber() {
    int i;
    float arrNumber[3];

    inputFloatNumber(&arrNumber[0], "Nhập số thứ nhất: ");
    inputFloatNumber(&arrNumber[1], "Nhập số thứ hai: ");
    inputFloatNumber(&arrNumber[2], "Nhập số thứ ba: ");

    float maxNumber = arrNumber[0];
    for (i = 1; i < (sizeof(arrNumber) / sizeof(arrNumber[0])); i++) {
        if (arrNumber[i] > maxNumber) {
            maxNumber = arrNumber[i];
        }
    }

    printf("Số lớn nhất là: %f\n", maxNumber);
}

void checkYear() {
    int year;

    inputIntNumber(&year, "Nhập năm cần kiểm tra:");

    if ((year % 400 == 0 || year % 4 == 0) && year % 100 != 0) {
        printf("%d Là năm nhuận\n", year);
    } else {
        printf("%d Không phải là năm nhuận\n", year);
    }
}

void swap() {
    int maxLen;

    inputIntNumber(&maxLen, "Nhập độ dài của giá trị:");

    char* a = malloc(maxLen);
    char* b = malloc(maxLen);

    inputString(a, "Nhập giá trị A:");
    inputString(b, "Nhập giá trị B:");

    char tempA[maxLen];
    strcpy(tempA, a);

    strcpy(a, b);
    strcpy(b, tempA);

    printf("Giá trị A sau khi hoán đổi: %s\n", a);
    printf("Giá trị B sau khi hoán đổi: %s\n", b);

    free(a);
    free(b);
}

int main() {
    int input;

    printf("Chọn chương trình!\n");
    printf("[1] Bài 1\n");
    printf("[2] Bài 2\n");
    printf("[3] Bài 3\n");
    printf("[4] Thoát\n");

reInput:
    printf("Nhập số bài muốn chọn\n");

    if (scanf("%d", &input) && input <= 4 && input > 0) {

    } else {
        cleanInput();
        goto reInput;
    }

    switch (input) {
    case 1: {
        getMaxNumber();
        break;
    }
    case 2: {
        checkYear();
        break;
    }
    case 3: {
        swap();
        break;
    }
    case 4: {
        return 0;
        break;
    }
    }
    return 0;
};
