#include <stdio.h>
#include <string.h>
#ifndef CALC_DATA_H 
#define CALC_DATA_H 

typedef struct{
	char pname[40];
	char explain[100];
	char weight[30];
	int price;
	int delivery;
}Product;
#endif 
int addProduct(Product *s); //product를 creat하는 함수
int updateProduct(Product *s); // 특정 roduct 정보 update 하는 함수
int deleteProduct(Product *s); // 특정 product delete 하는 함수
int selectMenu();

