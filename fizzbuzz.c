
typedef unsigned int size_t;
typedef signed int ssize_t;

extern ssize_t sys_write(int fd, void* buf, size_t sz);

__attribute__((__noreturn__))
extern void sys_exit(int rval);

inline size_t numdigits(unsigned int n) {
	size_t count = 0;

	while (n > 0) {
		count++;
		n /= 10;
	}

	return count;
}

inline size_t utoa(char* dest, unsigned int n) {
	const size_t digit_count = numdigits(n);
	size_t i = digit_count;

	if (!digit_count) {
		dest[0] = '0';
		dest[1] = '\0';
		return 1;
	}

	dest[i--] = '\0';

	do {
		unsigned int digit = n % 10;
		
		dest[i] = digit + '0';

		n /= 10;
	} while (i--);

	return digit_count;
}

__attribute__((__noreturn__))
void _start() {
	unsigned int i;

	for (i = 1; i <= 100; i++) {
		if (i % 3 == 0 && i % 5 == 0) sys_write(1, "FizzBuzz\n", 9);
		else if (i % 3 == 0) sys_write(1, "Fizz\n", 5);
		else if (i % 5 == 0) sys_write(1, "Buzz\n", 5);
		else {
			char buffer[32];
			size_t sz = utoa(buffer, i);
			buffer[sz] = '\n';
			sys_write(1, buffer, sz + 1);
		}
	}

	sys_exit(0);
}
