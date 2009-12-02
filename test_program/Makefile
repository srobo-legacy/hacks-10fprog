all: test.hex

test.hex: test.asm
	gpasm test.asm

.PHONY: clean

clean:
	-rm -f test.{cod,hex,lst}
