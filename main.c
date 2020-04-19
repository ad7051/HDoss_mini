#include "manager.h"

int readmenu(){
int menu;
printf("\n***과자 관리 프로그램***\n");
printf("1. 과자 정보 추가\n");
printf("2. 과자 정보 출력\n");
printf("3. 과자 정보 수정\n");
printf("4. 과자 정보 삭제\n");
printf("5. 과자 정보 저장\n");
printf("6. 과자 정보 검색\n");
printf("0. 종료\n");
printf("\n메뉴 번호를 입력해주세요.");
scanf("%d",&menu);
return menu;
}

int main(){
int savecheck=0;
int size=100;
	#ifdef DEBUG
		printf("[Debug] : main.c : size is %d\n",size);
	#endif

product *p[size];
for(int i=0;i<size;i++){
    p[i]=(product *)malloc(sizeof(product));
}
	#ifdef DEBUG
		printf("[Debug] : main.c : malloc clear!\n");
	#endif
int count=0;
int menu;
count = loadProduct(p);
while(1){
    menu=readmenu();
    if(menu==1){
	if(count>=size){
		printf("더이상 추가할 수 없습니다.\n");
	}else
	#ifdef DEBUG
		printf("[Debug] : product.h : createProduct()\n");
	#endif
        count +=createProduct(p,count);
	savecheck=0;
    }else if(menu==2){	
	#ifdef DEBUG
		printf("[Debug] : product.h : listProduct()\n");
	#endif
        listProduct(p,count);
    }else if(menu==3){
	#ifdef DEBUG
		printf("[Debug] : manager.h : listProduct()\n");
	#endif
	listProduct(p,count);
	#ifdef DEBUG
		printf("[Debug] : product.h : updateProduct()\n");
	#endif
        updateProduct(p,count);
	savecheck=0;
    }else if(menu==4){
	#ifdef DEBUG
		printf("[Debug] : manager.h : listProduct()\n");
	#endif
	listProduct(p,count);
	#ifdef DEBUG
		printf("[Debug] : product.h : deleteProduct()\n");
	#endif
        deleteProduct(p,count);
	savecheck=0;
    }
    else if(menu==5){
	#ifdef DEBUG
		printf("[Debug] : manager.h : saveProduct()\n");
	#endif
        saveProduct(p,count);
	savecheck=1;
	}
   else if(menu==6){
	#ifdef DEBUG
		printf("[Debug] : manager.h : searchProduct()\n");
	#endif
        searchProduct(p,count);
    }
    else if(menu==0){
	if(savecheck==0){
	printf("세이브가안 되어 있습니다. 이대로 종료하시겠습까?(1: 저장 후 종료0: 바로 종료)\n");
	scnaf("%d",savecheck);
	if(savecheck ==1){
		#ifdef DEBUG
			printf("[Debug] : manager.h : saveProduct()\n");
		#endif
	        saveProduct(p,count);
		savecheck=1;
	}else break;
	}
        break;
    }
}
for(int i=0;i<size;i++){
    free(p[i]);
}
	#ifdef DEBUG
		printf("[Debug] : main.c : free is clear()\n");
	#endif
return 0;
}
