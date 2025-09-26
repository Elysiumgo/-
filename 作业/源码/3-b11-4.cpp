/* 2452545 ¼ÆËã»ú ÁõÇçÓï */
#include <iostream> 
using namespace std;
//sum=16,i=0,j=3,k=3
int main()
{
	int i, j, k, sum = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				cout << "*";
				sum++;
				if (k >= 3)
					break;
			}
			cout << ' ';
			if (j >= 3)
				break;
		}
		cout << endl;
		break;
	}

	cout << "sum=" << sum << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;

	return 0;
}

