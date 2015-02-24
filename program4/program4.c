#include <stdio.h>
#include <string.h>

//object start
typedef struct {
	int a;
	int b;
	int c;
	int (*foo)();
	int (*bar)(int);
} sstruct;
//object end

//method start
int foo(){
	printf("this is a method which prints this message\n");
	return 0;
}
//method end

//method start
int bar(int i){
	printf("this is a method which prints a number: %d\n",i);
	return 0;
} 
//method end

//method start
void trim(char* s, int n){
	int i;
	int start=0;
	for(i=0;i<n;++i){
		if(s[i]==' '||s[i]=='\t'||s[i]=='\n'||s[i]=='\r'){
			start=i;
		} else {
			break;
		}
	}
	if(i==n-1){
		s="";
	}
	int end;
	for(i=n-1;i>=start;--i){
		if(s[i]==' '||s[i]=='\t'||s[i]=='\n'||s[i]=='\r'){
			end=i;
		} else {
			break;
		}
	}
	strncpy(s,s+start,end-start);
}
//method end

//method start
int main(){
	FILE* file = fopen("program4.c","rt");

	char line[201];

	int total_count=0;
	int method_count=0;
	int object_count=0;

	//make a very poor assumption that there are a max of 200 methods and objects
	int methods[200];
	int objects[200];
	int i;
	for(i=0;i<200;++i){
		methods[i]=objects[i]=0;
	}

	int in_method=0;
	int in_object=0;

	while(fgets(line,200,file)!=NULL){
		total_count++;
		//this is a hack, but it takes similar effor to the correct solution
		//particularly if Java were used, the reflection libraries would be available and would make this a trivial task (i suspect the subjects were using java based on the language used in the article, but the language is not specified (another mistake)
		if(strncmp(line,"//method start",200)==0 && !in_method){
			method_count++;
			in_method=1;
		} else if(strncmp(line,"//method end",200)==0 && in_method){
			in_method=0;
		} else if(strncmp(line,"//object start",200)==0 && !in_object){
			object_count++;
			in_object=1;
		} else if(strncmp(line,"//object end", 200)==0 && in_object) {
			in_object=0;
		} else {
			if(in_method){
				//increment this method's line count
				methods[method_count]++;
			}
			if(in_object){
				//increment this object's line count
				objects[object_count-1]++;
			}
		}
	}
	printf("The program consists of %d lines of code consisting of\n",total_count);
	printf("\t%d objects\n",object_count);
	for(i=0;i<object_count;++i){
		printf("\t\tThe %dth object has %d lines\n",i,objects[i]);
	}
	printf("\t%d methods\n",method_count);
	for(i=0;i<method_count;++i){
		printf("\t\tThe %dth method has %d lines\n",i,methods[i]);
	}
	return 0;
}
//method end
