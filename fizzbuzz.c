
typedef unsigned int size_t;
typedef signed int ssize_t;

extern ssize_t sys_write(int fd, void* buf, size_t sz);

__attribute__((__noreturn__))
extern void sys_exit(int rval);

size_t strlen(const char* str) {
	register size_t size = 0;

	while (str[size] != 0) size++;

	return size;
}

void _strcpy(char* dest, const char* src) {
	while ((*dest++ = *src++));
}

size_t numdigits(unsigned int n) {
	size_t count = 0;

	while (n > 0) {
		count++;
		n /= 10;
	}

	return count;
}

size_t utoa(char* dest, unsigned int n) {
	const size_t digit_count = numdigits(n);
	size_t i = digit_count;

	if (!digit_count) {
		_strcpy(dest, "0");
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
			buffer[utoa(buffer, i)] = '\n';
			sys_write(1, buffer, strlen(buffer));
		}
	}

	sys_exit(0);
}
