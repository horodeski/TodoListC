# 📝 To-Do List em C

Este projeto é um gerenciador simples de tarefas (To-Do List) desenvolvido em linguagem C. Ele foi criado como parte dos meus estudos com base no vídeo [**"Projeto TO-DO LIST em linguagem C"**](https://www.youtube.com/watch?v=AvVzfpQAQuE) do canal **Curso em Vídeo**, ministrado por Gustavo Guanabara.

## 📌 Funcionalidades

- Adicionar tarefas
- Listar todas as tarefas
- Marcar tarefas como concluídas
- Editar uma tarefa
- Remover tarefas
- Encerrar o programa (liberando memória)

## 📂 Estrutura do Projeto

O projeto utiliza:

- `struct Task`: estrutura que armazena o nome da tarefa e seu status (concluída ou não).
- Ponteiros dinâmicos e `realloc` para gerenciar a lista de tarefas em tempo de execução.
- Funções para cada operação do menu, como adicionar, editar, remover, etc.

## 💡 Como usar

1. Compile o programa:
   ```bash
   gcc -o todo todo.c
   ```

2. Execute:
   ```bash
   ./todo
   ```

3. Use o menu interativo para gerenciar suas tarefas.

## 📷 Exemplo de uso

```plaintext
Options
1. Add a task
2. List all tasks
3. Mark as complete
4. Edit task
5. Delete task
6. Exit
Enter choice (1, 2, 3, 4, 5, 6): 1
Enter task: Estudar estrutura de dados
task added
```

## 🧠 O que aprendi

- Manipulação de memória com `malloc`, `realloc` e `free`
- Uso de `structs` para representar objetos no C
- Interação com o usuário via terminal
- Práticas de organização de código em C

## 🎥 Referência

- [Projeto TO-DO LIST em linguagem C - Curso em Vídeo](https://www.youtube.com/watch?v=AvVzfpQAQuE)

## 📜 Licença

Este projeto é apenas para fins de estudo e aprendizado. Sinta-se à vontade para modificar e usar como quiser.
