#include <stdio.h>

int vip_rooms[3] = { 0 };
int normal_rooms[5] = { 0 };

int vip_num[3] = { 301, 302, 303 };
int normal_num[5] = { 201, 202, 203, 204, 205 };

int vip_check(int num_people, int* assigned_rooms);
int normal_check(int num_people, int* assigned_rooms);
int reservation_hotel(int num_people, char room_type, int* assigned_rooms);

int main() {
    int num;
    char room;
    int assigned_rooms[5];

    for (int i = 0; i < 5; i++) {
        printf("예약 인원: ");
        scanf("%d", &num);
        printf("방 종류 (V: VIP, N: 일반): ");
        scanf(" %c", &room);

        int result = reservation_hotel(num, room, assigned_rooms);

        if (result == -1) {
            printf("예약 실패.\n");
        }
        else {
            printf("예약 성공. 방 번호: ");
            for (int j = 0; j < result; j++) {
                printf("%d ", assigned_rooms[j]);
            }
            printf("\n");
        }
    }
    return 0;
}

int vip_check(int num_people, int* assigned_rooms) {
    int rooms_needed = (num_people + 3) / 4;
    int rooms_assigned = 0;

    for (int i = 0; i < 3 && rooms_assigned < rooms_needed; i++) {
        if (vip_rooms[i] == 0) {
            vip_rooms[i] = 1;
            assigned_rooms[rooms_assigned++] = vip_num[i];
        }
    }

    if (rooms_assigned != rooms_needed) {
        for (int i = 0; i < rooms_assigned; i++) {
            for (int j = 0; j < 3; j++) {
                if (vip_num[j] == assigned_rooms[i]) {
                    vip_rooms[j] = 0;
                }
            }
        }
        return -1;
    }
    return rooms_assigned;
}

int normal_check(int num_people, int* assigned_rooms) {
    int rooms_needed = (num_people + 1) / 2;
    int rooms_assigned = 0;

    for (int i = 0; i < 5 && rooms_assigned < rooms_needed; i++) {
        if (normal_rooms[i] == 0) {
            normal_rooms[i] = 1;
            assigned_rooms[rooms_assigned++] = normal_num[i];
        }
    }

    if (rooms_assigned != rooms_needed) {
        for (int i = 0; i < rooms_assigned; i++) {
            for (int j = 0; j < 5; j++) {
                if (normal_num[j] == assigned_rooms[i]) {
                    normal_rooms[j] = 0;
                }
            }
        }
        return -1;
    }
    return rooms_assigned;
}

int reservation_hotel(int num_people, char room_type, int* assigned_rooms) {
    int rooms_assigned = -1;
    if (room_type == 'V' || room_type == 'v') {
        rooms_assigned = vip_check(num_people, assigned_rooms);
    }
    else if (room_type == 'N' || room_type == 'n') {
        rooms_assigned = normal_check(num_people, assigned_rooms);
    }
    return rooms_assigned;
}
