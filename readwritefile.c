#include <stdio.h>
#include <stdlib.h>
typedef struct {
     unsigned int dcvtag;
     unsigned int dcsrvload;
     unsigned int dcramusage;
     unsigned char *dcaddr;
     int dcport;
             }ngx_dcinfo;
typedef struct {
     unsigned int vtag;
     unsigned int srvload;
     unsigned int ramusage;
     unsigned char *addr;
     int port;
             }ldc;
typedef struct {
            int x;
            ngx_dcinfo dcdatainfo[100];
                }gdc;
gdc *g_dc;

int main()
{
    int j, cnt = 0, n;
    ldc l_dc[1];
    //FILE *fp;
    int flag = 0;
    //fp = fopen("test.txt", "r");
    //fscanf(fp, "%d",&n);
    //fclose(fp);
    FILE* ptr_myfile;
    if ( (ptr_myfile = fopen("data.txt", "w+")) == NULL )
    {
        printf("Error opening file\n");
        return 1;   
    }

    //int fputc( int n, FILE *fp );

        g_dc = (gdc *) malloc (sizeof (gdc));
        fread(&g_dc,sizeof(gdc),1,ptr_myfile);      
        printf("enter the id:\n");
        scanf("%d",&l_dc[0].vtag);
        printf("enter the id:\n");
        scanf("%d",&l_dc[0].srvload);
        printf("enter the id:\n");
        scanf("%d",&l_dc[0].ramusage);
        printf("enter the id:\n");
        scanf("%d",&l_dc[0].port);
                        flag = 0;
                        for(j = 0; j <  g_dc->x; j++)
                         {
                           while(g_dc->dcdatainfo[j].dcvtag == l_dc[0].vtag)
                            {
                              g_dc->dcdatainfo[j].dcvtag = l_dc[0].vtag;
                              g_dc->dcdatainfo[j].dcsrvload = l_dc[0].srvload;
                              g_dc->dcdatainfo[j].dcramusage = l_dc[0].ramusage;
                              g_dc->dcdatainfo[j].dcport = l_dc[0].port;
                              flag = 1;
                              break;
                            }
                           }
                            if(flag == 0)
                             {
                              g_dc->dcdatainfo[cnt].dcvtag = l_dc[0].vtag;
                              g_dc->dcdatainfo[cnt].dcsrvload = l_dc[0].srvload;
                              g_dc->dcdatainfo[cnt].dcramusage = l_dc[0].ramusage;
                              g_dc->dcdatainfo[cnt].dcport = l_dc[0].port;
                              cnt++;
                            }
            g_dc->x = cnt;
            fwrite(&g_dc , sizeof(gdc) , 1, ptr_myfile);
            fclose(ptr_myfile);
        
                int counter;
  	ptr_myfile=fopen("data.txt","r");
		if (!ptr_myfile)
		{
			printf("Unable to open file!");
			return 1;
		}
                 n = g_dc->x;
		for ( counter=1; counter <= n; counter++)
		{
			fread(&g_dc,sizeof(gdc),1,ptr_myfile);
			printf("%d\n",g_dc->dcdatainfo[n].dcvtag);
                        printf("%d\n",g_dc->dcdatainfo[n].dcsrvload);
                        printf("%d\n",g_dc->dcdatainfo[n].dcramusage);
                        printf("%d\n",g_dc->dcdatainfo[n].dcport);
                }
                fclose(ptr_myfile);
    return 0;
} 
 


