/* 2452545 计算机 刘晴语 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖拾"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */


//追加
int tj_strcat(char s1[], const char s2[])
{
	int i = 0, j = 0;

	while (s1[i] != '\0') {
		i++;
	}

	while (s2[j] != '\0') {
		s1[i++] = s2[j++];
	}
	s1[i] = '\0';

	return 0;




}



void daxie(int num, int flag_of_zero)
{
	if (num != 0) {
		char tem[3] = { chnstr[num * 2],chnstr[num * 2 + 1],0 };
		tj_strcat (result, tem);
	}
	else if (num == 0 && flag_of_zero) {
		char tem[3] = { chnstr[num * 2],chnstr[num * 2 + 1],0 };
		tj_strcat(result, tem);
	}

}


int main()
{
	double k;
	long long k1, i, k2, i2;
	int count = 1;
	int flag_of_zero = 1;
	int have_zero = 0;


	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &k);
	k1 = (long long)k;
	k2 = (long long)(100 * (k - k1 + 0.005));
	printf("大写结果是:\n");
	//处理十亿、亿
	for (i = 1000000000;i >= 100000000;i /= 10, count += 1) {
		if (k >= i) {
			flag_of_zero = 0;
			daxie(k1 / i % 10, flag_of_zero);
			switch (count) {
			case 1:
				tj_strcat(result, "拾");
				break;
			case 2:
				tj_strcat(result, "亿");
				break;
			}
		}
	}
	count = 1;

	flag_of_zero = 1;
	have_zero = 0;

	//处理千万-万位
	for (i = 10000000;i >= 10000;i /= 10, count++) {
		if (k1 / i % 10 == 0) {
			for (i2 = i / 10;i2 >= 10000;i2 /= 10) {
				if (k1 / i2 % 10 == 0)				//检查本位以下是否都是0，如果都是则false，不输出0
					flag_of_zero = 0;

				else {
					flag_of_zero = 1;
					break;
				}
			}
			flag_of_zero = (flag_of_zero) && !have_zero;
			have_zero = 1;
		}
		else {
			flag_of_zero = 1;
			have_zero = 0;
		}
		if (i == 10000)
			flag_of_zero = 0;
		if (k1 >= i)
			daxie(k1 / i % 10, flag_of_zero);

		if (k1 / i % 10 == 0) //如果本位为0，则后一位0不读
			flag_of_zero = 0;
		else
			flag_of_zero = 1;//每有一位不是0，重置flag

		if (k1 / i % 10) {//此位不是0，则输出中间单位
			switch (count) {
			case 1:
				tj_strcat(result, "仟");
				break;
			case 2:
				tj_strcat(result, "佰");
				break;
			case 3:
				tj_strcat(result, "拾");
				break;
			}
		}
	}
	if ((k1 / 10000000 % 10 != 0) || k1 / 1000000 % 10 || k1 / 100000 % 10 || k1 / 10000 % 10)
		tj_strcat(result, "万");
	count = 1;
	flag_of_zero = 1;
	have_zero = 0;
	//处理千-个位
	for (i = 1000;i >= 1;i /= 10, count++) {
		if (k1 / i % 10 == 0) {
			for (i2 = i / 10;i2 >= 1;i2 /= 10) {
				if (k1 / i2 % 10 == 0)				//检查本位以下是否都是0，如果都是则false，不输出0
					flag_of_zero = 0;
				else {
					flag_of_zero = 1;
					break;
				}
			}
			flag_of_zero = (flag_of_zero) && !have_zero;
			have_zero = 1;
		}
		else {
			flag_of_zero = 1;
			have_zero = 0;
		}
		if (i == 1)
			flag_of_zero = 0;
		if (k1 >= i)
			daxie(k1 / i % 10, flag_of_zero);

		if (k1 / i % 10) {//此位不是0，则输出中间单位
			switch (count) {
			case 1:
				tj_strcat(result, "仟");
				break;
			case 2:
				tj_strcat(result, "佰");
				break;
			case 3:
				tj_strcat(result, "拾");
				break;
			}
		}
	}
	if (k1 > 0)
		tj_strcat(result, "圆");

	flag_of_zero = 1;
	have_zero = 0;

	if (k1 < 1 && k2 == 0) {
		daxie(k1 % 10, flag_of_zero);//单独处理0元
		tj_strcat(result, "圆");
	}
	if (k2 == 0)
		tj_strcat(result, "整");
	count = 1;
	//处理小数位
	for (i = 10;i >= 1;i /= 10, count++) {
		if (k2 > 0) {
			flag_of_zero = 0;
			if (k1 != 0 && k2 / i % 10 == 0 && i == 10)
				flag_of_zero = 1;
			daxie(k2 / i % 10, flag_of_zero);

			if (k2 / i % 10) {//此位不是0，则输出中间单位
				switch (count) {
				case 1:
					tj_strcat(result, "角");
					break;
				case 2:
					tj_strcat(result, "分");
					break;
				}
			}
		}
	}
	if (k2 % 10 == 0 && k2 != 0)
		tj_strcat(result, "整");





    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
