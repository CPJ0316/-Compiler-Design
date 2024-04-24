%{
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#define Trace(t) printf(t)
#define MAX_LINE_LENG 256
#include "symbol_table.cpp"

int yyerror(char *s);
void yyrestart  (FILE * input_file );

extern int yylex(void);
extern void yyrestart ( FILE *input_file  );
extern symbol_table* current_table;
extern struct DataItem* dummyItem;
extern struct DataItem* item;
extern symbol_table* new_table;
extern stack<symbol_table*> STstack;
extern int yylex(void);
extern bool Opt_L;
extern int linenum;
extern char buf[MAX_LINE_LENG];

int L_index=0;
int negative_num=0;   //confirm double negative sign
char* class_name=new char[MAX_LINE_LENG];//save class name
bool is_return=false; //check procedure contains return
bool is_result=false; //check function contains result
int number_function=0;//check result in function
int number_procedure=0;//check return in function
bool is_main=false;//check the main class created or not

int number_loop=0;//check exit in function
char* function_return_type=new char[10];//check return type
vector<para> current_Arguments;//use in saving input arguments when Function & Procedure Declarations
vector<para> input_Arguments;//save input Arguments
stack<symbol_table*> temp_stack;//used in search ID
stack<int> loop_stack;//save loops exit place
stack<int> if_stack;//save begin place of if 
stack<int> counter_stack;//save the index of counter in the current symbol table
int variables_count=0;//recorde variables index

%}
/* tokens */
%token SEMICOLON 
%token Int Real
%token ARRAY Begin BOOL CHAR CONST DECREASING DEFAULT DO ELSE END EXIT FALSE FOR FUNCTION
%token GET IF INT LOOP OF PUT PROCEDURE REAL RESULT RETURN SKIP STRING TRUE VAR WHEN THEN

%token <type> TYPE
%token <v.Str> ID
%token <v.Str> String
%token <v.real_number> R_NUMBER
%token <v.int_number> I_NUMBER
%token <v.bool_value> B_VALUE

%right ASSIGN
%left OR
%left AND
%left NE '='
%left '<' '>' RE LE
%left '-' '+'
%left '*' '/' MOD
%nonassoc UMINUS NOT
%type<real_number> Value_expressions

%%
INPUT:Declarations
{
  if((is_main==false)&&(number_function==0)&&(number_procedure==0))
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  }
} INPUT
| Statements INPUT
/*| Declarations
| Statements*/
|/* empty */
;

Declarations:Constants Declarations
| Variables Declarations
| Array Declarations
| Function_de Declarations
| Procedure_de Declarations
| Constants
| Variables
| Array
| Function_de
| Procedure_de
;
Expressions:Value_expressions 
| Bool_expressions 
;

Statements:simple_statement
| Condiction
| Loop
| Block
| Exit
| Skip
;

simple_statement:Assignment
| Get_input
| Put_output
| RETURN_exp
| RESULT_exp
| Invocation 
{
  if(yyvsp[0].special==1)
  {
    yyerror("Need some variable to save the value.(array)");
  }
  else if(yyvsp[0].special==2)
  {
    yyerror("Need some variable to save the value.(function)");
  }
}
;

