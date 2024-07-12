#ifndef FILME_HPP
#define FILME_HPP

#include <string>

class Filme {
private:
    std::string _nome;
    std::string _genero;
    int _duracao;

public:
    Filme(std::string nome, std::string genero, int duracao);

    void imprimir_dados() const;

    std::string get_nome() const;
    std::string get_genero() const; // Adicione esta linha
    int get_duracao() const;
};

#endif // FILME_HPP