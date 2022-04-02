#include "item.h"

#define N 10

void input_array(Item a[], int n);
void output_array(Item a[], int n);
void selection_sort(Item a[], int n);
void insert_array(Item a[], int *n, Item el, int pos);
void delete_element(Item a[], int *n, int pos);
void insert_sorted_array(Item a[], int *n, Item el);
void insertion_sort(Item a[],int n);
void bubble_sort(Item a[], int n);
void adaptive_bubble_sort(Item a[], int n);
int search_element(int a[], int n, int el);
int search_sorted_array(int a[], int n, int el);// <3
int binary_search(int a[], int n, int el);
int compare_arrays(int a [], int b [],int  n1, int n2);
int input_array_str(int *arr,char* line);
void i_sum(int a[], int b[], int n1, int n2);
int i_prod(int a[], int b[], int n1, int n2);
int tot_array(int a[], int n);
int *array_str_dyn(int *n, char *line);
