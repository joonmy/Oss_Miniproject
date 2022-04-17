#include "product.h"
int addProduct(Product *s){
	printf("상품 이름-> ");
    	fgets(s->pname,40,stdin);
	s->pname[strlen(s->pname)-1]='\0';

    	printf("상품설명 -> ");
    	fgets(s->explain,100,stdin);
	s->explain[strlen(s->explain)-1]='\0';

    	printf("상품 무게 -> ");
    	scanf("%s",s->weight);

    	printf("가격 ->  ");
    	scanf("%d",&s->price);

	printf("배달 방법(1 새벽배송/ 2 택배배송)-> ");
	scanf("%d",&s->delivery);
    	return 1;
}
int updateProduct(Product *s){
	printf("상품 이름-> ");
    	fgets(s->pname,40,stdin);
	s->pname[strlen(s->pname)-1]='\0';

    	printf("상품설명 -> ");
    	fgets(s->explain,100,stdin);
	s->explain[strlen(s->explain)-1]='\0';

    	printf("상품 무게 -> ");
    	scanf("%s",s->weight);

    	printf("가격 ->  ");
    	scanf("%d",&s->price);

	printf("배달 방법(1 새벽배송/ 2 택배배송)-> ");
	scanf("%d",&s->delivery);

	return 1;
	
}
int deleteProduct(Product *s){
	s->price = -1;
	return 1;
}
int selectMenu(){
    	int menu;
    	printf("\n**********\n");
    	printf("1. 상품조회\n");
    	printf("2. 상품추가\n");
    	printf("3. 상품수정\n");
    	printf("4. 상품삭제\n");
    	printf("5. 저장\n");
    	printf("6. 검색\n");
    	printf("0. 종료\n\n");
    	printf("=> 원하는 메뉴를 입력하세요 -> ");
    	scanf("%d", &menu);
    	getchar();
    	return menu;
}

