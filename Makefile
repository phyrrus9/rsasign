FLAGS=-lssl -lgmp -lcrypto -Wall -Wno-deprecated-declarations
W=-Wall -Wno-deprecated-declarations
RSA=RSA/rsalib.o
all: rsasign
clean:
	rm -rf rsasign
	rm -rf $(RSA)
	rm -rf sign.o
rsasign: sign.o $(RSA)
	gcc $(FLAGS) -o rsasign sign.o $(RSA)
sign.o: sign.c
	gcc $(W) -c -o sign.o sign.c
