#include <arch/bsp/uart.h>
#include <lib/kprintf.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

static void print_unsigned(unsigned int val, unsigned int base, bool negative, unsigned int width,
			   bool zero_pad)
{
	static const char digits[] = "0123456789abcdef";
	char		  buf[16];
	unsigned int	  len = 0;

	do {
		buf[len] = digits[val % base];
		len++;
		val /= base;
	} while (val > 0);

	unsigned int total_len = len + (negative ? 1u : 0u);
	unsigned int pad_len   = (width > total_len) ? (width - total_len) : 0u;

	if (!zero_pad) {
		while (pad_len > 0) {
			uart_putc(' ');
			pad_len--;
		}
	}

	if (negative) {
		uart_putc('-');
	}

	if (zero_pad) {
		while (pad_len > 0) {
			uart_putc('0');
			pad_len--;
		}
	}

	while (len > 0) {
		len--;
		uart_putc(buf[len]);
	}
}

void kprintf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format != '\0') {
		if (*format != '%') {
			uart_putc(*format);
			format++;
			continue;
		}

		format++;
		bool	     zero_pad	    = false;
		unsigned int width	    = 0;
		bool	     valid_modifier = true;

		if (*format == '0') {
			zero_pad = true;
			format++;
		}

		while (*format >= '0' && *format <= '9') {
			width = width * 10u + (unsigned int)(*format - '0');
			if (width > 8u) {
				valid_modifier = false;
			}
			format++;
		}

		if ((zero_pad && width != 8u) || (width != 0u && width != 8u)) {
			valid_modifier = false;
		}

		if (!valid_modifier) {
			uart_puts("Unknown conversion specifier");
			if (*format != '\0') {
				format++;
			}
			continue;
		}

		switch (*format) {
		case '%':
			if (width != 0) {
				uart_puts("Unknown conversion specifier");
			} else {
				uart_putc('%');
			}
			break;
		case 'c':
			if (width != 0) {
				uart_puts("Unknown conversion specifier");
			} else {
				unsigned char c = (unsigned char)va_arg(args, int);
				uart_putc((char)c);
			}
			break;
		case 's':
			if (width != 0) {
				uart_puts("Unknown conversion specifier");
			} else {
				const char *s = va_arg(args, const char *);
				uart_puts(s);
			}
			break;
		case 'i': {
			int	     val      = va_arg(args, int);
			bool	     negative = false;
			unsigned int uval;
			if (val < 0) {
				negative = true;
				uval	 = 0u - (unsigned int)val;
			} else {
				uval = (unsigned int)val;
			}
			print_unsigned(uval, 10u, negative, width, zero_pad);
			break;
		}
		case 'u': {
			unsigned int uval = va_arg(args, unsigned int);
			print_unsigned(uval, 10u, false, width, zero_pad);
			break;
		}
		case 'x': {
			unsigned int uval = va_arg(args, unsigned int);
			print_unsigned(uval, 16u, false, width, zero_pad);
			break;
		}
		case 'p':
			if (width != 0) {
				uart_puts("Unknown conversion specifier");
			} else {
				void *ptr = va_arg(args, void *);
				uart_puts("0x");
				print_unsigned((uintptr_t)ptr, 16u, false, 8u, true);
			}
			break;
		default:
			uart_puts("Unknown conversion specifier");
			break;
		}

		if (*format != '\0') {
			format++;
		}
	}

	va_end(args);
}
