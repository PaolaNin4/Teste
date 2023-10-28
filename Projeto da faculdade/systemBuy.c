#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Estrutura para representar um ingresso
struct Ticket {
    int ticketNumber;
    char visitorName[50];
    float price;
    char ticketType[20];
};

// Estrutura para registrar vendas por categoria de ingresso
struct SalesRecord {
    float fullPriceTotal;
    float studentDiscountTotal;
    float elderlyTotal;
};

// Função para salvar o valor somado de vendas por categoria em um arquivo
void saveSalesRecord(struct SalesRecord record) {
    FILE *file = fopen("C:\\Users\\willi\\OneDrive\\Área de Trabalho\\trabalho pim\\sales_record.txt", "w");
    if (file != NULL) {
        fprintf(file, "Total de vendas de Inteira (R$20.00): %.2f\n", record.fullPriceTotal);
        fprintf(file, "Total de vendas de Meia-entrada (Estudantes - R$10.00): %.2f\n", record.studentDiscountTotal);
        fprintf(file, "Total de vendas de Gratuidade (Idosos acima de 65 anos): %.2f\n", record.elderlyTotal);
        fclose(file);
    }
}

// Função para salvar a quantidade de ingressos vendidos em um arquivo
void saveTicketCount(int soldTickets) {
    FILE *file = fopen("C:\\Users\\willi\\OneDrive\\Área de Trabalho\\trabalho pim\\sold_tickets.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d", soldTickets);
        fclose(file);
    }
}

int main() {
    int maxTickets = 100;
    struct Ticket tickets[maxTickets];
    int numSoldTickets = 0;

    // Inicialize o registro de vendas
    struct SalesRecord salesRecord = {0.0, 0.0, 0.0};

    // Recupere a quantidade de ingressos vendidos a partir do arquivo (se existir)
    FILE *file = fopen("C:\\Users\\willi\\OneDrive\\Área de Trabalho\\trabalho pim\\sold_tickets.txt", "r");
    if (file != NULL) {
        fscanf(file, "%d", &numSoldTickets);
        fclose(file);
    }

    int choiceExhibition;
    char userInput[50]; // Variável para armazenar a entrada do usuário como string

    while (1) {
        printf("Bem-vindo ao Museu de Multitematico! Escolha o tipo de exposição que deseja adquirir: \n");
        printf("1. 150 Anos de Santos Dumont\n");
        printf("2. 100 Anos da semana da Arte Moderna\n");
        printf("3. Jogos Olímpicos Paris 2024\n");
        printf("4. IBM\n");
        printf("5. Todas as exposições\n");
        printf("6. Sair\n");
        printf("Escolha uma exposicao: ");

        // Lê a entrada do usuário como uma string
        scanf("%s", userInput);

        // Converte a entrada do usuário para um número inteiro
        choiceExhibition = atoi(userInput);

        if (choiceExhibition >= 1 && choiceExhibition <= 5) {
            // Adicione o código para lidar com as escolhas das exposições aqui
            // Certifique-se de controlar a quantidade de ingressos vendidos e atualizar o registro de vendas

            int choiceTicket;
            while (1) {
                printf("Escolha o tipo de ingresso:\n");
                printf("1. Inteira (R$20.00)\n");
                printf("2. Meia-entrada (Estudantes - R$10.00)\n");
                printf("3. Gratuidade (Idosos acima de 65 anos)\n");
                printf("4. Sair\n");
                printf("Escolha uma opcao: ");

                // Lê a entrada do usuário como uma string
                scanf("%s", userInput);

                // Converte a entrada do usuário para um número inteiro
                choiceTicket = atoi(userInput);

                if (choiceTicket >= 1 && choiceTicket <= 3) {
                    if (numSoldTickets < maxTickets) {
                        printf("Digite seu nome: ");
                        scanf("%s", tickets[numSoldTickets].visitorName);

                        // Adicione o código para lidar com os preços e a categorização dos ingressos
                        if (choiceTicket == 1) {
                            strcpy(tickets[numSoldTickets].ticketType, "Inteira");
                            tickets[numSoldTickets].price = 20.0; // Preço da inteira em reais
                            salesRecord.fullPriceTotal += 20.0; // Atualize o registro de vendas
                        } else if (choiceTicket == 2) {
                            strcpy(tickets[numSoldTickets].ticketType, "Meia-entrada (Estudante)");
                            tickets[numSoldTickets].price = 10.0; // Preço da meia-entrada em reais
                            salesRecord.studentDiscountTotal += 10.0; // Atualize o registro de vendas
                        } else if (choiceTicket == 3) {
                            int visitorAge;
                            printf("Digite sua idade: ");
                            scanf("%d", &visitorAge);
                            if (visitorAge > 65) {
                                strcpy(tickets[numSoldTickets].ticketType, "Gratuidade (Idoso)");
                                tickets[numSoldTickets].price = 0.0; // Gratuidade para idosos
                                salesRecord.elderlyTotal += 0.0; // Atualize o registro de vendas
                            } else {
                                printf("Você não tem direito a gratuidade.\n\n");
                                continue;
                            }
                        }

                        numSoldTickets++;
                        printf("Ingresso comprado com sucesso! O número do seu ingresso é %d.\n\n", numSoldTickets);
                    } else {
                        printf("Desculpe, todos os ingressos foram vendidos.\n\n");
                    }
                } else if (choiceTicket == 4) {
                    break;  // Sair do loop de escolha de ingressos
                } else {
                    printf("Opcao invalida. Tente novamente.\n\n");
                }
            }
        } else if (choiceExhibition == 6) {
            printf("Obrigado por visitar o Museu de Mainframes!\n");

            // Salve a quantidade total de ingressos vendidos e o registro de vendas antes de sair
            saveSalesRecord(salesRecord);
            saveTicketCount(numSoldTickets);

            break;
        } else {
            printf("Opcao invalida. Tente novamente.\n\n");
        }
    }

    return 0;
}
