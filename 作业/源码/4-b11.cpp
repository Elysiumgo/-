/* 2452545 ����� ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */
void line1(char end_ch) {
	if (end_ch == 'A')
		cout << 'A';
	else {
		cout<< end_ch;
		line1(char(end_ch - 1));
	}
}


void line2(char end_ch) {
	if (end_ch == 'A')
		return;
	else {
		line2(char(end_ch - 1));
		cout << char(end_ch);
	}
}


void kongge(char end_ch) {
	if (end_ch == 'A')
		return;
	else {
		cout << setfill(' ') << setw(2 * (int(end_ch) - 'A') + 1) << ' ';
	}
}







   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_tower(char end_ch,int order)
{
	static int width = (end_ch - 'A') + 1;
	

	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */
	if (order == 1) {
		if (end_ch == 'A') {
			cout << setfill(' ') << setw(width);
			cout <<  'A' << endl;
			return;
		}
			
		else {
			print_tower(char(end_ch-1), 1);
			width -= 1;
			cout << setfill(' ') << setw(width) ;
			line1(char(end_ch));
			line2(char(end_ch));
			cout << endl;
		}
	}

	if (order == 2) {
		if (end_ch == 'A') {
			cout << setfill(' ') << setw(width);
			cout << 'A' << endl;
			return;
		}
		else {
			cout << setfill(' ')<< setw(width) ;
			width += 1;
			line1(char(end_ch));
			line2(char(end_ch));
			cout << endl;
			print_tower(char(end_ch) - 1, 2);
		}

	}
	if (order == 3) { //�����°벿�֣���һ����ĸ��������������A�����

		if (end_ch == '@') {
			return;
		}
		else if (end_ch == 'A') {
			cout << setfill(' ') << setw(width+1);
			cout << 'A' << endl;
			return;
		}
		else {
			cout << setfill(' ') << setw(width+1);
			width += 1;
			line1(char(end_ch));
			line2(char(end_ch));
			cout << endl;
			print_tower(char(end_ch) - 1, 3);
		}

	}

	

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */ 
	cout << setfill('=')<< setw(2 * int(end_ch) - 2 * 'A' + 1) <<'=' << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=')<< setw(2 * end_ch - 2 * 'A' +1) << '=' << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch,1); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') <<setw(2 * int(end_ch) - 2 * 'A' + 1) << '=' <<  endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=') <<setw(2 * int(end_ch) - 2 * 'A' + 1) << '=' <<  endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 2); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setfill('=') <<setw(2 * end_ch - 2 * 'A' + 1) << '='<< endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') <<setw(2 * end_ch - 2 * 'A'  +1) <<'='<<  endl;/* ����ĸ����������= */
	print_tower(end_ch, 1);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch-1, 3);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
