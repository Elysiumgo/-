/* 2452545 计算机 刘晴语 */
#include<iostream>
#include<conio.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "pullze.h"

#define MAX_HINTS 8
using namespace std;




//伪图形界面的相关函数


struct puzzle {
    int size;
    int data[15][15]; // 按最大尺寸分配
};

struct Hints {
    int row_hints[15][MAX_HINTS] = { 0 }; // 行提示 [行号][提示序列]
    int col_hints[15][MAX_HINTS] = { 0 }; // 列提示 [列号][提示序列]
    int row_counts[15] = { 0 }; // 每行的提示数
    int col_counts[15] = { 0 }; // 每列的提示数
};










//先填充内部数组
puzzle input(int* SIZE)
{
    puzzle p;

    while (1) {

        cout << "请输入区域大小(5/10/15) ：";
        cin >> *SIZE;
        if (*SIZE == 10 || *SIZE == 15 || *SIZE == 5)
            break;
    }
    //输入完毕
    cout << endl;
    cout << "初始数组：" << endl;

    p.size = *SIZE;




    for (int i = 0; i < p.size; i++) {
        for (int j = 0; j < p.size; j++) {
            p.data[i][j] = rand() % 2;
        }
    }
    return p;

}



//根据内部数组填充提示数组
void input_hint(const puzzle& p, Hints& h)
{
    for (int i = 0; i < p.size; i++) {
        int count = 0;
        int hint_idx = 0;
        for (int j = 0; j < p.size; j++) {
            if (p.data[i][j] == 1) {
                count++;
            }
            else if (count > 0) {
                h.row_hints[i][hint_idx++] = count;
                count = 0;
            }
        }
        if (count > 0) {
            h.row_hints[i][hint_idx++] = count;
        }
        h.row_counts[i] = hint_idx;
    }

    //每行



    for (int j = 0; j < p.size; j++) {
        int count = 0;
        int hint_idx = 0;
        for (int i = 0; i < p.size; i++) {
            if (p.data[i][j] == 1) {
                count++;
            }
            else if (count > 0) {
                h.col_hints[j][hint_idx++] = count;
                count = 0;
            }
        }
        if (count > 0) {
            h.col_hints[j][hint_idx++] = count;
        }
        h.col_counts[j] = hint_idx;
    }

    //每列



}



//获取行提示的最大数量
int get_max_row_hints(const Hints& h, int size) {
    int max_hints = 0;
    for (int i = 0; i < size; i++) {
        if (h.row_counts[i] > max_hints) {
            max_hints = h.row_counts[i];
        }
    }
    return max_hints;
}

// 获取列提示的最大数量
int get_max_col_hints(const Hints& h, int size) {
    int max_hints = 0;
    for (int j = 0; j < size; j++) {
        if (h.col_counts[j] > max_hints) {
            max_hints = h.col_counts[j];
        }
    }
    return max_hints;
}




//内部数组处理完毕

//下面开始输出


//输出abcd行，换行
void print_row_abcd(int size, int max_row, int max_col,bool printhint)
{
    //设置字体大小

    cct_setfontsize( "仿宋",32);

   

    
    
    
    cct_setcolor();
    cct_gotoxy(max_row, max_col+1);
    cout << "    ";
    if (printhint) {
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row + 2, max_col + 1, "║", COLOR_HWHITE, COLOR_BLACK);
    }
    for (int i = 0;i < size;i++) {
        cout << ' '<< char('a' + i) ;


    }
    cout << endl;
}







