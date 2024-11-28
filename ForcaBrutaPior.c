#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BruteForce(char *t, int n, char *p, int m) {
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && t[i + j] == p[j]) {
            j++;
        }

        if (j == m) {
            printf("Padrao \"%s\" encontrado na posicao [%d].\n", p, i);
            return 1;
        }
    }

    printf("Padrao \"%s\" nao encontrado no texto.\n", p);
    return 0;
}

int main() {
    FILE *arq = fopen("piorCaso.txt", "r");

    char *text = (char *)malloc(1024 * sizeof(char)); 
    if (fgets(text, 1024, arq) == NULL) {
        printf("Erro ao ler o conteudo do arquivo.\n");
        fclose(arq);
        free(text);
        return 1;
    }

    text[strcspn(text, "\n")] = '\0'; 

    fclose(arq); 

    char *pattern = (char *)malloc(255 * sizeof(char)); 
    printf("Indique o padrao a ser procurado no texto:\n");
    fgets(pattern, 255, stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; 

    int x = strlen(text);
    printf("%d\n",x);
    int y = strlen(pattern);

    BruteForce(text, x, pattern, y);

    free(text);
    free(pattern);

    return 0;
}
