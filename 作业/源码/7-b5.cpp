/* 2452545 ����� ������ */

#include <iostream>
#include <cstring>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512

class stu_merge {
private:
	int  stu_no;
	char stu_name[MAX_NAME_LEN];
	bool selected_round_1;  // ��¼�Ƿ�μӵ�һ��ѡ��
	bool selected_round_2;  // ��¼�Ƿ�μӵڶ���ѡ��

	stu_merge() : stu_no(0), selected_round_1(false), selected_round_2(false) {
		stu_name[0] = '\0';
	}

	friend class stu_list;
};

class stu_list {
private:
	student list_round_1[MAX_STU_NUM];
	int list_num_1;

	student list_round_2[MAX_STU_NUM];
	int list_num_2;

	stu_merge list_merge[MAX_STU_NUM];
	int list_merge_num;

	// ���ѧ���Ƿ���ĳһ��ѡ����
	bool is_in_round(int round, int student_no);

	// ����ѧ���ںϲ��б��е�����
	int find_student(int student_no);

public:
	stu_list();
	int read(const char* filename, const int round);
	int print(const char* prompt = NULL);
	void merge_and_sort();
};

// ���캯��
stu_list::stu_list() {
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;
}

// ���ѧ���Ƿ���ĳһ��ѡ����
bool stu_list::is_in_round(int round, int student_no) {
	if (round == 1) {
		for (int i = 0; i < list_num_1; i++) {
			if (list_round_1[i].no == student_no) {
				return true;
			}
		}
	}
	else if (round == 2) {
		for (int i = 0; i < list_num_2; i++) {
			if (list_round_2[i].no == student_no) {
				return true;
			}
		}
	}
	return false;
}

// ����ѧ���ںϲ��б��е�����
int stu_list::find_student(int student_no) {
	for (int i = 0; i < list_merge_num; i++) {
		if (list_merge[i].stu_no == student_no) {
			return i;
		}
	}
	return -1;
}

// �ϲ�ȥ������
void stu_list::merge_and_sort() {
	// �Ƚ���һ��ѧ������ϲ��б�
	for (int i = 0; i < list_num_1; i++) {
		int idx = find_student(list_round_1[i].no);
		if (idx == -1 && list_merge_num < MAX_STU_NUM) {
			list_merge[list_merge_num].stu_no = list_round_1[i].no;
			strcpy_s(list_merge[list_merge_num].stu_name, list_round_1[i].name);
			list_merge[list_merge_num].selected_round_1 = true;
			list_merge[list_merge_num].selected_round_2 = false;
			list_merge_num++;
		}
	}

	// �ٴ���ڶ���ѧ��
	for (int i = 0; i < list_num_2; i++) {
		int idx = find_student(list_round_2[i].no);
		if (idx == -1 && list_merge_num < MAX_STU_NUM) {
			// �ڶ�������ѧ��
			list_merge[list_merge_num].stu_no = list_round_2[i].no;
			strcpy_s(list_merge[list_merge_num].stu_name, list_round_2[i].name);
			list_merge[list_merge_num].selected_round_1 = false;
			list_merge[list_merge_num].selected_round_2 = true;
			list_merge_num++;
		}
		else if (idx != -1) {
			// �����Ѵ���ѧ���ĵڶ���ѡ��״̬
			list_merge[idx].selected_round_2 = true;
		}
	}

	// ��ѧ����������
	for (int i = 0; i < list_merge_num - 1; i++) {
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				swap(list_merge[j], list_merge[j + 1]);
			}
		}
	}
}

// ��ӡ����ѡ������
int stu_list::print(const char* prompt) {
	if (prompt != NULL) {
		cout << prompt << endl;
	}

	// �������������
	int max_name_len = 0;
	for (int i = 0; i < list_merge_num; i++) {
		max_name_len = max(max_name_len, (int)strlen(list_merge[i].stu_name));
	}
	int name_width = max_name_len + 4;

	// �������ܿ��
	int total_width = 4 + 7 + name_width + 6 + 6 + 2 * 4 + 2;
	string separator(total_width - 3, '=');


	cout << " " << separator << " " << endl;
	cout << " ���  ѧ��       ����" << string(name_width - 8, ' ') << "  ��һ��  �ڶ���" << endl;
	cout << " " << separator << " " << endl;

	// ��ӡѧ����Ϣ
	for (int i = 0; i < list_merge_num; i++) {
		cout << "  " << setw(4) << left << (i + 1) << "  "
			<< setw(7) << left << list_merge[i].stu_no << "  "
			<< setw(name_width) << left << list_merge[i].stu_name << "  ";

		// ��һ��ѡ��״̬
		cout << setw(6) << left << (list_merge[i].selected_round_1 ? "Y" : "/");

		// �ڶ���ѡ��״̬
		if (list_merge[i].selected_round_1 && !list_merge[i].selected_round_2) {
			cout << "�˿�    ";  // ��һ��ѡ�˵��ڶ���ûѡ���˿�
		}
		else if (!list_merge[i].selected_round_1 && list_merge[i].selected_round_2) {
			cout << "��ѡ    ";  // ��һ��ûѡ���ڶ���ѡ�ˣ���ѡ
		}
		else {
			cout << setw(6) << left << (list_merge[i].selected_round_2 ? "Y" : "/") ;
		}
		
		cout << endl;
	}

	cout << " " << separator << " " << endl;
	
	return 0;
}

// ѡ������
int stu_list::read(const char* filename, const int round) {
	int ret = 0;
	switch (round) {
	case 1:
		list_num_1 = read_stulist(filename, list_round_1, MAX_STU_NUM);
		if (list_num_1 > 0)
			print_stulist("��һ��ѡ��������", list_round_1, list_num_1);
		else
			ret = -1;
		break;
	case 2:
		list_num_2 = read_stulist(filename, list_round_2, MAX_STU_NUM);
		if (list_num_2 > 0)
			print_stulist("�ڶ���ѡ��������", list_round_2, list_num_2);
		else
			ret = -1;
		break;
	default:
		ret = -1;
		break;
	}
	return ret;
}

int main(int argc, char** argv) {
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1);
	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	if (list.read(file1, 1) < 0 || list.read(file2, 2) < 0) {
		cout << "�޷��򿪸��ļ���" << endl;
		return -1;
	}

	list.merge_and_sort();
	list.print("����ѡ������");

	return 0;
}

