#include "manager.h"

void listProduct(product *p[],int count){
    int check=0;
    printf("   무게  가격  표준가격 별점 이름\n");
    for(int i=0;i<count;i++){
        if(p[i]->price!=-1){
        printf("%2d %d %4d %3d  %d %s",i+1,p[i]->weight,p[i]->price,p[i]->stprice,p[i]->review,p[i]->name);
        check=1;
        }
    }
    if(check==0){
        printf("\n정보가 없습니다.\n");
    }
}

void saveProduct(product *p[],int count){
    FILE *fp=fopen("product.txt","wt");
    for(int i=0;i<count;i++){
        if(p[i]->price!=-1)
        fprintf(fp,"%d %d %d %d %s",p[i]->weight,p[i]->price,p[i]->stprice,p[i]->review,p[i]->name);
    }
    printf("저장됨!!\n");
}

int loadProduct(product *p[]){
    FILE *fp=fopen("product.txt","rt");
    if(fp==NULL){
        printf("저장된 파일 없음!\n");
        return 0;
    }
    else{
        int i;
        for(i=0;;i++){
            if(feof(fp))break;
            fscanf(fp,"%d %d %d %d",&p[i]->weight,&p[i]->price,&p[i]->stprice,&p[i]->review);
            fgets(p[i]->name,sizeof(p[i]->name),fp);
        }
        printf("불러오기 성공!\n");
        return i-1;
    }
}
void searchProduct(product *p[],int count){
	int check=0;
	int mode;
	printf("원하는 검색방식은? (1.이름 2.무게 3.가격0. 취소)");
	scanf("%d",&mode);
	getchar();
	if(mode==0){
        	printf("취소됨!\n");
	}
	else if(mode==1){
		check = sname(p,count);
	}
	else if (mode ==2){
		check = sweight(p,count);
	}
	else if (mode ==3){
		check = sprice(p,count);
	}
	else{
		printf("잘못된 입력 입니다.\n");
	}
	if(check==0)printf("==>검색 결과 없음\n");
}
int sname(product*p[],int count){
	int check=0;
	char src[20];
	printf("검색할 이름은?");
	scanf("%[^\n]",src);
	printf("   무게  가격  표준가격 별점 이름\n");
	for(int i=0;i<count;i++){
		if(p[i]->price!=-1)
		if(strstr(p[i]->name,src)){
			readProduct(p[i]);	
			check=1;
		}
	}
	return check;	
}
int sweight(product*p[],int count){
	int check=0;
	int sr=0;
	printf("검색할 무게는?");
	scanf("%d",&sr);
	printf("이름 무게 가격 표준가격 별점\n");	
	for(int i=0;i<count;i++){
		if(p[i]->price!=-1)
		if(sr==p[i]->weight){
			readProduct(p[i]);	
			check=1;
		}
	}
	return check;	
}
int sprice(product*p[],int count){
	int check=0;
	int sr=0;
	printf("검색할가격은?");
	scanf("%d",&sr);
	printf("이름 무게 가격 표준가격 별점\n");	
	for(int i=0;i<count;i++){
		if(p[i]->price!=-1)
		if(sr==p[i]->price){
			readProduct(p[i]);	
			check=1;
		}
	}
	return check;	
}
