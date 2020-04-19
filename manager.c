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