//根据尺寸，缓冲区，再打印白色背景
void print_bg(int size, bool print, int max_row, int max_col)
{
    // 计算需要的最大间距（根据提示数字的最大位数）
   

    cct_setconsoleborder(max_row + 4 * size, 80);

    cout << endl;


    // 打印行提示（如果需要）
    if (print) {

        cct_showstr(0, 2 + max_col, "╔", COLOR_HWHITE, COLOR_BLACK); //2是字母+框的大小
        cct_showstr(1, 2 + max_col, "═", COLOR_HWHITE, COLOR_BLACK, max_row - 1);
        

        //第一行

        for (int i = 0;i < size;i++) {
            cct_showstr(0, i + 1 + 2 + max_col, "║", COLOR_HWHITE, COLOR_BLACK);
            for (int j = 0;j < max_row;j++) {
                cct_showstr(j + 1, i + 1 + 2 + max_col, " ", COLOR_HWHITE, COLOR_BLACK);

            }
            // cct_showstr(2 * size + 4 + max_row, 1 + i, "║", COLOR_HWHITE, COLOR_BLACK);
        }

        //中间

        cct_showstr(max_row - 2, 2 + max_col , "╦", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row - 2+1, 2 + max_col, "═", COLOR_HWHITE, COLOR_BLACK);
        for (int i = 0;i < size ;i++) {
            cct_showstr(max_row - 2, 1+2 + max_col + i, "║", COLOR_HWHITE, COLOR_BLACK);
        }
       // cct_showstr(max_row - 2, 1 + max_col+size+2, "╩", COLOR_HWHITE, COLOR_BLACK);
       


        // ABCD和数字间的分隔线



        cct_showstr(0, max_col + size + 3, "╚", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(1, max_col + size + 3, "═", COLOR_HWHITE, COLOR_BLACK, max_row - 1);
        cct_showstr(max_row - 2, 1 + max_col + size + 2, "╩", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row - 2+1, 1 + max_col + size + 2, "═", COLOR_HWHITE, COLOR_BLACK);
        //最后一行打印完毕


    }












    // 打印列提示（如果需要）
    if (print) {

        cct_showstr(2 + max_row, 0, "╔", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(3 + max_row, 0, "═", COLOR_HWHITE, COLOR_BLACK, size + 1);
        cct_showstr(2 * size + 4 + max_row, 0, "╗", COLOR_HWHITE, COLOR_BLACK);

        //第一行

        for (int i = 0;i < max_col + 2;i++) {
            cct_showstr(2 + max_row, 1 + i, "║", COLOR_HWHITE, COLOR_BLACK);
            for (int j = 0;j < 2 * size + 2;j++) {
                cct_showstr(j + 3 + max_row, 1 + i, " ", COLOR_HWHITE, COLOR_BLACK);

            }
            cct_showstr(2 * size + 4 + max_row, 1 + i, "║", COLOR_HWHITE, COLOR_BLACK);
        }

        //中间


        cct_showstr(2 + max_row, max_col, "╠", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(3 + max_row, max_col, "═", COLOR_HWHITE, COLOR_BLACK, size + 1);
        cct_showstr(2 * size + 4 + max_row, max_col, "╣", COLOR_HWHITE, COLOR_BLACK);
        //最后一行打印完毕




    }


    






    //铺完两侧背景，开始打印中间方格



    // 打印abcd行（调整起始位置）
    print_row_abcd(size, max_row, max_col, print);

   
   

    if (print)
        cct_showstr(2 + max_row, 2 + max_col, "╬", COLOR_HWHITE, COLOR_BLACK);
    else
        cct_showstr(2 + max_row, 2 + max_col, "╔", COLOR_HWHITE, COLOR_BLACK);

    cct_showstr(3 + max_row, 2 + max_col, "═", COLOR_HWHITE, COLOR_BLACK, size + 1);

    if(print)
        cct_showstr(2 * size + 4 + max_row, 2 + max_col, "╣", COLOR_HWHITE, COLOR_BLACK);
    else
        cct_showstr(2 * size + 4 + max_row, 2 + max_col, "╗", COLOR_HWHITE, COLOR_BLACK);
    //第一行打印完毕



    for (int i = 0;i < size;i++) {
        if (print) 
        {
            cct_showch(0 + max_row, i + 3 + max_col, char(i + 'A'), COLOR_HWHITE, COLOR_BLACK);
            cct_setcolor(COLOR_HWHITE,COLOR_BLACK);
            cout << ' ';
            cct_setcolor();
        }
        else
            cct_showch(0 + max_row, i + 3 + max_col, char(i + 'A')); //前面的ABCD
        cct_showstr(2 + max_row, 3 + i + max_col, "║", COLOR_HWHITE, COLOR_BLACK);
        for (int j = 0;j < 2 * size + 2;j++) {
            cct_showstr(j + 3 + max_row, 3 + i + max_col, " ", COLOR_HWHITE, COLOR_BLACK);

        }
        cct_showstr(2 * size + 4 + max_row, 3 + i + max_col, "║", COLOR_HWHITE, COLOR_BLACK);
    }


   
    cct_showstr(2 + max_row, size + 3 + max_col, "╚", COLOR_HWHITE, COLOR_BLACK);
    cct_showstr(3 + max_row, size + 3 + max_col, "═", COLOR_HWHITE, COLOR_BLACK, size + 1);
    cct_showstr(2 * size + 4 + max_row, size + 3 + max_col, "╝", COLOR_HWHITE, COLOR_BLACK);
    //最后一行打印完毕


}



void print_circle(int X, int Y)
{
    
    cct_showstr(X , Y , "○", COLOR_HBLUE, COLOR_BLACK);
    cct_setcolor();     // 恢复原始颜色
}

void print_false(int X, int Y)
{
    cct_showstr(X, Y, "×", COLOR_RED, COLOR_BLACK);
    cct_setcolor();     // 恢复原始颜色
}


void print_square(int X, int Y,int COLOR) {
    const int width = 3; // 调整为更合适的尺寸

    X += 3;

    // 绘制上边框
    cct_showstr(X - 1 - 1, Y - 1, "╔", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y - 1, "═", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y - 1, "╗", COLOR, COLOR_BLACK);

    // 绘制左右边框
    for (int i = 0; i < width - 2; i++) {
        cct_showstr(X - 1 - 1, Y + i, "║", COLOR, COLOR_BLACK);
        cct_showstr(X + 2 * width - 2 - 2, Y + i, "║", COLOR, COLOR_BLACK);
    }

    // 绘制下边框
    cct_showstr(X - 1 - 1, Y + 2 - 1, "╚", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y + 2 - 1, "═", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y + 2 - 1, "╝", COLOR, COLOR_BLACK);

    // 在中心绘制圆
    cct_showstr(X + (width - 2) / 2, Y + (width - 2) / 2, "○", COLOR, COLOR_BLACK);

    cct_setcolor(); // 恢复原始颜色
}

void print_false_square(int X, int Y,int COLOR) {
    const int width = 3; // 调整为更合适的尺寸

    X += 3;

    // 绘制上边框
    cct_showstr(X - 1 - 1, Y - 1, "╔", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y - 1, "═", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y - 1, "╗", COLOR, COLOR_BLACK);

    // 绘制左右边框
    for (int i = 0; i < width - 2; i++) {
        cct_showstr(X - 1 - 1, Y + i, "║", COLOR, COLOR_BLACK);
        cct_showstr(X + 2 * width - 2 - 2, Y + i, "║", COLOR, COLOR_BLACK);
    }

    // 绘制下边框
    cct_showstr(X - 1 - 1, Y + 2 - 1, "╚", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y + 2 - 1, "═", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y + 2 - 1, "╝", COLOR, COLOR_BLACK);

    // 在中心绘制圆
    cct_showstr(X + (width - 2) / 2, Y + (width - 2) / 2, "×", COLOR, COLOR_BLACK);

    cct_setcolor(); // 恢复原始颜色
}

void print_restore_square(int X, int Y) {
    const int width = 3; // 调整为更合适的尺寸

    X += 3;

    // 绘制上边框
    cct_showstr(X - 1 - 1, Y - 1, "  ", COLOR_HWHITE, COLOR_BLACK);
    cct_showstr(X - 1, Y - 1, "  ", COLOR_HWHITE, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y - 1, "  ", COLOR_HWHITE, COLOR_BLACK);

    // 绘制左右边框
    for (int i = 0; i < width - 2; i++) {
        cct_showstr(X - 1 - 1, Y + i, "  ", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(X + 2 * width - 2 - 2, Y + i, "  ", COLOR_HWHITE, COLOR_BLACK);
    }

    // 绘制下边框
    cct_showstr(X - 1 - 1, Y + 2 - 1, "  ", COLOR_HWHITE, COLOR_BLACK);
    cct_showstr(X - 1, Y + 2 - 1, "  ", COLOR_HWHITE, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y + 2 - 1, "  ", COLOR_HWHITE, COLOR_BLACK);

    // 在中心绘制圆
    cct_showstr(X + (width - 2) / 2, Y + (width - 2) / 2, "  ", COLOR_HWHITE, COLOR_BLACK);

    cct_setcolor(); // 恢复原始颜色
}



void print_puzzleonly(const puzzle& p)
{
    //先打印背景
    print_bg(p.size, 0,0,0);
    



    for (int i = 0;i < p.size;i++) {
        for (int j = 0; j < p.size; j++) {
            if (p.data[i][j]) {
                int x = 4 + j * 2;  // 列坐标
                int y = 3 + i;      // 行坐标
                print_circle(x, y);
            }
            
            
        }
    }


}



void print_puzzlewithhints(bool play,const puzzle& p, const Hints& h)
{
    int size = p.size;
    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // 计算需要的间距
    int row_hint_space = max_row_hints * 2 + 6; // 每个提示数字占2字符宽
    int col_hint_space = max_col_hints + 1;

    print_bg(p.size, true, row_hint_space, col_hint_space);

    // 打印行提示（左侧）
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < h.row_counts[i]; k++) {
                cct_showint(row_hint_space - (h.row_counts[i] - k) * 2-2,
                    3 + col_hint_space + i,
                    h.row_hints[i][k], COLOR_HWHITE, COLOR_BLACK);

        }
    }

    // 打印列提示（上方）
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < h.col_counts[j]; k++) {
            cct_showch(4 + row_hint_space + j * 2,
                col_hint_space - h.col_counts[j] + k,
                ' ', COLOR_HWHITE, COLOR_BLACK);
            cct_showint(4 + row_hint_space + j * 2+1,
                col_hint_space - h.col_counts[j] + k,
                h.col_hints[j][k], COLOR_HWHITE, COLOR_BLACK);
        }
    }

    if(!play)
    {
        // 打印数据内容
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (p.data[i][j]) {
                    int x = 4 + row_hint_space + j * 2;
                    int y = 3 + col_hint_space + i;
                    print_circle(x, y);
                }
            }
        }
    }
}


