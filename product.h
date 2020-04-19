#include <stdio.h>//기본 입출력및 함수를 위해서 포함
#include <stdlib.h>//구조체를 배열 선언 대신 구조체 포인터 배열을 선언해서 사용하기때문에 메모리 할당을 위한 함수인 malloc과 free를 위해 추가.
#include <string.h>//제품 이름을 통한 검색시 문자열 검색을 위해 포함

typedef struct{
char name[100];//과자의 이름을 저장할 변수
int weight;//과자의 무게
int price;//과자의 가격
int stprice;//과자의 표준 가격
int review;//과자의 별점
}product;

int createProduct(product *p[],int count);//count를 가져와서 바로 count 순서의 배열에 새로운 정보를 입력받는다. 또, 메인 함수에 count를 1 증가시킨다.
void readProduct(product *p);//하나의 줄만을 출력하는 출력문으로 배열중 하나의 구조체 포인터를 받아와 출력한다.
void deleteProduct(product *p[],int count);//과자 메뉴를 삭제한다. price멤버를 -1로 변경한다.
void updateProduct(product *p[],int count);//업데이트 여부를 묻고 수정할 배열의 위치를 받아 다시 createProduct의 count로 보네서 수정한다o
//void listProduct(product *p[],int count);//전체 과자 메뉴를 출력한다. 0부터 count-1까지 출력한다
