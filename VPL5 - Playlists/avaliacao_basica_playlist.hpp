#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include "CadastroUsuario.hpp"

using namespace std;

void avaliacao_basica() {
    
    CadastroUsuario cadastro;

    cout << "----------" << endl;

    cadastro.imprimir_informacoes_gerais();

    cout << "----------" << endl;

    cadastro.adicionar_playlist("PB");
    cadastro.adicionar_playlist("PA");
    cadastro.imprimir_informacoes_gerais();

    cout << "----------" << endl;

    cadastro.adicionar_filme("PA", "FB", "G", 25);
    cadastro.adicionar_filme("PA", "FA", "G", 35);
    cadastro.imprimir_detalhes_playlist("PA", 0);

    cout << "----------" << endl;

    cadastro.imprimir_detalhes_playlist("PA", 1);

    cout << "----------" << endl;

    cadastro.adicionar_filme("PB", "FB", "G", 35);
    cadastro.adicionar_filme("PB", "FA", "G", 25);
    cadastro.imprimir_informacoes_gerais();

    cout << "----------" << endl;

    cadastro.remover_filme_por_nome("PA", "FB");
    cadastro.remover_filme_por_nome("PB", "FA");

    cadastro.imprimir_informacoes_gerais();

    cout << "----------" << endl;

    cadastro.remover_filme_por_nome("PA", "FB");
    cadastro.remover_filme_por_nome("PB", "FA");

    cout << "----------" << endl;

}

#endif