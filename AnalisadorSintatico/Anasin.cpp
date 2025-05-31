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
        else{
            proximo();
            program();
        }
    }

    void Anasin::proximo(){
        arquivoAnalex >> palavra;
        if(verificaSeEhDigito(palavra)){
            linhaAtual = stoi(palavra);
            proximo();
        }
        
    }

    bool Anasin::ehReservada(){
        std::string temp;
        for(int i=0;i<palavra.length();i++){
            temp[i]=tolower(palavra[i]);
        }
        return verificaReservadas(temp);
    }

    void Anasin::erro(std::string txt = ""){
        std::cout << "Erro na linha "<< linhaAtual <<": " << txt << std::endl;
        exit(1);
    }

    bool Anasin::identificador(){
        if(!(palavra[0]='i' && palavra[1]=='d' && isdigit(palavra[2]))){
            return false;
        }
        else return true;
    }

    bool Anasin::pontoEvirgula(){
        if(palavra!="PV"){return false;}
        return true;
    }
    bool Anasin::virgula(){
        if(palavra!="V") return false;
        return true;
    }
    void Anasin::program(){
        if(palavra=="PROGRAM"){
            proximo();
            if(!identificador()){
                erro("esperado identificador");
                
            }
            proximo();
            if(!pontoEvirgula()) erro("esperando ';'");
            proximo();
            bloco();
        }
        else erro("Nao comeca com PROGRAM");
    }
    
    bool Anasin::doisPontos(){
        if(palavra=="DOISP") return true;
        return false;

    }

    bool Anasin::tipo(){
        if(palavra=="INTEGER" || palavra=="BOOLEAN") return true;
        return false;
    }
    void Anasin::declaracaoDeVariaveis(){
        
        listaDeIdentificadores();
        

        if(!doisPontos()) erro("Esperando ':'");
        proximo();

        if(!tipo()) erro("tipo desconhecido");
        proximo();
        if(!pontoEvirgula()) erro("Esperava ';'");
    }

    void Anasin::listaDeIdentificadores(){
        
        if(!identificador()) erro("Espeando identificador");
        
        proximo();

        while(virgula()){
            proximo();
            if(!identificador()) erro("Esperando identificador");
            proximo();
        }
    }

    void Anasin::secaoDeParametrosFormais(){
        if(palavra=="VAR") proximo();
        
        listaDeIdentificadores();
        if(!doisPontos()) erro("Esperando ':'");
        proximo();
        if(!(palavra=="INTEGER" || palavra=="BOOLEAN")) erro("Esperando identificador");
        

    }
    void Anasin::parametrosFormais(){
        
        secaoDeParametrosFormais();
        proximo();
        while(pontoEvirgula()){
            proximo();
            secaoDeParametrosFormais();
            proximo();
        }
    }
    void Anasin::declaracaoDeProcedure(){
        
        
        if(!identificador()) erro("Esperando identificador");
        
        proximo();
        if(palavra=="PAREN"){
            proximo();
            parametrosFormais();
            if(palavra!="TESIS") erro("Esperado parentesis");
            else proximo();
        }
        
        
        if(!pontoEvirgula()) erro("Esperando ';'");
        bloco();
    }

    void Anasin::declaracaoDeFuncao(){
        //CONTINUAR DAQUI
        
    }

    void Anasin::bloco(){
        bool certo=false;
        
        if(palavra=="VAR"){
            proximo();
            declaracaoDeVariaveis();
            certo=true;
            proximo();
        }
        while(palavra=="FUNCTION" || palavra == "PROCEDURE"){
            proximo();
            if(palavra=="PROCEDURE") declaracaoDeProcedure();
            else if(palavra == "FUNCTION") declaracaoDeFuncao();
        }
        
        //if(!certo){erro();}

    }
        