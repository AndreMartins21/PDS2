#include "venda.hpp"
#include <iostream>
#include <iomanip>

Venda::~Venda() {
    for (auto pedido : m_pedidos) {
        delete pedido;  // Libera cada pedido alocado dinamicamente
    }
    m_pedidos.clear();  // Limpa a lista de pedidos
}

void Venda::adicionaPedido(Pedido* p) {
    m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
    float totalVendas = 0.0;
    int numPedidos = 0;

    for (const auto& pedido : m_pedidos) {
        numPedidos++;
        std::cout << "Pedido " << numPedidos << std::endl;
        std::cout << pedido->resumo() << std::endl;
        totalVendas += pedido->calculaTotal();
    }

    std::cout << "Relatorio de Vendas" << std::endl;
    std::cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << totalVendas << std::endl;
    std::cout << "Total de pedidos: " << numPedidos << std::endl;
}