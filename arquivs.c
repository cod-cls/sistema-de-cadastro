#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "posto.h"

FILE *fp ;

void abrirAquivo()
{
    fp = fopen("postos.txt", "rb+");

    if (fp == NULL)
    {
        fp = fopen("postos.txt", "wb+");
        if (fp == NULL)
        {
            printf("Erro ao criar arquivo\n");
            exit(1);
        }

    }
}

void fecharArquivo()
{
	fclose(fp);
}

void salvarArquivo()
{
	posto a;
	system("cls");
	mostrarTelaCadastro();
	a = novoPosto();

	fseek(fp,0,SEEK_END);

	fwrite(&a, sizeof(posto), 1, fp);

	system("cls");
	TextColor(10);

	int co[4] = {20, 9, 120, 13};

    caixa(co[0], co[1], co[2], co[3]);
    gotoxy(30,11);
    printf("arquivo salvo!\n");
}

void listarAquivo()
{
    system("cls");
    posto a;
    fseek(fp,0,SEEK_SET);
    int co[4] = {20, 3, 120, 26};
    int contador = 0;

    int y = 12;
    int coord[4] = {10, 12, 110, 35};


    while(fread(&a, sizeof(posto), 1, fp))
    {

        if(!strcmp(a.codigo, "0") == 0)
        {
            TextColor(5);
            caixa(coord[0], coord[1], coord[2], coord[3]);
            contador++;

            TextColor(15);

            gotoxy(20,y + 3);
            printf("Codigo: ");
            gotoxy(40,y + 3);
            printf("%s\n", a.codigo);
            caixa(38,y + 2,100, y + 4);

            gotoxy(20,y + 6);
            printf("Nome: ");
            gotoxy(40, y + 6);
            printf("%s\n", a.nome_fantasia);
            caixa(38,y + 5,100, y + 7);

            gotoxy(20, y + 9);
            printf("P.Gasolina: ");
            gotoxy(40, y + 9);
            printf("%s\n", a.p_gasolina);
            caixa(38,y + 8,100, y + 10);

            gotoxy(20,y + 12);
            printf("P.Etanol: ");
            gotoxy(40,y + 12);
            printf("%s\n", a.p_etanol);
            caixa(38,y + 11,100, y + 13);

            gotoxy(20, y + 15);
            printf("P.Diesel: ");
            gotoxy(40, y + 15);
            printf("%s\n", a.p_diesel);
            caixa(38, y + 14,100, y + 16);

            gotoxy(20,y + 18);
            printf("P.Troca de Oleo: ");
            gotoxy(40,y + 18);
            printf("%s\n", a.p_trocaoleo);
            caixa(38,y + 17,100, y + 19);

            gotoxy(20,y + 21);
            printf("Bandeira: ");
            gotoxy(40, y + 21);
            printf("%s\n", a.bandeira);
            caixa(38, y + 20,100, y + 22);

            y += 27;
            coord[1] += 27;
            coord[3] += 27;
        }

        if(0)
        {
            system("cls");
            TextColor(4);
            caixa(co[0], co[1] + 5, co[2], co[3] - 14);
            gotoxy(30,10);
            printf("NAO HA PESSOAS CADASTRADAS!\n");
        }
    }

    gotoxy(45,10);
    TextColor(BACKGROUND_BLUE);
    printf("%i PESSOA(S) ENCONTRADOS\n", contador);
}

void alterarArquivo(char str[], char str2[])
{
    TextColor(11);
    int co[4] = {10, 3, 110, 26};
    int contador = 0;
    int xy[2] = {30, 10};
    int op;
    char pesquisa[100];
    posto a;

    system("cls");
    gotoxy(50, 7);
    TextColor(BACKGROUND_BLUE);
    printf("ALTERAR REGISTRO");
    int co2[4] = {10, 10, 110, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(13,10);
    printf("%s", str);
    caixa(45,9,100,11);
    gotoxy(46, 10);
    scanf("%s", pesquisa);
    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&a, sizeof(posto), 1, fp))
        {
            if (strcmp(a.codigo, pesquisa) == 0)
            {
                contador++;
                TextColor(1);
                system("cls");
                caixa(co[0]-5, co[1], co[2], co[3] + 8);

                gotoxy(55,6);
                TextColor(BACKGROUND_BLUE);
                printf("ALTERAR REGISTRO\n");
                TextColor(15);

                gotoxy(19,10);
                printf("Codigo: ");
                gotoxy(40,10);
                printf("%s\n", a.codigo);
                caixa(38,9,100,11);

                gotoxy(19,13);
                printf("Nome: ");
                gotoxy(40,13);
                printf("%s\n", a.nome_fantasia);
                caixa(38,12,100,14);

                gotoxy(19,16);
                printf("P.Gasolina: ");
                gotoxy(40,16);
                printf("%s\n", a.p_gasolina);
                caixa(38,15,100,17);

                gotoxy(19,19);
                printf("P.Etanol: ");
                gotoxy(40,19);
                printf("%s\n", a.p_etanol);
                caixa(38,18,100,20);

                gotoxy(19,22);
                printf("P.Diesel: ");
                gotoxy(40,22);
                printf("%s\n", a.p_diesel);
                caixa(38,21,100,23);

                gotoxy(19,25);
                printf("P.Troca de Oleo: ");
                gotoxy(40,25);
                printf("%s\n", a.p_trocaoleo);
                caixa(38,24,100,26);

                gotoxy(19,28);
                printf("Bandeira: ");
                gotoxy(40,28);
                printf("%s\n", a.bandeira);
                caixa(38,27,100,29);

                gotoxy(40,32);
                TextColor(11);
                printf(str2);

                scanf("%i", &op);

                if(op)
                {
                    posto a;
                    system("cls");
                    mostrarTelaCadastro();
                    a = novoPosto();
                    fseek(fp, -sizeof(posto), SEEK_CUR);
                    fwrite(&a, sizeof(posto), 1, fp);
                    system("cls");


                    system("cls");

                    TextColor(1);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("POSTO ALTERADO!\n");
                }
                else
                {
                    system("cls");
                    TextColor(10);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("REGISTRO NAO ALTERADO!\n");
                }
                break;
            }
        }
    }

    if(!contador)
    {
        int co2[4] = {20, 10, 120, 13};

        TextColor(4);
        caixa(co[0], co[1] + 5, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("REGISTRO NAO ENCONTRADO!\n");

    }
}

