#include "manager.h"
int loadData(Product *s, FILE * fp){
	int i=0;
	while(!feof(fp)){
		fgets(s[i].pname,40,fp);
		s[i].pname[strlen(s[i].pname)-1] = '\0';
		fgets(s[i].explain,100,fp);
		s[i].explain[strlen(s[i].explain)-1] = '\0';
		fscanf(fp,"%s %d %d",s[i].weight,&s[i].price,&s[i].delivery);
		fgetc(fp);
		i++;
	}
	fclose(fp);
	printf("=>로딩 성공\n");
	return i;
}

void saveData(Product *s, int count){
	FILE * fp;
	fp = fopen("product.txt","w");
	for(int i=0; i<count; i++){
		if(s[i].price > 0){
			if(i != count -1){
				fprintf(fp,"%s\n",s[i].pname);
				fprintf(fp,"%s\n",s[i].explain);
				fprintf(fp,"%s %d %d\n",s[i].weight,s[i].price,s[i].delivery);
			}
			else{
				fprintf(fp,"%s\n",s[i].pname);
				fprintf(fp,"%s\n",s[i].explain);
				fprintf(fp,"%s %d %d",s[i].weight,s[i].price,s[i].delivery);
			}
		}
	}
	fclose(fp);
	printf("=>저장됨!\n");
}

void selectSearchMenu(Product *s, int index){
	while(1){
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
			break;
		}
		else if(select == 2){
			int pri;
			printf("검색할 가격? ");
			scanf("%d",&pri);
			findprice(s,pri,index);
			break;
		}
		else if(select == 3){
			int deli;
			printf("검색할 배송법? ");
			scanf("%d",&deli);
			finddelivery(s,deli,index);
			break;
		}
		else if(select == 4){
			char expl[100];
			printf("검색할 설명? ");
			fgets(expl,100,stdin);
			expl[strlen(expl)-1]='\0';
			findexplain(s,expl,index);
			break;
		}
		else{
			printf("다른 옵션을 선택해 주세요\n\n");
		}
	}
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
void findexplain(Product *s, char *explain , int count){
	int cnt=0;
	printf("이름 설명  무게  가격  배달방법\n");
	printf("=========================\n");
	for(int i=0; i<count; i++){
		if((s[i].price > 0) && (strstr(s[i].explain,explain) != NULL)){
			printf("%2d ",i+1);
			readProduct(s[i]);
			cnt++;
		}
	}
	printf("총 %d개의 주문이 있습니다.\n",cnt);
}

void findprice(Product *s, int price , int count){
	int cnt=0;
	printf("이름 설명  무게  가격  배달방법\n");
	printf("=========================\n");
	for(int i=0; i<count; i++){
		if((s[i].price > 0) && (s[i].price == price)){
			printf("%2d ",i+1);
			readProduct(s[i]);
			cnt++;
		}
	}
	printf("총 %d개의 주문이 있습니다.\n",cnt);

}
void finddelivery(Product *s, int deli , int count){
	int cnt=0;
	printf("이름 설명  무게  가격  배달방법\n");
	printf("=========================\n");
	for(int i=0; i<count; i++){
		if((s[i].price > 0) && (s[i].delivery == deli)){
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
