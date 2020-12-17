#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "posto.h"

int menu(){
    //caixa(20,2,100,25);
    //caixa do menu
    TextColor(9);
    caixa(10, 3, 110, 7);
    // this will return an option that you can use

    char opcoes[6][15] = {"Cadastrar", "Alterar", "Excluir", "Pesquisar", "Listar", "Relatorio"};

    int cols[6] = {20, 35, 50, 65, 80, 95};
    int opcao = 0, i, tecla;
    TextColor(15);
    for(i=0;i<6;i++)
    {
        gotoxy(cols[i], 5);
        printf("%-8s", opcoes[i]);
    }
    while(1){
        TextColor(BACKGROUND_INTENSITY);
        gotoxy(cols[opcao], 5);
        printf("%-8s", opcoes[opcao]);
        tecla = getch();
        if (tecla == 27)
			break;
        TextColor(7);
        gotoxy(cols[opcao],5);
        printf("%-8s", opcoes[opcao]);
        if (tecla == 77)
			opcao++;
        if (tecla == 75)
			opcao--;
        if (tecla == 13) {
            // printf("%i", opcao);
            return opcao;
        }

        if (opcao < 0) opcao = 5;
        if (opcao > 5) opcao = 0;
    }

}
void mostrarTelaCadastro(){
    TextColor(9);
    int co[4] = {10, 7, 110, 31};
    caixa(co[0], co[1], co[2], co[3]);
    TextColor(14);

    TextColor(15);
                gotoxy(21,10);
                printf("Codigo: ");

                caixa(38,9,100,11);

                gotoxy(21,13);
                printf("Nome: ");

                caixa(38,12,100,14);

                gotoxy(21,16);
                printf("P. Gasolina: ");

                caixa(38,15,100,17);

                gotoxy(21,19);
                printf("P.Etanol: ");

                caixa(38,18,100,20);

                gotoxy(21,22);
                printf("P.Diesel: ");

                caixa(38,21,100,23);

                gotoxy(21,25);
                printf("P.Troca de Oleo: ");

                caixa(38,24,100,26);

                gotoxy(21,28);
                printf("Bandeira: ");

                caixa(38,27,100,29);
}
int handleMenuOptions()
{
    int opcao = menu();

      while(opcao != 8) {
        system("cls");
        switch(opcao) {
            case 0:
                salvarArquivo();
                break;
            case 1:
                alterarArquivo("Digite o codigo do posto: ", "VOCE QUER ALTERAR DADOS DESSE POSTO? 0 -> Nao 1 -> Sim ");
                break;
            case 2:
                excluirArquivo("Digite o codigo do posto: ", "VOCE TEM CERTEZA QUE QUER EXCLUIR ESSE POSTO? 0 -> Nao 1 -> Sim ");
                break;
            case 3:
                pesquisarArquivo("Digite o codigo do posto: ");
                break;
            case 4:
                listarAquivo();
                break;
            case 5:
                criarRelatorio();
                break;
        }

        opcao = menu();

    }
}
