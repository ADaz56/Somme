#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

int main(int argc, char** argv) {
    traiter_commande(argc == 2, argv[0], "<port>\nmauvais nombre d'arguments");
    traiter_commande(est_nombre(argv[1]), argv[0], "<port>\n<port> doit être un nombre");

    int port = atoi(argv[1]);

    traiter_commande(port > 1024, argv[0], "<port>\n<port> est un port non réservé");
    

   
    exit(0);
}