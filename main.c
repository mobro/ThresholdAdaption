#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "thresholdAdapt.h"

#define MEAS_RANGE 3000
#define START_POSITION 2800
#define OFFSET 300

static void TestThreshold(void);

int main(int argc, const char *argv[])
{
  // Hello
  printf("\nHello World\n\n");

  TestThreshold();
}

void TestThreshold(void)
{
  STTHRESHOLD stThreshold;
  uint32_t u32MeasRange = MEAS_RANGE;
  uint32_t u32ActPosition = START_POSITION;
  uint16_t u16Return = 0;

  u16Return = InitThreshold(&stThreshold, u32MeasRange);
  assert(!(0 != u16Return));

  stThreshold.stThresholdElement[FIRST_THRESHOLD].u32Offset = OFFSET;
  stThreshold.stThresholdElement[FIRST_THRESHOLD].u32StartPosition = START_POSITION;

  u16Return = SetThreshold(&stThreshold, FIRST_THRESHOLD);
  assert(!(0 != u16Return));

  while (true != stThreshold.stThresholdElement[FIRST_THRESHOLD].oTriggered)
  {
    u16Return = CheckThresholdTriggerd(&stThreshold, FIRST_THRESHOLD, u32ActPosition);
    assert(!(0 != u16Return));

    u32ActPosition = (u32ActPosition + 1) % MEAS_RANGE;
  }
}