void excluirArquivo(char str[], char str2[])
{
    int co[4] = {10, 3, 110, 26};
    int xy[2] = {30, 10};
    int op;

    char pesquisa[100];
    posto a;

    system("cls");
    gotoxy(50, 7);
    TextColor(BACKGROUND_RED);
    printf("EXCLUIR REGISTRO");
    int co2[4] = {10, 10, 110, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(12,10);
    printf("%s", str);
    caixa(43,9,100,11);
    gotoxy(45, 10);
    scanf("%s", pesquisa);
    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&a, sizeof(posto), 1, fp))
        {
            if (strcmp(a.codigo, pesquisa) == 0)
            {
                TextColor(4);
                system("cls");
                //caixa(f[0],f[1],f[2],f[3]);
                caixa(co[0], co[1], co[2], co[3] + 8);
                //TextColor(15);

                gotoxy(50,6);
                TextColor(BACKGROUND_RED);
                printf("EXCLUIR REGISTRO\n");
                TextColor(15);

                gotoxy(19,10);
                printf("Codigo: ");
                gotoxy(40,10);
                printf("%s\n", a.codigo);
                caixa(38,9,100,11);

                gotoxy(19,13);
                printf("Nome: ");
                gotoxy(40,13);
                printf("%s\n", a.nome_fantasia);
                caixa(38,12,100,14);

                gotoxy(19,16);
                printf("P.Gasolina: ");
                gotoxy(40,16);
                printf("%s\n", a.p_gasolina);
                caixa(38,15,100,17);

                gotoxy(19,19);
                printf("P.Etanol: ");
                gotoxy(40,19);
                printf("%s\n", a.p_etanol);
                caixa(38,18,100,20);

                gotoxy(19,22);
                printf("P.Diesel: ");
                gotoxy(40,22);
                printf("%s\n", a.p_diesel);
                caixa(38,21,100,23);

                gotoxy(19,25);
                printf("P.Troca de Oleo: ");
                gotoxy(40,25);
                printf("%s\n", a.p_trocaoleo);
                caixa(38,24,100,26);

                gotoxy(19,28);
                printf("Bandeira: ");
                gotoxy(40,28);
                printf("%s\n", a.bandeira);
                caixa(38,27,100,29);

                gotoxy(32,32);
                TextColor(4);
                printf(str2);

                scanf("%i", &op);

                if(op)
                {
                	posto a;
                    system("cls");
                    strcpy(a.codigo, "0");
                    strcpy(a.nome_fantasia, "0");
                    strcpy(a.p_gasolina, "0");
                    strcpy(a.p_etanol, "0");
                    strcpy(a.p_diesel, "0");
                    strcpy(a.p_trocaoleo, "0");
                    strcpy(a.bandeira, "0");

                    fseek(fp, -sizeof(posto), SEEK_CUR);

                    fwrite(&a, sizeof(posto), 1, fp);

                    system("cls");

                    TextColor(4);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("REGISTRO APAGADO!\n");
                }
                else
                {
                    system("cls");
                    TextColor(10);
                    caixa(co[0], co[1] + 5, co[2], co[3] - 14);
                    gotoxy(30,10);
                    printf("REGISTRO NAO APAGADO!\n");
                }

                break;
            }

        }
    }

    if (strcmp(a.codigo, pesquisa) != 0)
    {
        int co2[4] = {20, 10, 120, 13};

        TextColor(4);
        caixa(co[0], co[1] + 5, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("REGISTRO NAO ENCONTRADO!\n");

    }
}

