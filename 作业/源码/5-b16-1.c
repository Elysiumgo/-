/*2452545 计算机 刘晴语*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define STUDENT_NUM 10

void inputStudents(char ids[][8], char names[][9], int scores[]) {
    for (int i = 0; i < STUDENT_NUM; i++) {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
        scanf("%7s %8s %d", ids[i], names[i], &scores[i]);
    }
}

// 排序,按学号降序
void sortStudents(char ids[][8], char names[][9], int scores[]) {
    for (int i = 0; i < STUDENT_NUM - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < STUDENT_NUM; j++) {
            if (strcmp(ids[j], ids[max_idx]) > 0) {
                max_idx = j;
            }
        }
        if (max_idx != i) {

            // 交换学号
            char temp_id[8];
            strcpy(temp_id, ids[i]);
            strcpy(ids[i], ids[max_idx]);
            strcpy(ids[max_idx], temp_id);

            // 交换姓名
            char temp_name[9];
            strcpy(temp_name, names[i]);
            strcpy(names[i], names[max_idx]);
            strcpy(names[max_idx], temp_name);

            // 交换成绩
            int temp_score = scores[i];
            scores[i] = scores[max_idx];
            scores[max_idx] = temp_score;
        }
    }
}

// 输出及格学生
void printPassedStudents(char ids[][8], char names[][9], int scores[]) {
    printf("\n及格学生名单（按学号降序）：\n");
    for (int i = 0; i < STUDENT_NUM; i++) {
        if (scores[i] >= 60) {
            printf("%s %s %d\n", ids[i], names[i], scores[i]);
        }
    }
}

int main() {
    char ids[STUDENT_NUM][8];    // 学号
    char names[STUDENT_NUM][9];  // 姓名
    int scores[STUDENT_NUM];     // 成绩

    inputStudents(ids, names, scores);
    sortStudents(ids, names, scores);
    printPassedStudents(ids, names, scores);

    return 0;
}