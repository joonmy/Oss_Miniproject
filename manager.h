#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef CALC_DATA_H    // CALC_DATA_H가 정의되어 있으면
#define CALC_DATA_H
typedef struct{
    char pname[40];
    char explain[100];
    char weight[30];
    int price;
    int delivery;
}Product;
#endif
void findname(Product *s, char *nm , int count);
void readProduct(Product s);
void listProduct(Product *s, int count);
int selectDataNo(Product *s, int count);
