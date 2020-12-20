//Вывод
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
COURSES cours[20];

int Number;

void Print( void )
{
  int i;
  for (i = 0; i < Number; i ++)
    printf("\nID - %d\nНазвание курса - %s\nURL курса - %s\nДата начала курса - %s\nСколько будет идти курс - %s\nЦена курса -%s\n", i + 1, cours[i].name,cours[i].URL, cours[i].date, cours[i].howDays, cours[i].price);
} 

//Добавление
void Add( void )
{
  if (Number == 19)
  {
    fprintf(stderr, "Невозможно добавить еще один элемент\n");
    return;
  }

  printf("Введите название курса > ");
  scanf("%20s", cours[Number].name);
    printf("Введите URL курса > ");
    scanf("%20s", cours[Number].URL);
      printf("Введите дату проведения курса > ");
      scanf("%20s", cours[Number].date);
        printf("Введите количество дней у курса > ");
        scanf("%20s", cours[Number].howDays);
           printf("Введите стоимость курса > ");
           scanf("%20s", cours[Number].price);

  Number ++;
} 

//Удаление 
void Del( void )
{
  int i;

  Print();
  printf("Введите номер удаляемого элемента > ");
  scanf("%i", &i);
  if (i < 1 || i > Number)
  {
    fprintf(stderr, "Элемент с номером %i не существует\n", i);
    return;
  }

  for (i --; i < Number - 1; i ++)
    cours[i] = cours[i + 1];

  Number --;
} 

//Сохранение
void Save( void )
{
  FILE *F;
  int i;

  if ((F = fopen("input.txt", "w")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для записи файл 'input.txt'\n");
    return;
  }

  fprintf(F, "%i\n", Number);
  for (i = 0; i < Number; i ++)
    fprintf(F, "%s\n%s\n%s\n%s\n%s\n", cours[i].name, cours[i].URL, cours[i].date, cours[i].howDays, cours[i].price);

  fclose(F);
} 
void Load( void )
{
  FILE *F;
  int i;

  if ((F = fopen("input.txt", "r")) == NULL)
  {
    fprintf(stderr, "Невозможно открыть для чтения файл 'input.txt'\n");
    return;
  }

  fscanf(F, "%i", &Number);
  for (i = 0; i < Number; i ++)
    fscanf(F, "%20s%20s%20s%20s%20s", cours[i].name, cours[i].URL, cours[i].date, cours[i].howDays,cours[i].price);

  fclose(F);
}

//Меню вывод
int Menu( void )
{
  int c = 0;

  while ((c < '0' || c > '5') && c != 27)
  {
    printf("0 : выход\n"
           "1 : добавить\n"
           "2 : сохранить\n"
           "3 : загрузить\n"
           "4 : вывести\n"
           "5 : удалить\n"
           ">");
    c = getchar();
    printf("%c\n", c);
  }
  return c;
} 
