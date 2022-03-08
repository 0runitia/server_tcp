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
	
	Erreur = -1;	// a supprimer une fois la bonne fonction choisie
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
		cout<<"Serveur : L'etat du Serveur TCP/IP est : "; // A compl�ter de fa�on � r�pondre totalement � C-1
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
        return -1;   // A supprimer apr�s avoir r�pondu � C-1
}



int TCPServeur::SocketCreation()
{

	// Initialisation des donn�es pour cr�er le socket
	
    /*
        TCP_Socket =  ???;
	    Adresse =???;
	    type_communication = ???;
	    protocole = ???;
	    DwFlag = ????;
	*/

        /*********************************************************
	*  R�ponse � la question C-2                             *
	*********************************************************/
	 

	/*if (???????) // Remplacer les ? 
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
	}*/
	return -1;   // A supprimer apr�s avoir r�pondu � C-2
 
}


int TCPServeur::SocketConnexion()
{
	int Reponse;

	// Initialisation des donn�es pour faire cette connexion
	/*
        adresse.sin_family = ???;
	    adresse.sin_addr.S_un.S_addr = ???;
	    adresse.sin_port = ???;
	*/

	/*********************************************************
	*  R�ponse � la question C-3                             *
	*********************************************************/
       
       // Cr�ation de l'adresse physique de la liaison de communication


	/*if (??????????) // Remplacer les ? 
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
	}*/
       	return -1;   // A supprimer apr�s avoir r�pondu � C-3

}



int TCPServeur::SocketEcoute()
{
	int reponse;

	
        /*********************************************************
	*  R�ponse � la question C-4                             *
	*********************************************************/
	


	/*if (??????????????) // Remplacer les ? 
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
	}*/
	return -1;   // A supprimer apr�s avoir r�pondu � C-4

}



int TCPServeur::ClientAcceptation()
{
        /*********************************************************
	*  R�ponse � la question C-5                             *
	*********************************************************/
		

	/*if (????????????) // Remplacer les ? 
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
	}*/
	return -1;   // A supprimer apr�s avoir r�pondu � C-5

}



int TCPServeur::MessageReception()
{
	int Reponse;
	WSABUF receptionMessage;
	DWORD NbOctetsMessage, flag = 0;
	char  MessageBuffer[T_bloc];

	/*********************************************************
	*  R�ponse � la question C-6                             *
	*********************************************************/


	// R�ception du message du client
	// Appeler la bonne fonction

	/*if (?????????????????????) // Remplacer les ? 
	  {
	         cout<<"Serveur : Le client vient de se deconnecter "<< endl;
		 closesocket(TCP_Client);
		 TCP_Client = 0;
		 return 1;
	  }
	  else
	  {
	
	         // Affichage du message re�u
		 cout<<endl;

	
		 // Compl�tez l'affichage du message re�u         
		
		 return 0;
	  }
	*/
	return -1;   // A supprimer apr�s avoir r�pondu � C-6
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

