#pragma once

#include <string>
#include <fstream>
#include <unordered_map>
class Analex{
    private:
        std::string atomo;
        char proximo;
        int contadorLinhas=1;
        int contadorDeIdentificadores=0;
        std::string arquivoFonte;
        std::unordered_map<std::string, std::string> tabelaDeSimbolos;
        std::unordered_map<std::string, int> tabelaDeIdentificadores;
        std::ifstream programaFonte;
        std::ofstream programaEmCodigo;
        
        void pulaLinhas();
        void criaTabelaSimbolos();

        void traduzSimbolosEspeciais();
        void traduzNomes(std::string *token);
        void traduzNumeros(std::string *token);

        void PROXIMO();
        void ERRO();//TEM QUE MUDAR
        void CODIGO(std::string *token);

        

    public:
        void traducao();
        Analex(std::string arqFonte);
        void fechaArq();
        

};
