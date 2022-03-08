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
Obj_TCP_Serveur.SocketCreation();


	// Le socket est cr��, nous pouvons mettre en place le processus de communication
	cout<<"Serveur : Le Socket est cree !!!"<<endl;
Obj_TCP_Serveur.SocketConnexion();

Obj_TCP_Serveur.SocketEcoute();

	cout<<"Serveur : le serveur est en ecoute, il attend la connexion d'un client .... "<<endl;


Obj_TCP_Serveur.ClientAcceptation();

	cout<<"Serveur : Le serveur a accepte la demande de connexion du client."<<endl;

	cout<<"Serveur : Attente de reception d'un message"<<endl;


Obj_TCP_Serveur.MessageReception();
	// R�ception du message provenant du client
	// A compl�ter ...


	// Envoi de l'accus� de r�ception au client
        // A compl�ter ...


	// D�connexion
	// A compl�ter ...


	system("PAUSE");

	return 0;
}
