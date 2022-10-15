/*************************************************************************/
/*       Auther: Ahmed Samir       */
/*       version: V01              */
/*       Date: 10/9/2022           */

#ifndef IR_PRIVATE_H
#define IR_PRIVATE_H

void (*REMOTE_POWERFunction)(void);
void (*REMOTE_MODEFunction)(void);
void (*REMOTE_SILENTFunction)(void);
void (*REMOTE_PAUSEFunction)(void);
void (*REMOTE_LEFTFunction)(void);
void (*REMOTE_RIGHTFunction)(void);
void (*REMOTE_EQFunction)(void);
void (*REMOTE_VOL_LOWFunction)(void);
void (*REMOTE_VOL_HIGHFunction)(void);
void (*REMOTE_RPTFunction)(void);
void (*REMOTE_U_SDFunction)(void);
void (*REMOTE_ZEROFunction)(void);
void (*REMOTE_ONEFunction)(void);
void (*REMOTE_TWOFunction)(void);
void (*REMOTE_THREEFunction)(void);
void (*REMOTE_FOURFunction)(void);
void (*REMOTE_FIVEFunction)(void);
void (*REMOTE_SIXFunction)(void);
void (*REMOTE_SEVENFunction)(void);
void (*REMOTE_EIGHTFunction)(void);
void (*REMOTE_NINEFunction)(void);


volatile u8 u8StartFlag = 0; //if variable is read in interrupt, make it volatile
volatile u32 u32FrameData[50] = {0};
volatile u8 u8EdgeCounter = 0;
volatile u8 u8Data = 0;

void voidPlay(void)
{

	switch(u8Data)
	{
	case REMOTE_POWER   : REMOTE_POWERFunction();    break;
	case REMOTE_MODE    :  REMOTE_MODEFunction();    break;
	case REMOTE_SILENT  : REMOTE_SILENTFunction();   break;
	case REMOTE_PAUSE   : REMOTE_PAUSEFunction();    break;
	case REMOTE_LEFT    : REMOTE_LEFTFunction();     break;
	case REMOTE_EQ      : REMOTE_EQFunction();       break;
	case REMOTE_VOL_LOW : REMOTE_VOL_LOWFunction();  break;
	case REMOTE_VOL_HIGH: REMOTE_VOL_HIGHFunction(); break;
	case REMOTE_RPT     : REMOTE_RPTFunction();      break;
	case REMOTE_U_SD    : REMOTE_U_SDFunction();     break;
	case REMOTE_ZERO    : REMOTE_ZEROFunction();     break;
	case REMOTE_ONE     : REMOTE_ONEFunction();      break;
	case REMOTE_TWO     : REMOTE_TWOFunction();      break;
	case REMOTE_THREE   : REMOTE_THREEFunction();    break;
	case REMOTE_FOUR    : REMOTE_FOURFunction();     break;
	case REMOTE_FIVE    : REMOTE_FIVEFunction();     break;
	case REMOTE_SIX     : REMOTE_SIXFunction();      break;
	case REMOTE_SEVEN   : REMOTE_SEVENFunction();    break;
	case REMOTE_EIGHT   : REMOTE_EIGHTFunction();    break;
	case REMOTE_NINE    : REMOTE_NINEFunction();     break;
	default             : /*error*/                  break;

	}
}

void voidTakeAction(void)
{
	u8 i;
	u8Data = 0;

	if((u32FrameData[0] >= 10000) && (u32FrameData[0] <= 20000)) //check start bit
	{
		for(i=0 ;i<8;i++)
		{
			if((u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <= 3000))
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}

		voidPlay();
	}
	else
	{
		//Invalid frame
	}

	u8StartFlag = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter =0;
}

void GetIRFrame(void)
{
	if(u8StartFlag == 0)
	{
		/* start timer */
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag =1;
	}
	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;
	}
}

#endif

