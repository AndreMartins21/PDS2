#include "Playlist.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>

Playlist::Playlist(std::string nome) : _nome(nome) {}

Playlist::~Playlist() {
    for (auto filme : _filmes) {
        delete filme;
    }
}

void Playlist::adicionar_filme(std::string nome, std::string genero, int duracao) {
    _filmes.push_back(new Filme(nome, genero, duracao));
}

void Playlist::remover_filme_por_nome(std::string nome) {
    auto it = std::find_if(_filmes.begin(), _filmes.end(),
        [&nome](Filme* filme) { return filme->get_nome() == nome; });

    if (it != _filmes.end()) {
        delete *it;
        _filmes.erase(it);
    } else {
        std::cout << "Filme nao encontrado: " << nome << "!" << std::endl;
    }
}

void Playlist::imprimir_playlist(int tipo_ordenacao) {
    if (_filmes.empty()) {
        std::cout << "Nenhum filme cadastrado na playlist: " << _nome << "!" << std::endl;
        return;
    }

    if (tipo_ordenacao == 0) {
        std::sort(_filmes.begin(), _filmes.end(), comparar_nome);
    } else if (tipo_ordenacao == 1) {
        std::sort(_filmes.begin(), _filmes.end(), comparar_duracao);
    }

    int tempo_total = 0;
    for (const auto& filme : _filmes) {
        filme->imprimir_dados();
        tempo_total += filme->get_duracao();
    }

    std::cout << "Tempo total: " << converter_tempo_total(tempo_total) << std::endl;
}

std::string Playlist::get_nome() const {
    return _nome;
}

bool Playlist::comparar_nome(const Filme* f1, const Filme* f2) {
    return f1->get_nome() < f2->get_nome();
}

bool Playlist::comparar_duracao(const Filme* f1, const Filme* f2) {
    return f1->get_duracao() < f2->get_duracao();
}

std::string Playlist::converter_tempo_total(int total_minutos) {
    int horas = total_minutos / 60;
    int minutos = total_minutos % 60;
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << horas << ":" << std::setw(2) << std::setfill('0') << minutos << "h";
    return oss.str();
}