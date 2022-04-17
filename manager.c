#include "manager.h"
void saveData(Product *s, int count){
    FILE * fp;
    fp = fopen("product.txt","w");
    for(int i=0; i<count; i++){
        if(s[i].price > 0){
            if(i != count -1)
                fprintf(fp,"%s %s %s %d %d\n",s[i].pname,s[i].explain,s[i].weight,s[i].price,s[i].delivery);
            else
                fprintf(fp,"%s %s %s %d %d",s[i].pname,s[i].explain,s[i].weight,s[i].price,s[i].delivery);
        }
    }
    fclose(fp);
    printf("=>저장됨!\n");
}

void findname(Product *s, char *nm , int count){
    int cnt=0;
    printf("이름 설명  무게  가격  배달방법\n");
    printf("=========================\n");
    for(int i=0; i<count; i++){
        if((s[i].price > 0) && (strstr(s[i].pname,nm) != NULL)){
            printf("%2d ",i+1);
            readProduct(s[i]);
            cnt++;
        }
    }
    printf("총 %d개의 주문이 있습니다.\n",cnt);

}

void readProduct(Product s){
        printf("%5s %15s %4s %4d %5d\n",s.pname,s.explain,s.weight,s.price,s.delivery);
}

void listProduct(Product *s, int count){
        printf("     이름      설명   무게   가격  배달방법\n");
        for(int i=0; i<count; i++){
                if(s[i].price < 0){
#ifdef DEBUG
			printf("   [DEBUG]deleted -> ");
                	readProduct(s[i]);
		       	continue;
#endif
		}
		else{
                	printf("%2d ",i+1);
               		readProduct(s[i]);
		}
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
