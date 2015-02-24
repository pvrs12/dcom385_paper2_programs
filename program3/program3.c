#include <stdio.h>
#include <string.h>

int main(){
	FILE* file = fopen("program3.c","rt");
	
	char line[201];

	int count=0;
	while(fgets(line,200,file)!=NULL){
		count++;
		int n=strnlen(line,200);
		if(n<1){
			//don't count this line, it's blank
			count--;
			continue;
		}
		int i;
		int isComment=0;
		int allWhiteSpace=1;
		for(i=0;i<n;++i){
			/*ignore whitespace*/
			if(line[i]==' '||line[i]=='\n'||line[i]=='\t'||line[i]=='\r'){
				continue;
			}
			if(line[i]=='/'){
				if(i<n-1){
					if(line[i+1]=='/'){
						isComment=1;
						allWhiteSpace=0;
						break;
					}
					if(line[i+1]=='*'){
						isComment=1;
						allWhiteSpace=0;
						break;
					}
				}
			} else {
				allWhiteSpace=0;
				break;
			}
		}
		if(isComment || allWhiteSpace){
			count--;
		}
	}
	printf("There are %d functional lines in \"program3.c\"\n",count);
	return 0;
}
