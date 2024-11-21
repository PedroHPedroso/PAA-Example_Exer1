#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char BruteForce(char *t, int n, char *p, int m) {
    for(int i = 0; i <= n - m; i++) {
        int j = 0;

        while(j < m && t[i + j] == p[j]) {
            j++;
        }

        if(j == m){
                printf("Padrao \"%s\" encontrado na posicao [%d].\n", p, i);
            return 1;
        }
    }
        printf("Padrao P nao encontrado no texto T.\n");
        return 0;
}


    int main(){
        char *text = (char*)malloc(255 * sizeof(char)); 
        char *pattern = (char*)malloc(255 * sizeof(char));

        printf("Indique o texto/string:\n");
        fgets(text,255,stdin);
        text[strcspn(text, "\n")] = '\0';

        printf("Indique o padrao a ser procurado no texto:\n");
        fgets(pattern,255,stdin);
        pattern[strcspn(pattern, "\n")] = '\0';

        int x = strlen(text);
        int y = strlen(pattern);

        BruteForce(text, x, pattern, y);

        free(text);
        free(pattern);

        return 0;
    }
