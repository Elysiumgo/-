/*2452545 ����� ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double k;
	long long k1;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &k);
	printf("��д�����:\n");
	k1 = (long long)k;
	const int false = 0, true = 1;
	int zheng1 = false, zheng2 = true, zero = false, needzero = false, havezero = true;
	if (k1 / 1000000000 % 10 > 0)//����ʮ��λ
	{
		switch (k1 / 1000000000 % 10)
		{
			case 1:
				printf("Ҽʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 9:
				printf("��ʰ");
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
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("����");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("����");
				break;
			case 8:
				printf("����");
				break;
			case 9:
				printf("����");
				break;
			default:
				break;
		}
	}
	if (k1 / 100000000 % 10 == 0 && k1 / 1000000000 != 0)//ʮ��λ����0����λ��0
		printf("��");

	if (((k1 / 10000000 % 10 == 0) || (k1 / 1000000 % 10 == 0) || (k1 / 100000 % 10 == 0)) && (k1 / 10000 % 10 != 0))
		needzero = true;//ǰ������λ����0��Ҫ��0
	if ((k1 / 10000000 % 10 == 0) && (k1 / 1000000 % 10 != 0))
		needzero = true;//ǧ��λ��0�Ұ���λ����0
	if ((k1 / 1000000 % 10 == 0) && (k1 / 10000 % 10 == 0) && (k1 / 100000 % 10 != 0))
		needzero = true;//����λ����λ��0����

	if (k1 >= 10000000)//����ǧ��λ
	{
		if ((k1 / 10000000 % 10 == 0) && (k1 / 10000 % 10 != 0) && needzero)//ǧ��λ��0
		{
			printf("��");
			needzero = false;
		}
		switch (k1 / 10000000 % 10)
		{
			case 1:
				printf("ҼǪ");
				break;
			case 2:
				printf("��Ǫ");
				break;
			case 3:
				printf("��Ǫ");
				break;
			case 4:
				printf("��Ǫ");
				break;
			case 5:
				printf("��Ǫ");
				break;
			case 6:
				printf("½Ǫ");
				break;
			case 7:
				printf("��Ǫ");
				break;
			case 8:
				printf("��Ǫ");
				break;
			case 9:
				printf("��Ǫ");
				break;
			default:
				break;
		}
	}

	if (k1 >= 1000000)//���ڰ���λ
	{
		if ((k1 / 1000000 % 10 == 0) && needzero )//����λ��0
		{
			printf("��");
			needzero = false;
		}
		switch (k1 / 1000000 % 10)
		{
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("���");
				break;
			case 8:
				printf("�ư�");
				break;
			case 9:
				printf("����");
				break;
			default:
				break;
		}
	}
	if (k1 >= 100000)//����ʮ��λ
	{
		if ((k1 / 100000 % 10 == 0) && needzero && (k1 / 10000 % 10 != 0))//ʮ��λ��0����λ����0
		{
			printf("��");
			needzero = false;
			havezero = false;
		}
		if ((k1 / 100000 % 10 == 0) && (k1 / 10000 % 10 != 0) && (k1 / 1000000 % 10 != 0) && havezero)//�ܹ�������������0
		{
			printf("��");
		}
		havezero = true;
		switch (k1 / 100000 % 10)
		{
			case 1:
				printf("Ҽʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 9:
				printf("��ʰ");
				break;
			default:
				break;
		}
	}
	if (k1 >= 10000)//������λ
	{
		if ((k1 / 10000 % 10 == 0) && ((k1 / 100000 % 10 != 0) || (k1 / 1000000 % 10 != 0) || (k1 / 10000000 % 10 != 0)))//��λ��0,����Ҫ������ǰ������λ�з��㣩
		{
			printf("��");
		}
		switch (k1 / 10000 % 10)
		{
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("����");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("����");
				break;
			case 8:
				printf("����");
				break;
			case 9:
				printf("����");
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
		if ((k1 / 100 % 10 == 0) && (k1 % 10 == 0) && (k1 / 10 % 10 != 0))
			needzero = true;//��λ�͸�λ��0����
		if ((k1 / 100 % 10 == 0) && (k1 / 10 % 10 == 0) && (k1 % 10 == 0))
			needzero = false;//��ʮ��λȫ��0�򲻶�
		if ((k1 / 1000 % 10 == 0) && needzero)//ǧλ��0
		{
			printf("��");
			needzero = false;
		}
		switch (k1 / 1000 % 10)
		{
			case 1:
				printf( "ҼǪ");
				break;
			case 2:
				printf("��Ǫ");
				break;
			case 3:
				printf("��Ǫ");
				break;
			case 4:
				printf( "��Ǫ");
				break;
			case 5:
				printf("��Ǫ");
				break;
			case 6:
				printf("½Ǫ");
				break;
			case 7:
				printf("��Ǫ");
				break;
			case 8:
				printf("��Ǫ");
				break;
			case 9:
				printf("��Ǫ");
				break;
			default:
				break;
		}
	}

	if (k1 > 100)//���ڰ�λ
	{
		if ((k1 / 100 % 10 == 0) && needzero)//��λ��0
		{
			printf("��");
			needzero = false;
		}
		switch (k1 / 100 % 10)
		{
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("���");
				break;
			case 8:
				printf("�ư�");
				break;
			case 9:
				printf("����");
				break;
			default:
				break;
		}
	}
	if (k1 >= 10)//����ʮλ
	{
		if ((k1 / 10 % 10 == 0) && needzero && (k1 % 10 != 0))//ʮλ��0�Ҹ�λ����0
		{
			printf("��");
			needzero = false;
			havezero = false;
		}
		if ((k1 / 10 % 10 == 0) && (k1 % 10 != 0) && (k1 / 100 % 10 != 0) && havezero)//�ܹ�������������0
			printf("��");
		switch (k1 / 10 % 10)
		{
			case 1:
				printf("Ҽʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 9:
				printf("��ʰ");
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
				printf("Բ");
				break;
			case 1:
				printf("ҼԲ");
				break;
			case 2:
				printf("��Բ");
				break;
			case 3:
				printf("��Բ");
				break;
			case 4:
				printf("��Բ");
				break;
			case 5:
				printf("��Բ");
				break;
			case 6:
				printf("½Բ");
				break;
			case 7:
				printf("��Բ");
				break;
			case 8:
				printf("��Բ");
				break;
			case 9:
				printf("��Բ");
				break;
			default:
				break;
		}
	}
	if (k == 0)
		printf("��Բ");
	long long k2 = (long long)(100 * (k - k1) + 0.5);
	zheng2 = (k2 % 10 == 0 && k2 / 10 != 0);//�ڶ�λС����0
	if (k2 == 0)
		printf("��");
	if (k2 > 0)
	{
		if (k1 != 0 && k2 / 10 % 10 == 0)
			printf("��");
		if (k2 >= 10)
		{
			switch (k2 / 10)
			{
				case 1:
					printf("Ҽ��");
					break;
				case 2:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 4:
					printf("����");
					break;
				case 5:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 7:
					printf("���");
					break;
				case 8:
					printf("�ƽ�");
					break;
				case 9:
					printf("����");
					break;
				default:
					break;
			}
		}
	}
	if (zheng2)
		printf("��");
	if (k2 % 10 > 0)
	{
		switch (k2 % 10)
		{
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("���");
				break;
			case 8:
				printf("�Ʒ�");
				break;
			case 9:
				printf("����");
				break;
			default:
				break;
		}
	}
	printf("\n");
	return 0;
}
