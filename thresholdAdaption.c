

// Includes *************************************************

  #include "stdafx.h"


#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "thresholdAdaption.h"

// Defines **************************************************


// Prototypes ************************************************
static void assert(bool oParameter);

// Variables ************************************************


// Functions *************************************************
//! 
//! 
//! 
//!
//! @return  
uint16_t InitThreshold(STTHRESHOLD *pstThreshold, uint32_t u32MeasRange)
{
  uint8_t u8Index = 0;
  uint16_t u16Return = 0;

  assert(NULL != pstThreshold);

  if (NULL != pstThreshold)
  {
    pstThreshold->u32MeasRange = u32MeasRange;

    if (0 != pstThreshold->u32MeasRange)
    {
      for (u8Index = 0; NUMOFTHRESHOLDS > u8Index; u8Index++)
      {
        pstThreshold->stThresholdElement[u8Index].oOverflow = false;
        pstThreshold->stThresholdElement[u8Index].oTriggered = false;
        pstThreshold->stThresholdElement[u8Index].u32Offset = 0;
        pstThreshold->stThresholdElement[u8Index].u32StartPosition = 0;
        pstThreshold->stThresholdElement[u8Index].u32Threshold = 0;
      }

      pstThreshold->oInitialized = true;
    }
    else
    {
      u16Return = EINVAL;
    }
  }
  else
  {
    u16Return = EPERM;
  }

  return u16Return;
}


//! 
//! Adapt the position value to the meas range.
//! Update the start position and the offset value before calling this function.
//!
//! @return  
uint16_t SetThreshold(STTHRESHOLD *pstThreshold, ETHRESHOLD eThresholdNumber)
{
  uint32_t u32PositionThreshold = 0;
  uint16_t u16Return = 0;

  assert(NULL != pstThreshold);
  assert(NUMOFTHRESHOLDS < eThresholdNumber);
  

  if ((false != pstThreshold->oInitialized) && (NULL != pstThreshold) && (NUMOFTHRESHOLDS > eThresholdNumber))
  {
    if ((0 != pstThreshold->u32MeasRange) && (pstThreshold->stThresholdElement[eThresholdNumber].u32Offset < pstThreshold->u32MeasRange))
    {
      u32PositionThreshold = pstThreshold->stThresholdElement[eThresholdNumber].u32StartPosition + pstThreshold->stThresholdElement[eThresholdNumber].u32Offset;

      if (u32PositionThreshold >= pstThreshold->u32MeasRange)
      {
        u32PositionThreshold %= pstThreshold->u32MeasRange;
        pstThreshold->stThresholdElement[eThresholdNumber].oOverflow = true;
      }

      pstThreshold->stThresholdElement[eThresholdNumber].u32Threshold = u32PositionThreshold;
    }
    else
    {
      u16Return = EINVAL;
    }
  }
  else
  {
    u16Return = EPERM;
  }

  return u16Return;
}

//! 
//! 
//! 
//!
//! @return  
uint16_t CheckThresholdTriggerd(STTHRESHOLD *pstThreshold, ETHRESHOLD eThresholdNumber, uint32_t u32ActPosition)
{
  uint16_t u16Return = 0;

  assert(NULL != pstThreshold);
  assert(NUMOFTHRESHOLDS < eThresholdNumber);

  if (NULL != pstThreshold)
  {
    if ((false != pstThreshold->oInitialized) && (NUMOFTHRESHOLDS > eThresholdNumber))
    {
      if (true != pstThreshold->stThresholdElement[eThresholdNumber].oOverflow)
      {
        if (u32ActPosition >= pstThreshold->stThresholdElement[eThresholdNumber].u32Threshold)
        {
          pstThreshold->stThresholdElement[eThresholdNumber].oTriggered = true;
        }
      }
      else
      {
        if (u32ActPosition < pstThreshold->stThresholdElement[eThresholdNumber].u32Threshold)
        {
          pstThreshold->stThresholdElement[eThresholdNumber].oOverflow = false;
        }
      }
    }
    else
    {
      u16Return = EPERM;
    }
  }
  else
  {
    u16Return = EPERM;
  }

  return u16Return;
}

//! 
//! 
//! 
//!
//! @return  
uint16_t ResetThresholdTriggerd(STTHRESHOLD *pstThreshold, ETHRESHOLD eThresholdNumber)
{
  uint16_t u16Return = 0;

  assert(NULL != pstThreshold);
  assert(NUMOFTHRESHOLDS < eThresholdNumber);

  if (NULL != pstThreshold)
  {
    if ((false != pstThreshold->oInitialized) && (NUMOFTHRESHOLDS > eThresholdNumber))
    {
      pstThreshold->stThresholdElement[eThresholdNumber].oTriggered = false;
    }
    else
    {
      u16Return = EPERM;
    }
  }
  else
  {
    u16Return = EPERM;
  }


  return u16Return;
}



// --- static functions ---
static void assert(bool oParameter)
{
  
}
