/*int compar(char *ho, uint16_t ha){
 int taill=sizeof(tab)/sizeof(tablo_typedef)
 int ret=0;
 for(int i=0;i<taill;i++){
 if (ha == tab[i].PID)
 {
 ret=i;
 }
 return ret;
 }*/
#include "conversion_can.h"
#include "main.h"

float conversion_can(uint16_t PID, uint8_t zedata[]) {
	float val;
	switch (PID) {
	case 5:

		val = (float)(zedata[0] - 40);
		return val;
	case 13:
		 val = (float)(zedata[0]);
		return val;
	case 31:
		val = (float)(256 * zedata[0] + zedata[1]);
		return val;
	case 33:
		val = (float)(256 * zedata[0] + zedata[1]);
		return val;
	case 47:
		val = (float)(zedata[0] * 100 / 255);
		return val;
	case 81:
		val = (float)(zedata[0]);
		return val;
	case 90:
		val = (float)(zedata[0] * 100 / 255);
		return val;
	case 92:
		val = (float)(zedata[0] - 40);
		return val;
	case 94:
		val = (float)((256 * zedata[0] + zedata[1]) / 20);
		return val;
	case 103:
		if (zedata[0] == 0) {
			val = (float)(zedata[1] - 40);
		}
		else if (zedata[0] == 1) {
			val =(float) ((zedata[1] - 80 + zedata[2]) / 2);
		}
		else{
			val=216;
		}
		return val;

	}
}

