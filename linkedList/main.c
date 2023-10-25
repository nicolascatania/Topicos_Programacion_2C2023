#include "lkdlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char frases[][MAXCOL] = {
        "Clase espejo LPU y UNLAM",
        "Linked lists",
        "Prueba",
        "Linked list circular, una o dos vias, etc",
        "Esta es otra frase de prueba"
    };

    char quote[]={"Something..."};
    int i;

    tNode* head;

    createLinkedList(&head);

    for (i = 0; i < sizeof(frases) / sizeof(frases[0]); i++) {
        insertNodeAtEnd(&head, frases[i], strlen(frases[i]) + 1);
    }


    deleteNode(&head, 2); //deletes "prueba"

    addNodeAnyPosition(&head,quote,strlen(quote)+1,2);

    operateLinkedList(&head,showStringNode);

    deleteLinkedList(&head);



    return 0;
}
