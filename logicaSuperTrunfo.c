#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// Desafio escolhido: nível aventureiro
// Defini a estrutura da carta
typedef struct
    {
        char codigo_carta[4];
        char cidade[30];
        char estado[2];
        int populacao;
        float area;
        float pib;
        int numero_pontos_turisticos;

    } Carta;

// Função para calcular densidade populacional
float densidade_populacional(Carta carta)
    {
        return (carta.area != 0) ? carta.populacao / carta.area : 0;  // Evita divisão por zero
    }

// Função para calcular pib per capita
float pib_per_capita(Carta carta)
    {
        return (carta.populacao != 0) ? carta.pib * 1000000000 / carta.populacao : 0;  // Evita divisão por zero
    }

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    int opcao;

    // Loop para exibir o menu até que o usuário escolha sair
    while (1)
    {
        printf("\nMenu Principal - Jogo Super Trunfo Países\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Ver Regras\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Iniciando o jogo...\n");

            int atributo;
            do
            {
                printf("\n1. População\n");
                printf("2. Área\n");
                printf("3. PIB\n");
                printf("4. Número de pontos turísticos\n");
                printf("5. Densidade Populacional\n");
                printf("6. PIB Per Capita\n");
                printf("Escolha um dos atributos acima: ");

                if (scanf("%d", &atributo) != 1) { // Verifica se a entrada é válida
                    printf("Entrada inválida! Digite um número entre 1 e 6.\n");
                    while (getchar() != '\n'); // Limpa o buffer do teclado
                    continue;
                }
                // Verifica se o atributo está fora do intervalo de 1 até 6, que são as opções de escolha
                if (atributo < 1 || atributo > 6)
                {
                    printf("Opção inválida! Escolha um número entre 1 e 6.\n");
                }

            } while (atributo < 1 || atributo > 6);

            printf("Você escolheu o atributo para comparar: %d.\n", atributo);

            // Definição das cartas 1 e 2 e captura de entradas do usuário
            Carta carta1, carta2;
            printf("\nBem-vindo ao jogo Super Trunfo\n");
            printf("Digite os dados da primeira carta:\n");

            printf("Código da carta (Uma letra de A a H + 0 + Um numero de 1 a 4. Ex: A01): ");
            scanf("%3s", carta1.codigo_carta);
            carta1.codigo_carta[0] = toupper(carta1.codigo_carta[0]);

            printf("Estado (Uma letra de A a H): ");
            scanf("%1s", carta1.estado);
            carta1.estado[0] = toupper(carta1.estado[0]);

            printf("Nome da cidade: ");
            scanf(" %29[^\n]", carta1.cidade);  // Permite espaços na entrada

            printf("População: ");
            scanf("%d", &carta1.populacao);

            printf("Área (km²): ");
            scanf("%f", &carta1.area);

            printf("PIB (Em bilhões): ");
            scanf("%f", &carta1.pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &carta1.numero_pontos_turisticos);

            // Calcula a densidade populacional e pib per capita da carta 1
            float dp1 = densidade_populacional(carta1);
            float ppc1 = pib_per_capita(carta1);

            printf("\nDigite os dados da segunda carta:\n");

            printf("Código da carta (Uma letra de A a H + 0 + Um numero de 1 a 4. Ex: A02): ");
            scanf("%3s", carta2.codigo_carta);
            carta2.codigo_carta[0] = toupper(carta2.codigo_carta[0]);

            printf("Estado (Uma letra de A a H): ");
            scanf("%1s", carta2.estado);
            carta2.estado[0] = toupper(carta2.estado[0]);

            printf("Nome da cidade: ");
            scanf(" %29[^\n]", carta2.cidade);  // Permite espaços na entrada

            printf("População: ");
            scanf("%d", &carta2.populacao);

            printf("Área (km²): ");
            scanf("%f", &carta2.area);

            printf("PIB (Em bilhões): ");
            scanf("%f", &carta2.pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &carta2.numero_pontos_turisticos);

            // Calcula a densidade populacional e pib per capita da carta 2
            float dp2 = densidade_populacional(carta2);
            float ppc2 = pib_per_capita(carta2);

            printf("\n--- Cartas Cadastradas ---\n");
            printf("Carta 1\nCódigo: %s\nCidade: %s\nEstado: %s\nPopulação: %d\nÁrea: %.2f km2\nPIB: R$ %.2f bilhões\nPontos turísticos: %d\nDensidade Populacional: %.2f hab/km2\nPib Per Capita: R$ %.2f\n",
                   carta1.codigo_carta, carta1.cidade, carta1.estado, carta1.populacao, carta1.area, carta1.pib, carta1.numero_pontos_turisticos, dp1, ppc1);
            printf("----------------------------\n");
            printf("Carta 2\nCódigo: %s\nCidade: %s\nEstado: %s\nPopulação: %d\nÁrea: %.2f km2\nPIB: R$ %.2f bilhões\nPontos turísticos: %d\nDensidade Populacional: %.2f hab/km2\nPib Per Capita: R$ %.2f\n",
                   carta2.codigo_carta, carta2.cidade, carta2.estado, carta2.populacao, carta2.area, carta2.pib, carta2.numero_pontos_turisticos, dp2, ppc2);
            printf("\n--- Carta Vencedora ---\n");
            // Verifica qual carta ganhou de acordo com o atributo escolhido
            switch (atributo)
            {
            case 1:
                if (carta1.populacao > carta2.populacao)
                {
                    printf("A Carta 1 venceu a Carta 2 pelo atributo: população\n");
                }
                else
                {
                    printf("A Carta 2 venceu a Carta 1 pelo atributo: população\n");
                }
                break;
            case 2:
                if (carta1.area > carta2.area)
                {
                    printf("A Carta 1 venceu a Carta 2 pelo atributo: área\n");
                }
                else
                {
                    printf("A Carta 2 venceu a Carta 1 pelo atributo: área\n");
                }
                break;
            case 3:
                if (carta1.pib > carta2.pib)
                {
                    printf("A Carta 1 venceu a Carta 2 pelo atributo: PIB\n");
                }
                else
                {
                    printf("A Carta 2 venceu a Carta 1 pelo atributo: PIB\n");
                }
                break;
            case 4:
                if (carta1.numero_pontos_turisticos > carta2.numero_pontos_turisticos)
                {
                    printf("A Carta 1 venceu a Carta 2 pelo atributo: número de pontos turísticos\n");
                }
                else
                {
                    printf("A Carta 2 venceu a Carta 1 pelo atributo: número de pontos turísticos\n");
                }
                break;
            case 5:
                if (dp1 < dp2)  // A menor densidade populacional vence
                {
                    printf("A Carta 1 venceu a Carta 2 pelo atributo: densidade populacional\n");
                }
                else
                {
                    printf("A Carta 2 venceu a Carta 1 pelo atributo: densidade populacional\n");
                }
                break;
            case 6:
                if (ppc1 > ppc2)
                {
                    printf("A Carta 1 venceu a Carta 2 pelo atributo: PIB per capita\n");
                }
                else
                {
                    printf("A Carta 2 venceu a Carta 1 pelo atributo: PIB per capita\n");
                }
                break;
            default:
                printf("Atributo não permitido\n");
                break;
            }
            break;
        case 2:
            printf("Regras do Jogo:\n");
            printf("\n1. Você e um amigo cadastram 2 cartas de cidades de algum país com os atributos pedidos;\n");
            printf("\n2. A carta que tiver o maior valor vence o jogo nos seguintes atributos: população, área, PIB, número de pontos turísticos e PIB per capita;\n");
            printf("\n3. Caso o atributo de comparação seja a densidade populacional, vence a que tiver o menor valor.\n");
            break;
        case 3:
            printf("Saindo do jogo...\n");
            return 0; // Sai completamente do programa
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
