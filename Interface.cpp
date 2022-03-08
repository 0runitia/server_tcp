#include <windows.h>
#include <stdio.h>

HINSTANCE instance;

#define ID_PUSHBUTTON_1     110
#define ID_PUSHBUTTON_2     111
#define ID_PUSHBUTTON_3     112
#define ID_CHECKBOX_1       113
#define ID_CHECKBOX_2       114
#define ID_CHECKBOX_3       115
#define ID_CHECKBOX_4       116
#define ID_RADIOBUTTON_11   117
#define ID_RADIOBUTTON_12   118
#define ID_RADIOBUTTON_13   119
#define ID_RADIOBUTTON_21   120
#define ID_RADIOBUTTON_22   121
#define ID_RADIOBUTTON_23   122

VOID RemplieFenetrePrincipale(HWND fenetrePrincipale)
{
    // Premier groupe: le push button
    HWND hGroup=CreateWindow(
        "BUTTON",
        "Le push button",
        WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
        10,10,
        120,150,
        fenetrePrincipale,
        NULL,
        instance,
        NULL);
    {
        HWND hControle;
        // On le remplit avec un premier push button tout bête
        hControle=CreateWindow(
            "BUTTON",
            "Button 1",
            WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
            10+10,10+20,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_PUSHBUTTON_1,
            instance,
            NULL);
        // un second avec quelques flags : plat et plusieurs lignes
        hControle=CreateWindow(
            "BUTTON",
            "Button 2: texte long",
            WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|BS_FLAT|BS_MULTILINE,
            10+10,10+50,
            100,40,
            fenetrePrincipale,
            (HMENU)ID_PUSHBUTTON_2,
            instance,
            NULL);
        // et un troisième un peu plus exotique, c'est aussi le bouton par défaut de la fenêtre
        // on lui met aussi une image alignée à gauche
        hControle=CreateWindow(
            "BUTTON",
            "",
            WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON|BS_ICON|BS_LEFT,
            10+10,10+100,
            100,40,
            fenetrePrincipale,
            (HMENU)ID_PUSHBUTTON_3,
            instance,
            NULL);

        HANDLE hIcon=LoadIcon(NULL,IDI_ERROR);
        SendMessage(hControle,BM_SETIMAGE,IMAGE_ICON,(LPARAM)hIcon);
    }
    // Deuxième groupe: les check box
    hGroup=CreateWindow(
        "BUTTON",
        "La check box",
        WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
        130,10,
        120,150,
        fenetrePrincipale,
        NULL,
        instance,
        NULL);
    {
        HWND hControle;
        // une check box automatique deux états
        hControle=CreateWindow(
            "BUTTON",
            "Check box 1",
            WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX,
            130+10,10+20,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_CHECKBOX_1,
            instance,
            NULL);
        // le même mais plat, et avec le texte à gauche de la case à cocher
        hControle=CreateWindow(
            "BUTTON",
            "Check box 2",
            WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX|BS_FLAT|BS_LEFTTEXT,
            130+10,10+50,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_CHECKBOX_2,
            instance,
            NULL);

        // une autre check box simple automatique mais trois états
        hControle=CreateWindow(
            "BUTTON",
            "Check box 3",
            WS_CHILD|WS_VISIBLE|BS_AUTO3STATE,
            130+10,10+80,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_CHECKBOX_3,
            instance,
            NULL);

        // le même mais non automatique :)
        hControle=CreateWindow(
            "BUTTON",
            "Check box 4",
            WS_CHILD|WS_VISIBLE|BS_3STATE,
            130+10,10+110,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_CHECKBOX_4,
            instance,
            NULL);
    }
    // troisième groupe : les radio button
    hGroup=CreateWindow(
        "BUTTON",
        "Le radio button",
        WS_CHILD|WS_VISIBLE|BS_GROUPBOX,
        10,160,
        240,110,
        fenetrePrincipale,
        NULL,
        instance,
        NULL);
    {
        HWND hControle;
        // trois radio button
        hControle=CreateWindow(
            "BUTTON",
            "Choix 1.1",
            WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON|WS_GROUP,
            10+10,160+20,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_RADIOBUTTON_11,
            instance,
            NULL);

        hControle=CreateWindow(
            "BUTTON",
            "Choix 1.2",
            WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,
            10+10,160+50,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_RADIOBUTTON_12,
            instance,
            NULL);

        hControle=CreateWindow(
            "BUTTON",
            "Choix 1.3",
            WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,
            10+10,160+80,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_RADIOBUTTON_13,
            instance,
            NULL);
        // trois autres, mais qui forment un autre groupe
        hControle=CreateWindow(
            "BUTTON",
            "Choix 2.1",
            WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON|WS_GROUP,
            130+10,160+20,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_RADIOBUTTON_21,
            instance,
            NULL);

        hControle=CreateWindow(
            "BUTTON",
            "Choix 2.2",
            WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,
            130+10,160+50,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_RADIOBUTTON_22,
            instance,
            NULL);

        hControle=CreateWindow(
            "BUTTON",
            "Choix 2.3",
            WS_CHILD|WS_VISIBLE|BS_AUTORADIOBUTTON,
            130+10,160+80,
            100,20,
            fenetrePrincipale,
            (HMENU)ID_RADIOBUTTON_23,
            instance,
            NULL);
    }

}

