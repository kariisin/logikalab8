#define _CRT_SECURE_NO_WARNINGS_
#include <queue>
#include <iostream>

using namespace std;
std::queue<int> Q;

int** createG(int size) {
    int** G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            else {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }
    return G;
}

void printG(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void BFS(int** G, int nG, int s, int* vis) {
    if (s < 0 || s >= nG) {
        printf("Ошибка: стартовая вершина вне диапазона!\n");
        return;
    }

    Q.push(s);
    vis[s] = 1;
    printf("%d ", s);

    while (!Q.empty()) {
        s = Q.front();
        Q.pop();

        for (int i = 0; i < nG; i++) {
            if (G[s][i] == 1 && vis[i] == 0) {
                Q.push(i);
                vis[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    int** G = NULL;
    int nG, s;

    printf("Введите размер графа: ");
    scanf("%d", &nG);

    if (nG <= 0) {
        printf("Ошибка: размер графа должен быть положительным числом!\n");
        return 1;
    }

    G = createG(nG);
    printG(G, nG);

    printf("Введите стартовую вершину: ");
    scanf("%d", &s);

    int* vis = (int*)malloc(nG * sizeof(int));
    if (!vis) {
        printf("Ошибка: не удалось выделить память для массива vis!\n");
        return 1;
    }

    for (int i = 0; i < nG; i++) {
        vis[i] = 0;
    }

    BFS(G, nG, s, vis);



    return 0;
}