//游戏函数

struct GameState {
    puzzle puzzle;
    Hints hints;
    int markState[15][15] = { 0 }; // 0=未标记, 1=圆圈, 2=叉号
    bool cheatMode = false;
};

// 检查完成函数
bool check_complete(const GameState& game) {
    for (int i = 0; i < game.puzzle.size; i++) {
        for (int j = 0; j < game.puzzle.size; j++) {
            if (game.puzzle.data[i][j] == 1 && game.markState[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}






//取消标记
void print_restore(int X, int Y)
{
    cct_showstr(X, Y, "  ", COLOR_HWHITE);
    cct_setcolor();
}




//由数据计算并输出坐标
void getlocation(int x, int y, const int max_row, const int max_col, const int size, bool play, int scale)
{
    cct_setcolor();

    // 计算格子坐标
    int row = (x - max_row * 2 - 10) / (2 * scale);
    int col = (y - max_col - 4) / scale;

    // 默认认为在有效区域
    bool is_valid = (row >= 0 && row < size && col >= 0 && col < size);

    // 只有当scale>1时才检查中心区域
    if (scale > 1 && is_valid) {
        // 计算鼠标在格子内的相对位置
        int relative_x = (x - max_row * 2 - 10) % (2 * scale);
        int relative_y = (y - max_col - 4) % scale;

        // 定义3×3中心区域范围
        int center_size = 3;  // 3×3的中心区域
        int x_center_start = scale - center_size / 2 - 1;
        int x_center_end = scale + center_size / 2 + 1;
        int y_center_start = scale / 2 - center_size / 2 - 1;
        int y_center_end = scale / 2 + center_size / 2 + 1;

        // 检查是否在3×3中心区域内
        is_valid = (relative_x >= x_center_start && relative_x < x_center_end) && (relative_y >= y_center_start && relative_y < y_center_end);
    }

    cct_gotoxy(10, max_col + size * scale + 5);
    if (is_valid) {
        cout << "[当前光标]" << " " << char('A' + col) << "行" << " " << char('a' + row) << "列";
    }
    else {
        cout << "[当前光标]" << "位置非法";
    }
}





void getxy_puzzle(bool play, const int max_row, const int max_col, int size, GameState& game, int scale = 1) {
    cct_enable_mouse();
    cct_setcolor();

    if (play) {
        cct_gotoxy(10, (scale == 1 ? max_col + size : max_col +scale * ( size)) + 7);
        cout << "左键选○，右键选×，Y/y提交，Z/z作弊，Q/q结束";
    }

    while (1) {
        int x, y, mouseAction, keycode1, keycode2;
        int event = cct_read_keyboard_and_mouse(x, y, mouseAction, keycode1, keycode2);

        // 鼠标移动事件 - 显示当前位置
        if (event == CCT_MOUSE_EVENT && mouseAction == MOUSE_ONLY_MOVED) {
            getlocation(x, y, max_row, max_col, size, play, scale);
        }

        // 键盘事件处理
        if (event == CCT_KEYBOARD_EVENT) {
            cct_setcolor();
            if (keycode1 == 'Y' || keycode1 == 'y') { // 检查完成
                if (play) {
                    bool correct = true;
                    for (int i = 0; i < size && correct; i++) {
                        for (int j = 0; j < size; j++) {
                            if ((game.puzzle.data[i][j] == 1 && game.markState[i][j] != 1) ||
                                (game.puzzle.data[i][j] == 0 && game.markState[i][j] == 1)) {
                                correct = false;
                                break;
                            }
                        }
                    }

                    cct_gotoxy(10, (scale == 1 ? max_col + size : scale * (max_col + size)) + 6);
                    if (correct) {
                        cout << "拼图完成！                  ";
                    }
                    else {
                        cout << "提交错误，可用作弊模式查看          ";
                    }
                }
            }
            else if (play && (keycode1 == 'Z' || keycode1 == 'z')) { // 作弊模式切换
                game.cheatMode = !game.cheatMode;
                cct_gotoxy(10, (scale == 1 ? max_col + size : scale * (max_col + size)) + 8);
                cout << "作弊模式 " << (game.cheatMode ? "开启" : "关闭") << "          ";

                // 计算行和列提示空间
                int row_hint_space = get_max_row_hints(game.hints, size) * 2 + 6;
                int col_hint_space = get_max_col_hints(game.hints, size) + 1;

                // 更新显示
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (scale == 1) {
                            int x = 4 + row_hint_space + j * 2;
                            int y = 3 + col_hint_space + i;

                            if (game.cheatMode) {
                                if (game.puzzle.data[i][j]) {
                                    cct_showstr(x, y, "○", COLOR_WHITE, COLOR_BLACK);
                                }
                                // 覆盖显示用户标记状态
                                if (game.markState[i][j] == 1) {
                                    int color = (game.puzzle.data[i][j] == 1) ? COLOR_HGREEN : COLOR_RED;
                                    cct_showstr(x, y, "○", color, COLOR_BLACK);
                                }
                                else if (game.markState[i][j] == 2) {
                                    int color = (game.puzzle.data[i][j] == 0) ? COLOR_HGREEN : COLOR_RED;
                                    cct_showstr(x, y, "×", color, COLOR_BLACK);
                                }
                            }
                            else {
                                if (game.markState[i][j] == 1) {
                                    print_circle(x, y);
                                }
                                else if (game.markState[i][j] == 2) {
                                    print_false(x, y);
                                }
                                else {
                                    print_restore(x, y);
                                }
                            }
                        }
                        else { // scale > 1
                            int x = max_row * 2 + 11 + 2 * scale * j;
                            int y = max_col + 6 + scale * i;

                            if (game.cheatMode) {
                                if (game.puzzle.data[i][j]) {
                                    print_square(x, y, COLOR_WHITE);
                                }
                                if (game.markState[i][j] == 1) {
                                    int color = (game.puzzle.data[i][j] == 1) ? COLOR_HGREEN : COLOR_RED;
                                    print_square(x, y, color);
                                }
                                else if (game.markState[i][j] == 2) {
                                    int color = (game.puzzle.data[i][j] == 0) ? COLOR_HGREEN : COLOR_RED;
                                    print_false_square(x, y, color);
                                }
                            }
                            else {
                                if (game.markState[i][j] == 1) {
                                    print_square(x, y, COLOR_HBLUE);
                                }
                                else if (game.markState[i][j] == 2) {
                                    print_false_square(x, y, COLOR_RED);
                                }
                                else {
                                    print_restore_square(x, y);
                                }
                            }
                        }
                    }
                }
            }
            else if (keycode1 == 'Q' || keycode1 == 'q') { // 退出
                break;
            }
        }

        // 鼠标点击处理
        if (play && event == CCT_MOUSE_EVENT &&
            (mouseAction == MOUSE_LEFT_BUTTON_CLICK || mouseAction == MOUSE_RIGHT_BUTTON_CLICK)) {

            int row = (x - max_row * 2 - 10) / (2 * scale);
            int col = (y - max_col - 4) / scale;

            if (row >= 0 && row < size && col >= 0 && col < size) {
                if (scale == 1) {
                    if (x % 2 != 0) x--; // 调整奇数坐标

                    if (mouseAction == MOUSE_LEFT_BUTTON_CLICK) {
                        game.markState[col][row] = (game.markState[col][row] == 1) ? 0 : 1;
                        if (game.markState[col][row] == 1)
                            print_circle(x, y);
                        else
                            print_restore(x, y);
                    }
                    else if (mouseAction == MOUSE_RIGHT_BUTTON_CLICK) {
                        game.markState[col][row] = (game.markState[col][row] == 2) ? 0 : 2;
                        if (game.markState[col][row] == 2)
                            print_false(x, y);
                        else
                            print_restore(x, y);
                    }
                }
                else { // scale > 1
                    int display_x = max_row * 2 + 11 + 2 * scale * row;
                    int display_y = max_col + 6 + scale * col;

                    if (mouseAction == MOUSE_LEFT_BUTTON_CLICK) {
                        game.markState[col][row] = (game.markState[col][row] == 1) ? 0 : 1;
                        if (game.markState[col][row] == 1)
                            print_square(display_x, display_y, COLOR_HBLUE);
                        else
                            print_restore_square(display_x, display_y);
                    }
                    else if (mouseAction == MOUSE_RIGHT_BUTTON_CLICK) {
                        game.markState[col][row] = (game.markState[col][row] == 2) ? 0 : 2;
                        if (game.markState[col][row] == 2)
                            print_false_square(display_x, display_y, COLOR_RED);
                        else
                            print_restore_square(display_x, display_y);
                    }
                }
            }
        }
    }
    cct_disable_mouse();
}

//总调用函数

void T_D()
{
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);
    Hints h;

    input_hint(p, h);

    print_puzzleonly(p);

    

    my_exit();
}


void T_E()
{
     cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);
    Hints h;

    input_hint(p, h);

    print_puzzlewithhints(0,p,h);

    

    my_exit();




}

