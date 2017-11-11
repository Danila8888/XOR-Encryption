#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
char *text, key, x, filename[20];
int dltext, i, kint, input;
FILE *file;
printf("What do you want?\n");
printf("1.Shifr\n");
printf("2.Deshifr\n");
printf("3.Exit\n");
scanf("%d", &input);
switch (input) {
	case 1:
		printf("Enter your key: ");
		scanf("%d", &key);
		printf("Enter file name: ");
		scanf("%s", filename);
		printf("Tekst: ");
		scanf("%s", text);
		dltext = strlen(text);
		if((file = fopen(filename,"w"))==NULL) {
			printf("Ошибка при открытии файла.\n");
			exit(1);
		}
		else {
			for (i=0;i<dltext;i++) {
				x = text[i]^key;
				fprintf(file, "%c", x);
			}
		}
		fclose(file);
		break;
	case 2:
		printf("Enter file name: ");
		scanf("%s", filename);
		printf("Key ");
		scanf("%d", &key);
		if((file = fopen(filename,"r+"))==NULL) {
			printf("Ошибка при открытии файла.\n");
			exit(2);
		}
		else {
			fseek(file , 0 , SEEK_END);
			long lSize = ftell(file);
			rewind (file);
			char * buffer = (char*) malloc(sizeof(char) * lSize);
			if (buffer == NULL) {
				fputs("Ошибка памяти", stderr);
				exit(3);
			}
			fread(buffer, 1, lSize, file);
			dltext = strlen(buffer);
			for (i=0;i<dltext;i++){
				kint = buffer[i];
				x = (kint^key);
				printf("%c", x);
			}
		}
		fclose(file);
		break;
	case 3: 
		break;
	}
return 0;
}
