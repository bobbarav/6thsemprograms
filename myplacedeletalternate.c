#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct Node
{
  int data;
	struct Node *next;
};

int main()
{
	int m = 2,n= 3,num = 10,i;
	struct Node *head = NULL;
	struct Node *new_node = NULL;
        
	printf("the values of M:%d\n",m);
	printf("the values of N:%d\n",n);
        for(i = 0; i< num; i++)
        	{
			new_node = (struct Node*) malloc(sizeof(struct Node));
			if (new_node == NULL)
        		{
				printf("node was not created\n");
			}			
			new_node->data = i+1;
                        new_node->next = head;	
			head = new_node;
		}
	print(head);
        deletealt(m,n,head);
        printf("list after deletion\n");
	print(head);
return 0;
}

print(struct Node *head)
{
        struct Node *tmp = head;
	while(tmp->next != NULL)
	{
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}
        printf("%d\n",tmp->data);
}

deletealt(int m, int n, struct Node *head)
{
	int i;
	struct Node *tmp = head,*t = NULL;
	struct Node *temp =  NULL;
	while(tmp)
	{
		for(i = 0; i < m && tmp != NULL; i++)
		{
			tmp = tmp->next;
		}	               
		if(tmp == NULL)
		{
			return;
		}
		t = tmp->next;
		for(i = 0; i < n && t != NULL; i++)
		{
			temp = t;
			t = t->next;
			free(temp);
		} 
		tmp->next = t;
		tmp = t;	
	}	


}
