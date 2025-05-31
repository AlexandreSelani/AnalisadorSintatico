#pragma once
#include <fstream>
#include <string>
class Anasin{
    private:
        std::string nomeArqAnalex;
        std::ifstream arquivoAnalex;
        std::string palavra;
        int linhaAtual;

        void proximo();
        bool ehReservada();
    public:
        Anasin(std::string nomeArqAnalex);
        void program();
        bool identificador();
        void erro(std::string txt);
        void bloco();
        bool pontoEvirgula();
        bool virgula();
        void declaracaoDeVariaveis();
        void listaDeIdentificadores();
        bool doisPontos();
        bool tipo();
        void secaoDeParametrosFormais();
        void parametrosFormais();
        void declaracaoDeFuncao();
        void declaracaoDeProcedure();
};