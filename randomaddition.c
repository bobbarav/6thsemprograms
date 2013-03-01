#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cnt1 = 0;
int cnt2 = 0;
static void catch_function(int signal) 
                {
                  int sum = 0;
               int num1;
                  int num2;
                  int num3;
                  num1 = rand() / 10;
                  num2 = rand() / 10;
                  num3 = num1 + num2;
                  printf("enter the sum of random number\n");
                  scanf("%d",&sum);
                  if(sum == num3)
                     {
                       printf("the sum is:%d\n",num3);
                       cnt1++;
                     }
                  else
                     {
                       printf("\n");
                       cnt2++;
                     }
                      
                  printf("Answer matched in 1 min:%d\n",cnt1);
                  printf("Answer not matched in 1 min:%d\n",cnt2);
                }

int main(void)  
          {
                time_t start,end;
	        double diff = 0.00; 
       		printf("hello all\n");
                   do
                     {
                       start = time(NULL);
    		       if(signal(SIGINT, catch_function) !=SIG_ERR);
		       raise(SIGINT);
                       end = time(NULL);
                       diff = diff + difftime(end,start);
                       if(diff >= 60)
                         {
                           int c;
                   	    printf("time duration exceed \n do you  want to continue enter \n1-continue\n2-exit\n");
                   	    scanf("%d",&c);
                   	    if(c == 1)
                    		{   
                                    diff = 0;
                        	    signal(SIGINT,catch_function);
                             	    raise(SIGINT);
                    		}
                   	    else
                    		{
                       		    exit(0);
                    		}
                         } 
                       printf("%lf\n",diff);  
                     }while(diff <= 60.0);
                return 0;
           }
