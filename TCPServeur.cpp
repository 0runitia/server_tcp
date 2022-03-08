#include "Bibliotheque.h"
#include "TCPServeur.h"

using namespace std;

TCPServeur::TCPServeur()
{
	int Erreur;
	Version_Requise = MAKEWORD(2,2);
	erreur_version = 2;

	/*********************************************************
	***         R�ponse � la question C-1                             *
	*********************************************************/

	Erreur = WSAStartup(Version_Requise, &VersionInfos);
	if (Erreur!=0)
	  {
		cout<<"Serveur : La version 2.2 de winsocket n'est pas installee sur cette machine"<<endl;
		erreur_version = 1;
		WSACleanup();
		system("PAUSE");
	  }
	else
	  {
		cout<<"Serveur : Winsock.dll est trouve !!"<<endl;
		cout<<"Serveur : L'etat du Serveur TCP/IP est : "<<VersionInfos.szSystemStatus<<endl;
                cout<<endl;
		erreur_version = 0;
       	  }
}



TCPServeur::~TCPServeur()
{
        cout<<"Destruction de l'objet de type TCPServeur"<<endl;

}


int TCPServeur::NumVersion()
{
        /*********************************************************
        *  R�ponse � la question C-1                             *
        *********************************************************/
        return erreur_version;   // A supprimer apr�s avoir r�pondu � C-1
}



int TCPServeur::SocketCreation()
{

	// Initialisation des donn�es pour cr�er le socket


      TCP_Socket =  INVALID_SOCKET;
	    Adresse =AF_INET;
	    type_communication = SOCK_STREAM;
	    protocole = IPPROTO_TCP;
	    DwFlag = WSA_FLAG_OVERLAPPED;

	TCP_Socket = WSASocket(Adresse, type_communication, protocole, NULL, 0, DwFlag);
        /*********************************************************
	*  R�ponse � la question C-2                             *
	*********************************************************/


	if (TCP_Socket == INVALID_SOCKET)
	{
	     cout<<"Serveur : Le Canal de Communication avec les clients n'a pas pu etre etabli pour la raison suivante : "<<endl;
	     cout<<WSAGetLastError()<<endl;
	     WSACleanup();
	     return 1;
	}
	else
	{
	     cout<<"Serveur : Le Canal de Communication avec les Clients est etabli."<<endl;
	     return 0;
	}


}


int TCPServeur::SocketConnexion()
{
	int Reponse = SOCKET_ERROR;

      adresse.sin_family = AF_INET;
	    adresse.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	    adresse.sin_port = htons(23);

	/*********************************************************
	*  R�ponse � la question C-3                             *
	*********************************************************/
	Reponse = bind(TCP_Socket,(struct sockaddr*)&adresse, sizeof(adresse));
       // Cr�ation de l'adresse physique de la liaison de communication


	if (Reponse == SOCKET_ERROR)
	{
	    cout<<"Serveur : La Connexion du Serveur n'a pas pu etre etablie pour la raison suivante : "<<endl;
	    cout<<WSAGetLastError()<<endl;
	    closesocket(TCP_Socket);
	    WSACleanup();
	    return 1;
	}
	else
	{
	    cout<<"Serveur : La Connexion du Serveur est etablie."<<endl;
	    return 0;
	}

}



int TCPServeur::SocketEcoute()
{
	int ecoute = SOCKET_ERROR;


        /*********************************************************
	*  R�ponse � la question C-4                             *
	*********************************************************/
	ecoute = listen(TCP_Socket, SOMAXCONN);


	if (ecoute == SOCKET_ERROR)
	{
	    cout<<"Serveur : La mise en ecoute du Serveur a echoue a cause de l'erreur "<<endl;
	    cout<<WSAGetLastError()<<endl;
	    closesocket(TCP_Socket);
	    WSACleanup();
	    return 1;
	}
	else
	{
	    cout<<"Serveur : La mise en ecoute du Serveur est etablie"<<endl;
	    return 0;
	}

}


int TCPServeur::ClientAcceptation()
{
        /*********************************************************
	*  R�ponse � la question C-5                             *
	*********************************************************/
	int accepter = SOCKET_ERROR;
	accepter = accept(TCP_Socket, NULL,0);

	if (accepter == SOCKET_ERROR)
	{
	     cout<<"Serveur : La connexion du Client n'est pas acceptee "<<endl;
	     cout<<WSAGetLastError()<<endl;
	     closesocket(TCP_Socket);
	     WSACleanup();
	     return 1;
	}
	else
	{
	     cout<<"Serveur : La connexion du Client est acceptee."<<endl;
	     return 0;
	}


}



int TCPServeur::MessageReception()
{
	int Reponse;
	WSABUF receptionMessage;
	DWORD NbOctetsMessage, flag = 0;
	char  MessageBuffer[T_bloc];
	receptionMessage.len = T_bloc;
	receptionMessage.buf = MessageBuffer;
	/*********************************************************
	*  R�ponse � la question C-6                             *
	*********************************************************/

Reponse = WSARecv(TCP_Socket, &receptionMessage, 1, &NbOctetsMessage, &flag, NULL,NULL);


	if (Reponse == SOCKET_ERROR)
	  {
	         cout<<"Serveur : Le client vient de se deconnecter "<< endl;
		 closesocket(TCP_Client);
		 TCP_Client = 0;
		 return 1;
	  }
	  else
	  {
			cout<<"Le message est : "<<receptionMessage.buf<<endl;

		 cout<<endl;


		 // Compl�tez l'affichage du message re�u

		 return 1;
	  }
}



int TCPServeur::Envoi_AccuseReception()
{
	int Reponse;
	DWORD NbOctetsMessage;
	WSABUF AccuseReception;
	char ContenuMessage[1024] = "Serveur : J'ai bien recu votre message\0";

	//Message de l'accus� de reception du serveur

	/*********************************************************
	*  R�ponse � la question C-7                             *
	*********************************************************/


	/*if (?????????????) / Remplacer les ?
	{
		cout<<"Serveur : L'accuse de reception n'a pas pu etre envoye au serveur client pour la raison suivante : "<<endl;
		cout<<WSAGetLastError()<<endl;
		closesocket(SocketTCP);
		WSACleanup();
		return 1;
	}
	else
	{
		cout<<"Serveur : L'accuse de reception a ete envoye au client."<<endl;
		return 0;
	}*/
	return -1;   // A supprimer apr�s avoir r�pondu � C-7

}



void TCPServeur::Fin_Connexion()
{
	/*********************************************************
	*  R�ponse � la question C-8                             *
	*********************************************************/
	cout<<"Serveur : La session de connexion est terminee."<<endl;
}
