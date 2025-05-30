#include <fstream>
#include <string>
class Anasin{
    private:
        std::string nomeArqAnalex;
        std::ifstream arquivoAnalex;
        std::string palavra;

        void proximo();
        bool ehReservada();
    public:
        Anasin(std::string nomeArqAnalex);
};