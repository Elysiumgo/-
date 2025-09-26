/*2452545 º∆À„ª˙ ¡ı«Á”Ô*/


#include<iostream>
#include"cmd_console_tools.h"
#include"pullze.h"
using namespace std;


int main()
{
	while(1)
	{
		cct_cls();
		char k = menu();
		if (k == 'A')
			T_A();
		else if (k == 'B')
			T_B();
		else if (k == 'C')
			T_C();
		else if (k == 'D')
			T_D();
		else if (k == 'E')
			T_E();
		else if (k == 'F')
			T_F();
		else if (k == 'G')
			T_G();
		else if (k == 'H')
			T_H();
		else if (k == 'I')
			T_I();
		else if (k == 'J')
			T_J();
		else if (k == 'K')
			T_K();
		else if (k == 'Q')
			break;
	}

}