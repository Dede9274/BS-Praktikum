#include <arch/cpu/powerdown.h>

void powerdown [[gnu::noreturn]] (void)
{
	// see https://developer.arm.com/documentation/dui0058/d/semihosting/semihosting/the-swi-interface?lang=en
	register int angel_SWIreason_ReportException asm("r0") = 0x18;
	register int ADP_Stopped_ApplicationExit asm("r1") = 0x20026;

	asm("svc 0x00123456" :: "r"(angel_SWIreason_ReportException), "r"(ADP_Stopped_ApplicationExit));

	for(;;){}
}
