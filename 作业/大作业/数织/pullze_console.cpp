/* 2452545 ����� ������ */
#include<iostream>
#include<conio.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "pullze.h"

#define MAX_HINTS 8
using namespace std;




//αͼ�ν������غ���


struct puzzle {
    int size;
    int data[15][15]; // �����ߴ����
};

struct Hints {
    int row_hints[15][MAX_HINTS] = { 0 }; // ����ʾ [�к�][��ʾ����]
    int col_hints[15][MAX_HINTS] = { 0 }; // ����ʾ [�к�][��ʾ����]
    int row_counts[15] = { 0 }; // ÿ�е���ʾ��
    int col_counts[15] = { 0 }; // ÿ�е���ʾ��
};










//������ڲ�����
puzzle input(int* SIZE)
{
    puzzle p;

    while (1) {

        cout << "�����������С(5/10/15) ��";
        cin >> *SIZE;
        if (*SIZE == 10 || *SIZE == 15 || *SIZE == 5)
            break;
    }
    //�������
    cout << endl;
    cout << "��ʼ���飺" << endl;

    p.size = *SIZE;




    for (int i = 0; i < p.size; i++) {
        for (int j = 0; j < p.size; j++) {
            p.data[i][j] = rand() % 2;
        }
    }
    return p;

}



//�����ڲ����������ʾ����
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

    //ÿ��



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

    //ÿ��



}



//��ȡ����ʾ���������
int get_max_row_hints(const Hints& h, int size) {
    int max_hints = 0;
    for (int i = 0; i < size; i++) {
        if (h.row_counts[i] > max_hints) {
            max_hints = h.row_counts[i];
        }
    }
    return max_hints;
}

// ��ȡ����ʾ���������
int get_max_col_hints(const Hints& h, int size) {
    int max_hints = 0;
    for (int j = 0; j < size; j++) {
        if (h.col_counts[j] > max_hints) {
            max_hints = h.col_counts[j];
        }
    }
    return max_hints;
}




//�ڲ����鴦�����

//���濪ʼ���


//���abcd�У�����
void print_row_abcd(int size, int max_row, int max_col,bool printhint)
{
    //���������С

    cct_setfontsize( "����",32);

   

    
    
    
    cct_setcolor();
    cct_gotoxy(max_row, max_col+1);
    cout << "    ";
    if (printhint) {
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row + 2, max_col + 1, "�U", COLOR_HWHITE, COLOR_BLACK);
    }
    for (int i = 0;i < size;i++) {
        cout << ' '<< char('a' + i) ;


    }
    cout << endl;
}







