class TCPServeur
{
   private :
	SOCKET TCP_Socket;
	SOCKET TCP_Client;
	SOCKADDR_IN adresse;
	int Adresse;
	int type_communication;
	int protocole;
	DWORD DwFlag;
	WSADATA VersionInfos;
	WORD Version_Requise;
	int erreur_version;


   public:
	TCPServeur();
	~TCPServeur();
	int NumVersion();
	int SocketCreation();
	int SocketConnexion();
	int SocketEcoute();
	int ClientAcceptation();
	int MessageReception();
	int Envoi_AccuseReception();
	void Fin_Connexion();
};

