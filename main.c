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
			selectSearchMenu(s,index);
		}
		else{
			printf("그런 메뉴는 없습니다 다시 선택해주세요 \n");
		}
	}
	printf("종료됨!\n");
	return 0;
}
