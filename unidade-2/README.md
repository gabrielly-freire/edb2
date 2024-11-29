# EDB2 - Unidade 2

Este repositório contém as implementações relacionadas aos conceitos de **Árvores Binárias**, **Heapsort** e **Árvores AVL**, abordados na Unidade 2 da disciplina de Estruturas de Dados II (EDB2).

## Tópicos Implementados

### Árvores - Percurso em Árvore Binária

1. Implementação do percurso em árvore binária:
   - **Pré-ordem** (visita a raiz antes das subárvores).
   - **Ordem Simétrica** (visita as subárvores esquerda e direita intercaladas pela raiz).
   - **Pós-ordem** (visita as subárvores antes da raiz).
   - **Em Nível** (visita os nós por nível, da raiz até as folhas).

---

### Árvores - Árvore Binária de Busca (BST)

1. **Busca**: Implementação do procedimento de busca de uma chave em uma árvore binária de busca.
2. **Inserção**: Inserção de novos nós respeitando as propriedades da árvore binária de busca.
3. **Remoção**: Remoção de nós, considerando os três casos principais:
   - Nó sem filhos.
   - Nó com um filho.
   - Nó com dois filhos.
4. **Construção de BST de Altura Mínima**:
   - Dada uma lista com `n` chaves, construção de uma árvore binária de busca com altura mínima utilizando o algoritmo de inserção.
   - **Complexidade**: Análise detalhada do método implementado.

---

### HEAPSORT - Conceitos Iniciais

1. **Alteração de Prioridade**: Implementação do procedimento para alterar a prioridade de um elemento em uma heap.
2. **Inserção**: Inserção de novos elementos em uma heap.
3. **Remoção da Raiz**: Procedimento para remover a raiz de uma heap.

---

### HEAPSORT - Construção da Heap e Ordenação

1. **Criação da Heap**: Construção de uma heap a partir de um vetor qualquer.
2. **Heapsort**: Implementação do algoritmo de ordenação utilizando heap.

---

### Árvore AVL - Conceitos Iniciais

1. **Rotações em Árvores Binárias**: Implementação das rotações necessárias para balanceamento:
   - **Rotação Esquerda**.
   - **Rotação Direita**.
   - **Rotação Dupla Esquerda**.
   - **Rotação Dupla Direita**.

---

### Árvore AVL - Busca, Inclusão e Remoção

1. **Busca**: Procedimento de busca de elementos em uma árvore AVL.
2. **Inserção**: Inserção de elementos com balanceamento automático.
3. **Remoção**: Remoção de elementos com ajuste do balanceamento.
