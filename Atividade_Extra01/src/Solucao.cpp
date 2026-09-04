#include <cstdlib>
#include<string>
#include<vector>



int main(){
    std::vector<std::string> Locais = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12","A13","A14","A15",};
    std::vector<int> capacidades = {6,5,7,5,8,6,5,7,6,7,5,6,7,6,5};
    std::vector<int> custos = {820,650,900,720,880,760,610,840,540,690,780,570,620,730,560};

    std::vector<std::vector<std::string>> Bairros_Cobertos = {
        {"B1","B2","B3","B6","B8","B12",},
        {"B2","B4","B5","B9","B13",},
        {"B1","B4","B7","B10","B14","B18","B19",},
        {"B3","B5","B6","B11","B16",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
        {"B1",},
    };

    return 0;
}
