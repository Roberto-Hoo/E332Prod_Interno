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
int my_n;  // O tamanho dos vetores receptores

//gsl_vector *my_v; // Os vetores emissores
//gsl_vector *v1, *v2;    // Os vetores v1 e v2 no emissor
//gsl_vector *my_v1, *my_v2  // Os vetores my_v1, my_v2 nos receptores
//gsl_vector *my_soma;
//gsl_vector *soma;
int n = 10; // O tamanho do vetor v no receptor
double num1, num2;
bool debug = true;
int min_ = 0;
int max_ = 10;
int dmin_ = 0;
int dmax_ = 0;

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

    double Vetor_my_soma[1]={0.0};
    double Vetor_soma[world_size];
    double w1[n], w2[n];
    srand((unsigned) (world_rank + time(0))); //para gerar números aleatórios reais.
    if (world_rank == 0) {
        //v1 = gsl_vector_alloc(n); // aloca o vetor v no processo 0 com n espaços
        //v2 = gsl_vector_alloc(n); // aloca o vetor v no processo 0 com n espaços
        for (int i = 0; i < n; i++) {
            num1 = (double) numeroAleatorio(min_, max_) +
                   (double) numeroAleatorio(dmin_, dmax_) / 100;
            //gsl_vector_set(v1, i, num1);
            w1[i] = num1;
            num2 = (double) numeroAleatorio(min_, max_) +
                   (double) numeroAleatorio(dmin_, dmax_) / 100;
            //gsl_vector_set(v2, i, num2);
            w2[i] = num2;

        }
        if (debug) {
            printf("\nVetor w1(%d) = ", world_rank);
            for (int i = 0; i < n; i++)
                printf("%6.2f", w1[i]);
            //printf("%6.1f", gsl_vector_get(v1, i));

            printf("\nVetor w2(%d) = ", world_rank);
            for (int i = 0; i < n; i++)
                printf("%6.2f", w2[i]);
            //printf("%6.1f", gsl_vector_get(v2, i));
            printf("\n");
        }
    }

    my_n = int(n / world_size);
    double my_w1[my_n], my_w2[my_n];

    if (world_rank == 0) {
        for (int i = 1; i < world_size; i++) {
            MPI_Send(&w1[n - (world_size - i) * my_n], my_n, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
            MPI_Send(&w2[n - (world_size - i) * my_n], my_n, MPI_DOUBLE, i, 0, MPI_COMM_WORLD);
        }
        for (int i = 0; i < n - my_n * (world_size - 1); i++)
            Vetor_my_soma[0] += w1[i] * w2[i];
        printf("\nsoma no processo %d eh %6.2f", world_rank, Vetor_my_soma[0]);
        //MPI_Send(&w1[n - (world_size - 1) * my_n], my_n, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
        //MPI_Send(&w1[n - (world_size - 2) * my_n], my_n, MPI_DOUBLE, 2, 0, MPI_COMM_WORLD);

    } else {
        //for (int i = 1; i < world_size; i++) {
        MPI_Recv(&my_w1, my_n, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\nmy_w1(%d) = ( ", world_rank);
        for (int j = 0; j < my_n; j++)
            printf(" %6.2f ", my_w1[j]);
        printf(" )");

        MPI_Recv(&my_w2, my_n, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("\nmy_w2(%d) = ( ", world_rank);
        for (int j = 0; j < my_n; j++)
            printf(" %6.2f ", my_w2[j]);
        printf(" )");

        for (int i = 0; i < my_n; i++)
            Vetor_my_soma[0] += my_w1[i] * my_w2[i];
        printf("\nsoma no processo %d eh %6.2f", world_rank, Vetor_my_soma[0]);
        //}
    }



    MPI_Gather(&Vetor_my_soma, 1, MPI_DOUBLE, &Vetor_soma, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    if (world_rank == 0) {
        double produtoInterno = 0.0;
        //printf("\n Produto %6.2f",produtoInterno);
        for (int i=0;i<world_size;i++) {
            produtoInterno += Vetor_soma[i];
            printf("\n Produto(%d)= %6.2f",i,produtoInterno);
        }
        printf("\nProduto interno eh %7.2f",produtoInterno);
    }


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
