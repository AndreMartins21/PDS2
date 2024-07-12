#include "pizza.hpp"
#include <sstream>

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario)
    : m_sabor(sabor), m_pedacos(pedacos), m_borda_recheada(borda_recheada) {
    m_qtd = qtd;
    m_valor_unitario = valor_unitario;
}

std::string Pizza::descricao() const {
    std::ostringstream oss;
    oss << m_qtd << "X Pizza " << m_sabor << ", " << m_pedacos << " pedacos";
    if (m_borda_recheada) {
        oss << " e borda recheada.";
    } else {
        oss << " e sem borda recheada.";
    }
    return oss.str();
}