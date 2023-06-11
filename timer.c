/*
 * timer.c
 *
 * Created: 12/20/2022 5:38:29 PM
 *  Author: akudlacek
 */

#include "timer.h"


/**************************************************************************************************
*                                             DEFINES
*************************************************^************************************************/

/**************************************************************************************************
*                                            VARIABLES
*************************************************^************************************************/
extern const volatile TICK_TYPE * volatile const g_tick_ms_ptr;

/**************************************************************************************************
*                                            FUNCTIONS
*************************************************^************************************************/
/******************************************************************************
*  \brief  resets timer
*  \param  pointer to last time
******************************************************************************/
void tmrReset(TICK_TYPE * const lastTime_ms)
{
	*lastTime_ms = *g_tick_ms_ptr;
}

/******************************************************************************
*  \brief  checks if time since last reset has expired
*  \param  pointer to last time
*  \param  time since
*  \return timer expired, 0-timer hasn't expired, 1-timer has expired
******************************************************************************/
uint8_t tmrCheck(const TICK_TYPE * const lastTime_ms, const TICK_TYPE timeLimit_ms)
{
	return (*g_tick_ms_ptr - *lastTime_ms) >= timeLimit_ms;
}

/******************************************************************************
*  \brief  checks if time since last reset has expired and automatically resets
*  \param  pointer to last time
*  \param  time since
*  \return timer expired, 0-timer hasn't expired, 1-timer has expired
******************************************************************************/
uint8_t tmrCheckReset(TICK_TYPE * const lastTime_ms, const TICK_TYPE timeLimit_ms)
{
	if(tmrCheck(lastTime_ms, timeLimit_ms))
	{
		tmrReset(lastTime_ms);
		return 1;
	}

	return 0;
}
