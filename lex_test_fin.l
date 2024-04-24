%{
#include "symbol_table.cpp"
#define MAX_LINE_LENG 256
#define LIST strcat(buf,yytext)
#define token(t) {LIST; }
#define tokenInteger(t,i) {LIST; yylval.type="INT";yylval.v.int_number=atoi(i);return I_NUMBER;}
#define tokenReal(t,i) {LIST; yylval.type="REAL",yylval.v.real_number=atof(i);return R_NUMBER;}
#define tokenString(t,s) {LIST; yylval.type="STRING",strncpy(yylval.v.Str, s, MAX_LINE_LENG);return String;}
#define tokenID(t,s) {LIST; yylval.type="ID",strncpy(yylval.v.Str, s, MAX_LINE_LENG);return ID;}
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"


int linenum = 1;
char buf[MAX_LINE_LENG];
char buf_pointer[MAX_LINE_LENG];
bool Opt_L=true;
bool dou_str=false;
symbol_table* current_table;
int mul_comment=0;
struct DataItem* dummyItem;
struct DataItem* item;
symbol_table* new_table;
stack<symbol_table*> STstack;

%}
%option noyywrap
%x sin_COMMENT
%x mul_COMMENT
%x STR
letter	[A-Za-z]
digs	[0-9]+
int	{digs}
plain_real  {digs}"."{digs}	
expreal	{digs}"."{digs}[Ee][+-]?{digs}
real	{plain_real}|{expreal}
id	{letter}({letter}|{digs})*
%%

"(" {token("(");return '(';}
")" {token(")");return ')';}
"]" {token("]");return ']';}
"[" {token("[");return '[';}
"." {token(".");return '.';}
"," {token(",");return ',';}
":" {token(":");return ':';}
";" {token(";");return ';';}

"+" {token("+");return '+';}
"-" {token("-");return '-';}
"*" {token("*");return '*';}
"/" {token("/");return '/';}
"mod" {token("MOD");return MOD;}
":=" {token("ASSIGN");return ASSIGN;}

"and" {token("AND");return AND;}
"or" {token("OR");return OR;}
"not" {token("NOT");return NOT;}

"<" {token("<"); return '<';}
"<=" {token("RE");return RE;}
">=" {token("LE");return LE;}
">" {token(">"); return '>';}
"=" {token("="); return '=';}
"not=" {token("NE");return NE;}

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



\"  {dou_str=false;LIST;BEGIN STR;}
<STR>[^"]+  {yymore();}
<STR>\"\"  {dou_str=true;yymore();}
<STR>\"  {
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
  BEGIN(INITIAL);
  tokenString("String",buf_pointer2);
  
}

"array" {token("ARRAY"); return ARRAY;}
"begin" {token("Begin");return Begin;}
"bool" {token("BOOL");return BOOL;}
"char" {token("CHAR");return CHAR;}
"const" {token("CONST");return CONST;}
"decreasing" {token("DECREASING");return DECREASING;}
"default" {token("DEFAULT");return DEFAULT;}
"do" {token("DO");return DO;}
"else" {token("ELSE");return ELSE;}
"end" {token("END");return END;}
"exit" {token("EXIT");return EXIT;}
"false" {yylval.type="BOOL";yylval.v.bool_value=false;token("bool");return B_VALUE;}
"for" {token("FOR");return FOR;}
"function" {token("FUNCTION");return FUNCTION;}
"get" {token("GET");return GET;}
"if" {token("IF");return IF;}
"int" {token("INT");return INT;}
"loop" {token("LOOP");return LOOP;}
"of" {token("OF");return OF;}
"put" {token("PUT");return PUT;}
"procedure" {token("PROCEDURE");return PROCEDURE;}
"real" {token("REAL");return REAL;}
"result" {token("RESULT");return RESULT;}
"return" {token("RETURN");return RETURN;}
"skip" {token("SKIP");return SKIP;}
"string" {token("STRING");return STRING;}
"true" {yylval.type="BOOL";yylval.v.bool_value=true;token("bool");return B_VALUE;}
"var" {token("VAR");return VAR;}
"when" {token("WHEN");return WHEN;}
"then" {token("THEN");return THEN;}

{int}	{
	sscanf(yytext, "%s", buf_pointer);
	tokenInteger("Int",buf_pointer);
	}

