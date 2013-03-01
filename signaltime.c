#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static void catch_function(int signal) 
                {
                  int n = 0;
               printf("Enter the number\n");
                  scanf("%d",&n);
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
                       if(diff >= 10)
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
                     }while(diff <= 10.0);
                return 0;
           }
