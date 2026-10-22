#include <stdio.h>

int main(){
    FILE* fp;
    int a[3] = {0,1,2};
    char b[3] = "ABC";
    float c[3] = {1.1,1.2,1.3};
    int ra[3];
    char rb[3];
    float rc[3];
    
    fp = fopen("a.bin", "w+");
    fwrite(a, sizeof(a), 3, fp);
    fwrite(b, sizeof(b), 3, fp);
    fwrite(c, sizeof(c), 3, fp);
    fseek(fp, 0, SEEK_SET);
    fread(ra, sizeof(ra), 3, fp);
    fread(rb, sizeof(rb), 3, fp);
    fread(rc, sizeof(rc), 3, fp);
    
    for(int i=0;i<3;i++){
        printf("%d ", ra[i]);
    }
    printf("\n");
    for(int j=0;j<3;j++){
        printf("%c ", rb[j]);
    }
    printf("\n");
    for(int k=0;k<3;k++){
        printf("%1f ", rc[k]);
    }
    fclose(fp);
    return 0;
}
