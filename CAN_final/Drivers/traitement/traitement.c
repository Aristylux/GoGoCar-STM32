/*
 * traitement.c
 *
 *  Created on: 28 mai 2023
 *      Author: samud
 */

#include "main.h"

//fonction pour récuperer le type de carburant
HAL_StatusTypeDef carburant(int carbura) {
	char* carb = NULL;

	switch (carbura) {
	case 1:
		;
		carb = "Gazoil";
		//return ou transmit
		return HAL_OK;
	case 2:
		;
		carb = "Methanol" ;
		//return ou transmit
		return HAL_OK;
	case 3:
		;
		carb = "Ethanol";
		//return ou transmit
		return HAL_OK;
	case 4:
		;
		carb = "Diesel";
		//return ou transmit
		return HAL_OK;
	case 5:
		;
		carb = "LPG";
		//return ou transmit
		return HAL_OK;
	case 6:
		;
		carb = "CNG";
		//return ou transmit
		return HAL_OK;
	case 7:
		;
		carb = "Propane";
		//return ou transmit
		return HAL_OK;
	case 8:
		;
		carb = "Electrique";
		//return ou transmit
		return HAL_OK;
	case 9:
		;
		carb = "Ethanol";
		//return ou transmit
		return HAL_OK;
	case 10:
		;
		carb = "Bicarburant au gazoil";
		//return ou transmit
		return HAL_OK;
	case 11:
		;
		carb = "Bicarubrant Methanol";
		//return ou transmit
		return HAL_OK;
	case 12:
		;
		carb = "Bicarburant Ethanol";
		//return ou transmit
		return HAL_OK;
	case 13:
		;
		carb = "Bicarburant LPG";
		//return ou transmit
		return HAL_OK;
	case 14:
		;
		carb = "Bicarburant CNG";
		//return ou transmit
		return HAL_OK;
	case 15:
		;
		carb = "Bicarburant Propane";
		//return ou transmit
		return HAL_OK;
	case 16:
		;
		carb = "Bicarburant Electrique";
		//return ou transmit
		return HAL_OK;
	case 17:
		;
		carb = "Bicarburant Electrique et combustion";
		//return ou transmit
		return HAL_OK;
	case 18:
		;
		carb = "Hybride gazoil";
		//return ou transmit
		return HAL_OK;
	case 19:
		;
		carb = "Hybride Ethanol";
		//return ou transmit
		return HAL_OK;
	case 20:
		;
		carb = "Hybride Diesel";
		//return ou transmit
		return HAL_OK;
	case 21:
		;
		carb = "Hybride Electrique";
		//return ou transmit
		return HAL_OK;
	case 22:
		;
		carb = "Hybride electrique et combustion";
		//return ou transmit
		return HAL_OK;
	case 23:
		;
		carb = "Hybride regeneratif";
		//return ou transmit
		return HAL_OK;

	default:
		;
		char err[] = "inconnu";
		//return ou transmit
		return HAL_ERROR;

	}
}

//determination de ce que représente l"information grace au PID puis convertion vers une valeur lisible puis transmition de cette donnée en uart
HAL_StatusTypeDef traitement(uint8_t *RxData) {
	int PID = (int) RxData[2];
	uint8_t Data_converti;

	switch (PID) {
//temperature liquide refroidissement moteur
	case 5:
		Data_converti = (RxData[3] - 40);
		if (Data_converti > 215 || Data_converti < -40) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//vitesse du vehicule
	case 13:
		Data_converti = RxData[3];
		if (Data_converti > 255 || Data_converti < 0) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//temps écoulé depuis le demarrage
	case 31:
		Data_converti = (RxData[3] * 256 + RxData[4]);
		if (Data_converti > 65535 || Data_converti < 0) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//Distance parcouru avec un voyant d'erreur
	case 33:
		Data_converti = (RxData[3] * 256 + RxData[4]);
		if (Data_converti > 65535 || Data_converti < 0) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//Niveau d'escence (%age)
	case 47:
		Data_converti = (RxData[3] * 100 / 255);
		if (Data_converti > 100 || Data_converti < 0) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//type de carburant
	case 81:
		Data_converti = RxData[3];
		carburant((int) Data_converti);
		return HAL_OK;
//position pedale d'accelerateur (%age)
	case 90:
		Data_converti = (RxData[3] * 100 / 255);
		if (Data_converti > 100 || Data_converti < -0) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//température huile moteur
	case 92:
		Data_converti = (RxData[3] - 40);
		if (Data_converti > 210 || Data_converti < -40) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//consomation carburant (L/h)
	case 94:
		Data_converti = ((RxData[3] * 256 + RxData[4]) / 20);
		if (Data_converti > 65535 || Data_converti < 0) {
			return HAL_ERROR;
		} else {
			//return ou transmit
			return HAL_OK;
		}
//temperature liquide refroidissement moteur bis
//les bits 0 et 1 représente l'existence (ou non) de capteurs de température du liquide refroidissement supplémentaires au capteur du PID 5
	case 103:
		if ((RxData[3] & 0b00000001) != 0) {
			Data_converti = (RxData[4] - 40);
			if (Data_converti > 215 || Data_converti < -40) {
				return HAL_ERROR;
			} else {
				//return ou transmit
				return HAL_OK;
			}
		}
		if ((RxData[3] & 0b00000010) != 0) {
			Data_converti = (RxData[5] - 40);
			if (Data_converti > 215 || Data_converti < -40) {
				return HAL_ERROR;
			} else {
				//return ou transmit
				return HAL_OK;
			}
		}

	default:
		return HAL_OK;
	}

}
