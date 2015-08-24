#include <stdio.h>
#include <string.h>
 
int main () {
  char password[]="pass!";
  char input[16+1];
  
  printf("Chall easy for Radare dissection\n");
  scanf("%16s", &input);
  if (strcmp(password,input)==0) {
    printf("You Win\n");
  } else {
    printf("You Failed\n");
  }
        return(0);
}
