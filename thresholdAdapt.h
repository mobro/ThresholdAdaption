#ifndef THRESHOLDADAPT_H
#define THRESHOLDADAPT_H
#include <stdint.h>

uint16_t AdaptThreshold(uint32_t u32Position, uint32_t u32Offset, uint32_t u32MeasRange, uint32_t *pu32Threshold);

#endif // THRESHOLDADAPT.H