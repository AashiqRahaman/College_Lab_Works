%{
#include<stdio.h>
%}
%option noyywrap
extern yyval

Keywords    ((i|I)(f|F)|(f|F)(o|O)(r|R)|(w|W)(h|H)(i|I)(l|L)(e|E))
Identifier  [A-Za-z][_A-Za-z0-9]*  
Integer     [0-9]+

%%
{Keywords}                  {printf("keyword:%s\n",yytext);}
{Identifier}                {printf("identifier:%s\n",yytext);}
"+"|"-"                     {printf("operator:%s",yytext);}
"++"|"--"|">="|"<="         {printf("relational operator%s\n",yytext);}
			  
[\t]                        ;//ignore the white space
{Integer}		    { printf("integer:%s",yytext); }

%%

int main(int argc,char *argv[]){

 if(argc>1){
 

   yyin=fopen(argv[1],"r");
   if(!yyin){
    fprintf(stderr,"Error message:%s",argv[0]);
    return 1;

  }
}
  yylex();
   
  if(yyin)
   
   fclose(yyin);
return 0;


}

