.PHONY:all
all: exec_cmd mycmd
mycmd:mycmd.c
	gcc $^ -o $@ -std=c99
exec_cmd:exec_cmd.c
	gcc $^ -o $@ -std=c99
.PHONY:clean
clean:
	rm -f exec_cmd mycmd
