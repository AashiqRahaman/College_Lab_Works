#include <stdio.h>
#include <stdlib.h>
int main() 
{char source_file[20] = "source.txt";
char target_file[20] = "target.txt";
FILE *source = fopen(source_file, "r");
if (source == NULL) {
printf("Error opening source file.\n");
return 1; }
FILE *target = fopen(target_file, "w");
if (target == NULL) 
{ printf("Error opening target file.\n");
  return 1; }
char ch;
while ((ch = fgetc(source)) != EOF) {
fputc(ch, target);
}
fclose(source);
fclose(target);
printf("Your File is successfully copied.\n");
return 0;
}