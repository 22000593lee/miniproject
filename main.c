#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

int main(void){
	Product list[100];
    	int index = 0;
    	int count = 0, menu;

    	count = loadData(list);
    	index = count;
 
    	while (1){
		#ifdef DEBUG
            		printf("\n[Debug] 상품개수 : %d개\n", count);
        	#endif
        	menu = selectMenu();
        	if (menu == 0) break;
        	if (menu == 1){
        	    if(count > 0) {
        	        listProduct(list, index);
        	    }
        	}
		else if (menu == 2){
        	    	count += createProduct(&list[index++]);
			#ifdef DEBUG
				printf("\n[Debug]\n제품명 : %s\n설명 : %s\n중량 : %s\n원산지 : %s\n가격 : %d\n배송방법 : %d\n", list[index-1].name, list[index-1].explain, list[index-1].weight, list[index-1].origin, list[index-1].price, list[index-1].d_type);
			#endif
        	}
        	else if (menu == 3){
			int no = selectDataNo(list, index);
			if(no == 0){
                		printf("=> 취소됨!\n");
                		continue;
            		}
            		updateProduct(&list[no-1]);
			#ifdef DEBUG
                		printf("\n[Debug]\n제품명 : %s\n설명 : %s\n중량 : %s\n원산지 : %s\n가격 : %d\n배송방법 : %d\n", list[no-1].name, list[no-1].explain, list[no-1].weight, list[no-1].origin, list[no-1].price, list[no-1].d_type);
            		#endif
        	}
        	else if (menu == 4){
            		int no = selectDataNo(list, index);
            		if(no == 0){
                		printf("=> 취소됨!\n");
                		continue;
            		}
            		int deleteok;
            		printf("정말로 삭제하시겠습니까?(삭제 : 1)");
            		scanf("%d", &deleteok);
            		if(deleteok == 1) {
                		if(deleteProduct(&list[no-1])) {
                    			count--;
                    			printf("=> 삭제됨!\n");
                		}
            		}
        	}
        	else if (menu == 5){
            		saveData(list, index);
        	}
        	else if (menu == 6){
            		searchProduct(list, index);
        	}
    	}
    	printf("종료됨!\n");
    	return 0;
}
