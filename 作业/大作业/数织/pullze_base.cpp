/* 2452545 计算机 刘晴语 */
#include<iostream>
#include<conio.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "pullze.h"

#define MAX_HINTS 8
using namespace std;



//内部数组版的函数



struct puzzle_base {
    int size;
    int data[15][15]; // 按最大尺寸分配
};

struct Hints_base {
    int row_hints[15][MAX_HINTS] = { 0 }; // 行提示 [行号][提示序列]
    int col_hints[15][MAX_HINTS] = { 0 }; // 列提示 [列号][提示序列]
    int row_counts[15] = { 0 }; // 每行的提示数
    int col_counts[15] = { 0 }; // 每列的提示数
};


//先填充内部数组
puzzle_base input_base(int* SIZE)
{
    puzzle_base p;
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
void input_hint_base(const puzzle_base& p, Hints_base& h)
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



//输出内部格线，规定5个字符一小格，换行
void print_insideline(int size)
{
    for (int i = 0;i < size / 5;i++) {
        cout << '+';
        for (int j = 0;j < 11;j++) {
            cout << '-';
        }
        
    }
    cout << '+'<< endl;
}


//输出前两行提示格线，根据size改变，不换行
void print_hintline1(int size)
{
    int num;
    if (size == 5)
        num = 3;
    else if (size == 10)
        num = 5;
    else
        num = 7;
    //每种情况对应的最大数量

    int sum = 2 * num + 1; //视情况调整此处？

    //根据数量计算需要多少空格或-

    for (int i = 0;i < sum;i++) {
        cout << '-';
    }




}


//输出后两行提示格线，根据size改变，不换行
void print_hintline2(int size)
{
    int num;
    if (size == 5)
        num = 3;
    else if (size == 10)
        num = 5;
    else
        num = 7;
    //每种情况对应的最大数量
    
    int sum = 2 * num + 1; //视情况调整此处？

    //根据数量计算需要多少空格或-

    for (int i = 0;i < sum-2;i++) {
        cout << '-';
    }

    cout << "+-";


}


//输出前两行前空格
void print_blank(int size)
{
    int num;
    if (size == 5)
        num = 3;
    else if (size == 10)
        num = 5;
    else
        num = 7;
    //每种情况对应的最大数量

    int sum = 2 * num+1;
    //根据数量计算需要多少空格或-

    for (int i = 0;i < sum;i++) {
        cout << ' ';
    }

    cout << '|';
}


//输出abcd行，换行
void print_row_console(int size)
{
    cout << ' ';
    for (int i = 0;i < size;i++) {
        cout << char('a' + i) << ' ';
        if((i+1) % 5 == 0) {
            cout << '|' << ' ';
        }
    }
    cout << endl;
}





//输出内部数组(无提示）
void print_puzzleonly_base(const puzzle_base& p)
{
    int size = p.size;

    cout << "+-";
    print_insideline(size);
    //第一行

    cout << "| |";
    print_row_console(size);
    //第二行abcd

    cout << "+-";
    print_insideline(size);
    //第三行



    for (int i = 0;i < size;i++) { 
        cout << '|' << char('A' + i) << '|';
        cout << ' ';
        for (int j = 0; j < size; j++) {
            cout << (p.data[i][j] ? '0' : ' ')<<' ';
            if ((j + 1) % 5 == 0) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 5 == 0) {
            cout << "+-";
            print_insideline(size);
        }

    }
}


//获取行提示的最大数量
int get_max_row_hints(const Hints_base& h, int size) {
    int max_hints = 0;
    for (int i = 0; i < size; i++) {
        if (h.row_counts[i] > max_hints) {
            max_hints = h.row_counts[i];
        }
    }
    return max_hints;
}

// 获取列提示的最大数量
int get_max_col_hints(const Hints_base& h, int size) {
    int max_hints = 0;
    for (int j = 0; j < size; j++) {
        if (h.col_counts[j] > max_hints) {
            max_hints = h.col_counts[j];
        }
    }
    return max_hints;
}











//输出内部数组(有提示）
void print_withhints_base(const puzzle_base& p, const Hints_base& h) {
    int size = p.size;
    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    
    cout << endl;
    print_hintline1(size);
    print_insideline(size);

    //第一行



    // 打印列提示(上方)
    for (int k = max_col_hints - 1; k >= 0; k--) {
        print_blank(size); 

        for (int j = 0; j < size; j++) {
            if (k < h.col_counts[j]) {
                cout << setw(2) << h.col_hints[j][k];
            }
            else {
                cout << "  ";
            }
            if ((j + 1) % 5 == 0 && j != size - 1) {
                cout << " |";
            }
        }
        cout << " |";
        cout << endl;
    }

    // 打印顶部边框
    print_hintline1(size);
    print_insideline(size);

    // 打印abcd行
    print_blank(size);
    print_row_console(size);

    // 打印分隔线
    print_hintline2(size);
    print_insideline(size);

    // 打印行内容和行提示
    for (int i = 0; i < size; i++) {
        // 打印行提示(左侧)
        for (int k = max_row_hints - 1; k >= 0; k--) {
            if (k < h.row_counts[i]) {
                cout << setw(2) << h.row_hints[i][k];
            }
            else {
                cout << "  ";
            }
        }
       

        // 打印行内容和格子
        cout << " |" << char('A' + i) << "|";
        for (int j = 0; j < size; j++) {
            cout << (p.data[i][j] ? " 0" : "  ");
            if ((j + 1) % 5 == 0 && j != size - 1) {
                cout << " |";
            }
        }
        cout << " |";
        cout << endl;

        // 打印分隔线
        if ((i + 1) % 5 == 0 && i != size - 1) {
            print_hintline2(size);
            print_insideline(size);
        }

       
    }

    // 打印底部边框
    print_hintline2(size);
    print_insideline(size);
}












void T_A()
{
    cct_cls();

    int size;
    puzzle_base p = input_base(&size);

    print_puzzleonly_base(p);

    my_exit();

}



void T_B()
{
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle_base p = input_base(&size);
    Hints_base h;
    input_hint_base(p, h);

    
   
    print_withhints_base(p, h);

    my_exit();
}


struct GameState_base {
    puzzle_base puzzle;
    Hints_base hints;
    bool marked[15][15] = { false }; // 标记用户已经选择的格子
    bool cheatMode = false;
};







void print_game(const GameState_base& game) {
    int size = game.puzzle.size;
    int max_row_hints = get_max_row_hints(game.hints, size);
    int max_col_hints = get_max_col_hints(game.hints, size);



    cout << endl;
    print_hintline1(size);
    print_insideline(size);

    // 打印列提示(上方)
    for (int k = max_col_hints - 1; k >= 0; k--) {
        print_blank(size);
        for (int j = 0; j < size; j++) {
            if (k < game.hints.col_counts[j]) {
                cout << setw(2) << game.hints.col_hints[j][k];
            }
            else {
                cout << "  ";
            }
            if ((j + 1) % 5 == 0 && j != size - 1) {
                cout << " |";
            }
        }
        cout << " |" << endl;
    }

    // 打印顶部边框
    print_hintline1(size);
    print_insideline(size);

    // 打印abcd行
    print_blank(size);
    print_row_console(size);

    // 打印分隔线
    print_hintline2(size);
    print_insideline(size);

    // 打印游戏内容
    for (int i = 0; i < size; i++) {
        // 打印行提示
        for (int k = max_row_hints - 1; k >= 0; k--) {
            if (k < game.hints.row_counts[i]) {
                cout << setw(2) << game.hints.row_hints[i][k];
            }
            else {
                cout << "  ";
            }
        }

        // 打印行内容和格子
        cout << " |" << char('A' + i) << "|";
        for (int j = 0; j < size; j++) {
            if (game.marked[i][j]) {
                // 普通模式下所有标记都显示黄色背景的0
                if (!game.cheatMode) {
                    cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
                    cout << " 0";
                    cct_setcolor();
                }
                // 作弊模式下根据是否正确显示不同颜色
                else if (game.puzzle.data[i][j] == 1) {
                    cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
                    cout << " 0";
                    cct_setcolor();
                }
                else {
                    cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
                    cout << " X";
                    cct_setcolor();
                }
            }
            // 作弊模式下显示所有正确位置的0
            else if (game.cheatMode && game.puzzle.data[i][j] == 1) {
                cout << " 0";
            }
            // 未标记位置显示空白
            else {
                cout << "  ";
            }

            if ((j + 1) % 5 == 0 && j != size - 1) {
                cout << " |";
            }
        }
        cout << " |" << endl;

        // 打印分隔线
        if ((i + 1) % 5 == 0 && i != size - 1) {
            print_hintline2(size);
            print_insideline(size);
        }
    }

    // 打印底部边框
    print_hintline2(size);
    print_insideline(size);
}



// 处理输入
void process_input(GameState_base& game) {
    cout << "输入坐标(如Aa)或命令(C:作弊模式/Q:退出): ";
    string input;
    cin >> input;

    if (input.size() == 1) {
        char cmd = toupper(input[0]);
        if (cmd == 'C') {
            game.cheatMode = !game.cheatMode;
            cout << "作弊模式 " << (game.cheatMode ? "开启" : "关闭") << endl;
        }
        else if (cmd == 'Q') {
            exit(0);
        }
        return;
    }

    if (input.size() >= 2) {
        int row = toupper(input[0]) - 'A';
        int col = tolower(input[1]) - 'a';

        if (row >= 0 && row < game.puzzle.size && col >= 0 && col < game.puzzle.size) {
            game.marked[row][col] = !game.marked[row][col]; // 切换标记状态
        }
        else {
            cout << "无效坐标!" << endl;
        }
    }
}



// 检查游戏是否完成
bool check_complete_base(const GameState_base& game) {
    for (int i = 0; i < game.puzzle.size; i++) {
        for (int j = 0; j < game.puzzle.size; j++) {
            if (game.puzzle.data[i][j] == 1 && !game.marked[i][j]) {
                return false;
            }
        }
    }
    return true;
}






void T_C() {
    cct_cls();
    srand(unsigned int(time(0)));

    // 初始化游戏
    int size;
    GameState_base game;
    game.puzzle = input_base(&size);
    input_hint_base(game.puzzle, game.hints);
    // 初始化所有位置为未标记
    memset(game.marked, false, sizeof(game.marked));
    game.cheatMode = false;


    
    // 游戏主循环
    while (1) {
       cct_cls();
        print_game(game);

        if (check_complete_base(game)) {
            cout << "游戏完成。" << endl;
            break;
        }

        // 提示用户输入
        cout << "命令形式：Aa=等价于图形游戏中鼠标左键选择Aa位(区分大小写)" << endl;
        cout << "不需要支持图形界面的右键打叉，再次输入Aa相当于清除" << endl;
        cout << "X/x=退出(新行仅有X/x，不分大小写)" << endl;
        cout << "Y/y=提交(新行仅有Y/y，不分大小写)" << endl;
        cout << "Z/z=作弊(新行仅有Z/z，不分大小写)" << endl;
        cout << "Ctrl+c 强制退出" << endl;
        cout << "请输入: ";

        // 读取输入
        char input[3] = { 0 };
        cin.getline(input, 3);

        cout << "输入";
        cout << input[0] << input[1];
            
        cout<< "后："<<endl;


        // 处理单字符命令
        if (strlen(input) == 1) {
            char cmd = toupper(input[0]);
            if (cmd == 'X') {
                break;
            }
            else if (cmd == 'Y') {
                if (check_complete_base(game)) {
                    cout << "游戏完成。" << endl;
                    system("pause");
                    break;
                }
                else {
                    cout << "提交错误, 可用作弊模式查看" << endl;
                    system("pause");
                }
            }
            else if (cmd == 'Z') {
                game.cheatMode = !game.cheatMode;
                cout << "作弊模式 " << (game.cheatMode ? "开启" : "关闭") << endl;
                system("pause");
            }
            continue;
        }

        // 处理坐标输入
        if (strlen(input) == 2) {
            int row = input[0] - 'A';
            int col = tolower(input[1]) - 'a';

            if (row >= 0 && row < game.puzzle.size && col >= 0 && col < game.puzzle.size) {
                // 切换标记状态（标记或取消标记）
                game.marked[row][col] = !game.marked[row][col];
            }
            else {
                cout << "输入错误" << endl;
                
            }
        }
    }

    my_exit();
}