void getxy_puzzle(bool play, const int max_row, const int max_col, int size) {
    GameState dummy;
    getxy_puzzle(play, max_row, max_col, size, dummy, 5); // 使用默认scale=5
}



void T_F()
{
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);
    Hints h;

    input_hint(p, h);

    size = p.size;
    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    input_hint(p, h);

    print_puzzlewithhints(0,p, h);

    getxy_puzzle(0,max_row_hints,max_col_hints,size);


    my_exit();



}



void T_G() 
{
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);  // 生成谜题数据
    Hints h;
    input_hint(p, h);         // 生成提示数据

    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // 创建游戏状态并初始化
    GameState game;
    game.puzzle = p;         // 保存谜题数据
    game.hints = h;          // 保存提示数据

    print_puzzlewithhints(1, game.puzzle, game.hints);

    // 传入游戏状态
    int scale = 1;
    getxy_puzzle(1, max_row_hints, max_col_hints, size, game,scale);
    my_exit();


}




















void print_row_abcd2(int size, int max_row, int max_col, bool printhint)
{
    //设置字体大小

    cct_setfontsize("仿宋", 14);






    cct_setcolor();
    cct_gotoxy(max_row, max_col + 1);
    cout << "    ";
    if (printhint) {
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row + 3, max_col + 2, "║", COLOR_HWHITE, COLOR_BLACK);
       
    }
    for (int i = 0;i < size;i++) {
        cout <<setw(4)<< " " << char('a' + i)<< setw(5) << " ";


    }
    if (printhint) {
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row + 3 + 10 * size, max_col + 2, "║", COLOR_HWHITE, COLOR_BLACK);

    }

    cout << endl;
}






