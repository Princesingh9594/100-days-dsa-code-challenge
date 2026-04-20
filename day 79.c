#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

Node* adj[MAX];

Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v, int w) {
    Node* node = createNode(v, w);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u, w);
    node->next = adj[v];
    adj[v] = node;
}

typedef struct {
    int v, dist;
} HeapNode;

HeapNode heap[MAX];
int size = 0;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int i) {
    while (i && heap[i].dist < heap[(i - 1) / 2].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < size && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

void push(int v, int dist) {
    heap[size].v = v;
    heap[size].dist = dist;
    heapifyUp(size);
    size++;
}

HeapNode pop() {
    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (size > 0) {
        HeapNode curr = pop();
        int u = curr.v;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < MAX; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
