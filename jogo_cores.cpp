#include "stack.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

#define TAM 6

using namespace std;

typedef int stack_element;

typedef struct
{
  int numero_elementos;
  Stack pilha;
} Tubo;

void iniciar_vazias(Tubo T[])
{
  for (int i = 0; i < TAM; i++)
  {
    initStack(T[i].pilha);
    T[i].numero_elementos = 0;
  }
}

void distribuir(Tubo T[])
{
}

void muda_cor(int cor)
{
  HANDLE Saida;
  Saida = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(Saida, cor);
}

void imprime_cor(int I)
{
  int cor[5] = {9, 13, 2, 15, 6};
  muda_cor(cor[I - 1]);
  cout << 'O';
  muda_cor(15);
}

void mostrar(Tubo T[])
{
}

int validar(Tubo T[], int o, int d)
{
}

int validar_fim(Tubo T[])
{
}

int jogada(Tubo T[])
{
}

int main()
{
  Tubo T[TAM];
  int repetir = 1, retorno;
  do
  {
    iniciar_vazias(T);
    distribuir(T);
    mostrar(T);
    do
    {
      retorno = jogada(T);
      mostrar(T);
      if (retorno == 0)
        break;
    } while (retorno);
    mostrar(T);
    cout << "\n P A R A B E N S ! ! ! ! ";
    cout << "\n Jogar Novamente? 1(sim)  ou  0(nao): ";
    cin >> repetir;
  } while (repetir);
  cout << "Fim de JOGO!" << endl;
  return 0;
}