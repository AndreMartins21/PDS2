#include "japonesa.hpp"
#include <sstream>

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario)
    : m_combinado(combinado), m_sushis(sushis), m_temakis(temakis), m_hots(hots) {
    m_qtd = qtd;
    m_valor_unitario = valor_unitario;
}

std::string Japonesa::descricao() const {
    std::ostringstream oss;
    oss << m_qtd << "X Comida japonesa - " << m_combinado << ", "
        << m_sushis << " sushis, "
        << m_temakis << " temakis e "
        << m_hots << " hots.";
    return oss.str();
}