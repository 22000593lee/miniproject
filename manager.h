#include <stdio.h>
#include "product.h"

void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
int selectDataNo(Product *p, int count); //선택된 제품의 번호 출력
int loadData(Product *p); // 저장된 제품 리스트 불러오기
void saveData(Product *p, int count); // 제품 리스트 저장
void searchProduct(Product *p, int count); // 제품이름 검색
void searchDelivery(Product *p, int count); //배송유형별 검색- 검색된 배송유형의 제품들 출력
void searchPrice(Product *p, int count); //배송가격별 검색 - 입력된 가격대의 제품들 출력
