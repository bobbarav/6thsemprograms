#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "pcc_inc.h"

  

   PCC_ERROR_E PCC_Init(unsigned long ulPCCIPAddr, PCC_WORK_MODE_E PCC_MODE_SYNC)
     {
       return PCC_SUCCESS_E;
     }
   PCC_ERROR_E PCC_ConnectPCE(unsigned long ulPCEIPAddr)
     {
       return PCC_SUCCESS_E;
     }
  PCC_ERROR_E PCC_NetworkQuery(PCC_PATH_INFO_S *pstPathInfo)
     { 
       return PCC_SUCCESS_E;
     }
  PCC_ERROR_E PCC_DisConnectPCE(unsigned long ulPCEIPAddr)
     {
       return PCC_SUCCESS_E;
     }
  
