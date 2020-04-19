#include "product.h"
int createProduct(product *p[],int count){
   getchar();
   printf("과자의 이름은?");
   fgets(p[count]->name,sizeof(p[count]->name),stdin);
   printf("과자의 무게는?");
   scanf("%d",&p[count]->weight);
   printf("과자의 가격은?");
   scanf("%d",&p[count]->price);
   printf("과자의 표준 가격은?");
   scanf("%d",&p[count]->stprice);
   printf("과자의 별점은?");
   scanf("%d",&p[count]->review);
   printf("추가됨!!!\n");
   return 1;

}
void readProduct(product *p){
    printf("   %d %d %d %d %s",p->weight,p->price,p->stprice,p->review,p->name);
}
void deleteProduct(product *p[],int count){
    printf("\n");
    int check,del;
    printf("삭제할 과자는?");
    scanf("%d",&del);
    del--;
    printf("정말로 삭제하시겠습니까?(1:삭제한다. 0:아니요)\n");
    scanf("%d",&check);
    if(check==0){
        printf("취소됨!\n");
    }
    else if(check==1){
        p[del]->price=-1;
        printf("삭제됨!!\n");
    }
}
void updateProduct(product *p[],int count){
    printf("\n");
    int upd;
    printf("수정할 과자를 골라주세요.");
    scanf("%d",&upd);
    upd--;
    createProduct(p,upd);
    printf("수정완료!!\n");
}

/*void listProduct(product *p[],int count){
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
}*/
