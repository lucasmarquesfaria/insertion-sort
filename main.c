#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n)
{

    int i, j, aux, count = 0;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (i = 1; i < n; i++)
    {
        aux = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > aux)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j + 1] = aux;
    }
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Vetor ordenado: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("\nQuantidade de trocas efetuadas: %d\n", count);
    printf("\nTempo de ordenacao: %f segundos\n", cpu_time_used);
}

int main()
{

    int n, i, opcao;

    printf("Informe a quantidade de posicoes do vetor: ");
    scanf("%d", &n);

    int arr[n];

    printf("Informe o estado inicial do vetor: \n\n ");
    printf("1 - Preenchimeto aleatório:\n\n");
    printf("2 - Preenchimento de forma decrescente:\n\n");
    scanf("%d", &opcao);

    switch (opcao)
    {

    case 1:
        srand(time(NULL));
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % 100;
        }
        break;

    case 2:
        for (i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }
        break;

    default:
        printf("Opcao invalida.\n");
        return 1;
    }
    printf("\nVetor original: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    insertion_sort(arr, n);

    return 0;
}