#ifndef UCONFIG_H_
#define UCONFIG_H_

/**
 * \file config.h
 *
 * Enthält Defines und deklariert Userkonfigurationsvariablen, welche
 * in der zugehörigen config.c-Datei initialisiert werden.
 * Die Werte in der config.c tauschen wir bei der Korrektur zum Testen aus.
 * Bitte fügt hier KEINE weiteren Defines o.Ä. ein. Ihr könnte die Werte
 * in der config.c zum Testen natürlich auch gerne selbst verändern.
 */

/* Falls auf den Boards gearbeitet wird am besten
 * die nächste Zeile auskommentieren
 */
#define BUILD_FOR_QEMU

/**
 * Erst ab Aufgabenblatt 3 relevant
 */

extern unsigned int UBUSY_WAIT_COUNTER;
extern unsigned int UPRINT_COUNT;

#endif // UCONFIG_H_
