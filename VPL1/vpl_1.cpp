#include <iostream>

using namespace std;

int main() {
    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    int valor1;
    cin >> valor1;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int* ponteiro = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    int tamanho;
    cin >> tamanho;
    int vetor[tamanho];
    for (int i = 0; i < tamanho; ++i) {
        cin >> vetor[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    cout << &valor1 << endl;
    // 5) Imprima o VALOR da variável declarada em (1)
    cout << valor1 << endl;

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    cout << &ponteiro << endl;
    // 7) Imprima o VALOR da variável declarada em (2)
    cout << ponteiro << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    cout << vetor << endl;
    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    cout << &vetor[0] << endl;
    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    cout << vetor[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    ponteiro = &valor1;
    // 12) Imprima o VALOR da variável declarada em (2)
    cout << ponteiro << endl;
    // 13) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiro << endl;
    // 14) Compare ENDEREÇO de (1) e o VALOR de (2), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    cout << ((&valor1 == ponteiro) ? "S" : "N") << endl;

    // 15) Coloque o VALOR '5' no ENDEREÇO apontado por (2)
    *ponteiro = 5;
    // 16) Imprima o VALOR da variável declarada em (1)
    cout << valor1 << endl;

    // 17) Atribua o VALOR da variável (3) à variável declarada em (2)
    ponteiro = vetor;
    // 18) Imprima o VALOR da variável declarada em (2)
    cout << ponteiro << endl;
    // 19) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiro << endl;

    // 20) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    ponteiro = &vetor[0];
    // 21) Imprima o VALOR da variável declarada em (2)
    cout << ponteiro << endl;
    // 22) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiro << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < tamanho; ++i) {
        *(ponteiro + i) *= 10;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação []
    for (int i = 0; i < tamanho; ++i) {
        cout << vetor[i] << " ";
        if (i < tamanho-1) cout << " ";
    }
    cout << endl;

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    for (int i = 0; i < tamanho; ++i) {
        cout << *(vetor + i);
        if (i < tamanho-1) cout << " ";
    }
    cout << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    for (int i = 0; i < tamanho; ++i) {
        cout << *(ponteiro + i);
        if (i < tamanho-1) cout << " ";
    }
    cout << endl;

    // 27) Atribua o ENDEREÇO da quinta posição de (3) à variável declarada em (2)
    ponteiro = &vetor[4];
    // 28) Imprima o VALOR da variável declarada em (2)
    cout << ponteiro << endl;
    // 29) Imprima o VALOR guardado no ENDEREÇO apontado por (2)
    cout << *ponteiro << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int** ponteiroParaPonteiro = &ponteiro;
    // 31) Imprima o VALOR da variável declarada em (30)
    cout << *ponteiroParaPonteiro << endl;
    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    cout << &ponteiroParaPonteiro << endl;
    // 33) Imprima o VALOR guardado no ENDEREÇO apontado por (30)
    cout << *ponteiroParaPonteiro << endl;
    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    cout << *(*ponteiroParaPonteiro) << endl;

    return 0;
}
