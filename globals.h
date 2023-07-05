#ifndef _GLOBALS_H 
#define _GLOBALS_H

//--------------------------------------------------------------------
// Include Files
#include "lrun.h"
#include "web_api.h"
#include "lrw_custom_body.h"

//--------------------------------------------------------------------
// Global Variables
int tt=1;

TransStat (char * transName, char * IterationNum, char * p_username)
	
{
	if (lr_get_transaction_status(transName) == LR_FAIL) 
	{
	//	lr_error_message("Transaction %s failed for User: %s, Iteration:%s",transName,username,IterationNum);
		lr_error_message("Transaction %s failed for  p_UserName:%s  at Iteration:%s",transName,IterationNum,p_username);
		lr_end_transaction(transName, LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_FAIL);
	}
	return 0;
	
}
#endif // _GLOBALS_H
