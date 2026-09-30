#include <stdio.h>

#define MAX_SIZE 50

int main() {
    int stock[MAX_SIZE] = {12, 7, 20, 5, 16};
    int n = 5;
    int choice, pos, value, newValue, target;
    int i, count;

    do {
        printf("\n========================================\n");
        printf("\nCHUONG TRINH QUAN LY LUOT MUON SACH BOOKHUB\n");
        printf("\n========================================\n");
        printf("1. Them so luot muon sach\n");
        printf("2. Sua so luot muon sach\n");
        printf("3. Xoa so luont muon sach\n");
        printf("4. Tim kiem so luot muon sach\n");
        printf("0. Thoat chuong trinh\n");
        printf("========================================\n");
        printf("Vui long nhap lua chon cua ban (0 - 4): ");
        scanf("%d", &choice);
switch (choice) {
            case 1:
                if (n == MAX_SIZE) {
                    printf("Mang da day, khong the them!\n");
                    break;
                }
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can chen: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri chen khong hop le!\n");
                } else {
                    for (i = n; i >= pos; i--) {
                        stock[i] = stock[i - 1];
                    }
                    stock[pos - 1] = value;
                    n++;
                    printf("Mang hien tai: [");
                    for (i = 0; i < n; i++) {
                        printf("%d", stock[i]);
                        if (i < n - 1)
                            printf(", ");
                    }
                    printf("]\n");
                }
                break;
			case 2:
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                printf("Nhap gia tri moi: ");
                scanf("%d", &newValue);

                if (pos < 1 || pos > n) {
                    printf("Vi tri sua khong hop le!\n");
                } else if (newValue < 0) {
                    printf("So luong ton kho khong hop le!\n");
                } else {
                    stock[pos - 1] = newValue;

                    printf("Mang hien tai: [");
                    for (i = 0; i < n; i++) {
                        printf("%d", stock[i]);
                        if (i < n - 1)
                            printf(", ");
                    }
                    printf("]\n");
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Mang rong, khong the xoa!\n");
                    break;
                }

                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Vi tri xoa khong hop le!\n");
                } else {
                    for (i = pos - 1; i < n - 1; i++) {
                        stock[i] = stock[i + 1];
                    }

                    n--;

                    printf("Mang hien tai: [");
                    for (i = 0; i < n; i++) {
                        printf("%d", stock[i]);
                        if (i < n - 1)
                            printf(", ");
                    }
                    printf("]\n");
                }
                break;
            case 4:
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                count = 0;
                printf("Tim thay tai vi tri: ");

                for (i = 0; i < n; i++) {
                    if (stock[i] == target) {
                        printf("%d ", i + 1);
                        count++;
                    }
                }
                if (count == 0) {
                    printf("\nKhong tim thay gia tri trong mang!\n");
                } else {
                    printf("\nTong so lan xuat hien: %d\n", count);
                }
                break;
			case 0:
                printf("Thoat chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);

    return 0;
}
