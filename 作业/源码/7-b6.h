/* 2452545 计算机 刘晴语 */
#pragma once

class Date {
private:
    int year;
    int month;
    int day;
    /* 不允许添加数据成员 */

    // 辅助函数：检查日期是否合法
    bool isCorrectDate(int y, int m, int d);

    // 辅助函数：设置默认值
    void setDefaults();

public:
    // 构造函数
    Date();                      // 默认2000.1.1
    Date(int y, int m, int d);   // 三参数构造
    Date(int days);              // 一参数构造(从1900.1.1开始的天数)

    // set函数
    void set(int y, int m, int d);
    void set(int y, int m);      // 日默认为1
    void set(int y);             // 月日默认为1

    // get函数
    void get(int& y, int& m, int& d) const;

    // show函数
    void show() const;
};