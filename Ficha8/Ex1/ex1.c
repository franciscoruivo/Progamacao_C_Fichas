// a) A estratégia de inserção é no início da lista (inserção à cabeça). Os novos nós são sempre colocados no início da lista.

// b) A lista ficará com a seguinte constituição:
// CCC -> BBB -> AAA -> NULL
// Os elementos são inseridos em ordem inversa à ordem de chamada da função.

// c) A estratégia de inserção é no fim da lista (inserção à cauda). Os novos nós são sempre colocados no final da lista.

// d) A lista ficará com a seguinte constituição:
// AAA -> BBB -> CCC -> NULL
// Os elementos são inseridos na mesma ordem das chamadas da função.

// e) A estratégia de inserção é após o primeiro nó da lista. Se a lista estiver vazia, insere no início.
// Para lista não vazia, o novo nó é inserido sempre na segunda posição.

// f) A lista ficará com a seguinte constituição:
// AAA -> CCC -> BBB -> NULL
// O primeiro elemento (AAA) é inserido no início.
// Os próximos elementos são inseridos sempre após o primeiro nó.

// g) A lista ficará com a seguinte constituição:
// CCC -> BBB -> AAA -> EEE -> DDD -> NULL
// AAA é inserido primeiro (addNo_3)
// BBB e CCC são inseridos no início (addNo_1)
// DDD é inserido no fim (addNo_2)
// EEE é inserido após o primeiro nó CCC (addNo_3)
