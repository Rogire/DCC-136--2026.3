#include <cstdio>
#include<string>
#include<vector>
#include <unordered_set>

#define LEN_LOCAIS 15
#define LEN_BAIRROS 20

int find_best(std::vector<int> custo, std::vector<int>* capacidade){
    float CC = 0;
    int best_index=0;
    for(int i=0; i<LEN_LOCAIS; i++)
    {
        float at = float(capacidade->at(i))/float(custo[i]);
        if(at > CC)
        {
            CC = at;
            best_index = i;
        }
        
    }
    return best_index;
}

std::vector<int> solve(std::vector<int> custos, std::vector<int>* capacidades,std::vector<std::unordered_set<int>>* Bairros_Cobertos ){
    int zeros = 0;
    std::vector<int> solution={};
    
    while(zeros < LEN_LOCAIS){
        int best = find_best(custos, capacidades);
        solution.push_back(best);
        
        std::vector<int> cp(Bairros_Cobertos->at(best).begin(), Bairros_Cobertos->at(best).end());;

        for(int b_id : cp)
        {
            for(int i=0; i<Bairros_Cobertos->size(); i++)//15
            {
                auto& l_id = Bairros_Cobertos->at(i);
                if(i != best && l_id.find(b_id) != l_id.end())
                {
                    l_id.erase(l_id.find(b_id));        
                    capacidades->at(i) = l_id.size();
                    if(l_id.empty())
                       zeros++;                        
                }
            }

            Bairros_Cobertos->at(best).erase(b_id);
            capacidades->at(best) = Bairros_Cobertos->at(best).size();
            if(Bairros_Cobertos->at(best).empty())  
                zeros++;
        }
    }   
    return solution;
}

int main(){
    std::vector<std::string> Locais = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12","A13","A14","A15",};
    std::vector<int> capacidades = {6,5,7,5,8,6,5,7,6,7,5,6,7,6,5};
    std::vector<int> custos = {820,650,900,720,880,760,610,840,540,690,780,570,620,730,560};

    std::vector<std::unordered_set<int>> Bairros_Cobertos = {
        {0,1,2,5,7,11,},        //{B1,B2,B3,B6,B8,B12,},
        {1,3,4,8,12,},          //{B2,B4,B5,B9,B13,},
        {0,3,6,9,13,17,18,},    //{B1,B4,B7,B10,B14,B18,B19,}
        {2,4,5,10,15,},         //{B3,B5,B6,B11,B16,}
        {1,5,7,11,16,17,18,19}, //{B2,B6,B8,B12,B17,B18,B19,B20}
        {3,6,8,12,14,17},       //{B4,B7,B9,B13,B15,B18}
        {0,4,9,10,15},          //{B1,B5,B10,B11,B16}
        {2,5,8,11,13,14,18},    //{B3,B6,B9,B12,B14,B15,B19}
        {1,3,7,12,16,19},       //{B2,B4,B8,B13,B17,B20}
        {4,6,9,14,15,17,19},    //{B5,B7,B10,B15,B16,B18,B20}
        {0,2,5,10,13},          //{B1,B3,B6,B11,B14}
        {3,7,8,11,16,19},       //{B4,B8,B9,B12,B17,B20}
        {1,4,6,12,15,17,19},    //{B2,B5,B7,B13,B16,B18,B20}
        {2,5,9,13,14,18},       //{B3,B6,B10,B14,B15,B19}
        {0,3,7,10,16},          //{B1,B4,B8,B11,B17}
    };
    
    std::printf("Começando...");
    std::vector<int> sol= solve(custos, &capacidades, &Bairros_Cobertos);
    std::printf("SOLUÇÃO: ");
    for(auto i : sol)
        std::printf("%d ",i);
    std::printf("\n");   
    
    return 0;
}


