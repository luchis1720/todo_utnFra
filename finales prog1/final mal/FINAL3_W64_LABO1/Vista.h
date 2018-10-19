#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED


#define MENU_PPAL_ES "\n1. Listar Clientes\n2. Agregar un cliente\n3. Elimina un cliente\n4. Edita un cliente\n10. Salir\n"

#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"




int vista_init (void);

int vista_mostrarMenu(void);

void vista_mostrarSocios(ArrayList* pListaSocios);

void vista_mostrarError(char *);





