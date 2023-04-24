#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]){
        FILE *plik = fopen(argv[1], "rb");
        int ilosclinii;
        char linia[6];
        int i;
        int ilosc = 0;
	int poczatek = 0;
        printf("Lodaing file: %s\n", argv[1]);
        while((ilosclinii = fread(linia, 1 , sizeof(linia), plik))){
		printf("%08x :", poczatek);
		for(i = 0; i < ilosclinii; i++){
			if(i < 6 ){
				printf(" %02x ", (unsigned char)linia[i]);
			} else {
				printf("  ");
			
			}
		
		}
		printf("  ");
        	for(i = 0; i < 6; i++){
			if(i < ilosclinii){	
				printf("%c", isprint(linia[i]) ? linia[i] : '.');
			}
			if(i == 5) {
				break;
			
			}
		}

		
		printf("\n");
		poczatek = poczatek + 6;
	}
       
        printf("Closing file: %s\n", argv[1]);
        fclose(plik);
        return 0;

}
