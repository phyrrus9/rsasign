#include "RSA/rsalib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "md5.h"

#define sigkey "sig.pri" //these will change

int main(int argc, char * * argv)
{
    char * filename = malloc(130);
    char * tmpfilename = malloc(130);
    char * outfilename = malloc(130);
    FILE * hashfile;
    char * buf = malloc(1024);

    if (argc < 2)
    {
        printf("Error, usage: %s <file>\n", argv[0]);
        return 0;
    }

    strcpy(filename, argv[1]);
    sprintf(tmpfilename, "/tmp/%s.md5", filename);
    sprintf(outfilename, "%s.sig", filename);

    hashfile = fopen(tmpfilename, "wb");
    fprintf(hashfile, "%s", lutil_md5_file(filename, buf));
    fclose(hashfile);

    rsa_encrypt_file(sigkey, tmpfilename, outfilename);
}
