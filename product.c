#include <stdio.h>
#include <string.h>
#include "product.h"

int selectMenu(){
    	int menu;
    	printf("\n*******\n");
    	printf("1. 조회\n");
    	printf("2. 추가\n");
	printf("3. 수정\n");
    	printf("4. 삭제\n");
    	printf("5. 저장\n");
    	printf("6. 검색\n");
    	printf("0. 종료\n");
    	printf("*******\n\n");
    	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	return menu;
}

int createProduct(Product *p) {
    	printf("제품 이름은? ");
    	getchar();
    	scanf("%[^\n]s", p->name);
    	printf("제품 설명은? ");
    	getchar();
    	scanf("%[^\n]s", p->explain);
    	printf("제품 중량은? ");
    	scanf("%s", p->weight);
    	printf("제품 원산지는? ");
    	scanf("%s", p->origin);
    	printf("제품 가격은? ");
    	scanf("%d", &p->price);
   	printf("배송 방법은? ");
    	scanf("%d", &p->d_type);
    	return 1;
}

void readProduct(Product p) {
    	printf("\n[%s] %s %s\n설명 : %s\n가격 : %d원\n배송 : ", p.origin, p.name, p.weight, p.explain, p.price);
    	if(p.d_type == 1) printf("새벽배송");
    	else if(p.d_type == 2) printf("택배배송");
    	printf("\n");
}

int updateProduct(Product *p) {
    	printf("제품 이름은? ");
    	getchar();
    	scanf("%[^\n]s", p->name);
    	printf("제품 설명은? ");
    	getchar();
    	scanf("%[^\n]s", p->explain);
    	printf("제품 중량은? ");
    	scanf("%s", p->weight);
    	printf("제품 원산지는? ");
    	scanf("%s", p->origin);
    	printf("제품 가격은? ");
    	scanf("%d", &p->price);
    	printf("배송 방법은? ");
    	scanf("%d", &p->d_type);
    	return 1;
}

int deleteProduct(Product *p) {
    	p->price = -1;
    	p->d_type = -1;
    	return 1;
}
