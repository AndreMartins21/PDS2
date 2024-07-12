#include "pedido.hpp"
#include <sstream>

Pedido::~Pedido() {
    // Limpa a lista de produtos ao destruir o pedido
    for (auto produto : m_produtos) {
        delete produto;  // Certifique-se de liberar a memória alocada para cada produto
    }
    m_produtos.clear();  // Limpa a lista após liberar os produtos
}

void Pedido::setEndereco(const std::string& endereco) {
    m_endereco = endereco;
}

float Pedido::calculaTotal() const {
    float total = 0.0f;
    for (auto produto : m_produtos) {
        total += produto->getQtd() * produto->getValor();
    }
    return total;
}

void Pedido::adicionaProduto(Produto* p) {
    m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
    std::ostringstream oss;

    // Monta o resumo de cada produto no pedido
    for (auto produto : m_produtos) {
        oss << produto->descricao() << std::endl;
    }

    oss << "Endereco: " << m_endereco;

    return oss.str();
}