#include <kernel/config.h>

#ifdef BUILD_FOR_QEMU
/* Werte zum testen unter QEMU */
unsigned int BUSY_WAIT_COUNTER = 100000;
#else
/* Werte zum testen auf der Hardware */
unsigned int BUSY_WAIT_COUNTER = 30000;
#endif // BUILD_FOR_QEMU

unsigned int PRINT_COUNT = 5;

// Timer Interrupt Interval zum testen in Mikrosekunden
// Systimer taktet mit 1MHz
// 1000000 -> 1 Sekunde
unsigned int TIMER_INTERVAL = 1000000;
