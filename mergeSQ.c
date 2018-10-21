#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergeSQ.h"

/*Integer----------------------------------------------------------------------------------------------------------------------------------------*/

void IntMerge(EInteger *v,int f,int m,int l){
	int i,j,k;
	int li,lj;
	EInteger  *aux;

	aux = (struct eInteger*) malloc((l - f + 1)*sizeof(struct eInteger));
	if(aux == NULL) exit(1);

	li = m - f; // ate = 
	lj = l - f; // ate =
	j  = 0;

	for(i = f;i <= l;i++) aux[j++] = v[i];
	
	i = 0; j = li + 1; k = f;

	while(i <= li && j <= lj){
		if(aux[i].data <= aux[j].data){
			v[k] = aux[i];
			i++;
		} else {
			v[k] = aux[j];
			j++;
		}
		k++;
	}

	while(i <= li) v[k++] = aux[i++];
	while(j <= lj) v[k++] = aux[j++];
	
	free(aux);
}

void IntMergeSort(EInteger *v,int f,int l){	
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		IntMergeSort(v,f  ,m);
		IntMergeSort(v,m+1,l);

		IntMerge(v,f,m,l);
	}
}

void IntMergeSQ(EInteger *v,int f,int l){
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		IntMergeSQ(v,f  ,m);
		IntMergeSQ(v,m+1,l);

		IntMergeSort(v,f,l);
	}
}

/*String-----------------------------------------------------------------------------------------------------------------------------------------*/

void StrMerge(EString *v,int f,int m,int l){
	int i,j,k;
	int li,lj;
	EString  *aux;

	aux = (struct eString*) malloc((l - f + 1)*sizeof(struct eString));
	if(aux == NULL) exit(1);

	li = m - f; // ate = 
	lj = l - f; // ate =
	j  = 0;

	for(i = f;i <= l;i++) aux[j++] = v[i];
	
	i = 0; j = li + 1; k = f;

	while(i <= li && j <= lj){
		if(strcmp(aux[i].data,aux[j].data) <= 0){
			v[k] = aux[i];
			i++;
		} else {
			v[k] = aux[j];
			j++;
		}
		k++;
	}

	while(i <= li) v[k++] = aux[i++];
	while(j <= lj) v[k++] = aux[j++];
	
	free(aux);
}

void StrMergeSort(EString *v,int f,int l){	
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		StrMergeSort(v,f  ,m);
		StrMergeSort(v,m+1,l);

		StrMerge(v,f,m,l);
	}
}

void StrMergeSQ(EString *v,int f,int l){
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		StrMergeSQ(v,f  ,m);
		StrMergeSQ(v,m+1,l);

		StrMergeSort(v,f,l);

	}
}

/*BinaryDna--------------------------------------------------------------------------------------------------------------------------------------*/

void BnaMerge(EBitDna *v,int f,int m,int l){
	int i,j,k;
	int li,lj;
	EBitDna  *aux;

	aux = (struct eBitDna*) malloc((l - f + 1)*sizeof(struct eBitDna));
	if(aux == NULL) exit(1);

	li = m - f; // ate = 
	lj = l - f; // ate =
	j  = 0;

	for(i = f;i <= l;i++) aux[j++] = v[i];
	
	i = 0; j = li + 1; k = f;

	while(i <= li && j <= lj){
//		if(strlen(aux[i].data) < strlen(aux[j].data)){
		if(aux[i].size < aux[j].size){
			v[k] = aux[i];
			i++;
		} else {
//			if(strlen(aux[i].data) > strlen(aux[j].data)) {
			if(aux[i].size > aux[j].size) {
				v[k] = aux[j];
				j++;
			} else {
				if(strcmp(aux[i].data,aux[j].data) <= 0){
					v[k] = aux[i];
					i++;
				} else {
					v[k] = aux[j];
					j++;
				}		
			}
		}
		k++;
	}

	while(i <= li) v[k++] = aux[i++];
	while(j <= lj) v[k++] = aux[j++];
	
	free(aux);
}

void BnaMergeSort(EBitDna *v,int f,int l){	
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		BnaMergeSort(v,f  ,m);
		BnaMergeSort(v,m+1,l);

		BnaMerge(v,f,m,l);
	}
}

void BnaMergeSQ(EBitDna *v,int f,int l){
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		BnaMergeSQ(v,f  ,m);
		BnaMergeSQ(v,m+1,l);

		BnaMergeSort(v,f,l);
	}
}

/*Double-----------------------------------------------------------------------------------------------------------------------------------------*/

void DblMerge(EDouble *v,int f,int m,int l){
	int i,j,k;
	int li,lj;
	EDouble  *aux;

	aux = (struct eDouble*) malloc((l - f + 1)*sizeof(struct eDouble));
	if(aux == NULL) exit(1);

	li = m - f; // ate = 
	lj = l - f; // ate =
	j  = 0;

	for(i = f;i <= l;i++) aux[j++] = v[i];
	
	i = 0; j = li + 1; k = f;

	while(i <= li && j <= lj){
//		if(strlen(aux[i].data) < strlen(aux[j].data)){
		if(aux[i].dec < aux[j].dec){
			v[k] = aux[i];
			i++;
		} else {
//			if(strlen(aux[i].data) > strlen(aux[j].data)) {
			if(aux[i].dec > aux[j].dec) {
				v[k] = aux[j];
				j++;
			} else {
				if(strcmp(aux[i].flt,aux[j].flt) <= 0){
					v[k] = aux[i];
					i++;
				} else {
					v[k] = aux[j];
					j++;
				}		
			}
		}
		k++;
	}

	while(i <= li) v[k++] = aux[i++];
	while(j <= lj) v[k++] = aux[j++];
	
	free(aux);
}

void DblMergeSort(EDouble *v,int f,int l){	
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		DblMergeSort(v,f  ,m);
		DblMergeSort(v,m+1,l);

		DblMerge(v,f,m,l);
	}
}

void DblMergeSQ(EDouble *v,int f,int l){
	int n;
	if(f < l){
		int m = (l - f)/2 + f;

		DblMergeSQ(v,f  ,m);
		DblMergeSQ(v,m+1,l);

		DblMergeSort(v,f,l);
	}
}
