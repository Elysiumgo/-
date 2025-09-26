/* 2452545 计算机 刘晴语 */
#include <iostream>
using namespace std;

bool flag_of_zero = true;
bool have_zero = false;


/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：
  返 回 值：num flag_of_zero
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
static void daxie(int num, int flag_of_zero)
{

	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
		cout<< "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double k;
	long long k1, i, k2, i2;
	int count = 1;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> k;
	k1 = static_cast<long long>(k);
	k2 = static_cast<long long>(100 * (k - k1 + 0.005));
	cout << "大写结果是:" << endl;
	//处理十亿、亿
	for (i = 1000000000;i >= 100000000;i /= 10, count += 1) {
		if (k >= i) {
			flag_of_zero = false;
			daxie(k1 / i % 10, flag_of_zero);
			switch (count) {
			case 1:
				cout << "拾";
				break;
			case 2:
				cout << "亿";
				break;
			}
		}
	}
	count = 1;

	flag_of_zero = true;
	have_zero = false;

	//处理千万-万位
	for (i = 10000000;i >= 10000;i /= 10, count++) {
		if (k1 / i % 10 == 0) {
			for (i2 = i / 10;i2 >= 10000;i2 /= 10) {
				if (k1 / i2 % 10 == 0)				//检查本位以下是否都是0，如果都是则false，不输出0
					flag_of_zero = false;

				else {
					flag_of_zero = true;
					break;
				}
			}
			flag_of_zero = (flag_of_zero) && !have_zero;
			have_zero = true;
		}
		else {
			flag_of_zero = true;
			have_zero = false;
		}
		if (i == 10000)
			flag_of_zero = false;
		if(k1>=i)
			daxie(k1 / i % 10, flag_of_zero);

		if (k1 / i % 10 == 0) //如果本位为0，则后一位0不读
			flag_of_zero = false;
		else
			flag_of_zero = true;//每有一位不是0，重置flag

		if (k1 / i % 10) {//此位不是0，则输出中间单位
			switch (count) {
			case 1:
				cout << "仟";
				break;
			case 2:
				cout << "佰";
				break;
			case 3:
				cout << "拾";
				break;
			}
		}
}
if ((k1 / 10000000 % 10 != 0) || k1 / 1000000 % 10 || k1 / 100000 % 10 || k1 / 10000 % 10)
cout << "万";
count = 1;
flag_of_zero = true;
have_zero = false;
//处理千-个位
for (i = 1000;i >= 1;i /= 10, count++) {
	if (k1 / i % 10 == 0) {
		for (i2 = i / 10;i2 >= 1;i2 /= 10) {
			if (k1 / i2 % 10 == 0)				//检查本位以下是否都是0，如果都是则false，不输出0
				flag_of_zero = false;
			else {
				flag_of_zero = true;
				break;
			}
		}
		flag_of_zero = (flag_of_zero) && !have_zero;
		have_zero = true;
	}
	else {
		flag_of_zero = true;
		have_zero = false;
	}
	if (i == 1)
		flag_of_zero = false;
	if (k1 >= i)
		daxie(k1 / i % 10, flag_of_zero);

	if (k1 / i % 10) {//此位不是0，则输出中间单位
		switch (count) {
		case 1:
			cout << "仟";
			break;
		case 2:
			cout << "佰";
			break;
		case 3:
			cout << "拾";
			break;
		}
	}
}
if (k1 > 0)
	cout << "圆";

flag_of_zero = true;
have_zero = false;

if (k1 < 1&&k2==0) {
	daxie(k1 % 10, flag_of_zero);//单独处理0元
	cout << "圆";
}
if (k2 == 0)
cout << "整";
count = 1;
//处理小数位
for (i = 10;i >= 1;i /= 10, count++) {
	if (k2 > 0) {
		flag_of_zero = false;
		if (k1!=0&&k2 / i % 10 == 0&&i==10)
			flag_of_zero = true;
		daxie(k2 / i % 10, flag_of_zero);
		
		if (k2 / i % 10) {//此位不是0，则输出中间单位
			switch (count) {
			case 1:
				cout << "角";
				break;
			case 2:
				cout << "分";
				break;
			}
		}
	}
}
if (k2 % 10 == 0 && k2 != 0)
cout << "整";

cout << endl;






/* 按需完成 */
return 0;
}