//���ݳߴ磬���������ٴ�ӡ��ɫ����
void print_bg(int size, bool print, int max_row, int max_col)
{
    // ������Ҫ������ࣨ������ʾ���ֵ����λ����
   

    cct_setconsoleborder(max_row + 4 * size, 80);

    cout << endl;


    // ��ӡ����ʾ�������Ҫ��
    if (print) {

        cct_showstr(0, 2 + max_col, "�X", COLOR_HWHITE, COLOR_BLACK); //2����ĸ+��Ĵ�С
        cct_showstr(1, 2 + max_col, "�T", COLOR_HWHITE, COLOR_BLACK, max_row - 1);
        

        //��һ��

        for (int i = 0;i < size;i++) {
            cct_showstr(0, i + 1 + 2 + max_col, "�U", COLOR_HWHITE, COLOR_BLACK);
            for (int j = 0;j < max_row;j++) {
                cct_showstr(j + 1, i + 1 + 2 + max_col, " ", COLOR_HWHITE, COLOR_BLACK);

            }
            // cct_showstr(2 * size + 4 + max_row, 1 + i, "�U", COLOR_HWHITE, COLOR_BLACK);
        }

        //�м�

        cct_showstr(max_row - 2, 2 + max_col , "�j", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row - 2+1, 2 + max_col, "�T", COLOR_HWHITE, COLOR_BLACK);
        for (int i = 0;i < size ;i++) {
            cct_showstr(max_row - 2, 1+2 + max_col + i, "�U", COLOR_HWHITE, COLOR_BLACK);
        }
       // cct_showstr(max_row - 2, 1 + max_col+size+2, "�m", COLOR_HWHITE, COLOR_BLACK);
       


        // ABCD�����ּ�ķָ���



        cct_showstr(0, max_col + size + 3, "�^", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(1, max_col + size + 3, "�T", COLOR_HWHITE, COLOR_BLACK, max_row - 1);
        cct_showstr(max_row - 2, 1 + max_col + size + 2, "�m", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row - 2+1, 1 + max_col + size + 2, "�T", COLOR_HWHITE, COLOR_BLACK);
        //���һ�д�ӡ���


    }












    // ��ӡ����ʾ�������Ҫ��
    if (print) {

        cct_showstr(2 + max_row, 0, "�X", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(3 + max_row, 0, "�T", COLOR_HWHITE, COLOR_BLACK, size + 1);
        cct_showstr(2 * size + 4 + max_row, 0, "�[", COLOR_HWHITE, COLOR_BLACK);

        //��һ��

        for (int i = 0;i < max_col + 2;i++) {
            cct_showstr(2 + max_row, 1 + i, "�U", COLOR_HWHITE, COLOR_BLACK);
            for (int j = 0;j < 2 * size + 2;j++) {
                cct_showstr(j + 3 + max_row, 1 + i, " ", COLOR_HWHITE, COLOR_BLACK);

            }
            cct_showstr(2 * size + 4 + max_row, 1 + i, "�U", COLOR_HWHITE, COLOR_BLACK);
        }

        //�м�


        cct_showstr(2 + max_row, max_col, "�d", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(3 + max_row, max_col, "�T", COLOR_HWHITE, COLOR_BLACK, size + 1);
        cct_showstr(2 * size + 4 + max_row, max_col, "�g", COLOR_HWHITE, COLOR_BLACK);
        //���һ�д�ӡ���




    }


    






    //�������౳������ʼ��ӡ�м䷽��



    // ��ӡabcd�У�������ʼλ�ã�
    print_row_abcd(size, max_row, max_col, print);

   
   

    if (print)
        cct_showstr(2 + max_row, 2 + max_col, "�p", COLOR_HWHITE, COLOR_BLACK);
    else
        cct_showstr(2 + max_row, 2 + max_col, "�X", COLOR_HWHITE, COLOR_BLACK);

    cct_showstr(3 + max_row, 2 + max_col, "�T", COLOR_HWHITE, COLOR_BLACK, size + 1);

    if(print)
        cct_showstr(2 * size + 4 + max_row, 2 + max_col, "�g", COLOR_HWHITE, COLOR_BLACK);
    else
        cct_showstr(2 * size + 4 + max_row, 2 + max_col, "�[", COLOR_HWHITE, COLOR_BLACK);
    //��һ�д�ӡ���



    for (int i = 0;i < size;i++) {
        if (print) 
        {
            cct_showch(0 + max_row, i + 3 + max_col, char(i + 'A'), COLOR_HWHITE, COLOR_BLACK);
            cct_setcolor(COLOR_HWHITE,COLOR_BLACK);
            cout << ' ';
            cct_setcolor();
        }
        else
            cct_showch(0 + max_row, i + 3 + max_col, char(i + 'A')); //ǰ���ABCD
        cct_showstr(2 + max_row, 3 + i + max_col, "�U", COLOR_HWHITE, COLOR_BLACK);
        for (int j = 0;j < 2 * size + 2;j++) {
            cct_showstr(j + 3 + max_row, 3 + i + max_col, " ", COLOR_HWHITE, COLOR_BLACK);

        }
        cct_showstr(2 * size + 4 + max_row, 3 + i + max_col, "�U", COLOR_HWHITE, COLOR_BLACK);
    }


   
    cct_showstr(2 + max_row, size + 3 + max_col, "�^", COLOR_HWHITE, COLOR_BLACK);
    cct_showstr(3 + max_row, size + 3 + max_col, "�T", COLOR_HWHITE, COLOR_BLACK, size + 1);
    cct_showstr(2 * size + 4 + max_row, size + 3 + max_col, "�a", COLOR_HWHITE, COLOR_BLACK);
    //���һ�д�ӡ���


}



void print_circle(int X, int Y)
{
    
    cct_showstr(X , Y , "��", COLOR_HBLUE, COLOR_BLACK);
    cct_setcolor();     // �ָ�ԭʼ��ɫ
}

void print_false(int X, int Y)
{
    cct_showstr(X, Y, "��", COLOR_RED, COLOR_BLACK);
    cct_setcolor();     // �ָ�ԭʼ��ɫ
}


void print_square(int X, int Y,int COLOR) {
    const int width = 3; // ����Ϊ�����ʵĳߴ�

    X += 3;

    // �����ϱ߿�
    cct_showstr(X - 1 - 1, Y - 1, "�X", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y - 1, "�T", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y - 1, "�[", COLOR, COLOR_BLACK);

    // �������ұ߿�
    for (int i = 0; i < width - 2; i++) {
        cct_showstr(X - 1 - 1, Y + i, "�U", COLOR, COLOR_BLACK);
        cct_showstr(X + 2 * width - 2 - 2, Y + i, "�U", COLOR, COLOR_BLACK);
    }

    // �����±߿�
    cct_showstr(X - 1 - 1, Y + 2 - 1, "�^", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y + 2 - 1, "�T", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y + 2 - 1, "�a", COLOR, COLOR_BLACK);

    // �����Ļ���Բ
    cct_showstr(X + (width - 2) / 2, Y + (width - 2) / 2, "��", COLOR, COLOR_BLACK);

    cct_setcolor(); // �ָ�ԭʼ��ɫ
}

void print_false_square(int X, int Y,int COLOR) {
    const int width = 3; // ����Ϊ�����ʵĳߴ�

    X += 3;

    // �����ϱ߿�
    cct_showstr(X - 1 - 1, Y - 1, "�X", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y - 1, "�T", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y - 1, "�[", COLOR, COLOR_BLACK);

    // �������ұ߿�
    for (int i = 0; i < width - 2; i++) {
        cct_showstr(X - 1 - 1, Y + i, "�U", COLOR, COLOR_BLACK);
        cct_showstr(X + 2 * width - 2 - 2, Y + i, "�U", COLOR, COLOR_BLACK);
    }

    // �����±߿�
    cct_showstr(X - 1 - 1, Y + 2 - 1, "�^", COLOR, COLOR_BLACK);
    cct_showstr(X - 1, Y + 2 - 1, "�T", COLOR, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y + 2 - 1, "�a", COLOR, COLOR_BLACK);

    // �����Ļ���Բ
    cct_showstr(X + (width - 2) / 2, Y + (width - 2) / 2, "��", COLOR, COLOR_BLACK);

    cct_setcolor(); // �ָ�ԭʼ��ɫ
}

void print_restore_square(int X, int Y) {
    const int width = 3; // ����Ϊ�����ʵĳߴ�

    X += 3;

    // �����ϱ߿�
    cct_showstr(X - 1 - 1, Y - 1, "  ", COLOR_HWHITE, COLOR_BLACK);
    cct_showstr(X - 1, Y - 1, "  ", COLOR_HWHITE, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y - 1, "  ", COLOR_HWHITE, COLOR_BLACK);

    // �������ұ߿�
    for (int i = 0; i < width - 2; i++) {
        cct_showstr(X - 1 - 1, Y + i, "  ", COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(X + 2 * width - 2 - 2, Y + i, "  ", COLOR_HWHITE, COLOR_BLACK);
    }

    // �����±߿�
    cct_showstr(X - 1 - 1, Y + 2 - 1, "  ", COLOR_HWHITE, COLOR_BLACK);
    cct_showstr(X - 1, Y + 2 - 1, "  ", COLOR_HWHITE, COLOR_BLACK, 2 * width - 4);
    cct_showstr(X + 2 * width - 2 - 2, Y + 2 - 1, "  ", COLOR_HWHITE, COLOR_BLACK);

    // �����Ļ���Բ
    cct_showstr(X + (width - 2) / 2, Y + (width - 2) / 2, "  ", COLOR_HWHITE, COLOR_BLACK);

    cct_setcolor(); // �ָ�ԭʼ��ɫ
}



void print_puzzleonly(const puzzle& p)
{
    //�ȴ�ӡ����
    print_bg(p.size, 0,0,0);
    



    for (int i = 0;i < p.size;i++) {
        for (int j = 0; j < p.size; j++) {
            if (p.data[i][j]) {
                int x = 4 + j * 2;  // ������
                int y = 3 + i;      // ������
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

    // ������Ҫ�ļ��
    int row_hint_space = max_row_hints * 2 + 6; // ÿ����ʾ����ռ2�ַ���
    int col_hint_space = max_col_hints + 1;

    print_bg(p.size, true, row_hint_space, col_hint_space);

    // ��ӡ����ʾ����ࣩ
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < h.row_counts[i]; k++) {
                cct_showint(row_hint_space - (h.row_counts[i] - k) * 2-2,
                    3 + col_hint_space + i,
                    h.row_hints[i][k], COLOR_HWHITE, COLOR_BLACK);

        }
    }

    // ��ӡ����ʾ���Ϸ���
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
        // ��ӡ��������
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


//��Ϸ����

struct GameState {
    puzzle puzzle;
    Hints hints;
    int markState[15][15] = { 0 }; // 0=δ���, 1=ԲȦ, 2=���
    bool cheatMode = false;
};

// �����ɺ���
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






//ȡ�����
void print_restore(int X, int Y)
{
    cct_showstr(X, Y, "  ", COLOR_HWHITE);
    cct_setcolor();
}




//�����ݼ��㲢�������
void getlocation(int x, int y, const int max_row, const int max_col, const int size, bool play, int scale)
{
    cct_setcolor();

    // �����������
    int row = (x - max_row * 2 - 10) / (2 * scale);
    int col = (y - max_col - 4) / scale;

    // Ĭ����Ϊ����Ч����
    bool is_valid = (row >= 0 && row < size && col >= 0 && col < size);

    // ֻ�е�scale>1ʱ�ż����������
    if (scale > 1 && is_valid) {
        // ��������ڸ����ڵ����λ��
        int relative_x = (x - max_row * 2 - 10) % (2 * scale);
        int relative_y = (y - max_col - 4) % scale;

        // ����3��3��������Χ
        int center_size = 3;  // 3��3����������
        int x_center_start = scale - center_size / 2 - 1;
        int x_center_end = scale + center_size / 2 + 1;
        int y_center_start = scale / 2 - center_size / 2 - 1;
        int y_center_end = scale / 2 + center_size / 2 + 1;

        // ����Ƿ���3��3����������
        is_valid = (relative_x >= x_center_start && relative_x < x_center_end) && (relative_y >= y_center_start && relative_y < y_center_end);
    }

    cct_gotoxy(10, max_col + size * scale + 5);
    if (is_valid) {
        cout << "[��ǰ���]" << " " << char('A' + col) << "��" << " " << char('a' + row) << "��";
    }
    else {
        cout << "[��ǰ���]" << "λ�÷Ƿ�";
    }
}





void getxy_puzzle(bool play, const int max_row, const int max_col, int size, GameState& game, int scale = 1) {
    cct_enable_mouse();
    cct_setcolor();

    if (play) {
        cct_gotoxy(10, (scale == 1 ? max_col + size : max_col +scale * ( size)) + 7);
        cout << "���ѡ���Ҽ�ѡ����Y/y�ύ��Z/z���ף�Q/q����";
    }

    while (1) {
        int x, y, mouseAction, keycode1, keycode2;
        int event = cct_read_keyboard_and_mouse(x, y, mouseAction, keycode1, keycode2);

        // ����ƶ��¼� - ��ʾ��ǰλ��
        if (event == CCT_MOUSE_EVENT && mouseAction == MOUSE_ONLY_MOVED) {
            getlocation(x, y, max_row, max_col, size, play, scale);
        }

        // �����¼�����
        if (event == CCT_KEYBOARD_EVENT) {
            cct_setcolor();
            if (keycode1 == 'Y' || keycode1 == 'y') { // ������
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
                        cout << "ƴͼ��ɣ�                  ";
                    }
                    else {
                        cout << "�ύ���󣬿�������ģʽ�鿴          ";
                    }
                }
            }
            else if (play && (keycode1 == 'Z' || keycode1 == 'z')) { // ����ģʽ�л�
                game.cheatMode = !game.cheatMode;
                cct_gotoxy(10, (scale == 1 ? max_col + size : scale * (max_col + size)) + 8);
                cout << "����ģʽ " << (game.cheatMode ? "����" : "�ر�") << "          ";

                // �����к�����ʾ�ռ�
                int row_hint_space = get_max_row_hints(game.hints, size) * 2 + 6;
                int col_hint_space = get_max_col_hints(game.hints, size) + 1;

                // ������ʾ
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (scale == 1) {
                            int x = 4 + row_hint_space + j * 2;
                            int y = 3 + col_hint_space + i;

                            if (game.cheatMode) {
                                if (game.puzzle.data[i][j]) {
                                    cct_showstr(x, y, "��", COLOR_WHITE, COLOR_BLACK);
                                }
                                // ������ʾ�û����״̬
                                if (game.markState[i][j] == 1) {
                                    int color = (game.puzzle.data[i][j] == 1) ? COLOR_HGREEN : COLOR_RED;
                                    cct_showstr(x, y, "��", color, COLOR_BLACK);
                                }
                                else if (game.markState[i][j] == 2) {
                                    int color = (game.puzzle.data[i][j] == 0) ? COLOR_HGREEN : COLOR_RED;
                                    cct_showstr(x, y, "��", color, COLOR_BLACK);
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
            else if (keycode1 == 'Q' || keycode1 == 'q') { // �˳�
                break;
            }
        }

        // ���������
        if (play && event == CCT_MOUSE_EVENT &&
            (mouseAction == MOUSE_LEFT_BUTTON_CLICK || mouseAction == MOUSE_RIGHT_BUTTON_CLICK)) {

            int row = (x - max_row * 2 - 10) / (2 * scale);
            int col = (y - max_col - 4) / scale;

            if (row >= 0 && row < size && col >= 0 && col < size) {
                if (scale == 1) {
                    if (x % 2 != 0) x--; // ������������

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

//�ܵ��ú���

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
    getxy_puzzle(play, max_row, max_col, size, dummy, 5); // ʹ��Ĭ��scale=5
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
    puzzle p = input(&size);  // ������������
    Hints h;
    input_hint(p, h);         // ������ʾ����

    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // ������Ϸ״̬����ʼ��
    GameState game;
    game.puzzle = p;         // ������������
    game.hints = h;          // ������ʾ����

    print_puzzlewithhints(1, game.puzzle, game.hints);

    // ������Ϸ״̬
    int scale = 1;
    getxy_puzzle(1, max_row_hints, max_col_hints, size, game,scale);
    my_exit();


}




















void print_row_abcd2(int size, int max_row, int max_col, bool printhint)
{
    //���������С

    cct_setfontsize("����", 14);






    cct_setcolor();
    cct_gotoxy(max_row, max_col + 1);
    cout << "    ";
    if (printhint) {
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row + 3, max_col + 2, "�U", COLOR_HWHITE, COLOR_BLACK);
       
    }
    for (int i = 0;i < size;i++) {
        cout <<setw(4)<< " " << char('a' + i)<< setw(5) << " ";


    }
    if (printhint) {
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_showstr(max_row + 3 + 10 * size, max_col + 2, "�U", COLOR_HWHITE, COLOR_BLACK);

    }

    cout << endl;
}






void print_bg2(int size, bool print, int max_row, int max_col) {
    const int scale = 5; // �Ŵ�5��
    const int cell_width = 2; // ÿ�����ӿ��
    const int cell_height = 1; // ÿ�����Ӹ߶�

    // ��������̨��С
    cct_setconsoleborder(max_row + 5 * size * scale, max_row + 5 * size * scale, max_row + 5 * size * scale, max_row + 5 * size * scale);
    cout << endl;

    

    // 2. ���̴���ɫ���� --------------------------------------

    // ��ӡ����ʾ�������Ҫ��
    if(print) {
        cct_showstr(1, 3 + max_col, "�X", COLOR_HWHITE, COLOR_BLACK);  // ����1������1
        cct_showstr(2, 3 + max_col, "�T", COLOR_HWHITE, COLOR_BLACK, max_row - 1);

        for (int i = 0; i < size * scale; i++) {
            cct_showstr(1, i + 1 + 3 + max_col, "�U", COLOR_HWHITE, COLOR_BLACK);  // ����1������1
            for (int j = 0; j < max_row*2-2; j++) {
                cct_showstr(j + 2, i + 1 + 3 + max_col, " ", COLOR_HWHITE, COLOR_BLACK);  // ����1
            }
        }

        cct_showstr(max_row - 1, 3 + max_col, "�j", COLOR_HWHITE, COLOR_BLACK);  // ����1������1
        cct_showstr(max_row, 3 + max_col, "�T", COLOR_HWHITE, COLOR_BLACK);
        for (int i = 0; i < size * scale; i++) {
            cct_showstr(max_row - 1, 1 + 3 + max_col + i, "�U", COLOR_HWHITE, COLOR_BLACK);  // ����1
        }

        cct_showstr(1, max_col + size * scale + 3, "�^", COLOR_HWHITE, COLOR_BLACK);  // ����1������1
        cct_showstr(2, max_col + size * scale + 3, "�T", COLOR_HWHITE, COLOR_BLACK, max_row - 1);
        cct_showstr(max_row - 1, 1 + max_col + size * scale + 2, "�m", COLOR_HWHITE, COLOR_BLACK);  // ����1
        cct_showstr(max_row, 1 + max_col + size * scale + 2, "�T", COLOR_HWHITE, COLOR_BLACK);
    }

    // ��ӡ����ʾ������1������1���߶ȼ�2��
    if (print) {
        cct_showstr(3 + max_row, 1, "�X", COLOR_HWHITE, COLOR_BLACK);  // ����1������1
        cct_showstr(4 + max_row, 1, "�T", COLOR_HWHITE, COLOR_BLACK, size * scale);  // ���ȼ�2
        cct_showstr(2 * size * scale + 3 + max_row, 1, "�[", COLOR_HWHITE, COLOR_BLACK);  // ����1

        // �߶ȼ�2��ԭmax_col+2��Ϊmax_col��
        for (int i = 0; i < max_col; i++) {  // ��Ϊmax_col
            cct_showstr(3 + max_row, 2 + i, "�U", COLOR_HWHITE, COLOR_BLACK);  // ����1������1
            for (int j = 0; j < 2 * size * scale ; j++) {  // ���ȼ�2
                cct_showstr(j + 4 + max_row, 2 + i, " ", COLOR_HWHITE, COLOR_BLACK);  // ����1
            }
            cct_showstr(2 * size * scale + 3 + max_row, 2 + i, "�U", COLOR_HWHITE, COLOR_BLACK);  // ����1
        }

       
    }

    


    // ��ӡabcd�б�ǩ



    print_row_abcd2(size, max_row, max_col, print);

    if (print) {
        cct_showstr(3 + max_row, max_col + 1, "�d", COLOR_HWHITE, COLOR_BLACK);  // ����1������1
        cct_showstr(4 + max_row, max_col + 1, "�T", COLOR_HWHITE, COLOR_BLACK, size * scale);  // ���ȼ�2
        cct_showstr(2 * size * scale + 3 + max_row, max_col + 1, "�g", COLOR_HWHITE, COLOR_BLACK);  // ����1

    }

    const int board_start_x = max_row + 2;
    const int board_start_y = max_col + 3;
    const int board_width = size * scale ;
    const int board_height = size * scale;

    // ���̰�ɫ����
    for (int y = 0; y < board_height; y++) {
        for (int x = 0; x < board_width*2; x++) {
            cct_showstr(board_start_x + 1 + x, board_start_y + y,
                "  ", COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // ������߿�
    
    cct_showstr(board_start_x + 1, board_start_y , "�T", COLOR_HWHITE, COLOR_BLACK, board_width);
    if(print)
        cct_showstr(board_start_x + 1 + board_width * 2, board_start_y, "�g", COLOR_HWHITE, COLOR_BLACK);
    else
        cct_showstr(board_start_x + 1 + board_width*2, board_start_y , "�[", COLOR_HWHITE, COLOR_BLACK);

    // ���ƴ�ֱ������ (ֻ�ڷŴ�����������)
    for (int col = 0; col <= size; col++) {
        int x = board_start_x + 1 + col * scale * cell_width;
        if(print&&col==0&&x== board_start_x + 1)
            cct_showstr(x, board_start_y, "�p", COLOR_HWHITE, COLOR_BLACK);
        
        
        else 
            cct_showstr(x, board_start_y , "�h", COLOR_HWHITE, COLOR_BLACK);
        
        for (int y = board_start_y+1; y < board_start_y + board_height; y++) {
            cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK);
       
        }
        
            cct_showstr(x, board_start_y + board_height, "�k", COLOR_HWHITE, COLOR_BLACK);

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

    // ����ˮƽ������ (ֻ�ڷŴ�����������)
    for (int row = 0; row <= size; row++) {
        int y = board_start_y + row * scale;
        for (int x = board_start_x + 1; x < board_start_x + 1 + 2*board_width; x += cell_width) {
            cct_showstr(x, y, "�T�T", COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // ���ƽ����
    for (int row = 0; row <= size; row++) {
        for (int col = 0; col <= size; col++) {
            int x = board_start_x + 1 + col * scale * cell_width;
            int y = board_start_y + row * scale;

            if (row == 0 && col == 0&&!print) {
                cct_showstr(x, y, "�X", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == 0 && col == size&&!print) {
                cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == size && col == 0) {
                cct_showstr(x, y, "�^", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == size && col == size) {
                cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == 0&&!print) {
                cct_showstr(x, y, "�h", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (row == size) {
                cct_showstr(x, y, "�k", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (col == 0) {
                cct_showstr(x, y, "�c", COLOR_HWHITE, COLOR_BLACK);
            }
            else if (col == size) {
                cct_showstr(x, y, "�f", COLOR_HWHITE, COLOR_BLACK);
            }
            else if(row!=0){
                cct_showstr(x, y, "�p", COLOR_HWHITE, COLOR_BLACK);
            }
            else
                cct_showstr(x, y, "�h", COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // ���Ƶײ��߿�
   
    //cct_showstr(board_start_x + 1, board_start_y + board_height, "�T", COLOR_HWHITE, COLOR_BLACK, board_width);
    
}




void print_puzzleonly_2(const puzzle& p,const Hints& h)
{
    //�ȴ�ӡ����
    
    print_bg2(p.size, 0, 0, 0);





    int size = p.size;
    
    // ������Ҫ�ļ��
    int row_hint_space = 0;
    int col_hint_space = 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (p.data[i][j]) {
                int x = 5 + row_hint_space + j * 10;  // �Ŵ�5���������
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

    // ������Ҫ�ļ��
    int row_hint_space = max_row_hints * 2 + 6;
    int col_hint_space = max_col_hints + 1;

    // ��ӡ������ı���
    print_bg2(size, true, row_hint_space, col_hint_space);

    // ��ӡ����ʾ����ࣩ
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < h.row_counts[i]; k++) {
            cct_showint(row_hint_space - (h.row_counts[i] - k) * 2 - 2,
                5 + col_hint_space + i * 5,  // ע�⣺�Ŵ�5�������λ��
                h.row_hints[i][k], COLOR_HWHITE, COLOR_BLACK);
        }
    }

    // ��ӡ����ʾ���Ϸ���
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < h.col_counts[j]; k++) {
            cct_showint(5 + row_hint_space + j * 10 + 4,  // �Ŵ�5�������λ��
                col_hint_space - h.col_counts[j] + k+1,
                h.col_hints[j][k], COLOR_HWHITE, COLOR_BLACK);
        }
    }

    if (!play) {
        // ��ӡ�������ݣ�ʹ��print_square��
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (p.data[i][j]) {
                    int x = 5 + row_hint_space + j * 10;  // �Ŵ�5���������
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
    puzzle p = input(&size);  // ������������
    Hints h;
    input_hint(p, h);         // ������ʾ����

    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // ������Ϸ״̬����ʼ��
    GameState game;
    game.puzzle = p;         // ������������
    game.hints = h;          // ������ʾ����

   
    print_puzzlewithhints_2(0, p, h);
   
    int scale = 5;
    getxy_puzzle(0, max_row_hints, max_col_hints, size,game,scale);


    my_exit();
}






void T_K() {
    cct_cls();
    srand(unsigned int(time(0)));

    int size;
    puzzle p = input(&size);  // ������������
    Hints h;
    input_hint(p, h);         // ������ʾ����

    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    // ������Ϸ״̬����ʼ��
    GameState game;
    game.puzzle = p;         // ������������
    game.hints = h;          // ������ʾ����


    print_puzzlewithhints_2(1, p, h);

    int scale = 5;
    getxy_puzzle(1, max_row_hints, max_col_hints, size, game, scale);


    my_exit();
}

