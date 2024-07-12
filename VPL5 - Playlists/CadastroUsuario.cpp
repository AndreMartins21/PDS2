#include "CadastroUsuario.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

CadastroUsuario::CadastroUsuario() {}

CadastroUsuario::~CadastroUsuario() {
    for (auto& pair : _playlists) {
        delete pair.second;
    }
}

void CadastroUsuario::adicionar_playlist(std::string nome) {
    if (_playlists.find(nome) == _playlists.end()) {
        _playlists[nome] = new Playlist(nome);
    }
}

void CadastroUsuario::adicionar_filme(std::string nome_playlist, std::string nome_filme, std::string genero_filme, int duracao_filme) {
    Playlist* playlist = encontrar_ou_criar_playlist(nome_playlist);
    playlist->adicionar_filme(nome_filme, genero_filme, duracao_filme);
}

void CadastroUsuario::remover_filme_por_nome(std::string nome_playlist, std::string nome_filme) {
    auto it = _playlists.find(nome_playlist);
    if (it != _playlists.end()) {
        it->second->remover_filme_por_nome(nome_filme);
    } else {
        std::cout << "Playlist nao encontrada: " << nome_playlist << "!" << std::endl;
    }
}

void CadastroUsuario::imprimir_detalhes_playlist(std::string nome_playlist, int tipo_ordenacao) {
    if (_playlists.empty()) {
        std::cout << "Nenhuma playlist cadastrada!" << std::endl;
        return;
    }

    auto it = _playlists.find(nome_playlist);
    if (it != _playlists.end()) {
        it->second->imprimir_playlist(tipo_ordenacao);
    } else {
        std::cout << "Playlist nao encontrada: " << nome_playlist << "!" << std::endl;
    }
}

void CadastroUsuario::imprimir_informacoes_gerais() {
    if (_playlists.empty()) {
        std::cout << "Nenhuma playlist cadastrada!" << std::endl;
        return;
    }

    std::vector<std::string> nomes_playlists;
    for (const auto& pair : _playlists) {
        nomes_playlists.push_back(pair.first);
    }
    std::sort(nomes_playlists.begin(), nomes_playlists.end());

    for (const auto& nome : nomes_playlists) {
        std::cout << "Playlist: " << nome << std::endl;
        _playlists[nome]->imprimir_playlist(0);
    }
}

Playlist* CadastroUsuario::encontrar_ou_criar_playlist(std::string nome_playlist) {
    auto it = _playlists.find(nome_playlist);
    if (it == _playlists.end()) {
        Playlist* nova_playlist = new Playlist(nome_playlist);
        _playlists[nome_playlist] = nova_playlist;
        return nova_playlist;
    }
    return it->second;
}