#include "manager.h"
#include "product.h"
int main(void){
    Product s[100];
    int count = 0, index=0,menu;
    FILE* fp;
    fp = fopen("product.txt","r");
    if(fp != NULL){
        count = loadData(s,fp);
        index = count;
    }
    else{
        printf("=>파일 없음\n");
    }
    while (1){
#ifdef DEBUG
	printf("\n[DEGUG] left space of array : %d\n",100-count);	
#endif 
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
                listProduct(s,index);
        }
        else if (menu == 2){
                count += addProduct(&s[index++]);
                printf("=>추가됨!\n");
        }
        else if (menu == 3){
            int no = selectDataNo(s,index);
            if(no == 0){
                printf("=>취소됨!\n");
            }
            else{
                if(updateProduct(&s[no-1])){
                    printf("=>수정됨!\n");
                }
            }
        }
        else if (menu == 4){
            int no = selectDataNo(s,index);
            if(no == 0){
                printf("=>취소됨!\n");
            }
            else{
                int del;
                printf("정말로 삭제하시겠습니까?(삭제 :1) ");
                scanf("%d",&del);
                if(del == 1){
                    if(deleteProduct(&s[no-1])){
                        printf("=>삭제됨!\n");
                        count--;
                    }
                }

            }
        }
	else if(menu == 5){
		saveData(s,index);
	}
	else if(menu == 6){
	    int select;
	    printf("1번: 이름\n");
	    printf("2번: 가격\n");
	    printf("3번: 배송법\n");
	    printf("4번: 설명\n");
	    printf("검색 옵션을 선택하세요 => ");
	    scanf("%d",&select);
	    getchar();
	    if(select == 1){ 
            	char nm[20];
            	printf("검색할 이름? ");
            	fgets(nm,20,stdin);
	    	nm[strlen(nm)-1]='\0';
            	findname(s,nm,index);
	    }
	    else if(select == 2){
           	int pri;
            	printf("검색할 가격? ");
	   	scanf("%d",&pri);
            	findprice(s,pri,index);
	    }
	    else if(select == 3){
            	int deli;
            	printf("검색할 배송법? ");
	    	scanf("%d",&deli);
            	finddelivery(s,deli,index);
	    }
	    else if(select == 4){
            	char expl[100];
            	printf("검색할 설명? ");
            	fgets(expl,100,stdin);
	    	expl[strlen(expl)-1]='\0';
            	findexplain(s,expl,index);
	    }
        }
    }
    printf("종료됨!\n");
    return 0;
}
