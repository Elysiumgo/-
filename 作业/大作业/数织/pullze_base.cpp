/* 2452545 ����� ������ */
#include<iostream>
#include<conio.h>
#include <iomanip>
#include "cmd_console_tools.h"
#include "pullze.h"

#define MAX_HINTS 8
using namespace std;



//�ڲ������ĺ���



struct puzzle_base {
    int size;
    int data[15][15]; // �����ߴ����
};

struct Hints_base {
    int row_hints[15][MAX_HINTS] = { 0 }; // ����ʾ [�к�][��ʾ����]
    int col_hints[15][MAX_HINTS] = { 0 }; // ����ʾ [�к�][��ʾ����]
    int row_counts[15] = { 0 }; // ÿ�е���ʾ��
    int col_counts[15] = { 0 }; // ÿ�е���ʾ��
};


//������ڲ�����
puzzle_base input_base(int* SIZE)
{
    puzzle_base p;
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



//����ڲ����ߣ��涨5���ַ�һС�񣬻���
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


//���ǰ������ʾ���ߣ�����size�ı䣬������
void print_hintline1(int size)
{
    int num;
    if (size == 5)
        num = 3;
    else if (size == 10)
        num = 5;
    else
        num = 7;
    //ÿ�������Ӧ���������

    int sum = 2 * num + 1; //����������˴���

    //��������������Ҫ���ٿո��-

    for (int i = 0;i < sum;i++) {
        cout << '-';
    }




}


//�����������ʾ���ߣ�����size�ı䣬������
void print_hintline2(int size)
{
    int num;
    if (size == 5)
        num = 3;
    else if (size == 10)
        num = 5;
    else
        num = 7;
    //ÿ�������Ӧ���������
    
    int sum = 2 * num + 1; //����������˴���

    //��������������Ҫ���ٿո��-

    for (int i = 0;i < sum-2;i++) {
        cout << '-';
    }

    cout << "+-";


}


//���ǰ����ǰ�ո�
void print_blank(int size)
{
    int num;
    if (size == 5)
        num = 3;
    else if (size == 10)
        num = 5;
    else
        num = 7;
    //ÿ�������Ӧ���������

    int sum = 2 * num+1;
    //��������������Ҫ���ٿո��-

    for (int i = 0;i < sum;i++) {
        cout << ' ';
    }

    cout << '|';
}


//���abcd�У�����
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





//����ڲ�����(����ʾ��
void print_puzzleonly_base(const puzzle_base& p)
{
    int size = p.size;

    cout << "+-";
    print_insideline(size);
    //��һ��

    cout << "| |";
    print_row_console(size);
    //�ڶ���abcd

    cout << "+-";
    print_insideline(size);
    //������



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


//��ȡ����ʾ���������
int get_max_row_hints(const Hints_base& h, int size) {
    int max_hints = 0;
    for (int i = 0; i < size; i++) {
        if (h.row_counts[i] > max_hints) {
            max_hints = h.row_counts[i];
        }
    }
    return max_hints;
}

// ��ȡ����ʾ���������
int get_max_col_hints(const Hints_base& h, int size) {
    int max_hints = 0;
    for (int j = 0; j < size; j++) {
        if (h.col_counts[j] > max_hints) {
            max_hints = h.col_counts[j];
        }
    }
    return max_hints;
}











//����ڲ�����(����ʾ��
void print_withhints_base(const puzzle_base& p, const Hints_base& h) {
    int size = p.size;
    int max_row_hints = get_max_row_hints(h, size);
    int max_col_hints = get_max_col_hints(h, size);

    
    cout << endl;
    print_hintline1(size);
    print_insideline(size);

    //��һ��



    // ��ӡ����ʾ(�Ϸ�)
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

    // ��ӡ�����߿�
    print_hintline1(size);
    print_insideline(size);

    // ��ӡabcd��
    print_blank(size);
    print_row_console(size);

    // ��ӡ�ָ���
    print_hintline2(size);
    print_insideline(size);

    // ��ӡ�����ݺ�����ʾ
    for (int i = 0; i < size; i++) {
        // ��ӡ����ʾ(���)
        for (int k = max_row_hints - 1; k >= 0; k--) {
            if (k < h.row_counts[i]) {
                cout << setw(2) << h.row_hints[i][k];
            }
            else {
                cout << "  ";
            }
        }
       

        // ��ӡ�����ݺ͸���
        cout << " |" << char('A' + i) << "|";
        for (int j = 0; j < size; j++) {
            cout << (p.data[i][j] ? " 0" : "  ");
            if ((j + 1) % 5 == 0 && j != size - 1) {
                cout << " |";
            }
        }
        cout << " |";
        cout << endl;

        // ��ӡ�ָ���
        if ((i + 1) % 5 == 0 && i != size - 1) {
            print_hintline2(size);
            print_insideline(size);
        }

       
    }

    // ��ӡ�ײ��߿�
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
    bool marked[15][15] = { false }; // ����û��Ѿ�ѡ��ĸ���
    bool cheatMode = false;
};







void print_game(const GameState_base& game) {
    int size = game.puzzle.size;
    int max_row_hints = get_max_row_hints(game.hints, size);
    int max_col_hints = get_max_col_hints(game.hints, size);



    cout << endl;
    print_hintline1(size);
    print_insideline(size);

    // ��ӡ����ʾ(�Ϸ�)
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

    // ��ӡ�����߿�
    print_hintline1(size);
    print_insideline(size);

    // ��ӡabcd��
    print_blank(size);
    print_row_console(size);

    // ��ӡ�ָ���
    print_hintline2(size);
    print_insideline(size);

    // ��ӡ��Ϸ����
    for (int i = 0; i < size; i++) {
        // ��ӡ����ʾ
        for (int k = max_row_hints - 1; k >= 0; k--) {
            if (k < game.hints.row_counts[i]) {
                cout << setw(2) << game.hints.row_hints[i][k];
            }
            else {
                cout << "  ";
            }
        }

        // ��ӡ�����ݺ͸���
        cout << " |" << char('A' + i) << "|";
        for (int j = 0; j < size; j++) {
            if (game.marked[i][j]) {
                // ��ͨģʽ�����б�Ƕ���ʾ��ɫ������0
                if (!game.cheatMode) {
                    cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
                    cout << " 0";
                    cct_setcolor();
                }
                // ����ģʽ�¸����Ƿ���ȷ��ʾ��ͬ��ɫ
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
            // ����ģʽ����ʾ������ȷλ�õ�0
            else if (game.cheatMode && game.puzzle.data[i][j] == 1) {
                cout << " 0";
            }
            // δ���λ����ʾ�հ�
            else {
                cout << "  ";
            }

            if ((j + 1) % 5 == 0 && j != size - 1) {
                cout << " |";
            }
        }
        cout << " |" << endl;

        // ��ӡ�ָ���
        if ((i + 1) % 5 == 0 && i != size - 1) {
            print_hintline2(size);
            print_insideline(size);
        }
    }

    // ��ӡ�ײ��߿�
    print_hintline2(size);
    print_insideline(size);
}



// ��������
void process_input(GameState_base& game) {
    cout << "��������(��Aa)������(C:����ģʽ/Q:�˳�): ";
    string input;
    cin >> input;

    if (input.size() == 1) {
        char cmd = toupper(input[0]);
        if (cmd == 'C') {
            game.cheatMode = !game.cheatMode;
            cout << "����ģʽ " << (game.cheatMode ? "����" : "�ر�") << endl;
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
            game.marked[row][col] = !game.marked[row][col]; // �л����״̬
        }
        else {
            cout << "��Ч����!" << endl;
        }
    }
}



// �����Ϸ�Ƿ����
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

    // ��ʼ����Ϸ
    int size;
    GameState_base game;
    game.puzzle = input_base(&size);
    input_hint_base(game.puzzle, game.hints);
    // ��ʼ������λ��Ϊδ���
    memset(game.marked, false, sizeof(game.marked));
    game.cheatMode = false;


    
    // ��Ϸ��ѭ��
    while (1) {
       cct_cls();
        print_game(game);

        if (check_complete_base(game)) {
            cout << "��Ϸ��ɡ�" << endl;
            break;
        }

        // ��ʾ�û�����
        cout << "������ʽ��Aa=�ȼ���ͼ����Ϸ��������ѡ��Aaλ(���ִ�Сд)" << endl;
        cout << "����Ҫ֧��ͼ�ν�����Ҽ���棬�ٴ�����Aa�൱�����" << endl;
        cout << "X/x=�˳�(���н���X/x�����ִ�Сд)" << endl;
        cout << "Y/y=�ύ(���н���Y/y�����ִ�Сд)" << endl;
        cout << "Z/z=����(���н���Z/z�����ִ�Сд)" << endl;
        cout << "Ctrl+c ǿ���˳�" << endl;
        cout << "������: ";

        // ��ȡ����
        char input[3] = { 0 };
        cin.getline(input, 3);

        cout << "����";
        cout << input[0] << input[1];
            
        cout<< "��"<<endl;


        // �����ַ�����
        if (strlen(input) == 1) {
            char cmd = toupper(input[0]);
            if (cmd == 'X') {
                break;
            }
            else if (cmd == 'Y') {
                if (check_complete_base(game)) {
                    cout << "��Ϸ��ɡ�" << endl;
                    system("pause");
                    break;
                }
                else {
                    cout << "�ύ����, ��������ģʽ�鿴" << endl;
                    system("pause");
                }
            }
            else if (cmd == 'Z') {
                game.cheatMode = !game.cheatMode;
                cout << "����ģʽ " << (game.cheatMode ? "����" : "�ر�") << endl;
                system("pause");
            }
            continue;
        }

        // ������������
        if (strlen(input) == 2) {
            int row = input[0] - 'A';
            int col = tolower(input[1]) - 'a';

            if (row >= 0 && row < game.puzzle.size && col >= 0 && col < game.puzzle.size) {
                // �л����״̬����ǻ�ȡ����ǣ�
                game.marked[row][col] = !game.marked[row][col];
            }
            else {
                cout << "�������" << endl;
                
            }
        }
    }

    my_exit();
}





