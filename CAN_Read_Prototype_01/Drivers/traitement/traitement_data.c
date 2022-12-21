//#include "stm32f1xx_hal_uart.h"
#include "main.h"

UART_HandleTypeDef *huart1;

HAL_StatusTypeDef init(UART_HandleTypeDef *huart)
{
	huart1=huart;
	return HAL_OK;
}

HAL_StatusTypeDef fct_transmit(UART_HandleTypeDef *huart,char info3[])
{
	if(HAL_UART_Transmit(huart,(uint8_t *)info3,sizeof(info3),100)==HAL_OK)
		{
			return HAL_OK;
		}
	else{
		return HAL_ERROR;
	}
}

float calculdata(float ladata[],uint32_t PID){
	switch(PID){
	case 13: ;
		float val=ladata[0];
		return val;
	case 47: ;
		float val1=(ladata[0]/255);
		return val1;
	case 33: ;
		float val2=(ladata[0]*256+ladata[1]);
		return val2;
	case 31: ;
		float val3=ladata[0]*256+ladata[1];
		return val3;
	case 94: ;
		float val4=((ladata[0]*256+ladata[1])/20);
		return val4;
	case 103:	;
		float val5=(ladata[1]-40);
		return val5;
	case 92: ;
		float val6=(ladata[0]-40);
		return val6;
	case 90: ;
		float val7=(ladata[0]*100/255);
		return val7;
	case 5: ;
		float val8=(ladata[0]-40);
		return val8;



	}

}


HAL_StatusTypeDef carburant(int carbura)
{

	switch(carbura)
	{
	case 1: ;
		char carb[]={"Gazoil"};
		fct_transmit(huart1, carb);
		return HAL_OK;
	case 2: ;
		char carb1[]={"Methanol"};
		fct_transmit(huart1, carb1);
		return HAL_OK;
	case 3: ;
		char carb2[]="Ethanol";
		fct_transmit(huart1, carb2);
		return HAL_OK;
	case 4: ;
		char Vin[]="Diesel";
		fct_transmit(huart1, Vin);
		return HAL_OK;
	case 5:	;
		char carb3[]="LPG";
		fct_transmit(huart1, carb3);
		return HAL_OK;
	case 6: ;
		char carb4[]="CNG";
		fct_transmit(huart1, carb4);
		return HAL_OK;
	case 7: ;
		char hunt[]="Propane";
		fct_transmit(huart1, hunt);
		return HAL_OK;
	case 8: ;
		char carb5[]="Electrique";
		fct_transmit(huart1, carb5);
		return HAL_OK;
	case 9: ;
		char carb6[]="Ethanol";
		fct_transmit(huart1, carb6);
		return HAL_OK;
	case 10: ;
		char carb7[]="Bicarburant au gazoil";
		fct_transmit(huart1, carb7);
		return HAL_OK;
	case 11: ;
		char carb8[]="Bicarubrant Methanol";
		fct_transmit(huart1, carb8);
		return HAL_OK;
	case 12: ;
		char carb9[]="Bicarburant Ethanol";
		fct_transmit(huart1, carb9);
		return HAL_OK;
	case 13: ;
		char carb10[]="Bicarburant LPG";
		fct_transmit(huart1, carb10);
		return HAL_OK;
	case 14: ;
		char carb11[]="Bicarburant CNG";
		fct_transmit(huart1, carb11);
		return HAL_OK;
	case 15: ;
		char carb12[]="Bicarburant Propane";
		fct_transmit(huart1, carb12);
		return HAL_OK;
	case 16: ;
		char carb13[]="Bicarburant Electrique";
		fct_transmit(huart1, carb13);
		return HAL_OK;
	case 17: ;
		char carb14[]="Bicarburant Electrique et combustion";
		fct_transmit(huart1, carb14);
		return HAL_OK;
	case 18: ;
		char carb15[]="Hybride gazoil";
		fct_transmit(huart1, carb15);
		return HAL_OK;
	case 19: ;
		char carb16[]="Hybride Ethanol";
		fct_transmit(huart1, carb16);
		return HAL_OK;
	case 20: ;
		char carb17[]="Hybride Diesel";
		fct_transmit(huart1, carb17);
		return HAL_OK;
	case 21: ;
		char carb18[]="Hybride Electrique";
		fct_transmit(huart1, carb18);
		return HAL_OK;
	case 22: ;
		char carb19[]="Hybride electrique et combustion";
		fct_transmit(huart1, carb19);
		return HAL_OK;
	case 23: ;
		char carb20[]="Hybride regeneratif";
		fct_transmit(huart1, carb20);
		return HAL_OK;

	default: ;
		char err[]="inconnu";
		fct_transmit(huart1, err);
		return HAL_ERROR;

	}
}




