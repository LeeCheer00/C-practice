#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
int main(){
*fp
*buffer
*offset
*len
n  //返回的并且插入的字节数
return 0;
	
}

/**
*向文件中插入内容
*@LeeCheer fp		要插入内容的文件
*@LeeCheer buffer	缓冲区，也就是要插入的内容
*@LeeCheer offset	偏移量（相对文件开头），也就是从哪里开始插入
*@LeeCheer len		要插入的内容长度
*@return 		成功插入的字节数
**/

int finsert(FILE *fp,long offset, void *buffer, int len){
	long fileSize=fsize(fp);
	FILE *fpTemp;// 临时文件
	if(offset>fileSize || offset<0 ||len<0){//插入错误
	return -1；
	}	
	if(offset== fileSize){//文件末尾插入
		fseek(fp,offset,SEEK_SET);
		if(!fwrite(buffer,len,1,fp)){
			return -1;
	}}

	if(offset<fileSize){//从开头或者中间位置插入
		fpTemp=tmpfile();
		fcopy(fp,0,offset,fpTemp,0);
		fwrite(buffer, len,1, fpTemp);
		fcopy(fp,offset, -1, fpTemp, offset+len);
		fcopy(fpTemp,0,-1,fp,0);
		
		}
	return 0;	

}

