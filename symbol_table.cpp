#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

#include <stack>
#define MAX_LINE_LENG 256
#define SIZE 50
using namespace std;

struct DataItem {
    char name[MAX_LINE_LENG];
};

struct DataItem* dummyItem;
struct DataItem* item;
/*creat*/
class symbol_table{
private:

public:
  char name[MAX_LINE_LENG];
  struct DataItem* hashArray[SIZE];
  
  symbol_table(const char* name);
  int lookup(char* name);
  int insert(char* name);
  int dump(int hashindex);
  void display();
};

symbol_table* new_table;
stack<symbol_table*> STstack;

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
  strcat(new_table->name,str);
  STstack.push(new_table);
  return new_table;
}

symbol_table::symbol_table(const char* name)
{
  strcat(this->name,name);
  for (int i=0;i<SIZE;i++)
  {
    this->hashArray[i]=NULL;
  }
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
            printf(" (index:%d,%s)\n", i, del->hashArray[i]->name);
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
  free(del);
  del=NULL;
  return NULL; 
}

int symbol_table::lookup(char* name) {
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

int symbol_table::insert(char* name) {
    /*struct DataItem**/ item = (struct DataItem*)malloc(sizeof(struct DataItem));
    strcat(item->name, name);
     
    int hashIndex = hashCode(name);
    
    //move in array until an empty or deleted cell
    while (this->hashArray[hashIndex] != NULL) {
        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }
    this->hashArray[hashIndex] = item;
    return 0;
}

int symbol_table::dump(int hashindex) {
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
