#include <arch/bsp/uart.h>
#include <stddef.h>

static constexpr unsigned int UART_BASE		= 0x7E201000 - 0x3F000000;
static constexpr unsigned int UART_DR_DATA_MASK = 0xFFu;
static constexpr unsigned int UART_FR_RXFE	= 1u << 4;
static constexpr unsigned int UART_FR_TXFF	= 1u << 5;

struct uart {
	unsigned int dr;
	unsigned int rsrecr;
	unsigned int unused0[4];
	unsigned int fr;
	unsigned int ilpr;
	unsigned int ibrd;
	unsigned int fbrd;
	unsigned int lcrh;
	unsigned int cr;
	unsigned int ifls;
	unsigned int imsc;
	unsigned int ris;
	unsigned int mis;
	unsigned int icr;
	unsigned int dmacr;
};
static_assert(offsetof(struct uart, dr) == 0x00);
static_assert(offsetof(struct uart, rsrecr) == 0x04);
static_assert(offsetof(struct uart, fr) == 0x18);
static_assert(offsetof(struct uart, ilpr) == 0x1C);
static_assert(offsetof(struct uart, ibrd) == 0x20);
static_assert(offsetof(struct uart, fbrd) == 0x24);
static_assert(offsetof(struct uart, lcrh) == 0x28);
static_assert(offsetof(struct uart, cr) == 0x2C);
static_assert(offsetof(struct uart, ifls) == 0x30);
static_assert(offsetof(struct uart, imsc) == 0x34);
static_assert(offsetof(struct uart, ris) == 0x38);
static_assert(offsetof(struct uart, mis) == 0x3C);
static_assert(offsetof(struct uart, icr) == 0x40);
static_assert(offsetof(struct uart, dmacr) == 0x44);

static volatile struct uart *const uart_port = (struct uart *)UART_BASE;

char uart_getc(void)
{
	while ((uart_port->fr & UART_FR_RXFE) != 0) {
	}
	return (char)(uart_port->dr & UART_DR_DATA_MASK);
}

void uart_putc(char c)
{
	while ((uart_port->fr & UART_FR_TXFF) != 0) {
	}
	uart_port->dr = (unsigned char)c;
}

void uart_puts(const char *s)
{
	while (*s != '\0') {
		uart_putc(*s);
		s++;
	}
}

