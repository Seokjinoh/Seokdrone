/*
 * M8N.c
 *
 *  Created on: Dec 19, 2020
 *      Author: fietc
 */

#include "M8N.h"

M8N_UBX_NAV_POSLLH posllh;

const unsigned char UBX_CFG_PRT[] = {
		0xB5, 0x62, 0x06, 0x00, 0x14, 0x00, 0x01, 0x00, 0x00, 0x00,
		0xD0, 0x08, 0x00, 0x00, 0x80, 0x25, 0x00, 0x00, 0x01, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9A, 0x79
};
const unsigned char UBX_CFG_MSG[] = {
		0xB5, 0x62, 0x06, 0x01, 0x08, 0x00, 0x01, 0x02, 0x00, 0x01,
		0x00, 0x00, 0x00, 0x00, 0x13, 0xBE
};
const unsigned char UBX_CFG_RATE[] = {
		0xB5, 0x62, 0x06, 0x08, 0x06, 0x00, 0xC8, 0x00, 0x01, 0x00,
		0x01, 0x00, 0xDE, 0x6A
};
const unsigned char UBX_CFG_CFG[] = {
		0xB5, 0x62, 0x06, 0x09, 0x0D, 0x00, 0x00, 0x00, 0x00, 0x00,
		0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x31,
		0xBF
};
void M8N_UBX_Initialization()
{
	M8N_UBX_dataSend(&UBX_CFG_PRT[0],sizeof(UBX_CFG_PRT));
	HAL_Delay(100);
	M8N_UBX_dataSend(&UBX_CFG_MSG[0],sizeof(UBX_CFG_MSG));
	HAL_Delay(100);
	M8N_UBX_dataSend(&UBX_CFG_RATE[0],sizeof(UBX_CFG_RATE));
	HAL_Delay(100);
	M8N_UBX_dataSend(&UBX_CFG_CFG[0],sizeof(UBX_CFG_CFG));
}

void M8N_UBX_dataSend(unsigned char* data, unsigned char len)
{
	for(int i=0;i<len;i++)
	{
		while(!LL_USART_IsActiveFlag_TXE(UART4));
		LL_USART_TransmitData8(UART4,data[i]);
	}
}

unsigned char M8N_UBX_CHKSUM_Check(unsigned char* data, unsigned char len)
{
	unsigned char CK_A = 0, CK_B = 0;

	for(int i=2;i<len-2;i++)
	{
		CK_A = CK_A + data[i];
		CK_B = CK_B + CK_A;
	}

	return (CK_A == data[len-2]) && (CK_B == data[len-1]);
}

void M8N_UBX_NAV_POSLLH_Parsing(unsigned char* data, M8N_UBX_NAV_POSLLH* posllh)
{
	posllh->CLASS = data[2];
	posllh->ID = data[3];
	posllh->LENGTH = data[4] | data[5]<<8;

	posllh->iTOW = data[6] | data[7]<<8 | data[8]<<16 | data[9] <<24;
	posllh->lon = data[10] | data[11]<<8 | data[12]<<16 | data[13] <<24;
	posllh->lat = data[14] | data[15]<<8 | data[16]<<16 | data[17] <<24;
	posllh->height = data[18] | data[19]<<8 | data[20]<<16 | data[21] <<24;
	posllh->hMSL = data[25] | data[23]<<8 | data[24]<<16 | data[25] <<24;
	posllh->hAcc = data[26] | data[27]<<8 | data[28]<<16 | data[29] <<24;
	posllh->vAcc = data[30] | data[31]<<8 | data[32]<<16 | data[33] <<24;

//	posllh->lon_f64 = posllh->lon / 10000000.;
//	posllh->lat_f64 = posllh->lat / 10000000.;

}
