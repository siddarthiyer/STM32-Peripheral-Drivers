# MB1013 Ultrasound Sensor

<h4> Functions available :</h4>

```C
void MB1013_Init();
uint32_t MB1013_Dist_MM(int sensoridx);
uint32_t MB1013_Dist_CM(int sensoridx);
uint32_t MB1013_Dist_M(int sensoridx);
bool MB1013_Threshold(int sensoridx, float dist);

```
