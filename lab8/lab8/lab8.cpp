#include <iostream>
#include <queue>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
std::queue <int> Q;

int** createG(int size) {
	int** G;
	G = (int**)malloc(size * sizeof(int*));
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


int* vis = NULL;

void BFS(int** G, int nG, int s) {
	Q.push(s);
	vis[s] = 1;
	printf("%d", s);
	while (!Q.empty()) {
		s = Q.front();

		Q.pop();

		for (int i = 0; i < nG; i++) {
			if (G[s][i] == 1 && vis[i] == 0) {
				Q.push(i);
				vis[i] = 1;
				printf(" %d ", i);
			}
		}
	}
}

int main(void)
{
	setlocale(LC_ALL, "");
	int** G = NULL;
	int nG, s;
	printf("Введите размер графа : ");
	scanf("%d", &nG);
	G = createG(nG);
	printG(G, nG);
	printf("Введите стартовую вершину: ");
	scanf("%d", &s);

	vis = (int*)malloc(nG * sizeof(int));
	for (int i = 0; i < nG; i++) {
		vis[i] = 0;
	}
	BFS(G, nG, s);
}