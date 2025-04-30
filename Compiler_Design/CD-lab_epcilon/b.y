%{
  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>

 void yyerror(const char *s);

%}

%token IF FOR WHILE
%token ID
%token GE LE
%token "+" "-"
%token NUM

%%
 

%%
int main(int argc,int **argv){

 if(argc<2){
  fprintf(stderr,"Error message:%s",argv[0]);
}
   FILE *file=fopen(argv[1],"r");
   
   yyin=file;
   yyparse();
   fclose(file);
return 0;
}
