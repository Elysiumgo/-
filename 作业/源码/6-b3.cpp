/*2452545 ����� ������*/

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
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;

	
	cin >> bin;

	cout << transfer(bin) << endl;
	return 0;

}