void print_bg2(int size, bool print, int max_row, int max_col) {
    const int scale = 5; // 放大5倍
    const int cell_width = 2; // 每个格子宽度
    const int cell_height = 1; // 每个格子高度

    // 调整控制台大小
    cct_setconsoleborder(max_row + 5 * size * scale, max_row + 5 * size * scale, max_row + 5 * size * scale, max_row + 5 * size * scale);
    cout << endl;

    

    // 2. 先铺纯白色背景 --------------------------------------

    // 打印行提示（如果需要）
    if(print) {
        cct_showstr(1, 3 + max_col, "╔", COLOR_HWHITE, COLOR_BLACK);  // 向右1，下移1
        cct_showstr(2, 3 + max_col, "═", COLOR_HWHITE, COLOR_BLACK, max_row - 1);

        for (int i = 0; i < size * scale; i++) {
            cct_showstr(1, i + 1 + 3 + max_col, "║", COLOR_HWHITE, COLOR_BLACK);  // 向右1，下移1
            for (int j = 0; j < max_row*2-2; j++) {
                cct_showstr(j + 2, i + 1 + 3 + max_col, " ", COLOR_HWHITE, COLOR_BLACK);  // 向右1
            }
        }

        cct_showstr(max_row - 1, 3 + max_col, "╦", COLOR_HWHITE, COLOR_BLACK);  // 向右1，下移1
        cct_showstr(max_row, 3 + max_col, "═", COLOR_HWHITE, COLOR_BLACK);
        for (int i = 0; i < size * scale; i++) {
            cct_showstr(max_row - 1, 1 + 3 + max_col + i, "║", COLOR_HWHITE, COLOR_BLACK);  // 向右1
        }

        cct_showstr(1, max_col + size * scale + 3, "╚", COLOR_HWHITE, COLOR_BLACK);  // 向右1，下移1
        cct_showstr(2, max_col + size * scale + 3, "═", COLOR_HWHITE, COLOR_BLACK, max_row - 1);
        cct_showstr(max_row - 1, 1 + max_col + size * scale + 2, "╩", COLOR_HWHITE, COLOR_BLACK);  // 向右1
        cct_showstr(max_row, 1 + max_col + size * scale + 2, "═", COLOR_HWHITE, COLOR_BLACK);
    }

    // 打印列提示（向右1，向下1，高度减2）
    if (print) {
        cct_showstr(3 + max_row, 1, "╔", COLOR_HWHITE, COLOR_BLACK);  // 向右1，向下1
        cct_showstr(4 + max_row, 1, "═", COLOR_HWHITE, COLOR_BLACK, size * scale);  // 长度减2
        cct_showstr(2 * size * scale + 3 + max_row, 1, "╗", COLOR_HWHITE, COLOR_BLACK);  // 向右1

        // 高度减2（原max_col+2改为max_col）
        for (int i = 0; i < max_col; i++) {  // 改为max_col
            cct_showstr(3 + max_row, 2 + i, "║", COLOR_HWHITE, COLOR_BLACK);  // 向右1，向下1
            for (int j = 0; j < 2 * size * scale ; j++) {  // 长度减2
                cct_showstr(j + 4 + max_row, 2 + i, " ", COLOR_HWHITE, COLOR_BLACK);  // 向右1
            }
            cct_showstr(2 * size * scale + 3 + max_row, 2 + i, "║", COLOR_HWHITE, COLOR_BLACK);  // 向右1
        }

       
    }

    


    // 打印abcd行标签



    print_row_abcd2(size, max_row, max_col, print);

    if (print) {
        cct_showstr(3 + max_row, max_col + 1, "╠", COLOR_HWHITE, COLOR_BLACK);  // 向右1，向下1
        cct_showstr(4 + max_row, max_col + 1, "═", COLOR_HWHITE, COLOR_BLACK, size * scale);  // 长度减2
        cct_showstr(2 * size * scale + 3 + max_row, max_col + 1, "╣", COLOR_HWHITE, COLOR_BLACK);  // 向右1

    }

    const int board_start_x = max_row + 2;
    const int board_start_y = max_col + 3;
    const int board_width = size * scale ;
    const int board_height = size * scale;

    // 先铺白色背景
    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width*2; x++) {
            cct_showstr(board_start_x + 1 + x, board_start_y + y,
                "  ", COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // 绘制外边框
    
    cct_showstr(board_start_x + 1, board_start_y , "═", COLOR_HWHITE, COLOR_BLACK, board_width);
    if(print)
        cct_showstr(board_start_x + 1 + board_width * 2, board_start_y, "╣", COLOR_HWHITE, COLOR_BLACK);
    else
        cct_showstr(board_start_x + 1 + board_width*2, board_start_y , "╗", COLOR_HWHITE, COLOR_BLACK);

    // 绘制垂直网格线 (只在放大倍数处画粗线)
    for (int col = 0; col <= size; col++) {
        int x = board_start_x + 1 + col * scale * cell_width;
        if(print&&col==0&&x== board_start_x + 1)
            cct_showstr(x, board_start_y, "╬", COLOR_HWHITE, COLOR_BLACK);
        
        
        else 
            cct_showstr(x, board_start_y , "╤", COLOR_HWHITE, COLOR_BLACK);
        
        for (int y = board_start_y+1; y < board_start_y + board_height; y++) {
            cct_showstr(x, y, "║", COLOR_HWHITE, COLOR_BLACK);
       
        }
        
            cct_showstr(x, board_start_y + board_height, "╧", COLOR_HWHITE, COLOR_BLACK);

    }
    if (print)
    {

        for (int i = 0; i < size; i++) {
            cct_showch(max_row + 2, max_col + 5 + i * scale, 'A' + i, COLOR_HWHITE, COLOR_BLACK);
        }

    }
    else
        for (int i = 0; i < size; i++) {
            cct_showch(max_row + 1, max_col + 5 + i * scale, 'A' + i);
        }

    // 绘制水平网格线 (只在放大倍数处画粗线)
    for (int row = 0; row <= size; row++) {
        int y = board_start_y + row * scale;
        for (int x = board_start_x + 1; x < board_start_x + 1 + 2*board_width; x += cell_width) {
            cct_showstr(x, y, "══", COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // 绘制交叉点
    for (int row = 0; row <= size; row++) {
        for (int col = 0; col <= size; col++) {
            int x = board_start_x + 1 + col * scale * cell_width;
            int y = board_start_y + row * scale;

            if (row == 0 && col == 0&&!print) {
                cct_showstr(x, y, "╔", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == 0 && col == size&&!print) {
                cct_showstr(x, y, "╗", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == size && col == 0) {
                cct_showstr(x, y, "╚", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == size && col == size) {
                cct_showstr(x, y, "╝", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == 0&&!print) {
                cct_showstr(x, y, "╤", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == size) {
                cct_showstr(x, y, "╧", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (col == 0) {
                cct_showstr(x, y, "╟", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (col == size) {
                cct_showstr(x, y, "╢", COLOR_HWHITE, COLOR_BLACK);
            }
            else if(row!=0){
                cct_showstr(x, y, "╬", COLOR_HWHITE, COLOR_BLACK);
            }
            else
                cct_showstr(x, y, "╤", COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // 绘制底部边框
   
    //cct_showstr(board_start_x + 1, board_start_y + board_height, "═", COLOR_HWHITE, COLOR_BLACK, board_width);
    
}




void print_puzzleonly_2(const puzzle& p,const Hints& h)
{
    //先打印背景
    
    print_bg2(p.size, 0, 0, 0);





    int size = p.size;
    
    // 计算需要的间距
    int row_hint_space = 0;
    int col_hint_space = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (p.data[i][j]) {
                int x = 5 + row_hint_space + j * 10;  // 放大5倍后的坐标
                int y = 5 + col_hint_space + i * 5;
                print_square(x, y,COLOR_HBLUE);
            }
        }
    }


}









void T_H()
{
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);
    Hints h;

    input_hint(p, h);

    print_puzzleonly_2(p,h);



    my_exit();
}



void print_puzzlewithhints_2(bool play, const puzzle& p, const Hints& h) {
    int size = p.size;
    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // 计算需要的间距
    int row_hint_space = max_row_hints * 2 + 6;
    int col_hint_space = max_col_hints + 1;

    // 打印带网格的背景
    print_bg2(size, true, row_hint_space, col_hint_space);

    // 打印行提示（左侧）
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < h.row_counts[i]; k++) {
            cct_showint(row_hint_space - (h.row_counts[i] - k) * 2 - 2,
                5 + col_hint_space + i * 5,  // 注意：放大5倍后的行位置
                h.row_hints[i][k], COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // 打印列提示（上方）
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < h.col_counts[j]; k++) {
            cct_showint(5 + row_hint_space + j * 10 + 4,  // 放大5倍后的列位置
                col_hint_space - h.col_counts[j] + k+1,
                h.col_hints[j][k], COLOR_HWHITE, COLOR_BLACK);
        }
    }

    if (!play) {
        // 打印数据内容（使用print_square）
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (p.data[i][j]) {
                    int x = 5 + row_hint_space + j * 10;  // 放大5倍后的坐标
                    int y = 5 + col_hint_space + i * 5;
                    print_square(x, y,COLOR_HBLUE);
                }
            }
        }
    }
}

void T_I() {
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);
    Hints h;

    input_hint(p, h);
    print_puzzlewithhints_2(0, p, h);
    my_exit();
}









void T_J() {
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);  // 生成谜题数据
    Hints h;
    input_hint(p, h);         // 生成提示数据

    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // 创建游戏状态并初始化
    GameState game;
    game.puzzle = p;         // 保存谜题数据
    game.hints = h;          // 保存提示数据

   
    print_puzzlewithhints_2(0, p, h);
   
    int scale = 5;
    getxy_puzzle(0, max_row_hints, max_col_hints, size,game,scale);


    my_exit();
}






void T_K() {
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);  // 生成谜题数据
    Hints h;
    input_hint(p, h);         // 生成提示数据

    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // 创建游戏状态并初始化
    GameState game;
    game.puzzle = p;         // 保存谜题数据
    game.hints = h;          // 保存提示数据


    print_puzzlewithhints_2(1, p, h);

    int scale = 5;
    getxy_puzzle(1, max_row_hints, max_col_hints, size, game, scale);


    my_exit();
}

