#ifndef _PRO_H
#define _PRO_H
#include <stdio.h>

typedef struct {
    char name[50]; // 제품명
    char explain[100]; // 설명
    char weight[20]; // 중량
    char origin[10]; // 원산지
    int price; // 가격
    int d_type; // 배송방법
}Product;

int selectMenu(); // 제품 선택
int createProduct(Product *p); // 제품 추가
void readProduct(Product p); // 하나의 제품 출력
int updateProduct(Product *p); // 제품 내용 수정
int deleteProduct(Product *p); // 제품 삭제
void listProduct(Product *p, int count); // 전체 등록된 제품 리스트 출력
int selectDataNo(Product *p, int count); //선택된 제품의 번호 출력
int loadData(Product *p); // 저장된 제품 리스트 불러오기
void saveData(Product *p, int count); // 제품 리스트 저장
void searchProduct(Product *p, int count); // 제품이름 검색

#endif