{real}	{
	sscanf(yytext, "%s", buf_pointer);
	tokenReal("Real",buf_pointer);
	}

{id} 	{
	sscanf(yytext, "%s", buf_pointer);
	tokenID("ID",buf_pointer);
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
int hashCode(const char* str)
{
    const char* p;
    int sum = 0;
    int h = 0;

    for (p = str; *p != '\0'; p++)
    {
        sum = *p + sum;
    }
    if (sum < 0)sum = sum * (-1);
    h = sum % SIZE;
    //printf("hashIndex_function:%d\n",h);
    return h;
}

symbol_table* creat(char* str)
{
  new_table = (struct symbol_table*)malloc(sizeof(symbol_table));
  //symbol_table main("main_table");
  strcpy(new_table->name,str);
  STstack.push(new_table);
  return new_table;
}


symbol_table* dump(symbol_table* del)
{
  if(del==NULL)
  {
    printf("the symbol table is not exist.\n");
    return NULL;  
  }
  int i = 0;
    printf("hash_table:\n");
    for (i = 0; i < SIZE; i++) {
        if (del->hashArray[i] != NULL)
         if((del->hashArray[i]->c_v==0)&&(del->hashArray[i]->special==0))
         {
            if(strcmp(del->hashArray[i]->type_name,"INT")==0)
              {printf(" (index:%d,name:%s,type:%s,value:%d)\n", i, del->hashArray[i]->name,del->hashArray[i]->type_name,del->hashArray[i]->value.i);}
            else if(strcmp(del->hashArray[i]->type_name,"REAL")==0)
              {printf(" (index:%d,name:%s,type:%s,value:%f)\n", i, del->hashArray[i]->name,del->hashArray[i]->type_name,del->hashArray[i]->value.f);}
            else if(strcmp(del->hashArray[i]->type_name,"STRING")==0)
              {printf(" (index:%d,name:%s,type:%s,value:%s)\n", i, del->hashArray[i]->name,del->hashArray[i]->type_name,del->hashArray[i]->value.s);}
            else if(strcmp(del->hashArray[i]->type_name,"BOOL")==0)
              {printf(" (index:%d,name:%s,type:%s,value:%s)\n", i, del->hashArray[i]->name,del->hashArray[i]->type_name,del->hashArray[i]->value.b ? "true" : "false");}
            else {printf("print something wrong\n");}
         }
         else if ((del->hashArray[i]->c_v==1)&&(del->hashArray[i]->special==0))
         {
         printf(" VAR:(index:%d,name:%s,type:%s)\n", i, del->hashArray[i]->name,del->hashArray[i]->type_name);
         }
         else if(del->hashArray[i]->special==1)
         {
           printf(" Array:(index:%d,name:%s,type:%s,start_index:%d,end_index=%d)\n", i, del->hashArray[i]->name,del->hashArray[i]->type_name,del->hashArray[i]->start_number,del->hashArray[i]->end_number);
         }
         else if(del->hashArray[i]->special==2)
         {
           printf(" Function:(index:%d,name:%s,return_type:%s)\n", i, del->hashArray[i]->name,del->hashArray[i]->type_name);
           printf("    Arguments:\n");
           int j=0;
           for(j=0;j<del->hashArray[i]->para_array.size();j++)
           {
             printf("     ID:%s,Type:%s\n",del->hashArray[i]->para_array[j].p_name,del->hashArray[i]->para_array[j].p_type_name);
           }
         }
         else if(del->hashArray[i]->special==3)
         {
           printf(" procedure:(index:%d,name:%s)\n", i, del->hashArray[i]->name);
           printf("    Arguments:\n");
           int j=0;
           for(j=0;j<del->hashArray[i]->para_array.size();j++)
           {
             printf("     ID:%s,Type:%s\n",del->hashArray[i]->para_array[j].p_name,del->hashArray[i]->para_array[j].p_type_name);
           }
         }
    }
    
  /**only delete current_table*/
  for(int i=0;i<SIZE;i++)
  {
    if(del->hashArray[i]!=NULL)
    {
      //printf("delete\n");
      del->dump(i);
    }
  }
  STstack.pop(); 
  if(strcmp(del->name,"main_table")!=0)
  {
    current_table=STstack.top();
  }
  free(del);
  del=NULL;
  return NULL; 
}