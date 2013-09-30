FLAGS=-lssl -lgmp -lcrypto -Wall -Wno-deprecated-declarations
W=-Wall -Wno-deprecated-declarations
RSA=RSA/rsalib.o
MD5=md5.o
all: rsasign rsaexec
clean:
	rm -rf rsasign rsaexec
	rm -rf $(RSA)
	rm -rf sign.o md5.o exec.o
rsasign: sign.o $(RSA) $(MD5)
	gcc $(FLAGS) -o rsasign sign.o $(RSA) $(MD5)
rsaexec: exec.o $(RSA) $(MD5)
	gcc $(FLAGS) -o rsaexec exec.o $(RSA) $(MD5)
sign.o: sign.c
	gcc $(W) -c -o sign.o sign.c
exec.o: exec.c
	gcc $(W) -c -o exec.o exec.c
md5.o: md5.c
	gcc $(W) -c -o md5.o md5.c
