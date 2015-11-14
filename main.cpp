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
// tamanho dos Vetores e Matrizes
#define     LIMTE_VETORES       5                   // tamanho dos vetores TIPO, ORIGEM, DESTINO
#define     MAX_REBANHOS        10                  // número máximo de linhas da matriz REBANHO
#define		LIMITE_TOSAS		5					// total de tosas para o rebanho
// propriedades dos rebanhos
#define     TIPO                0                   // código do tipo de overlha do rebanho
#define     ORIG                1                   // código de origem da ovelha
#define     QTDE                2                   // quantidade de ovelhas do rebanho
// definições do sistema
#define     LIMPATELA			system ("cls")
#define     PAUSE				system ("pause")

using namespace std;

// Função para preencher um vetor
// Parâmetros:
//   Entrada:
//      char vetRef[] - vetor de caracteres a ser preenchido
//   Retorno:
//      void - Não tem valor de retorno
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
// Função para exibir um vetor
// Parâmetros:
//   Entrada:
//      char vetRef[] - vetor de caracteres a ser exibido
//   Retorno:
//      void - Não tem valor de retorno
void exibirVetor(char vetRef[], char *msg)
{
	cout << msg;
	for (int i = 0; i < LIMTE_VETORES; i++)
	{
		cout << vetRef[i] << " ";
	}
}
// Funcao para encontrar a posição de um valor dentro de um vetor
// Parâmetros
//   Entrada:
//      char vetRef[] - vetor onde será feita a procura
//      char cValor   - valor a ser procurado
//   Retorno:
//      int i         - índice do valor encontrado
//      int -1        - retorna -1 caso o valor não exista no vetor
int retornarIndice(char vetRef[], char cValor)
{
    for(int i = 0; i < LIMTE_VETORES; i++)
    {
        if(vetRef[i] == cValor)             // o valor digitado existe no vetor?
            return i;                       // retorna o índice do valor digitado
    }

    return -1;                              // retorna -1 caso o valor digitado não exista no vetor
}
int main() {
    setlocale(LC_ALL, "portuguese_brazil");     // suporte para caracteres com acento

    // 1. Controlar tipo, origem, destino
    //    Exigência: Armazenamento os valores em 3 vetores distintos
    // 1.1. Atribuir valores quaisquer para definir:
    //      os tipos de ovinos
    //      os lugares de origem
    //      os lugares de destino
    char vetTipo[LIMTE_VETORES],
        vetOrigem[LIMTE_VETORES],
        vetDestino[LIMTE_VETORES],
        cOpcao,                             // variável para receber opção digitada pelo operador
        cTipoOvelha,                        // variável para receber o tipo digitado pelo operador
        cOrigem;                            // variável para receber a origem digitada pelo operador

    // 2. Armazenar quantidade de animais de um rebanho
    //
    //    Operador deverá digitar qual o tipo, qual a
    //    origem e a quantidade de ovelhas. A matriz
    //    deve armazenar apenas os códigos (índices)
    //    referentes ao tipo e origem do rebanho além
    //    da quantidade de animais
    int matRebanho[MAX_REBANHOS][3],
        codRebanho = 0;                     // codigo da próxima linha livre da matriz rebanho

    // chamar a função preenhcerVetor para inserir
    // os valore A,B,C,D,E nos vetores tipo, origem, destino
    preencherVetor(vetTipo);
    preencherVetor(vetOrigem);
    preencherVetor(vetDestino);

    // cabeçalho apenas para situar o operador =)
    cout << "\t\tFATEC-MOGI DAS CRUZES\n\tCONTROLE DE REBANHOS DE OVINOS\n" << endl;

    // menu simples
    while(true)
    {
		LIMPATELA;

        cout << "*** MENU DE OPERAÇÔES ***" << endl;

        cout << "1 - Cadastrar Rebanho" << endl
            << "2 - Tosar Rebanho" << endl
            << "3 - Enviar para Corte" << endl;

        cout << "Selecione uma opção, ou 0 para cancelar: ";
        cin >> cOpcao;

        switch(cOpcao)
        {
            case '1':
                // solicitar o Tipo de ovelha
				exibirVetor(vetTipo, "Tipos de ovelhas: ");						// exibir tipos de ovelhas
				cout << "\nDigite o Tipo de ovelha: ";
                cin >> cTipoOvelha;

                // solicitar a Origem da Ovelha
				exibirVetor(vetOrigem, "Origens do rebanho: ");					// exibir origem das ovelhas
                cout << "\nDigite a origem do rebanho: ";
                cin >> cOrigem;

                // solicitar a quantidade de ovelhas
                cout << "\nDigite a quantidade de ovelhas do rebanho: ";
                cin >> matRebanho[codRebanho][QTDE];

                matRebanho[codRebanho][TIPO] = retornarIndice(vetTipo, cTipoOvelha);
                matRebanho[codRebanho][ORIG] = retornarIndice(vetTipo, cOrigem);
                codRebanho++;
                break;
            case '2':
                break;
            case '3':
                break;
            case '0':
                cout << "Deseja realmente encerrar o programa? (S - sim, N - não): ";
                cin >> cOpcao;
                if(toupper(cOpcao) == 'S')
                    return 0;
                break;
            default:
                break;
        }
    }

}
