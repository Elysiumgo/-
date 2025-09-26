/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define STUDENT_NUM 10

void inputStudents(char ids[][8], char names[][9], int scores[]) {
    for (int i = 0; i < STUDENT_NUM; i++) {
        printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
        scanf("%7s %8s %d", ids[i], names[i], &scores[i]);
    }
}

// ����,��ѧ�Ž���
void sortStudents(char ids[][8], char names[][9], int scores[]) {
    for (int i = 0; i < STUDENT_NUM - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < STUDENT_NUM; j++) {
            if (strcmp(ids[j], ids[max_idx]) > 0) {
                max_idx = j;
            }
        }
        if (max_idx != i) {

            // ����ѧ��
            char temp_id[8];
            strcpy(temp_id, ids[i]);
            strcpy(ids[i], ids[max_idx]);
            strcpy(ids[max_idx], temp_id);

            // ��������
            char temp_name[9];
            strcpy(temp_name, names[i]);
            strcpy(names[i], names[max_idx]);
            strcpy(names[max_idx], temp_name);

            // �����ɼ�
            int temp_score = scores[i];
            scores[i] = scores[max_idx];
            scores[max_idx] = temp_score;
        }
    }
}

// �������ѧ��
void printPassedStudents(char ids[][8], char names[][9], int scores[]) {
    printf("\n����ѧ����������ѧ�Ž��򣩣�\n");
    for (int i = 0; i < STUDENT_NUM; i++) {
        if (scores[i] >= 60) {
            printf("%s %s %d\n", ids[i], names[i], scores[i]);
        }
    }
}

int main() {
    char ids[STUDENT_NUM][8];    // ѧ��
    char names[STUDENT_NUM][9];  // ����
    int scores[STUDENT_NUM];     // �ɼ�

    inputStudents(ids, names, scores);
    sortStudents(ids, names, scores);
    printPassedStudents(ids, names, scores);

    return 0;
}