#include <stdio.h>
#include <string.h>
int main()
{ char sentence1[100];
  char sentence2[100];
  char *ptr1,*ptr2;
  int comp;
  printf("Enter the first sentence: ");
  gets(sentence1);
  printf("Enter the second sentence: ");
  gets(sentence2);
  ptr1=sentence1;
  ptr2=sentence2;
  comp=strcmp(ptr1,ptr2);
  if(strlen(ptr1)==strlen(ptr2))
  {    printf("The statements are Equal");  }
  else if(strlen(ptr1)<=strlen(ptr2))
  {    printf("The second statement is greater than first");  }
  else 
  {    printf("The first statement is greater than second");  }
}