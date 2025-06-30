#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[100];
    double price;
} MENU;

typedef struct {
    char name[50];
    int cnt;
    double total_price;
} ORDER;

void Initial_menulist(MENU* drinks, int* drink_cnt, MENU* desserts, int* dessert_cnt);
void drink_count(MENU* drinks, int drink_cnt, ORDER* orders, int* order_cnt);
void dessert_count(MENU* desserts, int dessert_cnt, ORDER* orders, int* order_cnt);
void print_receipt(ORDER* orders, int order_cnt, FILE* receipt);

int main() {
    MENU drinks[100];
    MENU desserts[100];
    int drink_num = 0, dessert_num = 0;
    ORDER orders[100];
    int order_cnt = 0;
    int choice;
    FILE* receipt = fopen("receipt.txt", "w");

    Initial_menulist(drinks, &drink_num, desserts, &dessert_num);

    while (1) {
        printf("\n--- 주문 메뉴 ---\n");
        printf("1. 음료 주문\n");
        printf("2. 디저트 주문\n");
        printf("0. 주문 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            drink_count(drinks, drink_num, orders, &order_cnt);
        }
        else if (choice == 2) {
            dessert_count(desserts, dessert_num, orders, &order_cnt);
        }
        else if (choice == 0) {
            break;
        }
    }

    print_receipt(orders, order_cnt, receipt);
    fclose(receipt);

    return 0;
}

void Initial_menulist(MENU* drinks, int* drink_cnt, MENU* desserts, int* dessert_cnt) {
    FILE* drink_file = fopen("drink.txt", "r");
    FILE* dessert_file = fopen("dessert.txt", "r");

    char name[50];
    double price;
    int id = 1;

    while (fscanf(drink_file, "%s %lf", name, &price) != EOF) {
        drinks[*drink_cnt].id = id++;
        strcpy(drinks[*drink_cnt].name, name);
        drinks[*drink_cnt].price = price;
        (*drink_cnt)++;
    }

    id = 1;
    while (fscanf(dessert_file, "%s %lf", name, &price) != EOF) {
        desserts[*dessert_cnt].id = id++;
        strcpy(desserts[*dessert_cnt].name, name);
        desserts[*dessert_cnt].price = price;
        (*dessert_cnt)++;
    }

    fclose(drink_file);
    fclose(dessert_file);
}

void drink_count(MENU* drinks, int drink_cnt, ORDER* orders, int* order_cnt) {
    printf("\n--- 음료 메뉴 ---\n");
    for (int i = 0; i < drink_cnt; i++) {
        printf("%d: %s %.2f\n", drinks[i].id, drinks[i].name, drinks[i].price);
    }

    int id, cnt;
    printf("주문할 음료의 ID를 입력하세요: ");
    scanf("%d", &id);
    printf("주문 수량을 입력하세요: ");
    scanf("%d", &cnt);

    for (int i = 0; i < drink_cnt; i++) {
        if (drinks[i].id == id) {
            printf("%s를 %d개 주문했습니다. 총 가격: %.2f\n", drinks[i].name, cnt, drinks[i].price * cnt);

            int found = 0;
            for (int j = 0; j < *order_cnt; j++) {
                if (strcmp(orders[j].name, drinks[i].name) == 0) {
                    orders[j].cnt += cnt;
                    orders[j].total_price += drinks[i].price * cnt;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(orders[*order_cnt].name, drinks[i].name);
                orders[*order_cnt].cnt = cnt;
                orders[*order_cnt].total_price = drinks[i].price * cnt;
                (*order_cnt)++;
            }
            return;
        }
    }
}

void dessert_count(MENU* desserts, int dessert_cnt, ORDER* orders, int* order_cnt) {
    printf("\n--- 디저트 메뉴 ---\n");
    for (int i = 0; i < dessert_cnt; i++) {
        printf("%d : %s %.2f\n", desserts[i].id, desserts[i].name, desserts[i].price);
    }

    int id, cnt;
    printf("주문할 디저트의 ID를 입력하세요: ");
    scanf("%d", &id);
    printf("주문 수량을 입력하세요: ");
    scanf("%d", &cnt);

    for (int i = 0; i < dessert_cnt; i++) {
        if (desserts[i].id == id) {
            printf("%s를 %d개 주문했습니다. 총 가격: %.2f\n", desserts[i].name, cnt, desserts[i].price * cnt);

            int found = 0;
            for (int j = 0; j < *order_cnt; j++) {
                if (strcmp(orders[j].name, desserts[i].name) == 0) {
                    orders[j].cnt += cnt;
                    orders[j].total_price += desserts[i].price * cnt;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(orders[*order_cnt].name, desserts[i].name);
                orders[*order_cnt].cnt = cnt;
                orders[*order_cnt].total_price = desserts[i].price * cnt;
                (*order_cnt)++;
            }
            return;
        }
    }
}

void print_receipt(ORDER* orders, int order_cnt, FILE* receipt) {
    fprintf(receipt, "        영수증       \n");
    fprintf(receipt, "----------------------\n");

    double total = 0.0;
    for (int i = 0; i < order_cnt; i++) {
        fprintf(receipt, "%s x %d = %.2f\n", orders[i].name, orders[i].cnt, orders[i].total_price);
        total += orders[i].total_price;
    }

    fprintf(receipt, "----------------------\n");
    fprintf(receipt, "총합 : %.2f\n", total);
}
