#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
long fsize(FILE *fp);
int main(){
	long size=0;
	FILE *fp=NULL;
	char filename[30]="demo.txt";
	if (( fp= fopen(filename,"rb")) == NULL ){
		printf("Failed to open %s...",filename);
		exit(EXIT_SUCCESS) ; 
	}
	printf("%ld\n",fsize(fp));
	return 0;
	}
	long fsize (FILE *fp){
		long n;
		fpos_t fpos;//当前位置
		fgetpos(fp, &fpos);//获取当前位置
		fseek(fp,0,SEEK_END);
		n=ftell(fp);
		fsetpos(fp,&fpos);
		fsetpos(fp,&fpos);//恢复之前的位置
		return n;
	}

