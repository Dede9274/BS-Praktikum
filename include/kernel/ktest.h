#ifndef KTEST_H_
#define KTEST_H_

/**
 * \file ktest.h
 * \brief Enthält mit `[[gnu::weak]]` annotierte Kerneltestfunktionen.
 *
 * Die Kerneltestfunktionen können durch ein zugehöriges Bibliotheksarchiv
 * (z.B. libktest.a) implementiert werden, an richtiger Stelle ausgeführt
 * werden und somit (durch das Linken gegen selbiges Archiv) Kerneltestcode
 * ausführen.
 */

#ifdef __ASSEMBLER__

.weak test_kernel_set_config

#else

/**
 * \brief Setzt Kernelkonfigurationsvariablen zur Laufzeit.
 */
void test_kernel_set_config [[gnu::weak]](void);

/**
 * \brief Führt Kerneltestcode aus.
 */
void test_kernel [[gnu::weak]](void);

#endif // __ASSEMBLER__
#endif // KTEST_H_
