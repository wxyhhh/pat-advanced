#include <stdlib.h>
#include <stdio.h>


int comp(const void*a, const void*b)
{
    return *(int*)b - *(int*)a;
}
int main()
{
    int coupon_num, product_num;
    int coupon[100000];
    int product[100000];
    long long int result = 0;

    scanf("%d", &coupon_num);

    for(int i=0; i<coupon_num; i++)
    {
        scanf("%d", &coupon[i]);
    }

    scanf("%d", &product_num);
    for(int i=0; i<product_num; i++){
        scanf("%d", &product[i]);
    }

    qsort(coupon, coupon_num, sizeof(int), comp);
    qsort(product, product_num, sizeof(int), comp);

    int i=0;
    int j=0;
    for(i=0; coupon[i]>0&&product[i]>0&&i<coupon_num&&i<product_num; i++){
        result += coupon[i] * product[i];
    }

    if(i!=coupon_num && i!=product_num){
        for(i=coupon_num-1, j=product_num-1; i>=0&&j>=0&&coupon[i]<0&&product[j]<0;i--, j--){
            result += coupon[i] * product[j];
        }
    }

    printf("%d", result);

    system("pause");

    return 0;

}