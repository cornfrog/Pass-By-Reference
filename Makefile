all:
	@gcc -fsanitize=address -fno-omit-frame-pointer -g pbr.c -o pbr
	@mv pbr bin
	@echo MAKE Success: use \'make run\' to run

run:
	@./bin/pbr

clean:
	@rm bin/pbr
	@echo MAKE CLEAN Success: use \'make\' to get back
