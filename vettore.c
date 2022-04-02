#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void input_array(Item a[], int n){
	int i;
	for(i=0;i<n;i++)
		a[i] = inputItem();
}

void output_array(Item a[], int n) {
	int i;
	for(i=0;i<n;i++) 
		outputItem(a[i]);
}

int min(Item a[],int n) {
	int min=0;
	int i;
	for(i=1;i<n;i++) 
		if(compItem(a[min], a[i]) > 0)
			min=i;
	return min;
}

void selection_sort(Item a[], int n) {
	int i, m;
	for(i=0;i<n;i++) {
		m=min(a+i, n-i);
		swap(&a[i], &a[m+i]);
	}
}

void bubble_sort(Item a[], int n){
	int i,j;
	
	for(i = 1; i < n; i++) 
		for(j = 0; j < n - i; j++) 
			if(compItem(a[j],a[j+1]) > 0)
				swap(&a[j],&a[j+1]);
}

void adaptive_bubble_sort(Item a[], int n){
	int i,j,ordinato = 0;
	
	for(i = 1; i < n && !ordinato; i++) {
		ordinato = 1;
		for(j = 0; j < n - i; j++) 
			if(compItem(a[j],a[j+1]) > 0) {
				swap(&a[j],&a[j+1]);
				ordinato = 0;
		}
	}
}

void insert_array(Item a[], int *n, Item el, int pos){
	int i;
	if(pos<0||pos>*n)
		return;
	for(i=*n;i>pos;i--)
		a[i]=a[i-1];
	a[pos]=el;
	++*n;
}


void delete_element(Item a[], int *n, int pos) {
	int i;
	for (i=pos; i<*n-1; i++) 
		a[i]=a[i+1];		
	--*n;
}

void insert_sorted_array(Item a[], int *n, Item el){
	int i;
	
	for(i=*n;i>0 && a[i-1]>el;i--)
		a[i]=a[i-1];
	a[i]=el;
	++*n;
}

void insertion_sort(Item a[],int n){
	int i=1;
	while(i<n)
		insert_sorted_array(a,&i,a[i]);
}

int search_element(int a[], int n, int el){
	int i;
	for (i=0; i<n; i++)
		if (a[i]==el)
			return i;
	return -1;	
}

int search_sorted_array(int a[], int n, int el){
	int i;
	// <3
	for(i=0;i<n && el>a[i];i++);
	return ((el==a[i])?i:-1);
}

int binary_search(int a[], int n, int el) {
	int begin=0, end=n-1, center;
	while(begin<=end){
		center=(begin+end)/2;
		if (a[center]==el)
			return center;
		else if (el<a[center])
			end=center-1;
		else
			begin=center+1;
	}
	return -1;	
}

int compare_arrays(int a [], int b [],int  n1, int n2){
		int i;
		if(n1!=n2)
			return 0;
		for(i=0; i<n1 ;i++)
			if(a[i]!= b[i])
				return 0;
		return 1;
}

int input_array_str(int *arr,char *line){
	int i=0,n=0;
	while(sscanf(line,"%d%n",&arr[i],&n)==1){
		line+=n;
		i++;
	}	
	return i;
}

void i_sum(int a[], int b[], int n1, int n2) {
	int i;

	if(n1 != n2)
		return;

	for(i = 0; i < n1; i++)
		a[i] = a[i] + b[i];
}

int tot_array(int a[], int n) {
	int i, tot = 0;
	
	for(i = 0; i < n; i++)
		tot += *(a+i);

	return tot;
}

int i_prod(int a[], int b[], int n1, int n2) {
	int i, prod = 0;

	if(n1 != n2)
		return 0;

	for(i = 0; i < n1; i++)
		prod += a[i] * b[i];

	return prod;
}

int *array_str_dyn(int *n, char *line) {
	int *a;

	*n = conta_spazi(line, *n) + 1;

	a = malloc((*n) * sizeof(int));

	if(a == NULL) {
		fprintf(stderr,"Errore assegnamento array\n");
		return NULL;
	}

	input_array_str(a,line);

	return a;
}
