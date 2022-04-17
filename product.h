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
void findProduct(Product *s[], char *nm, int count); // 특정 product 검색 함수, count는 지금껏 더해졌던 product 개수, nm은 검색할 product 이름 string
int updateProduct(Product *s); // 특정 roduct 정보 update 하는 함수
int deleteProduct(Product *s); // 특정 product delete 하는 함수
int loadData(Product *s[]); // 파일로 부터 product 정보들 불러오기
void saveData(Product *s[], int count); // 파일에 현재 product 정보들 저장, count는 지금껏 더해졌던 product 개수
int selectMenu();

