/*
 * M8N.h
 *
 *  Created on: Dec 19, 2020
 *      Author: fietc
 */

#ifndef INC_M8N_H_
#define INC_M8N_H_
#ifdef __cplusplus
 extern "C" {
#endif

#include "main.h"

typedef struct _M8N_UBX_NAV_POSLLH
{
	unsigned char CLASS;
	unsigned char ID;
	unsigned short LENGTH;

	unsigned int iTOW;
	signed int lon;
	signed int lat;
	signed int height;
	signed int hMSL;
	unsigned int hAcc;
	unsigned int vAcc;

	double lon_f64;
	double lat_f64;
}M8N_UBX_NAV_POSLLH;

extern M8N_UBX_NAV_POSLLH;

unsigned char M8N_UBX_CHKSUM_Check(unsigned char* data, unsigned char len);
void M8N_UBX_NAV_POSLLH_Parsing(unsigned char* data, M8N_UBX_NAV_POSLLH* posllh);
void M8N_UBX_Initialization(void);
void M8N_UBX_dataSend(unsigned char* data, unsigned char len);

#ifdef __cplusplus
}
#endif
#endif /* INC_M8N_H_ */
