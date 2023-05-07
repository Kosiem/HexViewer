#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]){
    FILE *file = fopen(argv[1], "rb");
    if(file == NULL){
    	printf("Error occured, while opening file.)
	return 0;
    } 
    int numberOfLines;
    int group;
    char *line;
    printf("Specify how to group \n");
    scanf("%d", &group);
    line=malloc(sizeof(char) * group);
    printf("Loading file: %s\n", argv[1]);
    int i;
	int start = 0;
        while((numberOfLines= fread(line, 1 , group, file))){
		printf("%08x :", start);
		for(i = 0; i < numberOfLines; i++){
			if(i < group ){
				printf(" %02x ", line[i]);
			} else {
				printf("  ");
			
			}
		
		}
		printf("  ");
        	for(i = 0; i < group; i++){
			if(i < numberOfLines){	
				printf("%c", isprint(line[i]) ? line[i] : '.');
			}
			if(i == group) {
				break;
			
			}
		}

		
		printf("\n");
		start = start + group;
	}
       
    printf("Closing file: %s\n", argv[1]);
    fclose(file);
	free(line);
	return 0;
	       
}
