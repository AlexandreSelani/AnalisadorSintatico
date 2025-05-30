#include "Anasin.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include "AUX.h"

    Anasin::Anasin(std::string nomeArqAnalex){
        this->nomeArqAnalex=nomeArqAnalex;
        arquivoAnalex.open(nomeArqAnalex);
             
        if(!arquivoAnalex.is_open()){
            std::cout<<"Erro na abertura do arquivo gerado pelo Analex";
        }
    }

    void Anasin::proximo(){
        arquivoAnalex >> palavra;
    }

    bool Anasin::ehReservada(){
        std::string temp;
        for(int i=0;i<palavra.length();i++){
            temp[i]=tolower(palavra[i]);
        }
        return verificaReservadas(temp);
    }

    
        