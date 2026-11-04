#ifndef KCONFIG_H_
#define KCONFIG_H_

/**
 * \file config.h
 *
 * Enthält Defines und deklariert Kernelkonfigurationsvariablen, welche
 * in der zugehörigen config.c-Datei initialisiert werden.
 * Die Werte in der config.c tauschen wir bei der Korrektur zum Testen aus.
 * Bitte fügt hier KEINE weiteren Defines o.Ä. ein. Ihr könnte die Werte
 * in der config.c zum Testen natürlich auch gerne selbst verändern.
 */

/* Falls auf den Boards gearbeitet wird am besten
 * die nächste Zeile auskommentieren
 */
#define BUILD_FOR_QEMU

#ifndef __ASSEMBLER__

/**
 * Erst ab Aufgabenblatt 2 relevant
 */

extern unsigned int BUSY_WAIT_COUNTER;
extern unsigned int PRINT_COUNT;
extern unsigned int TIMER_INTERVAL;

#endif // __ASSEMBLER__
#endif // KCONFIG_H_
