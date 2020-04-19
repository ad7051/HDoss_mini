#include"product.h"


void listProduct(product *p[],int count);//전체 과자 메뉴를 출력한다. 0부터 count-1까지 출력한다.
void saveProduct(product *p[],int count);//기존까지 나온 모든 과자의 리스트를 저장한다.
int loadProduct(product *p[]);//txt파일로 이미 저장되어있는 파일을 읽어오고, 이때 읽어온 정보의 양을 메인함수의 count로 넘겨서 메인함수가 이 함수들에 누적으로 작동하게 한다.
void searchProduct(product *p[],int count);// 검색하는 함수로 정확히는 다른 검색 함수로 이어지게하는 연결 함수이다. 또 검색후 반환값이 0일시 결과없음을 출력한다.
int sname(product*p[],int count);//검색할 이름을 묻고 검색후 일치하면 이를 출력하며 없을시 0을 반환한다.
int sweight(product*p[],int count);//검색할 무게를 묻고 검색후 일치하면 이를 출력하며 없을시 0을 반환한다.
int sprice(product*p[],int count);//검색할 가격을 묻고 검색후 일치하면 이를 출력하며 없을시 0을 반환한다.
