/*
 * E 3.3.2.
 * Faça um código MPI para computar o produto interno de dois vetores de
 * elementos randômicos em ponto flutuante.
 */

/*
 3.3.4 Recebimento coletivo de dados distribuídos
 A rotina MPI_Gather, permite que um processo receba simultaneamente dados que estão distribuídos
 entre os demais processos. Sua sintaxe é a seguinte

int MPI_Gather(
  const void *sendbuf,
  int sendcount,
  MPI_Datatype sendtype,
  void *recvbuf,
  int recvcount,
  MPI_Datatype recvtype,
  int root,
  MPI_Comm comm)

Sua sintaxe é parecida com a da rotina MPI_Scatter. Veja lá!
 Aqui, root é o identificador rank do processo receptor.
*/
#include <iostream>
#include <cstdio>
#include <mpi.h> // API MPI
#include <gsl/gsl_vector.h> //gsl

using namespace std;

int world_size; // número total de processos
int world_rank; // ID (rank) do processo
int my_n = 20;   // O tamanho dos vetores  emissores

gsl_vector *my_v; // Os vetores emissores
gsl_vector *v1, *v2;    // O vetor v no receptor
gsl_vector *my_soma;
gsl_vector *soma;
int n = 20 ; // O tamanho do vetor v no receptor
double num1,num2;
double SomaTotal;
bool debug = true;
/*
 * Retorna um número aleatorio inteiro entre minimo e o maximo(inclusive os extremos)
 */
int numeroAleatorio(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

int main() {

    MPI_Init(NULL, NULL); // Inicializa o MPI
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    v1 = gsl_vector_alloc(0);
    v2 = gsl_vector_alloc(0);

    if (world_rank == 0) {
        v1 = gsl_vector_alloc(n); // aloca o vetor v no processo 0 com n espaços
        v2 = gsl_vector_alloc(n); // aloca o vetor v no processo 0 com n espaços
        for (int i = 0; i < n; i++) {
            num1 = (double) numeroAleatorio(0, 99) +
                   (double) numeroAleatorio(0, 99) / 100;
            gsl_vector_set(v1, i, num1);
            num2 = (double) numeroAleatorio(0, 99) +
                   (double) numeroAleatorio(0, 99) / 100;
            gsl_vector_set(v2, i, num2);
        }
        printf("\nVetor v1 = ");
        for (int i = 0; i < n; i++)
            printf("%6.1f", gsl_vector_get(v1,i));
        printf("\nVetor v2 = ");
        for (int i = 0; i < n; i++)
            printf("%6.1f", gsl_vector_get(v2,i));
    }

    // Finaliza o MPI
    MPI_Finalize();

    return 0;
}
/*
 * Rode no terminal
 * $ mpic++ 334gather.cpp -lgsl -lgslcblas -o 334gather
 * $ mpirun -np 6 -oversubscribe 334gather
 * Processo 0 soma = 15.000000
 *
 * */
