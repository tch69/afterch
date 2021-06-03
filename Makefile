SRC = L.c
CC ?= cc
PREFIX ?= ${HOME}/.local

all: L

L:	${SRC}
	${CC} ${SRC} -o L

clean:
	rm -f L

install: L
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp L ${DESTDIR}${PREFIX}/bin
	chmod +x ${DESTDIR}${PREFIX}/bin/L

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/L

.PHONY: all clean install uninstall
