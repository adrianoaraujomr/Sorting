#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#include "mergeSQ.h"

int classification(char *clss,int sz){

	int i;
	int count = 0;
	if(sz == 1 && isdigit(clss[0])) return 1;
 
	for(i = 0;i < sz - 1;i++){
		if(isdigit(clss[i])){
			if(clss[i] != '1' && clss[i] != '0') count++;
			if(!isdigit(clss[i+1])) return 4;
		} else {
			return 2;
		}
	}
	if(count > 0) return 1;
	return 3;
}

int main (int argc, char *argv[]){

	int i = 0;
	int j = 0;
	int d = 3;
	char clss[400];
	char key[6];
	char *ptr;	
	FILE *fd;
	struct eInteger *vec1;
	struct eString *vec2;
	struct eBitDna *vec3;
	struct eDouble *vec4;
	struct timeval first,final;

	fd = fopen(argv[1],"r");
	if(fd == NULL) exit(1);

	fgets(clss,sizeof(clss),fd);

	int k;
	k = strlen(clss);
	clss[--k] = '\0';
	while(clss[k] != 'v') k--;
	strcpy(key,clss + k);
	k = k - 1;
	while(isspace(clss[k])) k--;
	clss[k+1] = '\0';

	d = classification(clss,strlen(clss));
	printf("classification (%d)\n",d);

	if(strlen(clss) == 1) {
		d = 1;
	}

	switch(d){

		case 1 : //Looks like it's working
			vec1 = (struct eInteger *) malloc(sizeof(struct eInteger)*1000);
			vec1[0].data = atoi(clss);
			strcpy(vec1[0].key,key);
			i = 1;
			while(fgets(clss,sizeof(clss),fd) != NULL){ 

				int k;
				k = strlen(clss);
				clss[--k] = '\0';
				while(clss[k] != 'v') k--;
				strcpy(key,clss + k);
				k = k - 1;
				while(isspace(clss[k])) k--;
				clss[k+1] = '\0';		

				vec1[i].data = atoi(clss);
				strcpy(vec1[i].key,key);

				i++;
				if((i % 1000) == 0) vec1 = realloc(vec1,sizeof(struct eInteger)*(i + 10000));
			}
			gettimeofday(&first, NULL);
			IntMergeSQ(vec1,0,i-1);
			gettimeofday(&final, NULL);
			for(j = 0;j < i;j ++) printf( "%d (%s)\n",vec1[j].data,vec1[j].key);
			printf("Execução ordenação : %lu\n",final.tv_usec - first.tv_usec);
			break;
		
		case 2 : //Looks like its working
			vec2 = (struct eString *) malloc(sizeof(struct eString)*1000);
			strcpy(vec2[0].data,clss);
			strcpy(vec2[0].key,key);
			i = 1;
			while(fgets(vec2[i].data,sizeof(vec2[i].data),fd) != NULL){ 
				i++;
				if((i % 1000) == 0) vec2 = realloc(vec2,sizeof(struct eString)*(i + 10000));
			}
			for(j = 1;j < i;j++){
				int k;
				k = strlen(vec2[j].data);
				vec2[j].data[--k] = '\0';
				while(vec2[j].data[k] != 'v') k--;
				strcpy(vec2[j].key,vec2[j].data + k);
				k = k - 1;
				while(isspace(vec2[j].data[k])) k--;
				vec2[j].data[k+1] = '\0';				
			}
			gettimeofday(&first, NULL);
			StrMergeSQ(vec2,0,i-1);
			gettimeofday(&final, NULL);
			for(j = 0;j < i;j ++) printf( "%s (%s)\n",vec2[j].data,vec2[j].key);
			printf("Execução ordenação : %lu\n",final.tv_usec - first.tv_usec);
			break;

		case 3 :// Look like it's working
			vec3 = (struct eBitDna *) malloc(sizeof(struct eBitDna)*1000);
			strcpy(vec3[0].data,clss);
			strcpy(vec3[0].key,key);
			vec3[0].size = strlen(clss);
			i = 1;
			while(fgets(vec3[i].data,sizeof(vec3[i].data),fd) != NULL){ 
				i++;
				if((i % 1000) == 0) vec3 = realloc(vec3,sizeof(struct eBitDna)*(i + 10000));
			}
			for(j = 1;j < i;j++){

				int k;
				k = strlen(vec3[j].data);
				vec3[j].data[--k] = '\0';
				while(vec3[j].data[k] != 'v') k--;
				strcpy(vec3[j].key,vec3[j].data + k);
				k = k - 1;
				while(isspace(vec3[j].data[k])) k--;
				vec3[j].data[k+1] = '\0';
				vec3[j].size = strlen(vec3[j].data);
				k = 0;
//				while(vec3[j].data[k++] == '0') vec3[j].size--;
				
			}
			gettimeofday(&first, NULL);
			BnaMergeSQ(vec3,0,i-1);
			gettimeofday(&final, NULL);
			for(j = 0;j < i;j ++) printf( "%s (%s)\n",vec3[j].data,vec3[j].key);
			printf("Execução ordenação : %lu\n",final.tv_usec - first.tv_usec); 
			break;

		case 4 :// Look like it's working

			vec4 = (struct eDouble *) malloc(sizeof(struct eDouble)*1000);
			for(j = 0;j < strlen(clss);j++){
				if(!isdigit(clss[j])) {
					clss[j] = '\0';
					break;
				}
			}
			vec4[0].dec = strtol(clss, &ptr, 10);
			strcpy(vec4[0].flt,clss+j+1);
			strcpy(vec4[0].key,key);

			i = 1;
			while(fgets(clss,sizeof(clss),fd) != NULL){ 

				int k;
				k = strlen(clss);
				clss[--k] = '\0';
				while(clss[k] != 'v') k--;
				strcpy(key,clss + k);
				k = k - 1;
				while(isspace(clss[k])) k--;
				clss[k+1] = '\0';		

				for(j = 0;j < strlen(clss);j++){
					if(!isdigit(clss[j])) {
						clss[j] = '\0';
						break;
					}
				}
				vec4[i].dec = strtol(clss, &ptr, 10);
				strcpy(vec4[i].flt,clss+j+1);
				strcpy(vec4[i].key,key);
	
				i++;
				if((i % 1000) == 0) vec4 = realloc(vec4,sizeof(struct eDouble)*(i + 10000));
			}
			gettimeofday(&first, NULL);
			DblMergeSQ(vec4,0,i-1);
			gettimeofday(&final, NULL);
			for(j = 0;j < i;j ++) printf( "%ld.%s (%s)\n",vec4[j].dec,vec4[j].flt,vec4[j].key);
			printf("Execução ordenação : %lu\n",final.tv_usec - first.tv_usec);
			break;
	}
}
