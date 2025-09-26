/* 2452545 计算机 刘晴语 */

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
	bool selected_round_1;  // 记录是否参加第一轮选课
	bool selected_round_2;  // 记录是否参加第二轮选课

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

	// 检查学生是否在某一轮选课中
	bool is_in_round(int round, int student_no);

	// 查找学生在合并列表中的索引
	int find_student(int student_no);

public:
	stu_list();
	int read(const char* filename, const int round);
	int print(const char* prompt = NULL);
	void merge_and_sort();
};

// 构造函数
stu_list::stu_list() {
	list_num_1 = 0;
	list_num_2 = 0;
	list_merge_num = 0;
}

// 检查学生是否在某一轮选课中
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

// 查找学生在合并列表中的索引
int stu_list::find_student(int student_no) {
	for (int i = 0; i < list_merge_num; i++) {
		if (list_merge[i].stu_no == student_no) {
			return i;
		}
	}
	return -1;
}

// 合并去重排序
void stu_list::merge_and_sort() {
	// 先将第一轮学生加入合并列表
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

	// 再处理第二轮学生
	for (int i = 0; i < list_num_2; i++) {
		int idx = find_student(list_round_2[i].no);
		if (idx == -1 && list_merge_num < MAX_STU_NUM) {
			// 第二轮新增学生
			list_merge[list_merge_num].stu_no = list_round_2[i].no;
			strcpy_s(list_merge[list_merge_num].stu_name, list_round_2[i].name);
			list_merge[list_merge_num].selected_round_1 = false;
			list_merge[list_merge_num].selected_round_2 = true;
			list_merge_num++;
		}
		else if (idx != -1) {
			// 更新已存在学生的第二轮选课状态
			list_merge[idx].selected_round_2 = true;
		}
	}

	// 按学号升序排列
	for (int i = 0; i < list_merge_num - 1; i++) {
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				swap(list_merge[j], list_merge[j + 1]);
			}
		}
	}
}

// 打印最终选课名单
int stu_list::print(const char* prompt) {
	if (prompt != NULL) {
		cout << prompt << endl;
	}

	// 计算最长姓名长度
	int max_name_len = 0;
	for (int i = 0; i < list_merge_num; i++) {
		max_name_len = max(max_name_len, (int)strlen(list_merge[i].stu_name));
	}
	int name_width = max_name_len + 4;

	// 计算表格总宽度
	int total_width = 4 + 7 + name_width + 6 + 6 + 2 * 4 + 2;
	string separator(total_width - 3, '=');


	cout << " " << separator << " " << endl;
	cout << " 序号  学号       姓名" << string(name_width - 8, ' ') << "  第一轮  第二轮" << endl;
	cout << " " << separator << " " << endl;

	// 打印学生信息
	for (int i = 0; i < list_merge_num; i++) {
		cout << "  " << setw(4) << left << (i + 1) << "  "
			<< setw(7) << left << list_merge[i].stu_no << "  "
			<< setw(name_width) << left << list_merge[i].stu_name << "  ";

		// 第一轮选课状态
		cout << setw(6) << left << (list_merge[i].selected_round_1 ? "Y" : "/");

		// 第二轮选课状态
		if (list_merge[i].selected_round_1 && !list_merge[i].selected_round_2) {
			cout << "退课    ";  // 第一轮选了但第二轮没选，退课
		}
		else if (!list_merge[i].selected_round_1 && list_merge[i].selected_round_2) {
			cout << "补选    ";  // 第一轮没选但第二轮选了，补选
		}
		else {
			cout << setw(6) << left << (list_merge[i].selected_round_2 ? "Y" : "/") ;
		}
		
		cout << endl;
	}

	cout << " " << separator << " " << endl;
	
	return 0;
}

// 选课名单
int stu_list::read(const char* filename, const int round) {
	int ret = 0;
	switch (round) {
	case 1:
		list_num_1 = read_stulist(filename, list_round_1, MAX_STU_NUM);
		if (list_num_1 > 0)
			print_stulist("第一轮选课名单：", list_round_1, list_num_1);
		else
			ret = -1;
		break;
	case 2:
		list_num_2 = read_stulist(filename, list_round_2, MAX_STU_NUM);
		if (list_num_2 > 0)
			print_stulist("第二轮选课名单：", list_round_2, list_num_2);
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

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1);
	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	if (list.read(file1, 1) < 0 || list.read(file2, 2) < 0) {
		cout << "无法打开该文件。" << endl;
		return -1;
	}

	list.merge_and_sort();
	list.print("最终选课名单");

	return 0;
}

