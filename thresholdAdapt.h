#ifndef THRESHOLDADAPT_H
#define THRESHOLDADAPT_H
// Includes *************************************************

#include "stdint.h"
#include <stdlib.h>
#include <stdbool.h>

// Defines **************************************************

// Typedefinitions ******************************************
typedef enum tag_ETHRESHOLD {
  FIRST_THRESHOLD = 0,
  SECOND_THRESHOLD = 1,
  NUMOFTHRESHOLDS
}ETHRESHOLD;

typedef struct tag_THRESHOLDELEMENT {
  uint32_t u32StartPosition;
  uint32_t u32Offset;
  uint32_t u32Threshold;
  bool oOverflow;
  bool oTriggered;
}THRESHOLDELEMENT;

typedef struct tag_STTHRESHOLD {
  uint32_t u32MeasRange;
  THRESHOLDELEMENT stThresholdElement[NUMOFTHRESHOLDS];
  bool oInitialized;
}STTHRESHOLD;


// Prototypes ***********************************************
uint16_t InitThreshold(STTHRESHOLD *pstThreshold, uint32_t u32MeasRange);
uint16_t SetThreshold(STTHRESHOLD *pstThreshold, ETHRESHOLD eThresholdNumber);
uint16_t CheckThresholdTriggerd(STTHRESHOLD *pstThreshold, ETHRESHOLD eThresholdNumber, uint32_t u32ActPosition);
uint16_t ResetThresholdTriggerd(STTHRESHOLD *pstThreshold, ETHRESHOLD eThresholdNumber);


// Constants ************************************************

// Variables ************************************************
 

#endif // THRESHOLDADAPT.H
