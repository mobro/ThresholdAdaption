#include "thresholdAdapt.h"
#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

uint16_t AdaptThreshold(uint32_t u32Position, uint32_t u32Offset, uint32_t u32MeasRange, uint32_t *pu32Threshold)
{
  uint32_t u32PosDiff = 0;
  uint32_t u32PositionThreshold = 0;
  uint16_t u16Return = 0;

  assert(NULL != pu32Threshold);

  u32PositionThreshold = u32Position + u32Offset;

  if (0 != u32MeasRange)
  {
    if (u32PositionThreshold >= u32MeasRange)
    {
      u32PositionThreshold %= u32MeasRange;
    }
  }
  else
  {
    u16Return = EINVAL;
  }
  
  return u16Return;
}