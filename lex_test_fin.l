%{
#define MAX_LINE_LENG 256
#define LIST strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%s>\n",t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "symbol_table.cpp"

int linenum = 1;
char buf[MAX_LINE_LENG];
char buf_pointer[MAX_LINE_LENG];
bool Opt_L=true;
bool dou_str=false;
symbol_table* current_table;
int mul_comment=0;

%}
%x sin_COMMENT
%x mul_COMMENT
%x STRING
letter	[A-Za-z]
digs	[0-9]+
int	{digs}
plain_real  {digs}"."{digs}	
expreal	{digs}"."{digs}[Ee][+-]?{digs}
real	{plain_real}|{expreal}
id	{letter}({letter}|{digs})*
%%

"(" {token("token:(");}
")" {token("token:)");}
"]" {token("token:]");}
"[" {token("token:[");}
"." {token("token:.");}
"," {token("token:,");}
":" {token("token::");}
";" {token("token:;");}

"+" {token("token:Op:add");}
"-" {token("token:Op:sub");}
"*" {token("token:Op:mul");}
"/" {token("token:Op:div");}
"mod" {token("token:Op:remainder");}
":=" {token("token:Op:assignment");}

"and" {token("token:Op:and");}
"or" {token("token:Op:or");}
"not" {token("token:Op:not");}

"<" {token("token:Op:<");}
"<=" {token("token:Op:<=");}
">=" {token("token:Op:>=");}
">" {token("token:Op:>");}
"=" {token("token:Op:=");}
"not=" {token("token:Op:!=");}

"%"  {
  BEGIN sin_COMMENT;
} 
<sin_COMMENT>\n {
  printf("%d: %s%s\n", linenum,"%",buf);
	linenum++;
	buf[0] = '\0';
  BEGIN INITIAL;
}
<sin_COMMENT>.  {
  LIST;
}

"{%"  {
  mul_comment=1;
  BEGIN mul_COMMENT;
} 
<mul_COMMENT>"%}"  {
  strcat(buf,"%}");
  BEGIN INITIAL;
}
<mul_COMMENT>\n  {
  if(mul_comment==1)
  {
  printf("%d: %s%s\n", linenum,"{%",buf);
  mul_comment=0;
  }
  else
  {
  printf("%d: %s\n", linenum, buf);
  }
  linenum++;
  buf[0] = '\0';
}
<mul_COMMENT>.  {
  LIST;
}


\"  {dou_str=false;LIST;BEGIN STRING;}
<STRING>[^"]+  {yymore();}
<STRING>\"\"  {dou_str=true;yymore();}
<STRING>\"  {
  char buf_pointer3[MAX_LINE_LENG];
  char buf_pointer2[MAX_LINE_LENG];
  memset(buf_pointer3,0,sizeof(buf_pointer3));
  memset(buf_pointer2,0,sizeof(buf_pointer2));
  if(dou_str)
  {
    strncpy(buf_pointer3,yytext,yyleng-1);
    for(int i=0,j=0;i<strlen(buf_pointer3);i++)
    {
    if(buf_pointer3[i]=='\"'&&buf_pointer3[i+1]=='\"')
      i=i+1;
    buf_pointer2[j]=buf_pointer3[i];
    j++;
    } 
    for(int i=0;i<=strlen(buf_pointer3);i++)
    {
    buf_pointer3[i]='\0';
    } 
  }
  else
  {
  strncpy(buf_pointer2,yytext,yyleng-1);
  }
  tokenString("string",buf_pointer2);
  BEGIN(INITIAL);
}

"array" {token("ARRAY");}
"begin" {token("BEGIN");}
"bool" {token("BOOL");}
"char" {token("CHAR");}
"const" {token("CONST");}
"decreasing" {token("DECREASING");}
"default" {token("DEFAULT");}
"do" {token("DO");}
"else" {token("ELSE");}
"end" {token("END");}
"exit" {token("EXIT");}
"false" {token("FALSE");}
"for" {token("FOR");}
"function" {token("FUNCTION");}
"get" {token("GET");}
"if" {token("IF");}
"int" {token("INT");}
"loop" {token("LOOP");}
"of" {token("OF");}
"put" {token("PUT");}
"procedure" {token("PROCEDURE");}
"real" {token("REAL");}
"result" {token("RESULT");}
"return" {token("RETURN");}
"skip" {token("SKIP");}
"string" {token("STRING");}
"true" {token("TRUE");}
"var" {token("VAR");}
"when" {token("WHEN");}
"then" {token("THEN");}

{int}	{
	sscanf(yytext, "%s", buf_pointer);
	tokenInteger("int",buf_pointer);
	}

{real}	{
	sscanf(yytext, "%s", buf_pointer);
	tokenInteger("real",buf_pointer);
	}

{id} 	{
	sscanf(yytext, "%s", buf_pointer);
  if(current_table->lookup(buf_pointer)==-1)
  {
    current_table->insert(buf_pointer);
  }
  else if(current_table->lookup(buf_pointer)==-2)
  {
    printf("simbol table full.\n");
    exit(-1);
  }
	tokenString("id",buf_pointer);
}

 
\n 	{
	LIST;
	if (Opt_L)
    printf("%d: %s", linenum, buf);
	linenum++;
	buf[0] = '\0';
	}
[ \t]* {LIST;}
. {
  LIST;
  
  printf("%d:%s\n", linenum+1, buf);
  printf("bad character:’%s’\n",yytext);
  exit(-1);
}


%%
int main(int argc,char** argv ){
	if ( argc > 0 )
		yyin = fopen( argv[1], "r" );
	else
		yyin = stdin;

  dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
  strcpy(dummyItem->name,"\0");
  
  symbol_table* main=creat("main_table");
  current_table=STstack.top();
  
	yylex();
  main=dump(main);
	fclose(yyin);
  return 0;
}
