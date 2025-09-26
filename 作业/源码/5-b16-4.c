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

// 排序,按成绩降序
void sortStudents(char ids[][8], char names[][9], int scores[]) {
    for (int i = 0; i < STUDENT_NUM - 1; i++) {
        int max_score = i;
        for (int j = i + 1; j < STUDENT_NUM; j++) {
            if (scores[j]> scores[max_score]) {
                max_score = j;
            }
        }
        if (max_score != i) {

            // 交换成绩
            int temp_score = scores[i];
            scores[i] = scores[max_score];
            scores[max_score] = temp_score;
            // 交换学号
            char temp_id[8];
            strcpy(temp_id, ids[i]);
            strcpy(ids[i], ids[max_score]);
            strcpy(ids[max_score], temp_id);

            // 交换姓名
            char temp_name[9];
            strcpy(temp_name, names[i]);
            strcpy(names[i], names[max_score]);
            strcpy(names[max_score], temp_name);

            
        }
    }
}

// 输出及格学生
void printPassedStudents(char ids[][8], char names[][9], int scores[]) {
    printf("\n全部学生(成绩降序）: \n");
    for (int i = 0; i < STUDENT_NUM; i++) {
            printf("%s %s %d\n", ids[i], names[i], scores[i]);
        
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