/*刘晴语 2452545 计算机*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf( "请输入找零值：\n" );
	float k;
	int t50 = 0, t20 = 0, t10 = 0, t5 = 0, t1 = 0, t05 = 0, t01 = 0, t005 = 0, t002 = 0, t001 = 0, k2 = 0;
	scanf("%f",&k);
	t50 = (int) (k / 50);
	t20 = (int)((k - 50 * t50) / 20);
	t10 = (int)((k - 50 * t50 - 20 * t20) / 10);
	t5 = (int)((k - 50 * t50 - 20 * t20 - 10 * t10) / 5);
	t1 = (int)(k - 50 * t50 - 20 * t20 - 5 * t5 - 10 * t10);

	k2 = (int)(100 * (k - 50 * t50 - 20 * t20 - 5 * t5 - 10 * t10 - t1) + 0.5); //处理小数部分
	t05 = (int)(k2 / 50);
	t01 = (int)((k2 - 50 * t05) / 10);
	t005 = (int)((k2 - 50 * t05 - 10 * t01) / 5);
	t002 = (int)((k2 - 50 * t05 - 10 * t01 - 5 * t005) / 2);
	t001 = (int)(k2 - 50 * t05 - 10 * t01 - 5 * t005 - 2 * t002);

	printf("共%d张找零，具体如下：\n", (t50 + t20 + t10 + t5 + t1 + t05 + t01 + t005 + t002 + t001) );

	if (t50 != 0)
		printf("%-4s : %d张\n", "50元", t50);
	if (t20 != 0)
		printf("%-4s : %d张\n", "20元", t20);
	if (t10 != 0)
		printf("%-4s : %d张\n", "10元", t10);
	if (t5 != 0)
		printf("%-4s : %d张\n", "5元", t5);
	if (t1 != 0)
		printf("%-4s : %d张\n", "1元", t1);
	if (t05 != 0)
		printf("%-4s : %d张\n", "5角", t05);
	if (t01 != 0)
		printf("%-4s : %d张\n", "1角", t01);
	if (t005 != 0)
		printf("%-4s : %d张\n", "5分", t005);
	if (t002 != 0)
		printf("%-4s : %d张\n", "2分", t002);
	if (t001 != 0)
		printf("%-4s : %d张\n", "1分", t001);



	return 0;
}