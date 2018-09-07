#include <stdio.h>
int main(){
	fcopy(fSource,0,-1,fTarget,0);//函数的应用方法 我们还需要定义len(输入长度）, 目标文件的位置， 以及读取文件，写入文件。
	return 0}

/**
*文件复制函数
*@LeeCheer fSource		要复制的原文件
*@LeeCheer offsetSource		原文件的位置
*@LeeCheer len			要复制的内容长度，小于0表示offsetSource后面的所有内容
*@LeeCheer fTarget		目标文件，也就是将文件复制到哪里
*@LeeCheer offsetTarget		目标文件的位置偏移，也就是复制到目标文件的位置
*@return   成功复制的字节数
**/
long fcopy(FILE *fSource, long offsetSource, long len, FILE *fTarget, long offsetTarget){
	int bufferLen=1024;// 缓冲区长度
	char *buffer=(char *)malloc(bufferLen);// 开辟缓存
	int readCount;// 每次调用fread()读取的字节数
	long nBytes=0;// 总共复制了多少个字节
	int n=0;// 需要调用多少次fread()函数
	int i;//循环控制变量


	fseek(fSource,offsetSource, SEEK_SET);
	fseek(fTarget,offsetTarget, SEEK_SET);
	
	if(len<0){//复制所有内容
		while((readCount=fread(buffer, 1,bufferLen,fSource))>0){
		nBytes+=readCount;
		fwrite(buffer,readCount,1,fTarget);
	}
	}
	else {
		//复制len个字节的内容
		n=(int)ceil((double)((double)len/bufferLen));
		for(i=1;i<=n;i++){
			if(len-nBytes<bufferLen){bufferLen=len-nBytes;}
			readCount=fread(buffer,1,bufferLen,fSource);
			fwrite(buffer,reacount,1,fTarget);
			nBytes+=readCount;
		}
	}
	fflush(fTarget);
	free(buffer);
	return nBytes;

}


	
