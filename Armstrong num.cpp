#include <stdio.h>

int main()
{
	int n ;
	int temp = n;
	int p = 0;
	
	printf("Entre the number:");
	scanf("%d", &n);
	
	while (n > 0) {
		int rem = n % 10;
		p = (p) + (rem * rem * rem);
		n = n / 10;
	}

	if (temp == p) {
		printf("Yes. It is Armstrong Number");
	}
	else {
		printf("No. It is not an Armstrong Number");
	}
	return 0;
}

