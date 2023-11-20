#include <stdio.h>
#include <stdlib.h>
#include "magazin.h"
#include <string.h>

void write(struct stroika *arr, int n){
if(n<=0)
return;
FILE * f = fopen("s.txt", "w");
if(!f)
return;
fprintf(f, "%d\n", n);
for(int i = 0; i<n; i++)
fprintf(f, "%s %s %s %d\n", arr[i].name, arr[i].color, arr[i].whomade, arr[i].price);
fclose(f);
}
void read(struct stroika **arr, int *n){
FILE *f = fopen("j.txt", "r");
if(!f)
return;
if(fscanf(f, "%d", n) != 1)
return;
if(*n<=0)
return;
*arr = (struct stroika*)calloc(*n, sizeof(struct stroika));
for (int i = 0; i<*n; i++)
fscanf(f, "%s %s %s %d", (*arr)[i].name, (*arr)[i].color, (*arr)[i].whomade, &(*arr)[i].price);
fclose(f);
}
void create(struct stroika **arr, int *n){
printf("n=");
scanf("%d", n);
if(*n <= 0)
return;
*arr = (struct stroika*)calloc(*n, sizeof(struct stroika));
for(int i = 0; i < *n; i++){
printf("Название стройматериала: ");
scanf("%s", (*arr)[i].name);
printf("Цвет: ");
scanf("%s", (*arr)[i].color);
printf("Производитель: ");
scanf("%s", (*arr)[i].whomade);
printf("Цена за 1 кг в рублях: ");
scanf("%d", &(*arr)[i].price);
}
}
void find(struct stroika *arr, int n){
FILE *f = fopen("j.txt", "r");
if(!f)
return;
char search[40];
printf("Введите название стройматериала: ");
scanf("%s", search);
int found = 0;
for(int i = 0; i <= n; i++){
if(strcmp(arr[i].name, search) == 0){
printf("%s %s %s %d\n", arr[i].name, arr[i].color, arr[i].whomade, arr[i].price);
found = 1;
}
}
if(!found)
printf("Стройматериал не найден\n");
fclose(f);
}
