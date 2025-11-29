#include <stdio.h>
#include <string.h>
#include "usuario.h"

void menu() {
    int opc;
    char nome[100], email[100], senha[50];

    while (1) {
        printf("\n--- SISTEMA INTERNO - ELITE CAR ---\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Listar usuários\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);
        getchar(); // limpar buffer do teclado

        if (opc == 1) {
            printf("\nNome completo: ");
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = 0;

            printf("Email: ");
            fgets(email, 100, stdin);
            email[strcspn(email, "\n")] = 0;

            printf("Senha: ");
            fgets(senha, 50, stdin);
            senha[strcspn(senha, "\n")] = 0;

            if (cadastrarUsuario(nome, email, senha)) {
                printf("\nUsuário cadastrado com sucesso!\n");
            } else {
                printf("\nErro: Email já cadastrado ou limite de usuários atingido.\n");
            }
        }
        else if (opc == 2) {
            listarUsuarios();
        }
        else if (opc == 3) {
            printf("Saindo...\n");
            break;
        }
        else {
            printf("Opção inválida!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
