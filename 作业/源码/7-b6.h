/* 2452545 ����� ������ */
#pragma once

class Date {
private:
    int year;
    int month;
    int day;
    /* ������������ݳ�Ա */

    // ������������������Ƿ�Ϸ�
    bool isCorrectDate(int y, int m, int d);

    // ��������������Ĭ��ֵ
    void setDefaults();

public:
    // ���캯��
    Date();                      // Ĭ��2000.1.1
    Date(int y, int m, int d);   // ����������
    Date(int days);              // һ��������(��1900.1.1��ʼ������)

    // set����
    void set(int y, int m, int d);
    void set(int y, int m);      // ��Ĭ��Ϊ1
    void set(int y);             // ����Ĭ��Ϊ1

    // get����
    void get(int& y, int& m, int& d) const;

    // show����
    void show() const;
};