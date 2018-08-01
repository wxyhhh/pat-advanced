#include <stdlib.h>
#include <stdio.h>

int main()
{
  int a, b;
  int sum = 0;
  int i, count;
  int factor = 10;
  char formatResult[100];
  int position = 0;
  
  scanf("%d%d", &a, &b);
  sum = a+b;
  
  if(sum<0){
    formatResult[position] = '-';
    position++;
    sum = -sum;
  }
  
  else if (sum == 0){
  	formatResult[position] = '0';
  }
  
  for(i=1;sum/factor!=0;i++){
    factor *= 10;
  }
  count = i;
  
  int comma_mark_counter = 0;
  for(i=position+count+(count-1)/3-1; sum != 0; i--){
    formatResult[i] = '0'+ sum % 10;
    sum = sum/10;
    comma_mark_counter += 1;
    
    if(comma_mark_counter == 3 && sum != 0){
      comma_mark_counter = 0;
      i--;
      formatResult[i] = ',';
    }
  }
  
  formatResult[position+count+(count-1)/3] = 0;
  
  printf("%s", formatResult);
  
  return 0;
  
  
}
