#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){


	FILE *fp;
	char ch;
	
	//判断文件是否成功打开

	if((fp=fopen("demo.txt","wt+"))==NULL)	{


	printf("Cannot open file, press any key to exit !\n");


	exit(1);


	}



		printf("Input a string :\n");

		// 每次从键盘读取一个字符并且写入文件


	while((ch=getchar())!='\n'){


	fputc(ch,fp);

	}

	fclose(fp);


	return 0;
	}




