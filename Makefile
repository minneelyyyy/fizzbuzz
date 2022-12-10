
OBJS=fizzbuzz.o syscalls.o

.SUFFIXES: .c .s .o
.PHONY: all clean

all: fizzbuzz

fizzbuzz: $(OBJS)
	$(LD) $(LDFLAGS) -nostdlib -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c -nostdlib -nostdinc -o $@ $<

.s.o:
	$(AS) $(ASFLAGS) -o $@ $<

clean:
	rm -r -f fizzbuzz $(OBJS)

