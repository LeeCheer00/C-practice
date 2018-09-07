#include <stdio.h>
int getNum(){

	return 100;
}

int main(){
	int n=90;
	const int MaxNum1=getNum();
	const int MaxNum2=n;
	const int MaxNum3=80;
	printf("%d, %d, %d\n",MaxNum1,MaxNum2,MaxNum3);


	return 0;

	}
