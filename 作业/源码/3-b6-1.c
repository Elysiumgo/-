/*2452545 计算机 刘晴语*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double k;
	long long k1;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &k);
	printf("大写结果是:\n");
	k1 = (long long)k;
	const int false = 0, true = 1;
	int zheng1 = false, zheng2 = true, zero = false, needzero = false, havezero = true;
	if (k1 / 1000000000 % 10 > 0)//存在十亿位
	{
		switch (k1 / 1000000000 % 10)
		{
			case 1:
				printf("壹拾");
				break;
			case 2:
				printf("贰拾");
				break;
			case 3:
				printf("叁拾");
				break;
			case 4:
				printf("肆拾");
				break;
			case 5:
				printf("伍拾");
				break;
			case 6:
				printf("陆拾");
				break;
			case 7:
				printf("柒拾");
				break;
			case 8:
				printf("捌拾");
				break;
			case 9:
				printf("玖拾");
				break;
			default:
				break;

		}
	}
	if (k1 / 100000000 % 10 > 0) //存在不为0的亿位
	{
		switch (k1 / 100000000 % 10)
		{
			case 1:
				printf("壹亿");
				break;
			case 2:
				printf("贰亿");
				break;
			case 3:
				printf("叁亿");
				break;
			case 4:
				printf("肆亿");
				break;
			case 5:
				printf("伍亿");
				break;
			case 6:
				printf("陆亿");
				break;
			case 7:
				printf("柒亿");
				break;
			case 8:
				printf("捌亿");
				break;
			case 9:
				printf("玖亿");
				break;
			default:
				break;
		}
	}
	if (k1 / 100000000 % 10 == 0 && k1 / 1000000000 != 0)//十亿位不是0，亿位是0
		printf("亿");

	if (((k1 / 10000000 % 10 == 0) || (k1 / 1000000 % 10 == 0) || (k1 / 100000 % 10 == 0)) && (k1 / 10000 % 10 != 0))
		needzero = true;//前三个万位存在0且要读0
	if ((k1 / 10000000 % 10 == 0) && (k1 / 1000000 % 10 != 0))
		needzero = true;//千万位是0且百万位不是0
	if ((k1 / 1000000 % 10 == 0) && (k1 / 10000 % 10 == 0) && (k1 / 100000 % 10 != 0))
		needzero = true;//百万位和万位是0，读

	if (k1 >= 10000000)//存在千万位
	{
		if ((k1 / 10000000 % 10 == 0) && (k1 / 10000 % 10 != 0) && needzero)//千万位是0
		{
			printf("零");
			needzero = false;
		}
		switch (k1 / 10000000 % 10)
		{
			case 1:
				printf("壹仟");
				break;
			case 2:
				printf("贰仟");
				break;
			case 3:
				printf("叁仟");
				break;
			case 4:
				printf("肆仟");
				break;
			case 5:
				printf("伍仟");
				break;
			case 6:
				printf("陆仟");
				break;
			case 7:
				printf("柒仟");
				break;
			case 8:
				printf("捌仟");
				break;
			case 9:
				printf("玖仟");
				break;
			default:
				break;
		}
	}

	if (k1 >= 1000000)//存在百万位
	{
		if ((k1 / 1000000 % 10 == 0) && needzero )//百万位是0
		{
			printf("零");
			needzero = false;
		}
		switch (k1 / 1000000 % 10)
		{
			case 1:
				printf("壹佰");
				break;
			case 2:
				printf("贰佰");
				break;
			case 3:
				printf("叁佰");
				break;
			case 4:
				printf("肆佰");
				break;
			case 5:
				printf("伍佰");
				break;
			case 6:
				printf("陆佰");
				break;
			case 7:
				printf("柒佰");
				break;
			case 8:
				printf("捌佰");
				break;
			case 9:
				printf("玖佰");
				break;
			default:
				break;
		}
	}
	if (k1 >= 100000)//存在十万位
	{
		if ((k1 / 100000 % 10 == 0) && needzero && (k1 / 10000 % 10 != 0))//十万位是0且万位不是0
		{
			printf("零");
			needzero = false;
			havezero = false;
		}
		if ((k1 / 100000 % 10 == 0) && (k1 / 10000 % 10 != 0) && (k1 / 1000000 % 10 != 0) && havezero)//能够输出两个相隔的0
		{
			printf("零");
		}
		havezero = true;
		switch (k1 / 100000 % 10)
		{
			case 1:
				printf("壹拾");
				break;
			case 2:
				printf("贰拾");
				break;
			case 3:
				printf("叁拾");
				break;
			case 4:
				printf("肆拾");
				break;
			case 5:
				printf("伍拾");
				break;
			case 6:
				printf("陆拾");
				break;
			case 7:
				printf("柒拾");
				break;
			case 8:
				printf("捌拾");
				break;
			case 9:
				printf("玖拾");
				break;
			default:
				break;
		}
	}
	if (k1 >= 10000)//存在万位
	{
		if ((k1 / 10000 % 10 == 0) && ((k1 / 100000 % 10 != 0) || (k1 / 1000000 % 10 != 0) || (k1 / 10000000 % 10 != 0)))//万位是0,且需要读出万（前三个万位有非零）
		{
			printf("万");
		}
		switch (k1 / 10000 % 10)
		{
			case 1:
				printf("壹万");
				break;
			case 2:
				printf("贰万");
				break;
			case 3:
				printf("叁万");
				break;
			case 4:
				printf("肆万");
				break;
			case 5:
				printf("伍万");
				break;
			case 6:
				printf("陆万");
				break;
			case 7:
				printf("柒万");
				break;
			case 8:
				printf("捌万");
				break;
			case 9:
				printf("玖万");
				break;
			default:
				break;
		}
	}
	if (k1 >= 1000)//存在千位
	{
		if (((k1 / 1000 % 10 == 0) || (k1 / 100 % 10 == 0) || (k1 / 10 % 10 == 0)) && (k1 % 10 != 0))
			needzero = true;//千百十位存在0,个位不是0，需要读0
		if ((k1 / 1000 % 10 == 0) && (k1 / 100 % 10 != 0))
			needzero = true;//千位是0且百位不是0，个位无所谓
		if ((k1 / 100 % 10 == 0) && (k1 % 10 == 0) && (k1 / 10 % 10 != 0))
			needzero = true;//百位和个位是0，读
		if ((k1 / 100 % 10 == 0) && (k1 / 10 % 10 == 0) && (k1 % 10 == 0))
			needzero = false;//百十个位全是0则不读
		if ((k1 / 1000 % 10 == 0) && needzero)//千位是0
		{
			printf("零");
			needzero = false;
		}
		switch (k1 / 1000 % 10)
		{
			case 1:
				printf( "壹仟");
				break;
			case 2:
				printf("贰仟");
				break;
			case 3:
				printf("叁仟");
				break;
			case 4:
				printf( "肆仟");
				break;
			case 5:
				printf("伍仟");
				break;
			case 6:
				printf("陆仟");
				break;
			case 7:
				printf("柒仟");
				break;
			case 8:
				printf("捌仟");
				break;
			case 9:
				printf("玖仟");
				break;
			default:
				break;
		}
	}

	if (k1 > 100)//存在百位
	{
		if ((k1 / 100 % 10 == 0) && needzero)//百位是0
		{
			printf("零");
			needzero = false;
		}
		switch (k1 / 100 % 10)
		{
			case 1:
				printf("壹佰");
				break;
			case 2:
				printf("贰佰");
				break;
			case 3:
				printf("叁佰");
				break;
			case 4:
				printf("肆佰");
				break;
			case 5:
				printf("伍佰");
				break;
			case 6:
				printf("陆佰");
				break;
			case 7:
				printf("柒佰");
				break;
			case 8:
				printf("捌佰");
				break;
			case 9:
				printf("玖佰");
				break;
			default:
				break;
		}
	}
	if (k1 >= 10)//存在十位
	{
		if ((k1 / 10 % 10 == 0) && needzero && (k1 % 10 != 0))//十位是0且个位不是0
		{
			printf("零");
			needzero = false;
			havezero = false;
		}
		if ((k1 / 10 % 10 == 0) && (k1 % 10 != 0) && (k1 / 100 % 10 != 0) && havezero)//能够输出两个相隔的0
			printf("零");
		switch (k1 / 10 % 10)
		{
			case 1:
				printf("壹拾");
				break;
			case 2:
				printf("贰拾");
				break;
			case 3:
				printf("叁拾");
				break;
			case 4:
				printf("肆拾");
				break;
			case 5:
				printf("伍拾");
				break;
			case 6:
				printf("陆拾");
				break;
			case 7:
				printf("柒拾");
				break;
			case 8:
				printf("捌拾");
				break;
			case 9:
				printf("玖拾");
				break;
			default:
				break;
		}
	}
	if (k1 > 0)
	{
		switch (k1 % 10)
		{
			case 0:
				printf("圆");
				break;
			case 1:
				printf("壹圆");
				break;
			case 2:
				printf("贰圆");
				break;
			case 3:
				printf("叁圆");
				break;
			case 4:
				printf("肆圆");
				break;
			case 5:
				printf("伍圆");
				break;
			case 6:
				printf("陆圆");
				break;
			case 7:
				printf("柒圆");
				break;
			case 8:
				printf("捌圆");
				break;
			case 9:
				printf("玖圆");
				break;
			default:
				break;
		}
	}
	if (k == 0)
		printf("零圆");
	long long k2 = (long long)(100 * (k - k1) + 0.5);
	zheng2 = (k2 % 10 == 0 && k2 / 10 != 0);//第二位小数是0
	if (k2 == 0)
		printf("整");
	if (k2 > 0)
	{
		if (k1 != 0 && k2 / 10 % 10 == 0)
			printf("零");
		if (k2 >= 10)
		{
			switch (k2 / 10)
			{
				case 1:
					printf("壹角");
					break;
				case 2:
					printf("贰角");
					break;
				case 3:
					printf("叁角");
					break;
				case 4:
					printf("肆角");
					break;
				case 5:
					printf("伍角");
					break;
				case 6:
					printf("陆角");
					break;
				case 7:
					printf("柒角");
					break;
				case 8:
					printf("捌角");
					break;
				case 9:
					printf("玖角");
					break;
				default:
					break;
			}
		}
	}
	if (zheng2)
		printf("整");
	if (k2 % 10 > 0)
	{
		switch (k2 % 10)
		{
			case 1:
				printf("壹分");
				break;
			case 2:
				printf("贰分");
				break;
			case 3:
				printf("叁分");
				break;
			case 4:
				printf("肆分");
				break;
			case 5:
				printf("伍分");
				break;
			case 6:
				printf("陆分");
				break;
			case 7:
				printf("柒分");
				break;
			case 8:
				printf("捌分");
				break;
			case 9:
				printf("玖分");
				break;
			default:
				break;
		}
	}
	printf("\n");
	return 0;
}
