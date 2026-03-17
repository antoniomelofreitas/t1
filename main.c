#include <stdio.h>

#define MAX 5

// PILHA
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void iniciaPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilha(Pilha *p, int valor) {
    if (!pilhaCheia(p)) {
        p->topo++;
        p->dados[p->topo] = valor;
    } else {
        printf("Pilha cheia!\n");
    }
}

int desempilha(Pilha *p) {
    if (!pilhaVazia(p)) {
        int valor = p->dados[p->topo];
        p->topo--;
        return valor;
    } else {
        printf("Pilha vazia!\n");
        return -1;
    }
}

//  FILA 
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void iniciaFila(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == MAX;
}

void enfileira(Fila *f, int valor) {
    if (!filaCheia(f)) {
        f->fim = (f->fim + 1) % MAX;
        f->dados[f->fim] = valor;
        f->tamanho++;
    } else {
        printf("Fila cheia!\n");
    }
}

int desenfileira(Fila *f) {
    if (!filaVazia(f)) {
        int valor = f->dados[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        f->tamanho--;
        return valor;
    } else {
        printf("Fila vazia!\n");
        return -1;
    }
}

//  DEQUE
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Deque;

void iniciaDeque(Deque *d) {
    d->inicio = 0;
    d->fim = -1;
    d->tamanho = 0;
}

int dequeVazio(Deque *d) {
    return d->tamanho == 0;
}

int dequeCheio(Deque *d) {
    return d->tamanho == MAX;
}

void insereFrente(Deque *d, int valor) {
    if (!dequeCheio(d)) {
        d->inicio = (d->inicio - 1 + MAX) % MAX;
        d->dados[d->inicio] = valor;
        d->tamanho++;
        if (d->tamanho == 1)
            d->fim = d->inicio;
    } else {
        printf("Deque cheio!\n");
    }
}

void insereFim(Deque *d, int valor) {
    if (!dequeCheio(d)) {
        d->fim = (d->fim + 1) % MAX;
        d->dados[d->fim] = valor;
        d->tamanho++;
    } else {
        printf("Deque cheio!\n");
    }
}

int removeFrente(Deque *d) {
    if (!dequeVazio(d)) {
        int valor = d->dados[d->inicio];
        d->inicio = (d->inicio + 1) % MAX;
        d->tamanho--;
        return valor;
    } else {
        printf("Deque vazio!\n");
        return -1;
    }
}

int removeFim(Deque *d) {
    if (!dequeVazio(d)) {
        int valor = d->dados[d->fim];
        d->fim = (d->fim - 1 + MAX) % MAX;
        d->tamanho--;
        return valor;
    } else {
        printf("Deque vazio!\n");
        return -1;
    }
}

//  MAIN PARA TESTAR
int main() {
    Pilha p;
    Fila f;
    Deque d;

    iniciaPilha(&p);
    iniciaFila(&f);
    iniciaDeque(&d);

    // Testa pilha
    empilha(&p, 1);
    empilha(&p, 2);
    printf("Pop pilha: %d\n", desempilha(&p));
    printf("Pop pilha: %d\n", desempilha(&p));
    printf("Pop pilha: %d\n", desempilha(&p)); // vazia

    // Testa fila
    enfileira(&f, 10);
    enfileira(&f, 20);
    printf("Dequeue fila: %d\n", desenfileira(&f));
    printf("Dequeue fila: %d\n", desenfileira(&f));
    printf("Dequeue fila: %d\n", desenfileira(&f)); // vazia

    // Testa deque
    insereFrente(&d, 100);
    insereFim(&d, 200);
    printf("Remove frente deque: %d\n", removeFrente(&d));
    printf("Remove fim deque: %d\n", removeFim(&d));
    printf("Remove frente deque: %d\n", removeFrente(&d)); // vazio

    return 0;
}
