#include <stdio.h>

int main(){
	char s[31];
	for(int i=0; i < 5; i++){
		fgets(s,30,stdin);
		puts(s);
	}	

	return 0;
}