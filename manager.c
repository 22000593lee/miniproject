#include <stdio.h>
#include <string.h>
#include "product.h"
#include "manager.h"

void listProduct(Product *p, int count) {
    printf("\n================================\n");
    for(int i=0 ; i<count ; i++) {
        if(p[i].price == -1) continue;
        printf("(%d)\n", i+1);
        readProduct(p[i]);
        printf("================================\n");
    }
}

int selectDataNo(Product *p, int count) {
    int no;
    listProduct(p, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

int loadData(Product *p) {
    int i = 0;
    FILE *fp;
    char line[100];
    if((fp = fopen("product.txt", "rt")) == NULL) {
        printf("\n=> 파일 없음\n");
        return 0;
    };
    for(i=0 ; i<100 ; i++){
        if(feof(fp)) break;
        fgets(line, 100, fp);
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d %d", p[i].origin, p[i].name, p[i].explain, p[i].weight, &p[i].price, &p[i].d_type);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");
    return i;
}

void saveData(Product *p, int count) {
    FILE *fp;
    fp = fopen("product.txt", "wt");
    for(int i=0 ; i<count-1 ; i++) {
        if(p[i].price == -1) continue;
        fprintf(fp, "%s,%s,%s,%s,%d %d\n", p[i].origin, p[i].name, p[i].explain, p[i].weight, p[i].price, p[i].d_type);
    }
    fprintf(fp, "%s,%s,%s,%s,%d %d", p[count-1].origin, p[count-1].name, p[count-1].explain, p[count-1].weight, p[count-1].price, p[count-1].d_type);
    fclose(fp);
    printf("=> 저장됨!\n");
}

void searchProduct(Product *p, int count) {
    int scnt = 0;
    char search[20];

    printf("검색할 이름? ");
    getchar();
    scanf("%[^\n]s", search);

    printf("\n================================\n");
    for(int i=0 ; i<count ; i++) {
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)) {
            printf("(%d)", i+1);
            readProduct(p[i]);
            scnt++;
            printf("================================\n");
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchDelivery(Product *p, int count) {
    int scnt = 0;
    int type;

    printf("검색할 배송유형? ");
    scanf("%d", &type);

    printf("\n================================\n");
    for(int i=0 ; i<count ; i++) {
        if(p[i].price == -1) continue;
        if(type == p[i].d_type) {
            printf("(%d)", i+1);
            readProduct(p[i]);
            scnt++;
            printf("================================\n");
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchPrice(Product *p, int count) {
    int scnt = 0;
    int max;
    int min;

    printf("최대 가격은? ");
    scanf("%d", &max);
    printf("최소 가격은? ");
    scanf("%d", &min);

    printf("\n================================\n");
    for(int i=0 ; i<count ; i++) {
        if(p[i].price == -1) continue;
        if(p[i].price >= min && p[i].price <= max) {
            printf("(%d)", i+1);
            readProduct(p[i]);
            scnt++;
            printf("================================\n");
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
