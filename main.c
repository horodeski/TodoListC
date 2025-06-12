#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char *task;
  int completed; /* bool */
} Task;

Task *tasks = NULL;
int length = 0;

void addTask(const char *task)
{
  // Aloca (ou realoca) espaço na memória para armazenar mais uma tarefa
  tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task)); /* reservando um lugar dentro de tasks */

  // Aloca espaço na memória para armazenar o texto da nova tarefa (incluindo o \0 do final da string)
  tasks[length].task = (char *)malloc(strlen(task) + 1); /* preenchendo o nome da task */

  // Marca a nova tarefa como "não concluída" (0 = false)
  tasks[length].completed = 0; /* dizendo que não está concluída */

  // Copia o texto da tarefa recebida para a memória recém-alocada
  strcpy(tasks[length].task, task); /* nao sei */

  length++; /* aumenta o length */
  printf("task added");
}

void listTask()
{
  char * status;

  for (int i = 0; i < length; i++)
  {
    if (tasks[i].completed == 1)
    {
      status = "feito paizão, está de parabéns";
    }
    else
    {
      status = "ainda não fez essa budega?";
    }

    printf("%d. %s [%s]\n", i + 1, tasks[i].task, status);
  }
}

void markCompleted(int index)
{
  if (index <= length && index > 0)
  {
    tasks[index - 1].completed = 1;
    printf("Task concluída, parabéns meu querido\n");
  }
  else
  {
    printf("Bora escrever certo?\n");
  }
}

void deleteTask(int index)
{
  if (index <= length && index > 0)
  {
    index = index - 1;

    free(tasks[index].task);

    for (int i = index; i < length - 1; i++)
    {
      tasks[i] = tasks[i + 1];
    }

    length--;

    tasks = (Task *)realloc(tasks, (length * sizeof(Task)));
  }
  else
  {
    printf("Bora escrever certo?\n");
  }
}

void editTask(int index, const char *task)
{
  if (index <= length && index > 0)
  {
    index = index - 1;

    char *editedTask = (char *)realloc(tasks[index].task, strlen(task) + 1);

    if (editedTask != NULL)
    {
      tasks[index].task = editedTask;
      strcpy(tasks[length].task, task);
      printf("Boa!\n");
    }
    else
    {
      printf("Deu ruim\n");
    }

    printf("Bora escrever certo?\n");
  }
}

int main()
{
  int choice;
  int running = 1;
  char taskInput[256];

  while (running)
  {
    printf("\nOptions\n");
    printf("1. Add a task\n");
    printf("2. List all tasks\n");
    printf("3. Mark as complete\n");
    printf("4. Edit task\n");
    printf("5. Delete task\n");
    printf("6. Exit\n");

    printf("Enter choice (1, 2, 3, 4, 5, 6): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter task: ");
      getchar();
      fgets(taskInput, sizeof(taskInput), stdin);
      taskInput[strcspn(taskInput, "\n")] = '\0';
      addTask(taskInput);
      break;

    case 2:
      listTask();
      break;

    case 3:
      printf("Qual tarefa deseja marcar como concluída? ");
      scanf("%d", &choice);
      markCompleted(choice);
      break;

    case 4:
      printf("Qual tarefa deseja editar? ");
      scanf("%d", &choice);
      getchar(); // limpa o buffer
      printf("Digite o novo nome da tarefa: ");
      fgets(taskInput, sizeof(taskInput), stdin);
      taskInput[strcspn(taskInput, "\n")] = '\0';
      editTask(choice, taskInput);
      break;

    case 5:
      printf("Qual tarefa deseja deletar? ");
      scanf("%d", &choice);
      deleteTask(choice);
      break;

    case 6:
      running = 0;
      printf("Encerrando o programa. Até mais!\n");
      break;

    default:
      printf("Invalid choice\n");
      break;
    }
  }

  for (int i = 0; i < length; i++)
  {
    free(tasks[i].task);
  }
  free(tasks);

  return 0;
}