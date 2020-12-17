#ifndef POSTO_H_INCLUDED
#define POSTO_H_INCLUDED

struct postos {
	char codigo[101];
    char nome_fantasia[51] ;
    char p_gasolina[6] ;
    char p_etanol[11] ;
    char p_diesel[31] ;
    char p_trocaoleo[1] ;
    char bandeira[31] ;
};

typedef struct postos posto ;

posto novoPosto();
void listarArquivo();
void abrirArquivo();
void fecharArquivo();
void mostrarTelaCadastro();

#endif

