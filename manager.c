#include "manager.h"
void readProduct(Product s){
        printf("%5s %4s %4s %4d %5d\n",s.pname,s.explain,s.weight,s.price,s.delivery);
}

void listProduct(Product *s, int count){
        printf("이름 설명  무게  가격  배달방법\n");
        for(int i=0; i<count; i++){
                if(s[i].price < 0){
#ifdef DEBUG
			printf("   [DEBUG]deleted -> ");
                	readProduct(s[i]);
		       	continue;
#endif
		}
                printf("%2d ",i+1);
                readProduct(s[i]);
        }
        printf("\n");
}
int selectDataNo(Product *s, int count){
        int no;
        listProduct(s,count);
        printf("번호는 (취소 :0)? ");
        scanf("%d",&no);
        getchar();
        return no;
}
