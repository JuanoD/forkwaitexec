objmaxrand:
	gcc -c maxrand.c
libmaxrand: objmaxrand
	ar rc libmaxrand.a maxrand.o
main: libmaxrand
	gcc -L . mainmaxrand.c -o demomaxrand -lmaxrand
clean:
	rm -f maxrand.o libmaxrand.a demomaxrand