/*2452545 计算机 刘晴语*/

#include<iostream>
#include<cstring>
using namespace std;


int transfer(char* bin)
{
	
	int sum=0, add_term=1;
	char* end = bin + strlen(bin)-1;

	while(end>=bin) {
		sum += (*end-'0') * add_term;
		add_term *= 2;
		
		end--;

	}


	return sum;


}



int main()
{
	char bin[33] = { 0 };
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;

	
	cin >> bin;

	cout << transfer(bin) << endl;
	return 0;

}