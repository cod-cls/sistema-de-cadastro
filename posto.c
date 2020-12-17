#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "posto.h"

posto novoPosto() {
	posto a ;

	gotoxy(40, 10);
    scanf("%s", a.codigo);
    setbuf(stdin,NULL);

	gotoxy(40, 13);
    scanf("%[^\n]s", a.nome_fantasia);
    setbuf(stdin,NULL);

    gotoxy(40, 16);
    scanf("%s", a.p_gasolina);
    setbuf(stdin,NULL);

    gotoxy(40, 19);
    scanf("%s", a.p_etanol) ;
    setbuf(stdin,NULL);

    gotoxy(40, 22);
    scanf("%s", a.p_diesel);
    setbuf(stdin,NULL);

    gotoxy(40, 25);
    scanf("%s", a.p_trocaoleo);
    setbuf(stdin,NULL);

    gotoxy(40, 28);
    scanf("%[^\n]s", a.bandeira);
    setbuf(stdin,NULL);

    return a ;
}

