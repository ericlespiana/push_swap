# Push Swap

## Sobre o Projeto

Push Swap é uma aplicação desenvolvida em linguagem C que desafia os usuários a resolver problemas de ordenação utilizando apenas duas pilhas (stacks) e operações básicas de pilha. Através de uma série de movimentos permitidos, os usuários devem transferir todos os elementos de uma pilha para outra, mantendo-os ordenados de acordo com um critério específico. Este projeto não permite o uso de estruturas de dados adicionais além das duas pilhas, tornando-o um desafio interessante tanto para iniciantes quanto para programadores experientes.

### Objetivo

O principal objetivo do Push Swap é proporcionar uma experiência prática na manipulação de estruturas de dados, especialmente em contextos onde a eficiência e a otimização são cruciais. Ao longo do projeto, os participantes terão a oportunidade de explorar diferentes algoritmos de ordenação, aprender sobre a eficácia dos movimentos de pilha e entender melhor como a programação pode ser usada para resolver problemas complexos.

## Regras de Movimentação

As regras de movimentação entre as pilhas são fundamentais para o sucesso do projeto. Aqui estão as principais operações permitidas:

- `pa`: Move o topo da pilha B para a pilha A.
- `pb`: Move o topo da pilha A para a pilha B.
- `ra`: Rotaciona a pilha A para a direita.
- `rb`: Rotaciona a pilha B para a direita.
- `rr`: Rotaciona ambas as pilhas para a direita.
- `rra`: Rotaciona a pilha A para a esquerda.
- `rrb`: Rotaciona a pilha B para a esquerda.
- `rrr`: Rotaciona ambas as pilhas para a esquerda.

Essas operações permitem que os usuários movam elementos entre as pilhas e os ordene conforme necessário.

## Regras de Validação

Antes de iniciar a ordenação, o programa realiza várias verificações para garantir que todas as entradas estejam corretas e que a ordenação possa ser realizada de forma eficiente. As principais regras de validação incluem:

- **Número de Elementos**: O programa aceita um único argumento no momento da execução, que representa o número total de elementos a serem ordenados. Este número deve ser maior que zero.
- **Elementos Únicos**: Todos os elementos passados para o programa devem ser únicos. Repetição de elementos não é permitida.
- **Entrada Válida**: Os elementos devem ser passados como argumentos numéricos válidos. Entradas inválidas, como strings não numéricas ou caracteres especiais, serão ignoradas.

Estas regras garantem que o processo de ordenação seja realizado sob condições claras e consistentes, evitando erros e imprecisões durante a execução.

## Dependências

- GCC Compiler: Para compilação do código-fonte.
- Make: Para automação da compilação.

## Instalação

1. Clone o repositório:
```bash
git clone https://github.com/ericlespiana/push_swap.git
```

3. Navegue até o diretório do projeto:
```bash
cd push_swap
```

3. Compile o projeto usando o Makefile fornecido:
`make`

## Uso

Para executar o programa, use o seguinte comando no terminal:
bash ./push_swap [NÚMERO_DE_ELEMENTOS]

Substitua `[NÚMERO_DE_ELEMENTOS]` pelo número de elementos que deseja passar para o programa. Os elementos devem ser separados por espaços.

## Exemplos

Aqui estão alguns exemplos de como usar o programa:

- Para ordenar 5 números:
```bash
./push_swap 5 8 6 3 7
```

- Para ordenar 10 números:
```bash
./push_swap  1 5 4 2 3 9 8 7 6 10
```

## Contribuições

Contribuições são sempre bem-vindas Se você encontrar algum bug ou tiver sugestões de melhoria, por favor, abra uma issue ou envie um pull request.
