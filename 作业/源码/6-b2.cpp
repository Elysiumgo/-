/*2452545 计算机 刘晴语*/
#include<iostream>
#include<cstring>
#define N 80
using namespace std;


bool backNforth(char *str)
{
	int len = strlen(str);
	if (len <= 1) {
		return true;
	}
	
	char* check_right = &str[len - 1];
	char* check_left = str;

	while (check_left < check_right) {
		if (*check_left != *check_right)
			return false;


		check_left++;
		check_right--;


	}

	return true;







}




int main()
{
	
	char input[N + 2];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(input, sizeof(input), stdin);
	int len = strlen(input);
	if (len > 0 && input[len - 1] == '\n') {
		input[len - 1] = '\0';
	}

	cout << (backNforth(input) ? "yes" : "no") << endl;




}