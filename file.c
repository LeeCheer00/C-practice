#include <stdio.h>
#include <stdlib.h>

int main(){



	FILE *fp;
	char ch;
	
	//如果文件不存在，给出提示并且退出。
	if((fp=fopen("\home\leecheer\LeeCheer\Demo\demo.txt","rt"))==NULL){
		
		printf("Cannot open file, press any key to exit!");
		


		getch();
		exit(1);
	}

	//每次读取一个字节，直到读取完毕
	
	while((ch=fgetc(fp))!=EOF){
		putchar (ch);
		};
	putchar('\n');
	fclose(fp);
	return 0;

	}

