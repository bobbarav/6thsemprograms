#include <stdio.h>

int main()
{
  struct book
   {
     char name[20];
     char author[20];
     int cellno;
   };
  struct book b1 = {"bobba","ravi",974};
  struct book *ptr;
  ptr = &b1;
  printf("%s%s%d\n",b1.name,b1.author,b1.cellno);
  printf("%s%s%d\n",ptr->name,ptr->author,ptr->cellno);
return 0;
}
