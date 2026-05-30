#include <stdio.h>

// Função: Selection Sort
// Ordena o vetor em ordem crescente
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        
        // Encontra o índice do elemento mínimo
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Troca o elemento encontrado com a primeira posição
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Função: Binary Search
// Busca um elemento em vetor ordenado
// Retorna o índice se encontrado, -1 caso contrário
int binary_search(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Encontrado!
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // Procurar na metade direita
        }
        else {
            right = mid - 1;  // Procurar na metade esquerda
        }
    }
    
    return -1;  // Não encontrado
}

// Função auxiliar: Imprime o vetor
void print_array(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Programa Principal
int main() {
    int a[] = {5, 8, 10, 20, 40, 8};
    int n = 6;
    
    printf("Vetor original: ");
    print_array(a, n);
    
    // Ordena com selection sort
    selection_sort(a, n);
    printf("Vetor ordenado: ");
    print_array(a, n);
    
    // Realiza buscas binárias
    printf("\n--- Buscas Binárias ---\n");
    
    int alvos[] = {8, 20, 40, 100, 5};
    int num_alvos = 5;
    
    for (int i = 0; i < num_alvos; i++) {
        int resultado = binary_search(a, n, alvos[i]);
        if (resultado != -1) {
            printf("Elemento %d encontrado no índice %d\n", alvos[i], resultado);
        }
        else {
            printf("Elemento %d não encontrado\n", alvos[i]);
        }
    }
    
    return 0;
}
