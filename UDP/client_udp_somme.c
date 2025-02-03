#include "udp.h"
#include "erreur.h"
#include "nombre.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>


int main(int argc, char** argv) {
    // Vérifier si le nombre correct d'arguments est fourni
    traiter_commande(argc == 3, argv[0], "<adresse IP> <port>\nmauvais nombre d'arguments");

    // Valider le format de l'adresse IP
    struct in_addr addr;
    traiter_commande(inet_pton(AF_INET, argv[1], &addr) == 1, argv[0], "<adresse IP> <port>\n<adresse IP> est une adresse IP au format décimal pointé");

    // Valider que le port est un nombre et non réservé
    traiter_commande(est_un_nombre(argv[2]), argv[0], "<adresse IP> <port>\n<port> doit être un nombre");
    int port = atoi(argv[2]);
    traiter_commande(port > 1024, argv[0], "<adresse IP> <port>\n<port> est un port non réservé");

    // Créer et attacher une socket
    SOCK sock;
    creer_socket(argv[1], port, &sock);
    attacher_socket(&sock);

    // Logique supplémentaire pour votre programme peut être ajoutée ici
    // Par exemple, envoyer ou recevoir des messages en utilisant la socket

    // Fermer la connexion de la socket
    fermer_connexion(&sock);

    exit(0);
}

// Implémentation de la fonction traiter_commande
void traiter_commande(int condition, const char* prog_name, const char* usage_msg) {
    if (!condition) {
        fprintf(stderr, "Usage: %s %s\n", prog_name, usage_msg);
        exit(EXIT_FAILURE);
    }
}