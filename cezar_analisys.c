#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 100
#define ALPHA_LENGTH 26
#define COMMON

//(str[i] - 'a' + key) % 26 + 'a';
char *ceasar_dechipher(char *cipher, int key)
{
    int lenght = strlen(cipher);
    char *plaintext = (char *)malloc(sizeof(char) + (lenght + 1));
    for (int i = 0; i < lenght; i++)
    {
        if (cipher[i] >= 'a' && cipher[i] <= 'z')
        {
            plaintext[i] = ((cipher[i] - 'a') - key + 26) % 26 + 'a';
        }

        else if (cipher[i] >= 'A' && cipher[i] <= 'Z')
        {
            plaintext[i] = ((cipher[i] - 'A') - key + 26) % 26 + 'A';
        }
        else if (cipher[i] >= '0' && cipher[i] <= '9')
        {
            plaintext[i] = ((cipher[i] - '0') - key + 10) % 10 + '0';
        }
        else
        {
            plaintext[i] = cipher[i];
        }
    }

    plaintext[lenght] = '\0';
    return plaintext;
}

int* count_frequencies(char*cipher) {
    int*frequecy = (int*) malloc(sizeof(int)* ALPHA_LENGTH);
    memset(frequecy, 0, sizeof(int) ALPHA_LENGTH);

    int length = strlen (cipher);
    for(int i=0; i<length; i++) {
        char letter = tolower(cipher[i]);
        if (letter >= 'a' && letter <= 'z') {
            int position = letter - 'a';
            frequecy[position]++;
        }
    }
    return frequecy;
}

int get_max_index(int* frequecy) {
    int max_index = 0;
    for (int i =0; i<ALPHA_LENGTH; i++)
    if (frequecy[i]> frequecy[max_index]) {
        man_index = i;
    }
}
return max_index;
}

int read_cipher(char* filename, char*cipher)
{
    FILE *fp=fopen(filename, "r");
    if(fp==NULL){
        printf("error opening the file.");
        return EXIT_SUCCESS;
    }

    if(fgets(cipher, MAXN, fp) == NULL)
    {
        printf("Error reading from file.");
        return EXIT_SUCCESS;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void write_file(char* filename, char*txt){
    FILE *fp=fopen (filename, "wb");
    fprintf(fp, "%s", txt);
    fclose(fp);
}



int main()
{
    //char cipher[MAXN];
    char filename[MAXN];
    //fgets(cipher, MAXN,stdin);
    scanf("%s", filename);
    char cipher[MAXN];
    read_cipher(filename,cipher);

    int key;
    scanf("%d", &key);
    char *plaintext = ceasar_dechipher(cipher, key);
    printf("%s", plaintext);
    write_file("plaintext.txt", plaintext);
    free(plaintext);
    return EXIT_SUCCESS;
}
