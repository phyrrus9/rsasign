#include "RSA/rsalib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

char * md5(char * filename)
{
    unsigned char c[MD5_DIGEST_LENGTH];
    char *hash = malloc(100);
    int i, offset;
    FILE *inFile = fopen (filename, "rb");
    MD5_CTX mdContext;
    int bytes;
    unsigned char data[1024];
    
    memset(hash, 0, 100);
    
    if (inFile == NULL) {
        printf ("%s can't be opened.\n", filename);
        return NULL;
    }
    
    MD5_Init (&mdContext);
    while ((bytes = fread (data, 1, 1024, inFile)) != 0)
        MD5_Update (&mdContext, data, bytes);
    MD5_Final (c,&mdContext);
    for(i = 0, offset = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        sprintf(hash + offset, "%c", c[i]);
        offset = strlen(hash);
    }
    fclose (inFile);
    return NULL;
}

int main(int argc, char * * argv)
{
    char * keyfilename = malloc(130);
    char * filename = malloc(130);
    char * tmpfilename = malloc(130);
    char * outfilename = malloc(130);
    FILE * hashfile;
    
    if (argc < 3)
    {
        printf("Error, usage: %s <key> <file>\n", argv[0]);
        return 0;
    }
    
    strcpy(keyfilename, argv[1]);
    strcpy(filename, argv[2]);
    sprintf(tmpfilename, "/tmp/%s.md5", filename);
    sprintf(outfilename, "%s.sig", filename);
    
    hashfile = fopen(tmpfilename, "wb");
    fprintf(hashfile, "%s", md5(filename));
    fclose(hashfile);
    
    rsa_encrypt_file(keyfilename, tmpfilename, outfilename);
}
