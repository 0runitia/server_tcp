#include "Bibliotheque.h"
#include "TCPServeur.h"

using namespace std;


int main()
{
	 
	TCPServeur Obj_TCP_Serveur;
    

        // Vérification de la version
	if (Obj_TCP_Serveur.NumVersion()!=0)
		return 0;


	// Création du canal internet de communication avec les clients 
        // A compléter ...


	// Le socket est créé, nous pouvons mettre en place le processus de communication
	cout<<"Serveur : Le Socket est cree !!!"<<endl;	



	// Création de l'adresse physique de la liaison de communication
	// Le serveur est physiquement en place.
        // A compléter ...



	// Mise en écoute du serveur        
        // A compléter ...

	cout<<"Serveur : le serveur est en ecoute, il attend la connexion d'un client .... "<<endl;
	


        // Attente d'une demande de connexion du client
	// A compléter ...

	cout<<"Serveur : Le serveur a accepte la demande de connexion du client."<<endl;
	
	cout<<"Serveur : Attente de reception d'un message"<<endl;



	// Réception du message provenant du client
	// A compléter ...



	// Envoi de l'accusé de réception au client
        // A compléter ...


	// Déconnexion
	// A compléter ...


	system("PAUSE");

	return 0;
}