VOID AfficheActionCheckBox(int index,HWND hCtl,HWND fenetrePrincipale)
{
    // test si la check box est cochée, non cochée ou inderterminée.
    LRESULT lRes=SendMessage(hCtl,BM_GETCHECK,0,0);
    CHAR lpMessage[128];

    sprintf(lpMessage,"La check box n°%d est maintenant %s",index,
        lRes==BST_CHECKED?"cochée":
        lRes==BST_UNCHECKED?"décochée":"inderterminée");

    MessageBox(fenetrePrincipale,lpMessage,"Vous avez modifié une check box",
        MB_ICONINFORMATION|MB_OK);
}

VOID DemandeActionCheckBox4(HWND hCtl,HWND fenetrePrincipale)
{
    // test si la check box est cochée, non cochée ou inderterminée.
    LRESULT lRes=SendMessage(hCtl,BM_GETCHECK,0,0);
    PCHAR lpProchainEtat;
    UINT iProchainEtat;
    UINT iChoix;
    CHAR lpMessage[128];

    if(lRes==BST_CHECKED)
    {
        lpProchainEtat="inderterminée";
        iProchainEtat=BST_INDETERMINATE;
    }
    else if(lRes==BST_INDETERMINATE)
    {
        lpProchainEtat="décochée";
        iProchainEtat=BST_UNCHECKED;
    }
    else
    {
        lpProchainEtat="cochée";
        iProchainEtat=BST_CHECKED;
    }

    sprintf(lpMessage,"Voulez-vous passer à l'état %s ?",lpProchainEtat);

    iChoix=MessageBox(fenetrePrincipale,lpMessage,"",MB_YESNO);
    if(iChoix==IDYES)
        SendMessage(hCtl,BM_SETCHECK,(WPARAM)iProchainEtat,0);
}

VOID NotificationControle(HWND fenetrePrincipale,UINT message, WPARAM wParam, LPARAM lParam)
{
    UINT iId=LOWORD(wParam);
    HWND hCtl=(HWND)lParam;

    switch(iId)
    {
        case ID_PUSHBUTTON_1:
            MessageBox(fenetrePrincipale,"Vous avez appuyé sur le premier bouton","",MB_OK);
            break;
        case ID_PUSHBUTTON_2:
            MessageBox(fenetrePrincipale,"Vous avez appuyé sur le second bouton","",MB_OK);
            break;
        case ID_PUSHBUTTON_3:
            MessageBox(fenetrePrincipale,"Vous avez appuyé sur le troisième bouton","",MB_OK);
            break;
        case ID_CHECKBOX_1:
        case ID_CHECKBOX_2:
        case ID_CHECKBOX_3:
            AfficheActionCheckBox(iId-ID_CHECKBOX_1,hCtl,fenetrePrincipale);
            break;
        case ID_CHECKBOX_4:
            DemandeActionCheckBox4(hCtl,fenetrePrincipale);
            break;
    }
}

LRESULT CALLBACK procedureFenetrePrincipale(HWND fenetrePrincipale, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND boutons[2] = {NULL};

    switch (message)
    {
        case WM_CREATE:
            RemplieFenetrePrincipale(fenetrePrincipale);
            return 0;
        case WM_COMMAND:
            NotificationControle(fenetrePrincipale,message,wParam,lParam);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(fenetrePrincipale,message,wParam,lParam);
    }
}


int WinMain (HINSTANCE cetteInstance, HINSTANCE precedenteInstance,
             LPSTR lignesDeCommande, int modeDAffichage)
{
    HWND fenetrePrincipale;
    MSG message;
    WNDCLASS classeFenetre;

    instance = cetteInstance;

    classeFenetre.style = 0;
    classeFenetre.lpfnWndProc = procedureFenetrePrincipale;
    classeFenetre.cbClsExtra = 0;
    classeFenetre.cbWndExtra = 0;
    classeFenetre.hInstance = NULL;
    classeFenetre.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    classeFenetre.hCursor = LoadCursor(NULL, IDC_ARROW);
    classeFenetre.hbrBackground = (HBRUSH)(1 + COLOR_BTNFACE);
    classeFenetre.lpszMenuName = NULL;
    classeFenetre.lpszClassName = "classeF";

// On prévoit quand même le cas où ça échoue
    if(!RegisterClass(&classeFenetre))
        return FALSE;

    fenetrePrincipale=CreateWindow(
        "classeF",
        "Ma premiere fenetre winAPI !",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,CW_USEDEFAULT,
        270,320,
        NULL,
        NULL,
        cetteInstance,
        NULL);

    if (!fenetrePrincipale)
        return FALSE;

    ShowWindow(fenetrePrincipale,modeDAffichage);
    UpdateWindow(fenetrePrincipale);


    while(GetMessage(&message,NULL,0,0))
    {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}
