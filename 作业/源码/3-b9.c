/*2452545 ¼ÆËã»ú ÁõÇçÓï*/
#include<stdio.h>
int main()
{
	int m = 1, n = 1, k1 = 1, k2 = 0;
	while (n <= m) {
		n = 1;
		k2++;
		k1 = 1;
		while (n <= m) {
			printf("%dx%d=%-2d  ", k1, k2, k1 * k2);
			k1 ++;
			n ++;
		}
		printf("\n");
		m++;
		if (m > 9)
			break;
	}
	printf("\n");
	return 0;
}
	
	
