#include <stdio.h>
#include <string.h>

int main() {
   char sentence1[100], sentence2[100];
   char *p1, *p2;

   printf("Enter the first sentence: ");
   fgets(sentence1, 100, stdin);

   printf("Enter the second sentence: ");
   fgets(sentence2, 100, stdin);

   p1 = sentence1;
   p2 = sentence2;

   while (*p1 != '\0' && *p2 != '\0') {
      if (*p1 != *p2) {
         printf("The sentences are different.\n");
         return 0;
      }
      p1++;
      p2++;
   }

   if (*p1 != '\0' || *p2 != '\0') {
      printf("The sentences are different.\n");
      return 0;
   }

   printf("The sentences are the same.\n");
   return 0;
}