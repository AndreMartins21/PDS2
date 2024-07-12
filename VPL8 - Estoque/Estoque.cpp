#include "Estoque.hpp"
#include <iostream>
#include <map>


void Estoque::add_mercadoria(const std::string& s, unsigned int qtd) {
    estoque[s] += qtd;
}

unsigned int Estoque::get_qtd(const std::string& s) const {
    auto it = estoque.find(s);
    if (it != estoque.end()) {
        return it->second;
    }
    return 0;
}

void Estoque::sub_mercadoria(const std::string& s, unsigned int qtd) {
    auto it = estoque.find(s);
    if (it != estoque.end()) {
        if (it->second < qtd) {
            std::cout << s << " insuficiente" << std::endl;
        } else {
            it->second -= qtd;
            if (it->second == 0) {
                estoque.erase(it);
            }
        }
    } else {
        std::cout << s << " inexistente" << std::endl;
    }
}

void Estoque::imprime_estoque() const {
    std::map<std::string, unsigned int> sortedestoque(estoque.begin(), estoque.end());
    for (const auto& item : sortedestoque) {
        std::cout << item.first << ", " << item.second << std::endl;
    }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
    for (const auto& item : rhs.estoque) {
        add_mercadoria(item.first, item.second);
    }
    return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
    for (const auto& item : rhs.estoque) {
        sub_mercadoria(item.first, item.second);
    }
    return *this;
}

bool operator < (Estoque& e0, Estoque& e1) {
    for (const auto& item : e0.estoque) {
        auto it = e1.estoque.find(item.first);
        if (it == e1.estoque.end() || it->second <= item.second) {
            return false;
        }
    }
    return true;
}

bool operator > (Estoque& e0, Estoque& e1) {
    for (const auto& item : e1.estoque) {
        auto it = e0.estoque.find(item.first);
        if (it == e0.estoque.end() || it->second <= item.second) {
            return false;
        }
    }
    return true;
}