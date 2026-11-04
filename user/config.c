#include <user/config.h>

#ifdef BUILD_FOR_QEMU
/* Werte zum testen unter QEMU */
unsigned int UBUSY_WAIT_COUNTER = 100000;
#else
/* Werte zum testen auf der Hardware */
unsigned int UBUSY_WAIT_COUNTER = 30000;
#endif // BUILD_FOR_QEMU

unsigned int UPRINT_COUNT = 5;
