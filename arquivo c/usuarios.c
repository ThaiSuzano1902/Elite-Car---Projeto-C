#include <stdio.h>
#include <string.h>
#include "usuario.h"

struct Usuario bancoUsuarios[MAX_USUARIOS];
int totalUsuarios = 0;

int cadastrarUsuario(char nome[], char email[], char senha[]) {

    // Verificar se já existe email igual
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(bancoUsuarios[i].email, email) == 0) {
            return 0; // Email já existe
        }
    }

    // Criar novo usuário
    struct Usuario novoUsuario;
    novoUsuario.id = totalUsuarios + 1;

    strcpy(novoUsuario.nome, nome);
    strcpy(novoUsuario.email, email);
    strcpy(novoUsuario.senha, senha);

    // Gravar no banco
    bancoUsuarios[totalUsuarios] = novoUsuario;
    totalUsuarios++;

    return 1; // Sucesso
}

void listarUsuarios() {
    printf("\n--- LISTA DE USUÁRIOS CADASTRADOS ---\n");

    if (totalUsuarios == 0) {
        printf("Nenhum usuário cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d | Nome: %s | Email: %s\n",
               bancoUsuarios[i].id,
               bancoUsuarios[i].nome,
               bancoUsuarios[i].email);
    }
}
