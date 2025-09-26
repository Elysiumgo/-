/* 2452545 ¼ÆËã»ú ÁõÇçÓï */
#include <iostream> 
using namespace std;
//sum=40,i=5,j=1,k=3
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
			if (j < 1)
				k = 0;
			else
				break;

		}
		cout << endl;
		if (i < 4)
			j = 0; 
	}

	cout << "sum=" << sum << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;

	return 0;
}