void pesquisarArquivo(char str[])
{
    int co[4] = {10, 3, 110, 26};
    int xy[2] = {30, 10};

    char pesquisa[100];
    posto a;

    system("cls");
    gotoxy(50, 7);
    TextColor(BACKGROUND_GREEN);
    printf("PESQUISAR REGISTRO");
    int co2[4] = {10, 10, 110, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(12,10);
    printf("%s", str);
    caixa(43,9,100,11);
    gotoxy(46, 10);
    scanf("%s", pesquisa);
    system("cls");

    fseek(fp,0,SEEK_SET);
    while (!feof(fp))
    {
        if (fread(&a, sizeof(posto), 1, fp))
        {
            if (strcmp(a.codigo, pesquisa) == 0)
            {
                TextColor(10);
                system("cls");
                caixa(co[0], co[1] + 5, co[2], co[3] + 5);
                TextColor(15);

                gotoxy(19,10);
                printf("Codigo: ");
                gotoxy(40,10);
                printf("%s\n", a.codigo);
                caixa(38,9,100,11);

                gotoxy(19,13);
                printf("Nome: ");
                gotoxy(40,13);
                printf("%s\n", a.nome_fantasia);
                caixa(38,12,100,14);

                gotoxy(19,16);
                printf("P.Gasolina: ");
                gotoxy(40,16);
                printf("%s\n", a.p_gasolina);
                caixa(38,15,100,17);

                gotoxy(19,19);
                printf("P.Etanol: ");
                gotoxy(40,19);
                printf("%s\n", a.p_etanol);
                caixa(38,18,100,20);

                gotoxy(19,22);
                printf("P.Diesel: ");
                gotoxy(40,22);
                printf("%s\n", a.p_diesel);
                caixa(38,21,100,23);

                gotoxy(19,25);
                printf("P.Troca de Oleo: ");
                gotoxy(40,25);
                printf("%s\n", a.p_trocaoleo);
                caixa(38,24,100,26);

                gotoxy(19,28);
                printf("Bandeira: ");
                gotoxy(40,28);
                printf("%s\n", a.bandeira);
                caixa(38,27,100,29);

                break;
            }

        }
    }

    if (strcmp(a.codigo, pesquisa) != 0)
    {
        int co2[4] = {20, 10, 120, 13};

        TextColor(4);
        caixa(co[0], co[1] + 5, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("REGISTRO NAO ENCONTRADO!\n");

    }
}

void criarRelatorio()
{
    system("cls");

    posto a;
    fseek(fp,0,SEEK_SET);

    FILE *file;

    char arquivo[100];
    int co[4] = {20,2, 120, 26};
    int contador = 0;
    system("cls");

    gotoxy(68, 7);
    TextColor(BACKGROUND_INTENSITY);
    printf("CRIAR RELATORIO");
    int co2[4] = {20, 10, 120, 13};
    TextColor(15);
    caixa(co2[0], co[1] + 2, co[2], co[3] -13);
    gotoxy(30,10);
    printf("Digite o nome do documento: ");
    caixa(58,9,110,11);
    gotoxy(60, 10);

    scanf("%s", arquivo);
//    fgets(arquivo, sizeof(arquivo), stdin);
//    fflush(stdin);
    strcat(arquivo, ".txt");

    file = fopen(arquivo, "w");

    char codigo[101];
    char nome_fantasia[51];
    char p_gasolina[6];
    char p_etanol[11];
    char p_diesel[31];
    char p_trocaoleo[31];
    char bandeira[31];


    while(fread(&a, sizeof(posto), 1, fp))
    {

        if(!strcmp(a.nome_fantasia, "0") == 0)
        {
            contador++;

            strcpy(codigo, a.codigo);
            strcpy(nome_fantasia, a.nome_fantasia);
            strcpy(p_gasolina, a.p_gasolina);
            strcpy(p_etanol, a.p_etanol);
            strcpy(p_diesel, a.p_diesel);
            strcpy(p_trocaoleo, a.p_trocaoleo);
            strcpy(bandeira, a.bandeira);

            fprintf(file, "Codigo: %s\n", codigo);
            fprintf(file, "Nome: %s\n", nome_fantasia);
            fprintf(file, "P.Gasolina: %s\n", p_gasolina);
            fprintf(file, "P.Etanol: %s\n", p_etanol);
            fprintf(file, "P.Diesel: %s\n", p_diesel);
            fprintf(file, "P.Troca de Oleo: %s\n", p_trocaoleo);
            fprintf(file, "Bandeira: %s\n", bandeira);
            fprintf(file, "\n\n");
        }
    }


    fclose(file);

    system("cls");

    if(!contador)
    {
        system("cls");
        TextColor(4);
        caixa(co[0], co[1] + 6, co[2], co[3] - 14);
        gotoxy(30,10);
        printf("NAO HA POSTOS CADASTRADOS!\n");
    }

    else
    {
        TextColor(10);
        caixa(co[0], co[1] + 6, co[2], co[3] -13);

        gotoxy(30,10);
        printf("Arquivo %s criado!", arquivo);
    }
}


