#include <stdio.h>
#include <string.h>
#include "mainFunc.h"
int main( void )
{
  int Selection;

  Number = 0;
  while ((Selection = Menu()) != '0' && Selection != 27)
    switch (Selection)
    {
    case '1':
      Add();
      break;
    case '2':
      Save();
      break;
    case '3':
      Load();
      break;
    case '4':
      Print();
      break;
    case '5':
      Del();
      break;
    }
}


