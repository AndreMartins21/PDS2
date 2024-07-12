#include "complexo.h"
#include <cmath>


void Complexo::calcularPolar(double real, double imag) {
    modulo_ = std::sqrt(real * real + imag * imag);
    argumento_ = std::atan2(imag, real);
}


double Complexo::calcularReal() const {
    return modulo_ * std::cos(argumento_);
}


double Complexo::calcularImag() const {
    return modulo_ * std::sin(argumento_);
}


Complexo::Complexo() : modulo_(0.0), argumento_(0.0) {
}


Complexo::Complexo(double a, double b) {
    calcularPolar(a, b);
}


double Complexo::real() {
    return calcularReal();
}


double Complexo::imag() {
    return calcularImag();
}


bool Complexo::igual(Complexo x) {
    return (modulo_ == x.modulo_) && (argumento_ == x.argumento_);
}


void Complexo::Atribuir(Complexo x) {
    modulo_ = x.modulo_;
    argumento_ = x.argumento_;
}


double Complexo::modulo() {
    return modulo_;
}


Complexo Complexo::conjugado() {
    return Complexo(calcularReal(), -calcularImag());
}


Complexo Complexo::simetrico() {
    return Complexo(-calcularReal(), -calcularImag());
}


Complexo Complexo::inverso() {
    double real = calcularReal();
    double imag = calcularImag();
    double denom = real * real + imag * imag;
    return Complexo(real / denom, -imag / denom);
}


Complexo Complexo::somar(Complexo y) {
    double real = calcularReal() + y.calcularReal();
    double imag = calcularImag() + y.calcularImag();
    return Complexo(real, imag);
}


Complexo Complexo::subtrair(Complexo y) {
    double real = calcularReal() - y.calcularReal();
    double imag = calcularImag() - y.calcularImag();
    return Complexo(real, imag);
}


Complexo Complexo::multiplicar(Complexo y) {
    double novoModulo = modulo_ * y.modulo_;
    double novoArgumento = argumento_ + y.argumento_;
    return Complexo(novoModulo * std::cos(novoArgumento), novoModulo * std::sin(novoArgumento));
}


Complexo Complexo::dividir(Complexo y) {
    double novoModulo = modulo_ / y.modulo_;
    double novoArgumento = argumento_ - y.argumento_;
    return Complexo(novoModulo * std::cos(novoArgumento), novoModulo * std::sin(novoArgumento));
}