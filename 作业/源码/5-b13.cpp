/*2452545 刘晴语 计算机*/
#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;
#define row 10
#define col 26
#define TNT 50


void print_boom(char map[row+2][col+2]) {
	for (int i = 1;i < row+1;i++) {
		for (int j = 1;j < col+1;j++) {
            if(map[i][j]=='*')
			    cout << map[i][j] << ' ';
            else {
                map[i][j] += '0';
                cout << map[i][j] << ' ';
            }
		}
		cout << endl;
	}


}



int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

	char map[row+2][col+2] = { 0 };


    int count = 0;
    while (count < TNT) {
        int r = rand() % row + 1;  
        int c = rand() % col + 1;  

        if (map[r][c] != '*') {  // 如果不是雷
            map[r][c] = '*';    // 放雷
            count++;

            
            for (int i = r - 1; i <= r + 1; i++) {
                for (int j = c - 1; j <= c + 1; j++) {
                    if (map[i][j] != '*') {
                        map[i][j]++;
                    }
                }
            }
        }

    }
	print_boom(map);



}

