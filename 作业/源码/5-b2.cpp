/*2452545 ¼ÆËã»ú ÁõÇçÓï*/
#include<iostream>
using namespace std;

int main()
{
	bool light[101] = { 0 };
	int count, i=1;
	for (count = 1;count < 101;count++) {
		for (i=count;i<101;i++){
			if (i % count == 0)
				light[i] = !light[i];
		}
	}
	for (i = 1;i <101;i++) {
		if (light[i] == 1) {
			cout << i;
			if (i < 100)
				cout << ' ';
		}
	}
	cout << endl;
	return 0;

}