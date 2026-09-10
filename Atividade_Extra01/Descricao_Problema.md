# Algoritmo Costrutivo

## Definição
O algoritmo é baseado na heurística de melhor custo benefício de local de definido por
$$C_c = \frac{N}{C}$$

- Onde N é número de bairros não descobertos e C é o custo do local

Para a utilização dessa heurísitica foi montada a seguinte estrutura:
	- Um vetor de Locais
	- Um vetor de Capacidades (Número de bairros não cobertos que o local se conecta)
	- Um vetor de Custos (Custo do local)
	- Uma matriz de Bairros no alcance de cobertura onde cada linha representa um **set** de bairros 

>Essas três estruturas carregam a informação de um Local individual de forma paralela, ou seja os dados referentes ao Local i são acessados com:
Locais[ i ], Custos[ i ], Bairros_Cobertos[ i ], Capacidades[ i ]



## Execução do algoritmo
A execução do algoritmo funciona da seguinte forma:

1. O Local com melhor $C_c$ é escolhido
2. Utilizando da matriz de bairros cobertos, cada bairro coberto pelo Local é removido da lista de cobertura dos demais locais
	1. O uso do set permite fazer essa remoção em O(1)
3. O valor no índice do vetor de capacidades é atualizado
4. O processo se repete até que todos os sets na matriz de bairros cobertos estejam vazios

Esse processo pode ser descrito na forma do pseudocódigo:

`Conjuntos_zerados=0
Total_Conjuntos = tamanho(Bairros_Cobertos)

Enquanto Conjuntos_zerados < Total_Conjuntos{
melhor = MelhorLocal(Capacidades, Custos)

Para cada bairro coberto b de melhor{
	Para cada conjunto de bairros cobertos c em Bairros_Cobertos{
			se b existe em c{
					c.remove(b)	
					Se c está vazio{
						Conjuntos_zeros +=1
				}
			}
		}
	}
}`

# Algoritmo de Busca Local
