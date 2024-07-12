#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "Filme.hpp"
#include <vector>
#include <string>

class Playlist {
private:
    std::string _nome;
    std::vector<Filme*> _filmes;

public:
    
    Playlist(std::string nome);

    
    ~Playlist();

    
    void adicionar_filme(std::string nome, std::string genero, int duracao);

    
    void remover_filme_por_nome(std::string nome);

    
    void imprimir_playlist(int tipo_ordenacao);

    
    std::string get_nome() const;

private:
    
    static bool comparar_nome(const Filme* f1, const Filme* f2);
    static bool comparar_duracao(const Filme* f1, const Filme* f2);
    std::string converter_tempo_total(int total_minutos);
};

#endif // PLAYLIST_HPP