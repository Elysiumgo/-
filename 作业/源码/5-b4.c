/*刘晴语 2452545 计算机*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int score[1000];
	int i,count=0;
	for (i = 0;i < 1000;i++) {
		scanf("%d", &score[i]);
		count++;
		if (score[i] < 0 && count == 1) {
			printf("无有效输入\n");
			return 0;
		}
		else if (score[i] < 0) {
			break;
		}
			
	}
	//输入结束

	printf("输入的数组为:\n");
	for (i = 0;i < count - 1;i++){
		printf("%d ", score[i]);
		if ((i + 1) % 10==0&&(i+1)>=10)
			printf("\n");
	}
	if (i < 10)
		printf("\n");

	//开始排序
	int j, t;
	for (i = 0;i < count - 1;i++) {
		for (j = 0;j < count - (i + 1);j++) { //把小的数往后移
			if (score[j] < score[j + 1]) {
				t = score[j];
				score[j] = score[j + 1];
				score[j + 1] = t;
			}
		}
	}

	//输出
	printf("分数与人数的对应关系为:\n");
	int sum = 1;
	for (i = 0;i < count - 1;i++) {
		if (i < count - 2 && score[i] == score[i + 1]) { //排列时不能访问最后一个负数
			sum++;
		}
		else {
			printf("%d %d\n", score[i], sum);
			sum = 1;
		}
	}
		return 0;
}





