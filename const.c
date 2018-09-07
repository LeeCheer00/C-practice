#include <stdio.h>
#include <string.h>



size_t strnchr(const char *str, char ch){
	int i,n=0,len=strlen(str);


	for(i=0;i<len;i++){
		if(str[i]==ch){
			n++;
		}
	}
	
	return n;
}

int main(){

	char *str="http://c.biancheng.net";
	char ch='t';

	int n=strnchr(str,ch);
	printf("%d\n",n);
	return 0;

}
