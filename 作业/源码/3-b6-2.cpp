/*������ 2452545 �����*/
#include <iostream>
using namespace std;
int main()
{
	double k;
	long long k1;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> k;
	cout << "��д�����:" << endl;
	k1 = static_cast<long long>(k);
	bool zheng1 = false, zheng2 = false, zero = false, needzero = false, havezero = true;
	if (k1 / 1000000000 % 10 > 0)//����ʮ��λ
	{
		switch (k1 / 1000000000 % 10)
		{
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
			default:
				break;

		}
	}
	if (k1 / 100000000 % 10 > 0) //���ڲ�Ϊ0����λ
	{
		switch (k1 / 100000000 % 10)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}
	if (k1 / 100000000 % 10 == 0 && k1 / 1000000000 != 0)//ʮ��λ����0����λ��0
		cout << "��";

	if (((k1 / 10000000 % 10 == 0) || (k1 / 1000000 % 10 == 0) || (k1 / 100000 % 10 == 0)) && (k1 / 10000 % 10 != 0))
		needzero = true;//ǰ������λ����0��Ҫ��0
	if ((k1 / 10000000 % 10 == 0) && (k1 / 1000000 % 10 != 0))
		needzero = true;//ǧ��λ��0�Ұ���λ����0
	if ((k1 / 1000000 % 10 == 0) && (k1/10000 % 10 == 0)&&(k1/100000%10!=0))
		needzero = true;//����λ����λ��0����

	if (k1 >= 10000000)//����ǧ��λ
	{
		if ((k1 / 10000000 % 10 == 0)  && needzero)//ǧ��λ��0
		{
			cout << "��";
			needzero = false;
		}
		switch (k1 / 10000000 % 10)
		{
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
			default:
				break;
		}
	}

	if (k1 >= 1000000)//���ڰ���λ
	{
		if ((k1 / 1000000 % 10 == 0) && needzero )//����λ��0
		{
			cout << "��";
			needzero = false;
		}
		switch (k1 / 1000000 % 10)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}
	if (k1 >= 100000)//����ʮ��λ
	{
		if ((k1 / 100000 % 10 == 0) && needzero && (k1 / 10000 % 10 != 0))//ʮ��λ��0����λ����0
		{
			cout << "��";
			needzero = false;
			havezero = false;
		}
		if ((k1 / 100000 % 10 == 0) && (k1 / 10000 % 10 != 0) && (k1 / 1000000 % 10 != 0) && havezero)//�ܹ�������������0
		{
			cout << "��";
		}
		havezero = true;
		switch (k1 / 100000 % 10)
		{
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
				break;
			default:
				break;
		}
	}
	if (k1 >= 10000)//������λ
	{
		if ((k1 / 10000 % 10 == 0) && ((k1 / 100000 % 10 != 0) || (k1 / 1000000 % 10 != 0) || (k1 / 10000000 % 10 != 0)))//��λ��0,����Ҫ������ǰ������λ�з��㣩
		{
			cout << "��";
		}
		switch (k1 / 10000 % 10)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}
	if (k1 >= 1000)//����ǧλ
	{
		if (((k1 / 1000 % 10 == 0) || (k1 / 100 % 10 == 0) || (k1 / 10 % 10 == 0)) && (k1 % 10 != 0))
			needzero = true;//ǧ��ʮλ����0,��λ����0����Ҫ��0
		if ((k1 / 1000 % 10 == 0) && (k1 / 100 % 10 != 0))
			needzero = true;//ǧλ��0�Ұ�λ����0����λ����ν
		if ((k1 / 100 % 10 == 0) && (k1 % 10 == 0)&&(k1/10%10!=0))
			needzero = true;//��λ�͸�λ��0����
		if ((k1 / 100 % 10 == 0) && (k1 / 10 % 10 == 0) && (k1 % 10 == 0))
			needzero = false;//��ʮ��λȫ��0�򲻶�
		if ((k1 / 1000 % 10 == 0) && needzero)//ǧλ��0
		{
			cout << "��";
			needzero = false;
		}
		switch (k1 / 1000 % 10)
		{
			case 1:
				cout << "ҼǪ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 9:
				cout << "��Ǫ";
				break;
			default:
				break;
		}
	}

	if (k1 > 100)//���ڰ�λ
	{
		if ((k1 / 100 % 10 == 0) && needzero)//��λ��0
		{
			cout << "��";
			needzero = false;
		}
		switch (k1 / 100 % 10)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}
	if (k1 >= 10)//����ʮλ
	{
		if ((k1 / 10 % 10 == 0) && needzero && (k1 % 10 != 0))//ʮλ��0�Ҹ�λ����0
		{
			cout << "��";
			needzero = false;
			havezero = false;
		}
		if ((k1 / 10 % 10 == 0) && (k1 % 10 != 0) && (k1 / 100 % 10 != 0) && havezero)//�ܹ�������������0
			cout << "��";
		switch (k1 / 10 % 10)
		{
			case 1:
				cout << "Ҽʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 9:
				cout << "��ʰ";
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
				cout << "Բ";
				break;
			case 1:
				cout << "ҼԲ";
				break;
			case 2:
				cout << "��Բ";
				break;
			case 3:
				cout << "��Բ";
				break;
			case 4:
				cout << "��Բ";
				break;
			case 5:
				cout << "��Բ";
				break;
			case 6:
				cout << "½Բ";
				break;
			case 7:
				cout << "��Բ";
				break;
			case 8:
				cout << "��Բ";
				break;
			case 9:
				cout << "��Բ";
				break;
			default:
				break;
		}
	}
	if (k == 0)
		cout << "��Բ";
	long long k2 = (long long)(100 * (k - k1) + 0.5);
	zheng2 = (k2 % 10 == 0 && k2 / 10 != 0);//�ڶ�λС����0
	if (k2 == 0)
		cout << "��";
	if (k2 > 0)
	{
		if (k1 != 0 && k2 / 10 % 10 == 0)
			cout << "��";
		if (k2 >= 10)
		{
			switch (k2 / 10)
			{
				case 1:
					cout << "Ҽ��";
					break;
				case 2:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 4:
					cout << "����";
					break;
				case 5:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 7:
					cout << "���";
					break;
				case 8:
					cout << "�ƽ�";
					break;
				case 9:
					cout << "����";
					break;
				default:
					break;
			}
		}
	}
	if (zheng2)
		cout << "��";
	if (k2 % 10 > 0)
	{
		switch (k2 % 10)
		{
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�Ʒ�";
				break;
			case 9:
				cout << "����";
				break;
			default:
				break;
		}
	}
	cout << endl;
	return 0;
}
