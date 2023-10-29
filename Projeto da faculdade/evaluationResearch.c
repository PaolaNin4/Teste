#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[] = "C:\\Users\\willi\\OneDrive\\Área de Trabalho\\trabalho pim\\notas.csv";
    float nota1, nota2, nota3, media;

    // Solicitar notas ao usuário
    printf("1. Avalie as exposicoes apresentadas (0-10): ");
    scanf("%f", &nota1);

    printf("2. Como foi sua experiencia com a compra? (0-10): ");
    scanf("%f", &nota2);

    printf("3. Avalie sua experiência no museu em relação à infraestrutura (0-10): ");
    scanf("%f", &nota3);

    // Calcular a média das notas
    media = (nota1 + nota2 + nota3) / 3.0;

    // Abrir o arquivo CSV para escrita
    FILE *file = fopen(filename, "w");

    // Verificar se o arquivo foi aberto com sucesso
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escrever as médias no arquivo CSV
    fprintf(file, "Categoria,Nota\n");
    fprintf(file, "Qual exposicao você mais gostou?,%.2f\n", nota1);
    fprintf(file, "Como foi sua experiencia com a compra?,%.2f\n", nota2);
    fprintf(file, "Avalie sua experiência no museu em relação à infraestrutura,%.2f\n", nota3);
    fprintf(file, "Média das notas,%.2f\n", media);

    // Fechar o arquivo
    fclose(file);

    printf("Médias foram registradas com sucesso em %s.\n", filename);

    return 0;
}
