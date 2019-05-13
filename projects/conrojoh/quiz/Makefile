CFLAGS= -Wall -fpic -coverage -lm -std=c99

default: testme.c
	gcc -o testme -g testme.c  $(CFLAGS)
	./testme

testme: testme.c
	gcc -o testme -g testme.c  $(CFLAGS)
	./testme

coverage:
	gcc -ftest-coverage -fprofile-arcs -o coverage testme.c
	./coverage

cleantestme:
	rm testme *.gcov *.gcda *.gcno

cleancoverage:
	rm coverage *.gcov *.gcda *.gcno

cleanall:
	rm testme coverage *.gcov *.gcda *.gcno
