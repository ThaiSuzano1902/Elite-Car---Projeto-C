#ifndef USUARIO_H
#define USUARIO_H

#define MAX_USUARIOS 100

struct Usuario {
    int id;
    char nome[100];
    char email[100];
    char senha[50];
};

// Variáveis globais
extern struct Usuario bancoUsuarios[MAX_USUARIOS];
extern int totalUsuarios;

// Funções
int cadastrarUsuario(char nome[], char email[], char senha[]);
void listarUsuarios();

#endif
