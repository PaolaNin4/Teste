#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[] = "C:\\Users\\willi\\OneDrive\\�rea de Trabalho\\trabalho pim\\notas.csv";
    float nota1, nota2, nota3, media;

    // Solicitar notas ao usu�rio
    printf("1. Avalie as exposicoes apresentadas (0-10): ");
    scanf("%f", &nota1);

    printf("2. Como foi sua experiencia com a compra? (0-10): ");
    scanf("%f", &nota2);

    printf("3. Avalie sua experi�ncia no museu em rela��o � infraestrutura (0-10): ");
    scanf("%f", &nota3);

    // Calcular a m�dia das notas
    media = (nota1 + nota2 + nota3) / 3.0;

    // Abrir o arquivo CSV para escrita
    FILE *file = fopen(filename, "w");

    // Verificar se o arquivo foi aberto com sucesso
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escrever as m�dias no arquivo CSV
    fprintf(file, "Categoria,Nota\n");
    fprintf(file, "Qual exposicao voc� mais gostou?,%.2f\n", nota1);
    fprintf(file, "Como foi sua experiencia com a compra?,%.2f\n", nota2);
    fprintf(file, "Avalie sua experi�ncia no museu em rela��o � infraestrutura,%.2f\n", nota3);
    fprintf(file, "M�dia das notas,%.2f\n", media);

    // Fechar o arquivo
    fclose(file);

    printf("M�dias foram registradas com sucesso em %s.\n", filename);

    return 0;
}
