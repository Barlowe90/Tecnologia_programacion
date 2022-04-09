#include <stdio.h>
#include <windows.h>

void despejarEntrada(void)
{
    while (getchar() != '\n')
        ;
}

void imprime_matriz(int filas, int columnas, int **array)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
            printf("%d\n", array[i][j]);
    }
}

int leer_entero(int *num)
{
    int resultado = scanf("%d", num);
    despejarEntrada();
    if (resultado != 1)
        return 1;
    return 0;
}

int main()
{
    int filas, columnas, num, resultado;

    printf("Introduce filas: ");
    scanf("%d", &filas);
    printf("Introduce columnas: ");
    scanf("%d", &columnas);

    int **array = malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++)
        array[i] = malloc(columnas * sizeof(int));

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            do
            {
                printf("Introduce el elemento [%d][%d]", i, j);
                resultado = leer_entero(&num);
                if (resultado == 1)
                    printf("Error de formato. ");
            } while (resultado != 0);
            array[i][j] = num;
        }
    }

    imprime_matriz(filas, columnas, array);

    FILE *file = fopen("file.txt", "w");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            fprintf(file, "%d ", array[i][j]);
        }
    }
    fclose(file);

    for (int i = 0; i < filas; i++)
        free(array[i]);
    free(array);

    return 0;
}