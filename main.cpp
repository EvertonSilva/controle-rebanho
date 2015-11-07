/**
 * Controle de Rebanhos
 *
 * O programa para controlar a entrada e saída
 * de rebanhos ovinos. Para isso o sistema deve
 * cumprir os seguintes requisitos:
 *
 * 1. Controlar o TIPO, ORIGEM, DESTINO do rebanho
 * 2. Armazenar a quantidade de animais de um determinado rebanho
 * 3. Calcular a produção de lã.
 * 4. Enviar rebanho para o Abate após 5 tosas consecutivas
 *
 * FATEC - MC - 07/11/2015
 * autor: Everton Silva http://evertonsilva.flavors.me
 */
#include <iostream>
// definições do programa
#define     LIMTE_VETORES       5                   // tamanho dos vetores TIPO, ORIGEM, DESTINO
//#define     MAX_REBANHOS        10                  // número máximo de linhas da matriz REBANHO

using namespace std;

// Função para preencher um vetor
// Parâmetros:
//   Entrada:
//      char vetRef[] - vetor de caracteres a ser preenchido
//   Retorno:
//      void - Não precisa retornar nenhum valor
void preencherVetor(char vetRef[])
{
    for (int i = 0; i < LIMTE_VETORES; i++)
    {
        vetRef[i] = (char)(i+65);           // 65 em decimal é equivalente ao caracter 'A' maiúsculo na tabela ASCII
                                            // (char)(i+65) converte o resultado da adição para caracter gerando:
                                            // A, B, C, D, E
    } // for
    return;
}
int main() {
    // 1. Controlar tipo, origem, destino
    //    Foi exigido que esse valores devem ser armazenados em 3 vetores distintos
    // 1.1. Atribuir valores quaisquer para definir:
    //      os tipos de ovinos
    //      os lugares de origem
    //      os lugares de destino
    char vetTipo[LIMTE_VETORES],
        vetOrigem[LIMTE_VETORES],
        vetDestino[LIMTE_VETORES];

    // chamar a função preenhcerVetor para inserir
    // os valore A,B,C,D,E nos vetores tipo, origem, destino
    preencherVetor(vetTipo);
    preencherVetor(vetOrigem);
    preencherVetor(vetDestino);


    return 0;
}