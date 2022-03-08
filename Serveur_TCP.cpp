#include "Bibliotheque.h"
#include "TCPServeur.h"

using namespace std;


int main()
{

	TCPServeur Obj_TCP_Serveur;


        // V�rification de la version
	if (Obj_TCP_Serveur.NumVersion()!=0)
		return 0;


	// Cr�ation du canal internet de communication avec les clients



	// Le socket est cr��, nous pouvons mettre en place le processus de communication
	cout<<"Serveur : Le Socket est cree !!!"<<endl;



	// Cr�ation de l'adresse physique de la liaison de communication
	// Le serveur est physiquement en place.
        // A compl�ter ...



	// Mise en �coute du serveur
        // A compl�ter ...

	cout<<"Serveur : le serveur est en ecoute, il attend la connexion d'un client .... "<<endl;



        // Attente d'une demande de connexion du client
	// A compl�ter ...

	cout<<"Serveur : Le serveur a accepte la demande de connexion du client."<<endl;

	cout<<"Serveur : Attente de reception d'un message"<<endl;



	// R�ception du message provenant du client
	// A compl�ter ...



	// Envoi de l'accus� de r�ception au client
        // A compl�ter ...


	// D�connexion
	// A compl�ter ...


	system("PAUSE");

	return 0;
}
