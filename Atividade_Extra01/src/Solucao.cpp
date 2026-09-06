#include <cstdlib>
#include<string>
#include<vector>

#define LEN_LOCAIS 15

struct Local{
    std::string nome;
    int capacidade;
    int custo;
    std::vector<std::string> bairros_cobertos;
};

float find_best(std::vector<int> custo, std::vector<int> capacidade){
    float CC = 0;
    for(int i=0; i<LEN_LOCAIS; i++)
    {
        float at = float(capacidade[i])/float(custo[i]);
        if(at > CC)
            CC = at;
        
    }
    return CC;
}

void solve(std::vector<std::string> Locais, std::vector<int> capacidades, std::vector<int> custos, std::vector<std::vector<std::string>> Bairros_Cobertos){
    float first = find_best(custos, capacidades);
    
}

int main(){
    std::vector<std::string> Locais = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12","A13","A14","A15",};
    std::vector<int> capacidades = {6,5,7,5,8,6,5,7,6,7,5,6,7,6,5};
    std::vector<int> custos = {820,650,900,720,880,760,610,840,540,690,780,570,620,730,560};

    //TODO: revisar se tá tudo marcado certo
    std::vector<std::vector<std::string>> Bairros_Cobertos = {
        {"B1","B2","B3","B6","B8","B12",},
        {"B2","B4","B5","B9","B13",},
        {"B1","B4","B7","B10","B14","B18","B19",},
        {"B3","B5","B6","B11","B16",},
        {"B2","B6","B8","B12","B17","B18","B19",},
        {"B4","B7","B9","B13","B15","B18"},
        {"B1","B5","B10","B11","B16"},
        {"B3","B6","B9","B12","B14","B15","B19"},
        {"B2","B4","B8","B13","B17","B20"},
        {"B1","B3","B6","B11","B14"},
        {"B4","B8","B9","B12","B17","B20"},
        {"B2","B5","B7","B13","B16","B18","B20"},
        {"B2","B5","B7","B13","B16","B18","B20"},
        {"B3","B6","B10","B14","B15","B19"},
        {"B1","B4","B8","B11","B17"},
    };
    // A informação inidividual de cada local é armazenada pelos indexes pareados = Locais[i], capacidades[i], custos[i], Bairros_Cobertos[i]
    return 0;
}
