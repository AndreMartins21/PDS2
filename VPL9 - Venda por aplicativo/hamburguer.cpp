#include "hamburguer.hpp"
#include <sstream>

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario)
    : m_tipo(tipo), m_artesanal(artesanal) {
    m_qtd = qtd;
    m_valor_unitario = valor_unitario;
}

std::string Hamburguer::descricao() const {
    std::ostringstream oss;
    oss << m_qtd << "X Hamburguer ";
    if (m_artesanal) {
        oss << m_tipo << " artesanal.";
    } else {
        oss << m_tipo << " simples.";
    }
    return oss.str();
}