/*
 * MB1013.c
 *
 *  Created on: 07-Jun-2022
 *      Author: sidiyer27
 */

#ifndef MB1013_H_
#define MB1013_H_

void MB1013_Init();
uint32_t MB1013_Dist_MM(int sensoridx);
uint32_t MB1013_Dist_CM(int sensoridx);
uint32_t MB1013_Dist_M(int sensoridx);
bool MB1013_Threshold(int sensoridx, float dist);



#endif /* MB1013_H_ */
