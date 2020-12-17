#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "posto.h"
int main() {
	abrirAquivo();
    handleMenuOptions();
    fecharArquivo();
    return 0;
}
