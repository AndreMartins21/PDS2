#include "google_password.h"
#include <string>
#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  Usuario user;
  user.login = login;
  user.password = password;
  
  if (
    this->passwords_.find(url) == this->passwords_.end()
    && this->validPassword(password)
  ){
    this->passwords_[url] = user;
  }
}

void GooglePassword::remove(const std::string& url) {
  if (this->passwords_.find(url) != this->passwords_.end()){
    this->passwords_.erase(url);
  }
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  /**
   * Este metodo nao pode inserir novas credenciais, apenas atualizar as
   * ja existentes. Alem disso, o login e/ou senha do usuario so podem ser
   * atualizados se a senha armazenada no sistema for igual a old_password.
   * Nao esqueca de verificar se o novo password tambem e valido.
   */
  
  if (
    this->passwords_.find(url) != this->passwords_.end() 
    && this->passwords_[url].password == old_password
    && this->validPassword(new_password)
  ) {
    this->passwords_[url].login = login;
    this->passwords_[url].password = new_password;
  } 
}

void GooglePassword::printPasswords() {
  /**
   * Exemplo de saida:
   * 3
   * aaa.site.com: login and password
   * www.site.com: login and password
   * zzz.site.com: login and password
   *
  */
  std::cout << this->passwords_.size() << std::endl;

  for (const auto& pair: this->passwords_){
    string url = pair.first;
    Usuario user = pair.second;

    std::cout << url << ": " << user.login << " and " << user.password << std::endl;
  }
}

bool GooglePassword::validPassword(const std::string& password) const {
  /*
  Senhas inválidas:
  - Contenha a sequência '123456'
  - Caractéres em branco
  - Possuir menor do que 6 ou mais que 50 caractéres
  */
  if(
      password.find("123456") == std::string::npos
      && password.find(" ") == std::string::npos
      && password.length() >= 6 
      && password.length() <= 50
  ){
      return true;
  }
  return false;
}