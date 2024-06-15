SRC = L.c
CC ?= cc
PREFIX ?= /usr/local
CFLAGS = -std=c99 -g0 -flto -Wall -Wextra -pedantic
CPPFLAGS = -D_POSIX_SOURCE
LDFLAGS = -s -O3 -flto
CFADD =
LDADD =

SRCS = getuptime.c getsysname.c getkern.c
SRCS += main.c
OBJS = ${SRCS:.c=.o}

all: L

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} ${CFADD} $<

L:	${OBJS}
	${CC} -o L ${LDFLAGS} ${LDADD} ${OBJS}

clean:
	rm -f L ${OBJS}

install: L
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp L ${DESTDIR}${PREFIX}/bin
	chmod +x ${DESTDIR}${PREFIX}/bin/L

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/L

.PHONY: all clean install uninstall
