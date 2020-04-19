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
