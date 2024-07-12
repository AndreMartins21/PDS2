#include "Filme.hpp"
#include <iostream>

// Construtor para inicialização dos atributos
Filme::Filme(std::string nome, std::string genero, int duracao)
    : _nome(nome), _genero(genero), _duracao(duracao) {}

// Método para imprimir os dados do filme
void Filme::imprimir_dados() const {
    std::cout << _nome << " (" << _genero << ")\t" << _duracao << "min" << std::endl;
}

// Métodos getters para acessar os atributos
std::string Filme::get_nome() const {
    return _nome;
}

std::string Filme::get_genero() const {
    return _genero;
}

int Filme::get_duracao() const {
    return _duracao;
}