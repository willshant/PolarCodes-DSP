#include "polarDecode.h"
double before_dec[codeLen];
char dec[randLen];

void main(){
    FILE *rFile, *wFile;
    int i, j;
    rFile = fopen("decInput.dat","rb");
    wFile = fopen("dec.dat","wb");

    for(i=0;i<frame;i++)    {
        fread(before_dec, 8, codeLen, rFile);
        polarDec(before_dec, dec);
        fwrite(dec, 1, randLen, wFile);
        for(j=0;j<randLen;j++)
            printf("%d\t", dec[j]);
        printf("\n");
    }

    fclose(rFile);
    fclose(wFile);
}
