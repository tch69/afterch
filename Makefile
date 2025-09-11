CC 	?= cc
PREFIX 	?= /usr/local
CFLAGS 	= -O3 -march=native -pedantic
LDFLAGS = -O3 -s

SRCS = getuptime.c getsysname.c getkernver.c main.c
OBJS = ${SRCS:.c=.o}

all: afterch

.c.o:
	${CC} -c ${CFLAGS} ${CPPFLAGS} ${CFADD} $<

afterch: ${OBJS}
	${CC} -o afterch ${LDFLAGS} ${LDADD} ${OBJS}

clean:
	rm -f afterch ${OBJS}

install: afterch
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp afterch ${DESTDIR}${PREFIX}/bin
	chmod +x ${DESTDIR}${PREFIX}/bin/afterch

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/afterch

.PHONY: all clean install uninstall
