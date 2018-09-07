#include <stdio.h>
#include <string.h>
#include <curses.h>
int main(){


}




int fdelete(FILE *fp, long offset, int len){
	long fileSize=getFileSize(fp);
	FILE *fpTemp;
	
	if(offset>fileSize || offset<0 || len<0){

// 错误


	return -1;
}


	fpTemp=tmpfile();
	fcopy(fp,0,offet,fpTemp,0);// 将前offset字节的数据复制到临时文件
	fcopy(fp,offset+len,-1,fpTemp,offset);//将offset+len之后的所有内容都复制到临时文件
	freopen(FILENAME,"wb+",fp);//重新打开文件 
	fcopy(fpTemp,0,-1,fp,0);
	
	fclose(fpTemp);	
	return 0;

}





