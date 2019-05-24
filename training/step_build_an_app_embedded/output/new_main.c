# 1 "./src/main.c"
# 1 "D:\\Linux Embedded\\microcontroller\\training\\step_build_an_app_embedded//"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "./src/main.c"

# 1 "./inc/hw_stm32f030_mini.h" 1
# 3 "./src/main.c" 2

void delay(unsigned int timeout)
{
    unsigned int t1, t2;
    for (t1 = 0; t1 < timeout; t1++)
    {
        for (t2 = 0; t2 < 0xFFF; t2++)
        {
          asm(" nop");
        }
    }
}

void main(void)
{

  do { unsigned long int tmpreg; tmpreg = *((unsigned long int *)(0x40021000u + 0x14)) & (~0x00020000u); tmpreg = tmpreg | 0x00020000u; *((unsigned long int *)(0x40021000u + 0x14)) = tmpreg; delay(10); } while(0U);

  do { unsigned long int tmpreg; tmpreg = *((unsigned long int *)(0x48000000u + 0x00)) & (0xFFFFFCFF); tmpreg = tmpreg | 0x00000100u; *((unsigned long int *)(0x48000000u + 0x00)) = tmpreg; } while(0U);
  while(1)
  {
    *((unsigned long int *)(0x48000000u + 0x14)) = 0x00000000u;;
    delay(0xff);
    *((unsigned long int *)(0x48000000u + 0x14)) = 0x00000010u;;
    delay(0xff);
  }
}


void Reserved_IRQHandler(void)
{
  while(1)
  {

  }
}

void NMI_Handler(void)
{
  while(1)
  {

  }
}

void HardFault_Handler(void)
{
  while(1)
  {

  }
}

void SVC_Handler(void)
{
  while(1)
  {

  }
}

void PendSV_Handler(void)
{
  while(1)
  {

  }
}

void SysTick_Handler(void)
{
  while(1)
  {

  }
}
