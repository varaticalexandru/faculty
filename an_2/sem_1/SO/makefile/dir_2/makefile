CC = gcc
CFLAGS = -g

#out_files = p1 p2 p3
obj_files = loh.result p1.o p2.o p3.o
src_files = loh.raw p1.c p2.c p3.c

all: $(obj_files)
.PHONY: all

$(filter %.o, $(obj_files)): %.o: %.c
	echo "target: $@ prereq: $<"

$

clean:
	rm -f *.o
