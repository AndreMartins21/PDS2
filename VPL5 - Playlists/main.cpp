#include <iostream>
#include <sstream>
#include "CadastroUsuario.hpp"
#include "avaliacao_basica_playlists.hpp"

int main() {
    CadastroUsuario usuario;
    std::string linha;

    while (std::getline(std::cin, linha)) {
        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando == "p") {
            std::string nome_playlist;
            iss >> nome_playlist;
            usuario.adicionar_playlist(nome_playlist);
        } else if (comando == "f") {
            std::string nome_playlist, nome_filme, genero_filme;
            int duracao_filme;
            iss >> nome_playlist >> nome_filme >> genero_filme >> duracao_filme;
            usuario.adicionar_filme(nome_playlist, nome_filme, genero_filme, duracao_filme);
        } else if (comando == "d") {
            std::string nome_playlist;
            int tipo_ordenacao;
            iss >> nome_playlist >> tipo_ordenacao;
            usuario.imprimir_detalhes_playlist(nome_playlist, tipo_ordenacao);
        } else if (comando == "r") {
            std::string nome_playlist, nome_filme;
            iss >> nome_playlist >> nome_filme;
            usuario.remover_filme_por_nome(nome_playlist, nome_filme);
        } else if (comando == "g") {
            usuario.imprimir_informacoes_gerais();
        } else if (comando == "b") {
            avaliacao_basica();
        } else {
            std::cerr << "Comando inválido!" << std::endl;
        }
    }

    return 0;
}