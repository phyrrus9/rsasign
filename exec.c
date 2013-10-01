#include "RSA/rsalib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "md5.h"
#include <sys/stat.h>

extern int execl(const char *path, const char *arg0, ... /*, (char *)0 */);

#define syskey "sys." //these will change
#define sigkey "sig.pub"

bool exists(char * filename)
{
    FILE * f = fopen(filename, "r");
    if (f)
    {
        fclose(f);
        return true;
    }
    return false;
}

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
    sprintf(tmpfilename, "/tmp/%s.md5chk", filename);
    sprintf(outfilename, "%s.sig", filename);

    if (!exists(outfilename))
    {
        printf("Error, no file exists\n");
        return 1;
    }
    if (!exists(filename))
    {
        printf("Error, no file exists\n");
        return 1;
    }

    char * fkey = lutil_md5_file(filename, buf);
    rsa_decrypt_file(sigkey, outfilename, tmpfilename);
    hashfile = fopen(tmpfilename, "rb");
    memset(buf, 0, 1024);
    fscanf(hashfile, "%s", buf);
    fclose(hashfile);
    if (!fkey)
        return -1;
    if (strcmp(fkey, buf) == 0)
        printf("Success!\n");
    rsa_decrypt_file(syskey, filename, "/tmp/code");
    chmod("/tmp/code", S_IXUSR | S_IXGRP | S_IXOTH);
    execl("/tmp/code", "/tmp/code", "OK", NULL); //execute the code and delete the file
}
