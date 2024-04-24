#ifndef SYMBOL_TABLE_CPP
#define SYMBOL_TABLE_CPP
#define MAX_LINE_LENG 256
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
union Value{
  double real_number;
  int int_number;
  char Str[MAX_LINE_LENG];
  bool bool_value;
};
struct Y_type{
  char name[MAX_LINE_LENG];
  bool is_var=0;
  char* type;
  int special=0;
  bool G_L=false;//global
  Value v;
};
#define YYSTYPE Y_type
#include <stack>

#define SIZE 50
using namespace std;
/*
  union Un un;
  un.i = 10;
  un.f = 10.25;
*/
union Item_Value {
  int i;
  float f;
  bool b;
  char s[MAX_LINE_LENG];
};
struct para{
  char p_name[MAX_LINE_LENG];
  char p_type_name[20]={'\0'};
};
struct DataItem {
    char name[MAX_LINE_LENG];
    int c_v;//c=const=0, v=variable=1,
    int special=0;//array=1,function=2, procedure=3
    char* type_name;//if specila=2=>return type
    int start_number;
    int end_number;
    Item_Value value;//if specila=2=>return value
    int return_value=0;// if is return value==1
    vector<para> para_array;
    bool G_L=false;//false=global,true=local
};

extern struct DataItem* dummyItem;
extern struct DataItem* item;

/*creat*/

extern int hashCode(const char* str);
class symbol_table{
private:

public:
  char name[MAX_LINE_LENG];
  struct DataItem* hashArray[SIZE];
  symbol_table(const char* name)
  {
  strcpy(this->name,name);
  for (int i=0;i<SIZE;i++)
  {
    this->hashArray[i]=NULL;
  }
  }
  int lookup(char* name)
  {
   //get the hash 
    int hashIndex = hashCode(name);
    //move in array until an empty 
    int not_null_index = 0;
    while (this->hashArray[hashIndex] != NULL) {
        if (not_null_index >= SIZE)return -2;
        if (strcmp(this->hashArray[hashIndex]->name, name) == 0)
        {
            return hashIndex;
        }
        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
        not_null_index++;
    }
    return -1;
  }
  
  int insert(char* name)
  {
    /*struct DataItem**/ item = (struct DataItem*)malloc(sizeof(struct DataItem));
    strcpy(item->name, name);
    int hashIndex = hashCode(name);
    
    //move in array until an empty or deleted cell
    while (this->hashArray[hashIndex] != NULL) {
        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex = hashIndex%SIZE;
    }
    this->hashArray[hashIndex] = item;
    return hashIndex;
  }
  
  int dump(int hashindex)
  {
    if(this->hashArray[hashindex]==NULL)
  {
    return -1;
  }
  else
  {
    free(this->hashArray[hashindex]);
    hashArray[hashindex]=NULL;
    return 0;
  }
    
  }
  void display();
};
extern symbol_table* creat(char* str);
extern symbol_table* dump(symbol_table* del);
extern symbol_table* new_table;
extern stack<symbol_table*> STstack;

#endif