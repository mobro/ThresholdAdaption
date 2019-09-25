#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "thresholdAdapt.h"

static void TestThresholdAdaption(void);

int main(int argc, const char *argv[])
{
  // Hello
  printf("\nHello World\n\n");

  TestThresholdAdaption();
}

void TestThresholdAdaption(void)
{
  uint32_t u32Position = 2800;
  uint32_t u32Offset = 300;
  uint32_t u32MeasRange = 3000;
  uint32_t u32Threshold = 0;
  uint16_t u16Return = 0;

  u16Return = AdaptThreshold(u32Position, u32Offset, u32MeasRange, &u32Threshold);
  assert(!(0 != u16Return));
}
