#include "analex.hpp"
#include <string>
#include <fstream>
#include "Anasin.hpp"
int main(){
    Analex analex("Exemplo1_Trab2_Compiladores.txt");
    analex.traducao();
    analex.fechaArq();
    
    Anasin anasin("ResultadoAnalex.txt");

    


}