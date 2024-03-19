// Breno Gaia Crepaldi RA: 22007851
// Douglas Alves de Lima Monttozo 
// Henrique Zacarias
// Rafael Tamura

//#include "stack.h"
#include "stack_ld.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h> // impressão de cores
#include <time.h>    // srand()
#include <stdio.h>   // rand()

#define TAM 6

using namespace std;

typedef int stack_element;

typedef struct
{
  int numero_elementos;
  Stack pilha;
} Tubo;

void iniciar_vazias(Tubo T[]) // feita
{
  for (int i = 0; i < TAM; i++)
  {
    initStack(T[i].pilha);
    T[i].numero_elementos = 0;
  }
}

void distribuir(Tubo T[])
{
  int num, freq[TAM - 1] = {0};
  srand(time(0));
  for (int i = 0; i < TAM - 1; i++)
  {
    for (int j = 0; j < TAM - 1; j++)
    {
      do
      {
        num = rand() % (TAM - 1);
      } while (freq[num] == TAM - 1);
      freq[num]++;
      push(T[i].pilha, num + 1);
      T[i].numero_elementos++;
    }
  }
}

void muda_cor(int cor) // feita
{
  HANDLE Saida;
  Saida = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(Saida, cor);
}

void imprime_cor(int I) // feita
{
  int cor[5] = {9, 13, 2, 15, 6};
  muda_cor(cor[I - 1]);
  cout << 'O';
  muda_cor(15);
}

void mostrar(Tubo T[])
{
  stack_element elemento;
  Tubo Aux[TAM];
  iniciar_vazias(Aux);

  cout << endl;
  for (int i = 0; i < TAM - 1; i++)
  {
    for (int j = 0; j < TAM; j++)
    {
      if (!isEmpty(T[j].pilha))
      {
        elemento = pop(T[j].pilha);
        cout << "\t| ";
        imprime_cor(elemento);
        cout << " |";
        push(Aux[j].pilha, elemento);
      }
      else
      {
        cout << "\t|   | ";
      }
    }
    cout << endl;
  }
  for (int i = 0; i < TAM - 1; i++)
  {
    while (!isEmpty(Aux[i].pilha))
    {
      elemento = pop(Aux[i].pilha);
      push(T[i].pilha, elemento);
    }
  }

  for (int i = 0; i < TAM; i++)
  {
    cout << "\t-----";
  }
  cout << endl;

  for (int i = 0; i < TAM; i++)
  {
    cout << "\t  " << i + 1 << "  ";
  }
  cout << endl;
}

int validar(Tubo T[], int origem, int destino)
{
  if (origem == destino)
  {
    cout << "\nEscolha tubos diferentes!\n";
    return 0;
  }

  if (isEmpty(T[origem - 1].pilha) || T[origem].numero_elementos == 0)
  {
    cout << "\nTubo de origem vazio, escolha outro!\n";
    return 0;
  }

  if (!isEmpty(T[destino - 1].pilha) || T[destino].numero_elementos == TAM - 1)
  {
    cout << "\nTubo de destino cheio, escolha outro\n";
    return 0;
  }

  return 1;
}

int validar_fim(Tubo T[])
{
  int contador = 0;
  for (int i = 0; i < TAM - 1; i++)
  {
    if (T[i].numero_elementos == TAM - 1)
    {
      contador++;
    }
  }

  if (contador == TAM - 1)
  {
    cout << "Voce ganhou!";
    return 1;
  }

  return 0;
}


int jogada(Tubo T[])
{
  int ORIGEM, DESTINO;
  cout << "\nORIGEM <1 a 6 (-1 sair)>: ";
  cin >> ORIGEM;
  if (ORIGEM == -1)
    return 0;

  cout << "\nDESTINO <1 a 6 (-1 sair)>: ";
  cin >> DESTINO;
  if (DESTINO == -1)
    return 0;

  if (ORIGEM < 1 || ORIGEM > 6 || DESTINO < 1 || DESTINO > 6)
  {
    cout << "\nEscolha um tubo de 1 a 6!\n";
    return 1;
  }

  if (validar(T, ORIGEM, DESTINO))
  {
    stack_element v = pop(T[ORIGEM - 1].pilha);
    push(T[DESTINO - 1].pilha, v);
    T[ORIGEM - 1].numero_elementos--;
    T[DESTINO - 1].numero_elementos++;

    if (validar_fim(T))
      return 0;
    return 1;
  }
  return 1;
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
    cout << "\n P A R A B E N S ! ! ! ! ";
    cout << "\n Jogar Novamente? 1(sim)  ou  0(nao): ";
    cin >> repetir;
  } while (repetir);
  cout << "Fim de JOGO!" << endl;
  return 0;
}