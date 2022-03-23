.PHONY:all
all: my_cmd exec_cmd
my_cmd:my_cmd.c
	gcc $^ -o $@ -std=c99
exec_cmd:exec_cmd.c
	gcc $^ -o $@
.PHONY:clean
clean:
	rm -f my_cmd exec_cmd
