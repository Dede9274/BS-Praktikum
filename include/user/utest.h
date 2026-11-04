#ifndef UTEST_H_
#define UTEST_H_

/**
 * Erst ab Aufgabenblatt 3 relevant
 */

/**
 * \file utest.h
 * \brief Enthält mit `[[gnu::weak]]` annotierte Usertestfunktionen.
 *
 * Die Usertestfunktionen können durch ein zugehöriges Bibliotheksarchiv
 * (z.B. libutest.a) implementiert werden, an richtiger Stelle ausgeführt
 * werden und somit (durch das Linken gegen selbiges Archiv) Usertestcode
 * ausführen.
 */

/**
 * \brief Setzt Userkonfigurationsvariablen zur Laufzeit.
 */
void test_user_set_config [[gnu::weak]] (void);

/**
 * \brief Führt Usertestcode aus.
 */
void test_user_main [[gnu::weak]] (void);

/**
 * \brief Führt Usertestcode aus.
 */
void test_user [[gnu::weak]] (void *args);

#endif // UTEST_H_