Constants:CONST ID ':' Type ASSIGN Expressions {  
    char* ID_name=$2;
    int index=0;
    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[-2].type;
      current_table->hashArray[index]->c_v=0;
      current_table->hashArray[index]->special=0;
      if(strcmp(yyvsp[-2].type,yyvsp[0].type)==0)
      {
        if(strcmp(yyvsp[0].type,"INT")==0){current_table->hashArray[index]->value.i=yyvsp[0].v.int_number;}
        else if(strcmp(yyvsp[0].type,"REAL")==0){current_table->hashArray[index]->value.f=yyvsp[0].v.real_number;}
        else if(strcmp(yyvsp[0].type,"STRING")==0){strcpy(current_table->hashArray[index]->value.s,yyvsp[0].v.Str);}
        else if(strcmp(yyvsp[0].type,"BOOL")==0){current_table->hashArray[index]->value.b=yyvsp[0].v.bool_value;}
        else {yyerror("const assignment wrong!!set value=0"); current_table->hashArray[index]->value.i=0;}  
      }
      else
      {
      yyerror("assignment type wrong!");
      }
    }
    else if(current_table->lookup(ID_name)==-2)
    {
       yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
| CONST ID ASSIGN Expressions {
    char* ID_name=$2;
    int index=0;
    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=0;
      current_table->hashArray[index]->special=0;
      if(strcmp(yyvsp[0].type,"INT")==0){current_table->hashArray[index]->value.i=yyvsp[0].v.int_number;}
      else if(strcmp(yyvsp[0].type,"REAL")==0){current_table->hashArray[index]->value.f=yyvsp[0].v.real_number;}
      else if(strcmp(yyvsp[0].type,"STRING")==0){strcpy(current_table->hashArray[index]->value.s,yyvsp[0].v.Str);}
      else if(strcmp(yyvsp[0].type,"BOOL")==0){current_table->hashArray[index]->value.b=yyvsp[0].v.bool_value;}
      else {yyerror("const assignment wrong!!set value=0"); current_table->hashArray[index]->value.i=0;  }  
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
;

Const_values:I_NUMBER { yyval.is_var=0;yyval.type="INT";yyval.v.int_number = yyvsp[0].v.int_number; }
| R_NUMBER { yyval.is_var=0;yyval.type="REAL";yyval.v.real_number = yyvsp[0].v.real_number;}
| B_VALUE  { yyval.is_var=0;yyval.type="BOOL";yyval.v.bool_value = yyvsp[0].v.bool_value;}
| String   { yyval.is_var=0;yyval.type="STRING";strcpy(yyval.v.Str,yyvsp[0].v.Str);}
| ID       {
  char* temp_name=$1;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==0)
    {
      yyval.special=0;
      yyval.is_var=current_table->hashArray[temp_index]->c_v;
      if(current_table->hashArray[temp_index]->c_v==0)
      {
        if (current_table->hashArray[temp_index]->type_name=="INT"){ yyval.type="INT";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="REAL"){ yyval.type="REAL";yyval.v.real_number = current_table->hashArray[temp_index]->value.f;}
        else if(current_table->hashArray[temp_index]->type_name=="BOOL"){ yyval.type="BOOL";yyval.v.bool_value = current_table->hashArray[temp_index]->value.b;}
        else if(current_table->hashArray[temp_index]->type_name=="STRING"){ yyval.type="STRING";strcpy(yyval.v.Str,current_table->hashArray[temp_index]->value.s);}
        else {yyerror("ID expression get wrong(const)"); }
      }
      else if(current_table->hashArray[temp_index]->c_v==1)
      {
        yyval.G_L=current_table->hashArray[temp_index]->G_L;
        strcpy(yyval.name,temp_name);
        if (current_table->hashArray[temp_index]->type_name=="INT"){ yyval.type="INT";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="REAL"){ yyval.type="REAL";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="BOOL"){ yyval.type="BOOL";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else if(current_table->hashArray[temp_index]->type_name=="STRING"){ yyval.type="STRING";yyval.v.int_number = current_table->hashArray[temp_index]->value.i;}
        else {yyerror("ID expression get wrong(const)"); }
      }
    }
    else
    {
      yyerror("ID expression get wrong(not constant/variable)");
    }
  }
  else
  {
    printf("Const_values, ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
;
Array:VAR ID ':' ARRAY Expressions '.''.' Expressions OF Type
{   
    char* ID_name=$2;
    int index=0;
    if((yyvsp[-2].is_var)||(yyvsp[-5].is_var))
    {
    yyerror("Expressions not all const.");
    }
    if(current_table->lookup(ID_name)==-1)
    {
      if((strcmp(yyvsp[-2].type,"INT")!=0)||(strcmp(yyvsp[-5].type,"INT")!=0))
      {
        yyerror("Array index type wrong!\n");
      }
      else if ((yyvsp[-5].v.int_number<0)||(yyvsp[-2].v.int_number<yyvsp[-5].v.int_number))
      {
        yyerror("Array index value wrong!\n");
      }
      else
      {
        index=current_table->insert(ID_name);
        current_table->hashArray[index]->type_name=yyvsp[0].type;
        current_table->hashArray[index]->c_v=1;
        current_table->hashArray[index]->special=1;
        current_table->hashArray[index]->start_number=yyvsp[-5].v.int_number;
        current_table->hashArray[index]->end_number=yyvsp[-2].v.int_number;
        }
    }
    else if(current_table->lookup(ID_name)==-2)
    {
       yyerror("Array: simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("Array:The name already used.");
    }
}
;
Function_de:FUNCTION ID '(' Arguments ')' ':' Type
  {
    char* ID_name=$2;
    strcpy(function_return_type,yyvsp[0].type);
    if(current_table->lookup(ID_name)==-1)
    {
      int index=0;
      variables_count=0;
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->special=2;
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      int i=0;
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        current_table->hashArray[index]->para_array.push_back(temp);
      }
      symbol_table* Function=creat(ID_name);
      current_table=STstack.top();      
      number_function= number_function+1; 
      printf("\tmethod public static int %s(",ID_name);
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        if(current_table->lookup(temp.p_name)==-1)
        {
           int temp_index=0;
           temp_index=current_table->insert(temp.p_name);
           current_table->hashArray[temp_index]->c_v=1;
           current_table->hashArray[temp_index]->G_L=true;
           current_table->hashArray[temp_index]->special=0;
           if(strcmp(temp.p_type_name,"INT")==0){current_table->hashArray[temp_index]->type_name="INT";printf("int");}
           else if(strcmp(temp.p_type_name,"REAL")==0){current_table->hashArray[temp_index]->type_name="REAL";}
           else if(strcmp(temp.p_type_name,"STRING")==0){current_table->hashArray[temp_index]->type_name="STRING";printf("string");}
           else if(strcmp(temp.p_type_name,"BOOL")==0){current_table->hashArray[temp_index]->type_name="BOOL";printf("int");}
           current_table->hashArray[temp_index]->value.i=variables_count;
           variables_count=variables_count+1;
           if(i<current_Arguments.size()-1){printf(", ");}
        }
        else if(current_table->lookup(ID_name)==-2)
        {
          yyerror("simbol table full.(function)");
          exit(-1);
        }
        else
        {
           yyerror("The name already used.(function)");
        }
      }
      printf(")\n");
      printf("\tmax_stack 15\n");
      printf("\tmax_locals 15\n");
      printf("\t{\n");
      current_Arguments.clear();
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.(function)");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.(function)");
    }
  }
  INPUT END ID
  {
    char* ID_name=$2;
    char* ID_name_2=$11;
    if(strcmp(ID_name,ID_name_2)!=0)
    {
      yyerror("the start name is different to final name.(function)");
    }
    dump(current_table);
    if(!is_result)
    {
      yyerror("The function does not contain result.");
    }
    else
    {
      is_result=false;
    }
    number_function=number_function-1;
    printf("\treturn\n");
    printf("\t}\n");
  }
;
RESULT_exp:RESULT Expressions
{
  if(number_function>0)
  {
    if(strcmp(function_return_type,yyvsp[0].type)!=0)
    {
      yyerror("The return type of the function is wrong.");
    }
    is_result=true;
    printf("\tireturn\n");
  }
  else
  {
    yyerror("The result is not in a function.");
  }
}
;
Condiction: IF Bool_expressions THEN
{
  printf("\tifeq L%d\n",L_index);
  L_index=L_index+1;
  if_stack.push(L_index);
  L_index=L_index+1;
  symbol_table* If_table=creat("If_table");
  current_table=STstack.top();
  if(strcmp(yyvsp[-1].type,"BOOL")!=0)
  {
    yyerror("the type of Bool_expressions in condiction is wrong.");
  }
  
}
INPUT Else_exp 
;

Else_exp: END IF
{  
  printf("\tL%d:\n",if_stack.top()-1);
  if_stack.pop();
  dump(current_table);
}
| ELSE
{
  printf("\tgoto L%d\n",if_stack.top());
  printf("\tL%d:\n",if_stack.top()-1);
  dump(current_table);
  symbol_table* Else_table=creat("Else_table");
  current_table=STstack.top();
}
INPUT END IF
{
  printf("\tL%d:\n",if_stack.top());
  if_stack.pop();
  dump(current_table);
}
;

Loop: LOOP 
{
  printf("\tL%d:\n",L_index);
  symbol_table* Loop_table=creat("Loop_table");
  current_table=STstack.top();
  number_loop= number_loop+1;
  L_index=L_index+1;
  loop_stack.push(L_index);
  L_index=L_index+1;
}
INPUT END LOOP
{
  printf("\tgoto L%d\n",loop_stack.top()-1);
  number_loop= number_loop-1;
  dump(current_table);
  printf("\tL%d:\n",loop_stack.top());
  loop_stack.pop();
}
| FOR ID ':' Expressions '.' 
{
  int ID_index=0;
  bool ID_G_L=false;
  char* temp_name=$2;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  //find the index of the counter
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
      ID_index=current_table->hashArray[temp_index]->value.i;
      ID_G_L=current_table->hashArray[temp_index]->G_L;
    }
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
    
 
  symbol_table* For_table=creat(temp_name);
  current_table=STstack.top();
  number_loop= number_loop+1;

  if(current_table->lookup(temp_name)==-1)
  {
    int index=0;
    index=current_table->insert(temp_name);
    current_table->hashArray[index]->special=0;
    current_table->hashArray[index]->c_v=1;
    current_table->hashArray[index]->type_name="INT";
    current_table->hashArray[index]->value.i=ID_index;
    current_table->hashArray[index]->G_L=ID_G_L;
    counter_stack.push(index);
  }
  else if(current_table->lookup(temp_name)==-2)
  {
    yyerror("simbol table full.(function)\n");
    exit(-1);
  }
  else
  {
     yyerror("The name already used.(for loop)");
  }
  if(ID_G_L==true)//local
  {
    printf("\tistore %d\n",ID_index);
    printf("\tL%d:\n",L_index);
    printf("\tiload %d\n",ID_index);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
  else if (ID_G_L==false)//global
  {
    printf("\tputstatic int %s.%s\n",class_name,temp_name);
    printf("\tL%d:\n",L_index);
    printf("\tgetstatic int %s.%s\n",class_name,temp_name);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
}
'.' Expressions
{
  
  //exit when (ID > maix)  
  printf("\tisub\n");
  printf("\tifgt L%d\n",L_index);
  L_index=L_index+1;
  printf("\ticonst_0\n");
  printf("\tgoto L%d\n",L_index);
  printf("\tL%d: iconst_1\n",L_index-1);
  printf("\tL%d:\n",L_index);
  L_index=L_index+1;
   
  printf("\tifne L%d\n",loop_stack.top());
  //pop the index of counter in hash table
  
}
INPUT END FOR
{
  //counter++
  if(current_table->hashArray[counter_stack.top()]->G_L==true)//local
  {
    printf("\tiload %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    printf("\tsipush 1\n");
    printf("\tiadd\n");
    printf("\tistore %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    counter_stack.pop();
  }
  else if(current_table->hashArray[counter_stack.top()]->G_L==false)//global
  {
    printf("\tgetstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    printf("\tsipush 1\n");
    printf("\tiadd\n");
    printf("\tputstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    counter_stack.pop();
  }

  //
  printf("\tgoto L%d\n",loop_stack.top()-1);
  number_loop= number_loop-1;
  dump(current_table);
  printf("\tL%d:\n",loop_stack.top());
  loop_stack.pop();
}
| FOR DECREASING ID ':' Expressions '.'
{
  int ID_index=0;
  bool ID_G_L=false;
  char* temp_name=$3;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  //find the index of the counter
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
      ID_index=current_table->hashArray[temp_index]->value.i;
      ID_G_L=current_table->hashArray[temp_index]->G_L;
    }
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
    
 
  symbol_table* For_table=creat(temp_name);
  current_table=STstack.top();
  number_loop= number_loop+1;

  if(current_table->lookup(temp_name)==-1)
  {
    int index=0;
    index=current_table->insert(temp_name);
    current_table->hashArray[index]->special=0;
    current_table->hashArray[index]->c_v=1;
    current_table->hashArray[index]->type_name="INT";
    current_table->hashArray[index]->value.i=ID_index;
    current_table->hashArray[index]->G_L=ID_G_L;
    counter_stack.push(index);
  }
  else if(current_table->lookup(temp_name)==-2)
  {
    yyerror("simbol table full.(function)\n");
    exit(-1);
  }
  else
  {
     yyerror("The name already used.(for loop)");
  }
  if(ID_G_L==true)//local
  {
    printf("\tistore %d\n",ID_index);
    printf("\tL%d:\n",L_index);
    printf("\tiload %d\n",ID_index);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
  else if (ID_G_L==false)//global
  {
    printf("\tputstatic int %s.%s\n",class_name,temp_name);
    printf("\tL%d:\n",L_index);
    printf("\tgetstatic int %s.%s\n",class_name,temp_name);
    L_index=L_index+1;
    loop_stack.push(L_index);
    L_index=L_index+1;
  }
}
'.' Expressions
{
    
  //exit when (ID < maix)  
  printf("\tisub\n");
  printf("\tiflt L%d\n",L_index);
  L_index=L_index+1;
  printf("\ticonst_0\n");
  printf("\tgoto L%d\n",L_index);
  printf("\tL%d: iconst_1\n",L_index-1);
  printf("\tL%d:\n",L_index);
  L_index=L_index+1;
   
  printf("\tifne L%d\n",loop_stack.top());
  //pop the index of counter in hash table
}
 INPUT END FOR
{
  if(current_table->hashArray[counter_stack.top()]->G_L==true)//local
  {
    printf("\tiload %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    printf("\tsipush 1\n");
    printf("\tisub\n");
    printf("\tistore %d\n",current_table->hashArray[counter_stack.top()]->value.i);
    counter_stack.pop();
  }
  else if(current_table->hashArray[counter_stack.top()]->G_L==false)//global
  {
    printf("\tgetstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    printf("\tsipush 1\n");
     printf("\tisub\n");
    printf("\tputstatic int %s.%s\n",class_name,current_table->hashArray[counter_stack.top()]->name);
    counter_stack.pop();
  }
  
  //
  printf("\tgoto L%d\n",loop_stack.top()-1);
  number_loop= number_loop-1;
  dump(current_table);
  printf("\tL%d:\n",loop_stack.top());
  loop_stack.pop();
}
;

Block: Begin 
{
  char* temp_name="block";
  symbol_table* block=creat(temp_name);
  current_table=STstack.top();
}
INPUT END
{
  dump(current_table);
}
;
Exit:EXIT WHEN Bool_expressions
{
  if(strcmp(yyvsp[0].type,"BOOL")!=0)
  {
    yyerror("expressions type wrong\n");
  }
  else
  {
    if(yyvsp[0].v.bool_value==true)
    {
      if (number_loop<=0) {yyerror("exit not in the loop");}
    }
    printf("\tifne L%d\n",loop_stack.top());
  }
}
| EXIT{
  if (number_loop<=0) {yyerror("exit not in the loop");}
  printf("\tifne L%d\n",loop_stack.top());
}
;
Skip: SKIP{ 
  if((is_main==false)&&(number_function==0)&&(number_procedure==0))
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  } 
printf("\tgetstatic java.io.PrintStream java.lang.System.out\n");
printf("\tinvokevirtual void java.io.PrintStream.println()\n");
}
;
Procedure_de:PROCEDURE ID '(' Arguments ')' 
  {
    char* ID_name=$2;
    variables_count=0;
    if(current_table->lookup(ID_name)==-1)
    {
      int index=0;
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=3;
      int i=0;
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        current_table->hashArray[index]->para_array.push_back(temp);
      }
      symbol_table* Procedure=creat(ID_name);
      current_table=STstack.top();
      number_procedure= number_procedure+1;
      printf("\tmethod public static void %s(",ID_name);
      for(i=0;i<current_Arguments.size(); i++)
      {
        para temp=current_Arguments[i];
        if(current_table->lookup(temp.p_name)==-1)
        {
           int temp_index=0;
           temp_index=current_table->insert(temp.p_name);
           current_table->hashArray[temp_index]->c_v=1;
           current_table->hashArray[temp_index]->G_L=true;
           current_table->hashArray[temp_index]->special=0;
           if(strcmp(temp.p_type_name,"INT")==0){current_table->hashArray[temp_index]->type_name="INT";printf("int");}
           else if(strcmp(temp.p_type_name,"REAL")==0){current_table->hashArray[temp_index]->type_name="REAL";}
           else if(strcmp(temp.p_type_name,"STRING")==0){current_table->hashArray[temp_index]->type_name="STRING";printf("string");}
           else if(strcmp(temp.p_type_name,"BOOL")==0){current_table->hashArray[temp_index]->type_name="BOOL";printf("int");}
           current_table->hashArray[temp_index]->value.i=variables_count;
           variables_count=variables_count+1;
           if(i<current_Arguments.size()-1){printf(", ");}
        }
        else if(current_table->lookup(ID_name)==-2)
        {
          yyerror("simbol table full.(Procedure)");
          exit(-1);
        }
        else
        {
           yyerror("The name already used.(Procedure)");
        }
      }
      printf(")\n");
      printf("\tmax_stack 15\n");
      printf("\tmax_locals 15\n");
      printf("\t{\n");
      current_Arguments.clear();
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.\n");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.\n");
    }
  }
  INPUT END ID
  {
    char* ID_name=$2;
    char* ID_name_2=$9;
    if(strcmp(ID_name,ID_name_2)!=0)
    {
      yyerror("the start name is different to final name.(Procedure)");
    }
    dump(current_table);
    if(!is_return)
    {
      yyerror("The procedure does not contain return.");
    }
    else
    {
      is_return=false;
    }
    number_procedure=number_procedure-1;
    printf("\treturn\n");
    printf("\t}\n");
  }
;
RETURN_exp:RETURN{
  if (number_procedure>0) {is_return=true;}
  else {yyerror("RETURN not in the procedure");}
  printf("\treturn\n");
}
;
Arguments : /*empty*/
|ID ':' Type
{
  para temp_Argument;
  char* temp_name=$1;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_name,temp_name);
  strcpy(temp_Argument.p_type_name,temp_type_name);
  current_Arguments.push_back(temp_Argument);
};
|Arguments ',' ID ':' Type 
{
  para temp_Argument;
  char* temp_name=$3;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_name,temp_name);
  strcpy(temp_Argument.p_type_name,temp_type_name);
  current_Arguments.push_back(temp_Argument);
}
;
Assignment: ID ASSIGN Expressions
{
  char* temp_name=$1;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==0)
    {
      if(current_table->hashArray[temp_index]->c_v==0){yyerror("const can not assignment!!");}
      else
      {
        if(strcmp(current_table->hashArray[temp_index]->type_name,yyvsp[0].type)!=0)
        {
          yyerror("assignment type different!");
        }
        else
        {
          if(current_table->hashArray[temp_index]->G_L==false)//global
          {
            printf("\tputstatic int %s.%s\n", class_name,temp_name);
          }
          else if(current_table->hashArray[temp_index]->G_L==true)//local
          {
            printf("\tistore %d\n",current_table->hashArray[temp_index]->value.i);
          }
        }
      }
    }
    else
    {
      printf("Assign wrong, id:%s not constant/variable.\n",temp_name);
    }
  }
  else
  {
    printf("Assign wrong: ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
| ID '[' Expressions']' ASSIGN Expressions
{
  char* temp_name=$1;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==1)
    {
      if(current_table->hashArray[temp_index]->c_v==0){yyerror("const can not assignment!!");}
      else if(strcmp(current_table->hashArray[temp_index]->type_name,yyvsp[0].type)!=0)
      {
        yyerror("assignment type different!");
      }
      else if((yyvsp[-3].v.int_number<current_table->hashArray[temp_index]->start_number)||(yyvsp[-3].v.int_number>current_table->hashArray[temp_index]->end_number))
      {
        printf("Array, index value from expressions not correct.\n",temp_name);
      }
    }
    else
    {
      printf("Assign wrong, id:%s not array.\n",temp_name);
    }
  }
  else
  {
    printf("Assign wrong: ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
;
Get_input:GET ID{
  char* temp_name=$2;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==0)
    {
      if(current_table->hashArray[temp_index]->c_v!=0)
      {
        yyval.special=0;
        yyval.is_var=current_table->hashArray[temp_index]->c_v;
        if(strcmp(current_table->hashArray[temp_index]->type_name,"REAL")==0)
        {
          yyval.type="REAL";
          yyval.v.real_number=current_table->hashArray[temp_index]->value.f;
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"INT")==0)
        {
          yyval.type="INT";
          yyval.v.int_number=current_table->hashArray[temp_index]->value.i;
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"BOOL")==0)
        {
          yyval.type="BOOL";
          yyval.v.bool_value=current_table->hashArray[temp_index]->value.b;
        } 
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"STRING")==0)
        {
          yyval.type="STRING";
          strcpy(yyval.v.Str,current_table->hashArray[temp_index]->value.s); 
        }
      }
      else
      {
        printf("Get wrong, id:%s is constant.\n",temp_name);
      }
    }
    else
    {
      printf("Get wrong, id:%s not constant/variable.\n",temp_name);
    }
  }
  else
  {
    printf("Get wrong: ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
;
Put_output:PUT 
{
  if((is_main==false)&&(number_function==0)&&(number_procedure==0))
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  }
  printf("\tgetstatic java.io.PrintStream java.lang.System.out\n");
}
Expressions{
  if(strcmp(yyvsp[0].type,"STRING")==0)
  {
      printf("\tinvokevirtual void java.io.PrintStream.print(java.lang.String)\n");
  }
  else if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
  {
     printf("\tinvokevirtual void java.io.PrintStream.print(int)\n");
  }
}
;
Invocation : ID '[' Expressions ']'
{
  char* temp_name=$1;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    if(current_table->hashArray[temp_index]->special==1)
    {
      yyval.special=1;
      if((current_table->hashArray[temp_index]->special !=1)||(strcmp(yyvsp[-1].type,"INT")!=0))
      {
        printf("Array: id:%s not array, or value of expressions not int.\n",temp_name);
      }
      else if((yyvsp[-1].v.int_number<current_table->hashArray[temp_index]->start_number)||(yyvsp[-1].v.int_number>current_table->hashArray[temp_index]->end_number))
      {
        printf("Array: index value from expressions not correct.\n",temp_name);
      }
      else if(yyvsp[-1].is_var!=0)
      {
        printf("Array: index value from expressions not const.\n",temp_name);
      }
             
        if(strcmp(current_table->hashArray[temp_index]->type_name,"REAL")==0)
        {
          yyval.type="REAL";
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"INT")==0)
        {
          yyval.type="INT";
        }
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"BOOL")==0)
        {
          yyval.type="BOOL";
        } 
        else if(strcmp(current_table->hashArray[temp_index]->type_name,"STRING")==0)
        {
          yyval.type="STRING";
        }
    }
    else
    {
      printf("Invocation wrong, id:%s not array.\n",temp_name);
    }
  }
  else
  {
    printf("Invocation wrong(array): ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
| ID '(' P_s ')'
{
  char* temp_name=$1;
  bool find_id=false;
  int temp_index=0;
  symbol_table* temp;
  while(!find_id)
  {
    temp_index=current_table->lookup(temp_name);
    if(temp_index<0)
    {
       if(strcmp(current_table->name,"main_table")==0)
      {
        break;
      }
      temp=current_table;
      temp_stack.push(temp);
      STstack.pop();
      current_table=STstack.top();
    }
    else
    {
      find_id=true;
    }
  }
  if(temp_index>=0)
  {
    int j=0;
    bool check_input_Argu=true;
    if((current_table->hashArray[temp_index]->special==2)||(current_table->hashArray[temp_index]->special==3))
    {
        if(current_table->hashArray[temp_index]->special==2)
        {
          yyval.special=2;
          printf("\tinvokestatic int %s.%s(",class_name,temp_name);
        }
        else if(current_table->hashArray[temp_index]->special==3)
        {
          yyval.special=3;
          printf("\tinvokestatic void %s.%s(",class_name,temp_name);
        }
        
        yyval.type=current_table->hashArray[temp_index]->type_name;
        if(current_table->hashArray[temp_index]->para_array.size()!=input_Arguments.size())
        {
          yyerror("argument of function/procedure is wrong(different quantity).");
        }
        else
        {
          for(j=0;j<current_table->hashArray[temp_index]->para_array.size();j++)
          {
            if((strcmp(current_table->hashArray[temp_index]->para_array[j].p_type_name,"INT")==0)||(strcmp(current_table->hashArray[temp_index]->para_array[j].p_type_name,"BOOL")==0))
            {
              printf("int");
            }    
            if(j<current_table->hashArray[temp_index]->para_array.size()-1){printf(", ");}
          }
          printf(")\n");

        }
        input_Arguments.clear();
    }
    else
    {
      yyerror("ID expression get wrong(not function/procedure)\n");
    }
  }
  else
  {
    printf("Invocation wrong(function/procedure): ID:%s  not exist.\n",temp_name);
  }
  while(!temp_stack.empty())
  {
    temp=temp_stack.top();
    temp_stack.pop();
    STstack.push(temp);
  }
  current_table=STstack.top();
}
;

P_s:/*empty*/
|P_s ',' Expressions
{
  para temp_Argument;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_type_name,temp_type_name);
  input_Arguments.push_back(temp_Argument);
 
}
|Expressions
{
  para temp_Argument;
  char* temp_type_name=yyvsp[0].type;
  strcpy(temp_Argument.p_type_name,temp_type_name);
   yyval.is_var=yyvsp[0].is_var;
  input_Arguments.push_back(temp_Argument);
}
;


Value_expressions: Value_expressions '+' Value_expressions 
{
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    yyval.G_L=(yyvsp[0].G_L || yyvsp[-2].G_L);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not addition.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not addition.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number+yyvsp[-2].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number+yyvsp[-2].v.int_number;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.int_number+yyvsp[-2].v.real_number;
      }
      else {yyerror("real addtion something wrong.");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      //check const/var
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number = yyvsp[0].v.int_number+yyvsp[-2].v.int_number;
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tiadd\n");}
    }
    else {yyerror("addtion something wrong.");} 
}
|Value_expressions '-' Value_expressions {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not subtraction.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not subtraction.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.real_number<0 && negative_num > 0 ){yyerror("sub+minus");}
        yyval.v.real_number = yyvsp[-2].v.real_number-yyvsp[0].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        if(yyvsp[0].v.real_number<0 && negative_num > 0 ){yyerror("sub+minus");}
        yyval.v.real_number = yyvsp[-2].v.int_number-yyvsp[0].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.int_number<0 && negative_num > 0 ){yyerror("sub+minus");}
        yyval.v.real_number = yyvsp[-2].v.real_number-yyvsp[0].v.int_number;
      }
      else {yyerror("real subtraction something wrong.");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      if(yyvsp[0].v.int_number<0 && negative_num > 0 ){yyerror("sub+minus");}
      //check const/var
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number = yyvsp[-2].v.int_number-yyvsp[0].v.int_number;  
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tisub\n");}
    }
    else {yyerror("subtraction something wrong.");}
}
| Value_expressions '*' Value_expressions {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not multiplication.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not multiplication.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number*yyvsp[-2].v.real_number;
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.v.real_number = yyvsp[0].v.real_number*yyvsp[-2].v.int_number;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.v.real_number = yyvsp[0].v.int_number*yyvsp[-2].v.real_number;
      }
      else {yyerror("real multiplication something wrong.\n");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number = yyvsp[0].v.int_number*yyvsp[-2].v.int_number;  
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\timul\n");}
    }
    else {yyerror("multiplication something wrong.");}
}
| Value_expressions '/' Value_expressions{ 
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
    {
      yyerror("string can not division.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0))
    {
      yyerror("bool can not division.");
      yyval.type="INT";
      yyval.v.int_number=0;
    }
    else if((strcmp(yyvsp[0].type,"REAL")==0)||(strcmp(yyvsp[-2].type,"REAL")==0))
    {
      yyval.type="REAL";
      if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.real_number==0.0)
        {
          yyerror("divide by zero");
          yyval.v.real_number=0.0;
        }
        else{yyval.v.real_number = yyvsp[-2].v.real_number/yyvsp[0].v.real_number;}  
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        if(yyvsp[0].v.real_number==0.0)
        {
          yyerror("divide by zero");
          yyval.v.real_number=0.0;
        }
        else{yyval.v.real_number = yyvsp[-2].v.int_number/yyvsp[0].v.real_number;}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        if(yyvsp[0].v.int_number==0)
        {
          yyerror("divide by zero");
          yyval.v.real_number=0.0;
        }
        else{yyval.v.real_number = yyvsp[-2].v.real_number/yyvsp[0].v.int_number;}
      }
      else {yyerror("real division something wrong.\n");}
    }
    else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
       if(yyvsp[0].v.int_number==0)
        {
        yyerror("divide by zero");
        yyval.v.int_number=0;
        }
        else{
          if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
          {
            yyval.is_var=false;
            yyval.v.int_number = yyvsp[-2].v.int_number/yyvsp[0].v.int_number; 
          }
          else
          {
            yyval.is_var=true;
          }
          if(is_main||number_function||number_procedure){printf("\tidiv\n");}
        }      
    }
    else {yyerror("division something wrong.");}
}
| Value_expressions MOD Value_expressions{  
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
    {
      yyval.type="INT";
      if(yyvsp[0].is_var==false && yyvsp[-2].is_var==false)//both const
      {
        yyval.is_var=false;
        yyval.v.int_number=yyvsp[-2].v.int_number % yyvsp[0].v.int_number; 
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tirem\n");}
    }
    else
    {
      yyerror("type != int, can not mod.");
    }
}
| '-' Value_expressions %prec UMINUS {
    yyval.is_var=yyvsp[0].is_var; 
    if(yyvsp[0].is_var==false)
    {
      if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyerror("string can not negative.");
        yyval.type="INT";
        yyval.v.int_number=0;
      }
      else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyerror("bool can not negative.");
        yyval.type="INT";
        yyval.v.int_number=0;
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0))
      {
        yyval.type="REAL";
        if(yyvsp[0].v.real_number<0 && negative_num > 0 ){yyerror("sub+minus");}
        else{ yyval.v.real_number = yyvsp[0].v.real_number*(-1);negative_num=negative_num+1;}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0))
      {
        yyval.type="INT";
        if(yyvsp[0].v.int_number<0 && negative_num > 0){yyerror("sub+minus");}
        else{ yyval.v.int_number = yyvsp[0].v.int_number*(-1);negative_num=negative_num+1;}
        if(is_main||number_function||number_procedure){printf("\tineg\n");}   
      }
    }
    else if(yyvsp[0].is_var==true)
    {
      yyval.is_var=true;
      if(is_main||number_function||number_procedure){printf("\tineg\n");}
    }
}  
| '(' Value_expressions ')' {
  negative_num=0 ; 
  yyval.is_var=yyvsp[-1].is_var;
    if(strcmp(yyvsp[-1].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[-1].v.real_number;
      }
    else if(strcmp(yyvsp[-1].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[-1].v.int_number;
      }
    else if(strcmp(yyvsp[-1].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[-1].v.bool_value;
      } 
    else if(strcmp(yyvsp[-1].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[-1].v.Str);
      }
    else {yyerror("() assign something wrong.");}
 }
| Const_values 
{
  yyval.is_var=yyvsp[0].is_var;
  if(yyvsp[0].is_var==false)
  {
   if(strcmp(yyvsp[0].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[0].v.real_number;
      }
    else if(strcmp(yyvsp[0].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[0].v.int_number;
        //const int
        if(is_main||number_function||number_procedure){printf("\tsipush %d\n",yyvsp[0].v.int_number);}
      }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[0].v.bool_value;
        //const bool
        if(is_main||number_function||number_procedure){printf("\t%s\n",yyvsp[0].v.bool_value? "iconst_1" : "iconst_0");}
      } 
    else if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[0].v.Str);
        //const string
        if(is_main||number_function||number_procedure){printf("\tldc \"%s\"\n",yyval.v.Str);}
      }
    else {yyerror("Const_values something wrong.(const)");}
  }
  else
  {
    if(strcmp(yyvsp[0].type,"REAL")==0){yyval.type="REAL";}
    else if(strcmp(yyvsp[0].type,"INT")==0){yyval.type="INT";}
    else if(strcmp(yyvsp[0].type,"BOOL")==0){yyval.type="BOOL";} 
    else if(strcmp(yyvsp[0].type,"STRING")==0){yyval.type="STRING";}
    else {yyerror("Const_values something wrong.(var)");}
    yyval.v.int_number=yyvsp[0].v.int_number;
    strcpy(yyval.name,yyvsp[0].name);
    yyval.G_L=yyvsp[0].G_L;
    yyval.is_var=true;
    if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
    {
      if(yyvsp[0].G_L==false)//global
      {
        if(is_main||number_function||number_procedure){printf("\tgetstatic int %s.%s\n",class_name,yyvsp[0].name);}
      }
      else if(yyvsp[0].G_L==true)//local
      {
        if(is_main||number_function||number_procedure){printf("\tiload %d\n",yyvsp[0].v.int_number);}
      }
    }
  }
}
| Invocation
{
   if(yyvsp[0].special==3)
   {
     yyerror("The procedure cannot be calculated, so it returns 0 instead.");
     yyval.type="INT";
     yyval.v.int_number=0;
   }
   else
   {
     yyval.is_var=yyvsp[0].is_var;
     if(strcmp(yyvsp[0].type,"REAL")==0)
        {
          yyval.type="REAL";
          yyval.v.real_number=yyvsp[0].v.real_number;
        }
      else if(strcmp(yyvsp[0].type,"INT")==0)
        {
          yyval.type="INT";
          yyval.v.int_number=yyvsp[0].v.int_number;
        }
      else if(strcmp(yyvsp[0].type,"BOOL")==0)
        {
          yyval.type="BOOL";
          yyval.v.bool_value=yyvsp[0].v.bool_value;
        } 
      else if(strcmp(yyvsp[0].type,"STRING")==0)
        {
          yyval.type="STRING";
          strcpy(yyval.v.Str,yyvsp[0].v.Str);
        }
      else {yyerror("Invocation something wrong.");}
    }
}
;

Bool_expressions: /*empty*/
| Bool_expression AND Bool_expressions  {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if((strcmp(yyvsp[0].type,"BOOL")!=0)||(strcmp(yyvsp[-2].type,"BOOL")!=0)){
    yyerror("type wrong, can not AND, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
      if(yyval.is_var==false)
      {
        yyval.v.bool_value=(yyvsp[0].v.bool_value)&&(yyvsp[-2].v.bool_value);
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tiand\n");}
  }
}
| Bool_expression OR Bool_expressions  {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if((strcmp(yyvsp[0].type,"BOOL")!=0)||(strcmp(yyvsp[-2].type,"BOOL")!=0)){
    yyerror("type wrong, can not OR, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
      if(yyval.is_var==false)
      {
        yyval.v.bool_value=(yyvsp[0].v.bool_value)||(yyvsp[-2].v.bool_value);
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure){printf("\tior\n");}
  }
}
| NOT Bool_expressions {
   yyval.type="BOOL";
   yyval.is_var=yyvsp[0].is_var;
  if(strcmp(yyvsp[0].type,"BOOL")!=0){
    yyerror("type wrong, can not NOT, use false instead");
    yyval.v.bool_value=false;
  }
  else
  {
      if(yyval.is_var==false)
      {
        yyval.v.bool_value=!(yyvsp[0].v.bool_value);
      }
      else
      {
        yyval.is_var=true;
      }
      if(is_main||number_function||number_procedure)
      {
        printf("\tsipush 1\n");
        printf("\tixor\n");
      }
  }
}
| Bool_expression '=' Bool_expression {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if(strcmp(yyvsp[0].type,yyvsp[-2].type)==0)
  {
    if(strcmp(yyvsp[0].type,"INT")==0)
    {
      if((yyvsp[0].v.int_number)==(yyvsp[-2].v.int_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
      
      printf("\tisub\n");
      printf("\tifeq L%d\n",L_index);
      L_index=L_index+1;
      printf("\ticonst_0\n");
      printf("\tgoto L%d\n",L_index);
      printf("\tL%d: iconst_1\n",L_index-1);
      printf("\tL%d:\n",L_index);
      L_index=L_index+1;
    }
    else if(strcmp(yyvsp[0].type,"REAL")==0)
    {
      if((yyvsp[0].v.real_number)==(yyvsp[-2].v.real_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
    }
    else if(strcmp(yyvsp[0].type,"STRING")==0)
    {
      if(strcmp(yyvsp[0].v.Str,yyvsp[-2].v.Str)==0){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
    {
      if((yyvsp[0].v.bool_value)==(yyvsp[-2].v.bool_value)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else {yyerror("Bool_expressions '=' Bool_expressions, wrong");}
  }
  else
  {
    printf("%s, %s can not be compare,use false instead\n",yyvsp[0].type,yyvsp[-2].type);
    yyval.v.bool_value=false;
  }
}
| Bool_expression NE Bool_expression {
  yyval.type="BOOL";
  yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
  if(strcmp(yyvsp[0].type,yyvsp[-2].type)==0)
  {
    if(strcmp(yyvsp[0].type,"INT")==0)
    {
      if((yyvsp[0].v.int_number)!=(yyvsp[-2].v.int_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}
      
      printf("\tisub\n");
      printf("\tifne L%d\n",L_index);
      L_index=L_index+1;
      printf("\ticonst_0\n");
      printf("\tgoto L%d\n",L_index);
      printf("\tL%d: iconst_1\n",L_index-1);
      printf("\tL%d:\n",L_index);
      L_index=L_index+1;
    }
    else if(strcmp(yyvsp[0].type,"REAL")==0)
    {
      if((yyvsp[0].v.real_number)!=(yyvsp[-2].v.real_number)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else if(strcmp(yyvsp[0].type,"STRING")==0)
    {
      if(strcmp(yyvsp[0].v.Str,yyvsp[-2].v.Str)!=0){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
    {
      if((yyvsp[0].v.bool_value)!=(yyvsp[-2].v.bool_value)){yyval.v.bool_value=true;}
      else {yyval.v.bool_value=false;}    
    }
    else {yyerror("Bool_expressions '=' Bool_expressions, wrong");}
  }
  else
  {
    printf("%s, %s can not be compare,use false instead\n",yyvsp[0].type,yyvsp[-2].type);
    yyval.v.bool_value=false;
  }
}
| Bool_expression {
    yyval.is_var=yyvsp[0].is_var;
    if(strcmp(yyvsp[0].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[0].v.real_number;
      }
    else if(strcmp(yyvsp[0].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[0].v.int_number;
      }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[0].v.bool_value;
      } 
    else if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[0].v.Str);
      }
    else {yyerror("Bool_expression:something wrong.");}
}
;
Bool_expression:'(' Bool_expressions ')' {
    yyval.is_var=yyvsp[-1].is_var;
    if(strcmp(yyvsp[-1].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[-1].v.real_number;
      }
    else if(strcmp(yyvsp[-1].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[-1].v.int_number;
      }
    else if(strcmp(yyvsp[-1].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[-1].v.bool_value;
      } 
    else if(strcmp(yyvsp[-1].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[-1].v.Str);
      }
    else {yyerror("Bool_expression:()something wrong.");}
 }
| Relation_exp {
    yyval.type="BOOL";
    yyval.is_var=yyvsp[0].is_var;
    if(strcmp(yyvsp[0].type,"BOOL")==0)
    {
      yyval.v.bool_value=yyvsp[0].v.bool_value;
    }
    else
    {
      printf("Relation_exp type wrong, use false instead\n");
      yyval.v.bool_value=false;
    }
}
| Value_expressions{
   yyval.is_var=yyvsp[0].is_var;
   if(strcmp(yyvsp[0].type,"REAL")==0)
      {
        yyval.type="REAL";
        yyval.v.real_number=yyvsp[0].v.real_number;
      }
    else if(strcmp(yyvsp[0].type,"INT")==0)
      {
        yyval.type="INT";
        yyval.v.int_number=yyvsp[0].v.int_number;
      }
    else if(strcmp(yyvsp[0].type,"BOOL")==0)
      {
        yyval.type="BOOL";
        yyval.v.bool_value=yyvsp[0].v.bool_value;
      } 
    else if(strcmp(yyvsp[0].type,"STRING")==0)
      {
        yyval.type="STRING";
        strcpy(yyval.v.Str,yyvsp[0].v.Str);
      }
    else {yyerror("Bool_expression、Value_expressions something wrong.");}
}
;

Relation_exp: Value_expressions '>' Value_expressions
 {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:>, will return the default value: false ");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))>0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:>, will return the default value: false ");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
        printf("\tisub\n");
        printf("\tifgt L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else { yyval.type="BOOL";yyerror("Relation_item > Relation_item : wrong ");}
    } 
 }
| Value_expressions LE Value_expressions {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:>=, will return the default value: false");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          yyval.type="BOOL";
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))>=0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:>=, will return the default value: false");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
        
        printf("\tisub\n");
        printf("\tifge L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number>=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number>=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else {yyerror("Relation_item >= Relation_item : wrong");}
    }  
}
| Value_expressions RE Value_expressions {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:<=, will return the default value: false");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          yyval.type="BOOL";
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))<=0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:<=, will return the default value: false");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
        
        printf("\tisub\n");
        printf("\tifle L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<=yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<=yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else { yyerror("Relation_item > Relation_item : wrong");}
    }  
  }
| Value_expressions '<' Value_expressions {
    yyval.is_var=(yyvsp[0].is_var || yyvsp[-2].is_var);
    if((strcmp(yyvsp[0].type,"BOOL")==0)||(strcmp(yyvsp[-2].type,"BOOL")==0)){ yyval.type="BOOL";yyval.v.bool_value =false; yyerror("bool can not be compared:<, will return the default value: false");}
    else
    {
      if((strcmp(yyvsp[0].type,"STRING")==0)||(strcmp(yyvsp[-2].type,"STRING")==0))
      {
        if(yyvsp[0].type==yyvsp[-2].type)
        {
          yyval.type="BOOL";
          if((strcmp(yyvsp[-2].v.Str,yyvsp[0].v.Str))<0){yyval.type="BOOL";yyval.v.bool_value =true;}
          else {yyval.type="BOOL";yyval.v.bool_value =false;}
        }
        else{yyval.type="BOOL";yyval.v.bool_value =false; yyerror("string can not be compared:>, will return the default value: false");}
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
        
        printf("\tisub\n");
        printf("\tiflt L%d\n",L_index);
        L_index=L_index+1;
        printf("\ticonst_0\n");
        printf("\tgoto L%d\n",L_index);
        printf("\tL%d: iconst_1\n",L_index-1);
        printf("\tL%d:\n",L_index);
        L_index=L_index+1;
      }
      else if((strcmp(yyvsp[0].type,"INT")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<yyvsp[0].v.int_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"INT")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.int_number<yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else if((strcmp(yyvsp[0].type,"REAL")==0)&&(strcmp(yyvsp[-2].type,"REAL")==0))
      {
        yyval.type="BOOL";
        if(yyvsp[-2].v.real_number<yyvsp[0].v.real_number){yyval.type="BOOL";yyval.v.bool_value =true;}
        else {yyval.type="BOOL";yyval.v.bool_value =false;}
      }
      else { yyerror("Relation_item > Relation_item : wrong");}
    } 
}
;

Variables:VAR ID ':' Type ASSIGN Expressions {
    char* ID_name=$2;
    int index=0;

    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[-2].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
      if(strcmp(yyvsp[-2].type,yyvsp[0].type)!=0)
      {
         yyerror("assignment type wrong!"); 
      } 
      if((is_main==false)&&(STstack.size()==1))//Global Variables
      {
        if(strcmp(yyvsp[-2].type,"INT")==0)
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.int_number);
          current_table->hashArray[index]->G_L=false;
        }
        else if(strcmp(yyvsp[-2].type,"BOOL")==0)
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.bool_value? 1 : 0);
          current_table->hashArray[index]->G_L=false;
        }
      }
      else//local Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0))
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;

          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
        else if (strcmp(yyvsp[0].type,"BOOL")==0)
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;

          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
      }
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.\n");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
| VAR ID ASSIGN Expressions {
    char* ID_name=$2;
    int index=0;

    if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
      if((is_main==false)&&(STstack.size()==1))//Global Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0))
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.int_number);
          current_table->hashArray[index]->G_L=false;
        }
        else if(strcmp(yyvsp[-2].type,"BOOL")==0)
        {
          printf("\tfield static int %s = %d\n",ID_name,yyvsp[0].v.bool_value? 1 : 0);
          current_table->hashArray[index]->G_L=false;
        }
      }
      else//local Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0))
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;
          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
        else if (strcmp(yyvsp[0].type,"BOOL")==0)
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;
          printf("\tistore %d\n",variables_count);
          variables_count=variables_count+1;
        }
      }
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
| VAR ID ':' Type {
  char* ID_name=$2;
  int index=0;
  if(current_table->lookup(ID_name)==-1)
    {
      index=current_table->insert(ID_name);
      current_table->hashArray[index]->type_name=yyvsp[0].type;
      current_table->hashArray[index]->c_v=1;
      current_table->hashArray[index]->special=0;
      if((is_main==false)&&(STstack.size()==1))//Global Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
        {
          printf("\tfield static int %s\n",ID_name);
          current_table->hashArray[index]->G_L=false;
        }
      }
      else//local Variables
      {
        if((strcmp(yyvsp[0].type,"INT")==0)||(strcmp(yyvsp[0].type,"BOOL")==0))
        {
          current_table->hashArray[index]->value.i=variables_count;
          current_table->hashArray[index]->G_L=true;
          variables_count=variables_count+1;
        }
      }
    }
    else if(current_table->lookup(ID_name)==-2)
    {
      yyerror("simbol table full.");
      exit(-1);
    }
    else
    {
       yyerror("The name already used.");
    }
  }
;

Type:INT {yyval.type="INT";}
| REAL {yyval.type="REAL";}
| STRING {yyval.type="STRING";}
| BOOL {yyval.type="BOOL";}
;

%%

int yyerror(char *s)//output warning message
{
fprintf(stderr, "%s\n", s);
return 0;
}

int main(int argc, char *argv[])
{
  FILE *yyin;
  
  int input_type=0;
  char* buffer=new char[MAX_LINE_LENG];
	if ( argc > 1 )
  {
    yyin = fopen( argv[1], "r" );
    if(yyin==NULL)
    {
      printf("input file is null.\n");
    }
    memcpy(class_name,argv[1],strlen(argv[1])-3);
    printf("class %s\n",class_name);
    printf("{\n",class_name);
    input_type=1;    
  }
	else
  {
      printf("input file fail\n");
		  yyin = stdin;
  }
  dummyItem = (struct DataItem*)malloc(sizeof(struct DataItem));
  strcpy(dummyItem->name,"\0");
  
  symbol_table* main=creat("main_table");
  current_table=STstack.top();
/* perform parsing */
  yyrestart(yyin);
  if (yyparse() == 1) /* parsing */
    {yyerror("Parsing error !"); }/* syntax error */
  if(is_main==false)
  {
    printf("\tmethod public static void main(java.lang.String[])\n");
    printf("\tmax_stack 15\n");
    printf("\tmax_locals 15\n");
    printf("\t{\n");
    is_main=true;
    variables_count=0;
  }
  printf("\treturn\n");
  printf("\t}\n");
  printf("}\n");
  main=dump(main);
  if(input_type==1){fclose(yyin);}
  return 0;
}
