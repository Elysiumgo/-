/* 2452545 ����� ������ */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	cin.getline(str, 256);
	p = str;
	pa = a;
	pnum = a;
	is_num = false;
	while (*p != '\0' && (pa - a) < N) {
		if (*p >= '0' && *p <= '9'){
			*pa = *pa * 10 + (*p - '0');
			is_num = true;
		}
		else
			if (is_num) { // ֮ǰ�����֣������ַ���һ�����ֽ���
				pa++;
				is_num = false;
			}

		p++;
	}

	if (is_num && (pa - a) < N) {
		pa++;
	}

	cout << "����" << pa-a << "������" << endl;

	for (pnum = a; pnum < pa; pnum++) {
		cout << *pnum;
		if (pnum < pa - 1) {
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}