/* 2452545 ����� ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const char chnstr[] = "��Ҽ��������½��ƾ�ʰ"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */


//׷��
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


	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &k);
	k1 = (long long)k;
	k2 = (long long)(100 * (k - k1 + 0.005));
	printf("��д�����:\n");
	//����ʮ�ڡ���
	for (i = 1000000000;i >= 100000000;i /= 10, count += 1) {
		if (k >= i) {
			flag_of_zero = 0;
			daxie(k1 / i % 10, flag_of_zero);
			switch (count) {
			case 1:
				tj_strcat(result, "ʰ");
				break;
			case 2:
				tj_strcat(result, "��");
				break;
			}
		}
	}
	count = 1;

	flag_of_zero = 1;
	have_zero = 0;

	//����ǧ��-��λ
	for (i = 10000000;i >= 10000;i /= 10, count++) {
		if (k1 / i % 10 == 0) {
			for (i2 = i / 10;i2 >= 10000;i2 /= 10) {
				if (k1 / i2 % 10 == 0)				//��鱾λ�����Ƿ���0�����������false�������0
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

		if (k1 / i % 10 == 0) //�����λΪ0�����һλ0����
			flag_of_zero = 0;
		else
			flag_of_zero = 1;//ÿ��һλ����0������flag

		if (k1 / i % 10) {//��λ����0��������м䵥λ
			switch (count) {
			case 1:
				tj_strcat(result, "Ǫ");
				break;
			case 2:
				tj_strcat(result, "��");
				break;
			case 3:
				tj_strcat(result, "ʰ");
				break;
			}
		}
	}
	if ((k1 / 10000000 % 10 != 0) || k1 / 1000000 % 10 || k1 / 100000 % 10 || k1 / 10000 % 10)
		tj_strcat(result, "��");
	count = 1;
	flag_of_zero = 1;
	have_zero = 0;
	//����ǧ-��λ
	for (i = 1000;i >= 1;i /= 10, count++) {
		if (k1 / i % 10 == 0) {
			for (i2 = i / 10;i2 >= 1;i2 /= 10) {
				if (k1 / i2 % 10 == 0)				//��鱾λ�����Ƿ���0�����������false�������0
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

		if (k1 / i % 10) {//��λ����0��������м䵥λ
			switch (count) {
			case 1:
				tj_strcat(result, "Ǫ");
				break;
			case 2:
				tj_strcat(result, "��");
				break;
			case 3:
				tj_strcat(result, "ʰ");
				break;
			}
		}
	}
	if (k1 > 0)
		tj_strcat(result, "Բ");

	flag_of_zero = 1;
	have_zero = 0;

	if (k1 < 1 && k2 == 0) {
		daxie(k1 % 10, flag_of_zero);//��������0Ԫ
		tj_strcat(result, "Բ");
	}
	if (k2 == 0)
		tj_strcat(result, "��");
	count = 1;
	//����С��λ
	for (i = 10;i >= 1;i /= 10, count++) {
		if (k2 > 0) {
			flag_of_zero = 0;
			if (k1 != 0 && k2 / i % 10 == 0 && i == 10)
				flag_of_zero = 1;
			daxie(k2 / i % 10, flag_of_zero);

			if (k2 / i % 10) {//��λ����0��������м䵥λ
				switch (count) {
				case 1:
					tj_strcat(result, "��");
					break;
				case 2:
					tj_strcat(result, "��");
					break;
				}
			}
		}
	}
	if (k2 % 10 == 0 && k2 != 0)
		tj_strcat(result, "��");





    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