HAL_StatusTypeDef traitement(uint32_t PID, uint8_t zeData[])
{
	switch(PID){
		case 13:
			if(zeData>255 || zeData<0)
						{
							return HAL_ERROR;
						}
			else{
				char info[100];
				float recup=calculdata((float*)zeData,PID);
				sprintf(info, "votre vitesse est de : %f\n", recup);
				fct_transmit(huart1,info);
				return HAL_OK;
				}
		case 47:
		if(zeData>100 || zeData<0)
			{
				return HAL_ERROR;
			}
		else
			{
			char info[100];
			float recup=calculdata((float*)zeData,PID);
			sprintf(info, "votre niveau d'essence est de : %f\n", recup);
			fct_transmit(huart1,info);
			return HAL_OK;
			}
		case 33:
		if(zeData>65535 || zeData<0)
		{
			return HAL_ERROR;
		}
		else
		{
			char info[100];
			float recup=calculdata((float*)zeData,PID);
			sprintf(info, "depuis votre dernier malfonctionnement vous avez parcouru  : %f\n", recup);
			fct_transmit(huart1,info);
			return HAL_OK;
		}
		case 81: ;
			int recup=(int)zeData;
			carburant(recup);
			return HAL_OK;
		case 31:
		if(zeData>65535 || zeData<0)
				{
					return HAL_ERROR;
				}
				else
				{
					char info[100];
					float recup=calculdata((float*)zeData,PID);
					sprintf(info, "Depuis le demarrage, il s'est ecoule s : %f\n", recup);
					fct_transmit(huart1,info);
					return HAL_OK;
		}
		case 94:
		if(zeData>65535 || zeData<0)
		{
			return HAL_ERROR;
		}
		else
		{
			char info[100];
			float recup=calculdata((float*)zeData,PID);
			sprintf(info, "en l/h, vous consommez : %f\n", recup);
			fct_transmit(huart1,info);
			return HAL_OK;
		}
		case 103:
		if(zeData>215 || zeData<-40)
		{
			return HAL_ERROR;
		}
		else
		{
			char info[100];
			float recup=calculdata((float*)zeData,PID);
			sprintf(info, "la temperature de l'eau est a %f\n", recup);
			fct_transmit(huart1,info);
			return HAL_OK;
		}
		case 92:
		if(zeData>210 || zeData<-40)
				{
					return HAL_ERROR;
				}
				else
				{
					char info[100];
					float recup=calculdata((float*)zeData,PID);
					sprintf(info, "la temperature de l'huile %f\n", recup);
					fct_transmit(huart1,info);
					return HAL_OK;

				}
		case 90:
		if(zeData>100 || zeData<-0)
				{
					return HAL_ERROR;
				}
				else
				{
					char info[100];
					float recup=calculdata((float*)zeData,PID);
					sprintf(info, "la position de la pedale en pourcent %f\n", recup);
					fct_transmit(huart1,info);
					return HAL_OK;
				}
		case 5:
		if(zeData>215 || zeData<-40)
				{
					return HAL_ERROR;
				}
				else
				{
					char info[100];
					float recup=calculdata((float*)zeData,PID);
					sprintf(info, "la temperature du liquide de refroidissement %f\n", recup);
					fct_transmit(&huart1,info);
					return HAL_OK;
				}
		default: ;
			char info[]={"ce n'est pas le PID qu'on recherche"};
			fct_transmit(huart1, info);
		}

}
