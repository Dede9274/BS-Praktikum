#ifndef POWERDOWN_H_
#define POWERDOWN_H_

// Weißt qemu an die Ausführung zu beenden.
void powerdown [[gnu::noreturn]] (void);

#endif // POWERDOWN_H_