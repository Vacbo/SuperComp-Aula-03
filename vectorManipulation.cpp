#include <iostream>
#include <vector>

class Vector {
public:
    Vector(int tamanho);
    ~Vector();
    void inicializa(int valor);
    int get(int index) const;
    void set(int index, int valor);
    void inserir(int index, int valor);
    void remover(int index);
    void imprime() const;

private:
    int* dados;
    int tam;
    int capacidade;
    void redimensiona(int novaCapacidade);
};

// Construtor
Vector::Vector(int tamanho) {
    tam = tamanho;
    capacidade = tamanho;
    dados = new int[capacidade];
}

// Destrutor
Vector::~Vector() {
    delete[] dados;
}

// Implementação das funções...

void Vector::inicializa(int valor) {
    for (int i = 0; i < tam; i++) {
        dados[i] = valor;
    }
}

int Vector::get(int index) const {
    if (index < 0 || index >= tam) {
        std::cerr << "Erro: índice inválido" << std::endl;
        return -1;  // ou outro valor que indique erro
    }
    return dados[index];
}

void Vector::set(int index, int valor) {
    if (index < 0 || index >= tam) {
        std::cerr << "Erro: índice inválido" << std::endl;
        return;
    }
    dados[index] = valor;
}

void Vector::inserir(int index, int valor) {
    if (index < 0 || index > tam) {
        std::cerr << "Erro: índice inválido" << std::endl;
        return;
    }

    if (tam == capacidade) {
        redimensiona(2 * capacidade);
    }

    for (int i = tam; i > index; i--) {
        dados[i] = dados[i - 1];
    }

    dados[index] = valor;
    tam++;
}

void Vector::remover(int index) {
    if (index < 0 || index >= tam) {
        std::cerr << "Erro: índice inválido" << std::endl;
        return;
    }

    for (int i = index; i < tam - 1; i++) {
        dados[i] = dados[i + 1];
    }

    tam--;

    if (tam > 0 && tam == capacidade / 4) {
        redimensiona(capacidade / 2);
    }
}

void Vector::redimensiona(int novaCapacidade) {
    int* novosDados = new int[novaCapacidade];
    for (int i = 0; i < tam; i++) {
        novosDados[i] = dados[i];
    }
    delete[] dados;
    dados = novosDados;
    capacidade = novaCapacidade;
}

void Vector::imprime() const {
    for (int i = 0; i < tam; i++) {
        std::cout << dados[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Vector vec(5);
    vec.inicializa(0);
    vec.imprime();

    return 0;
}
