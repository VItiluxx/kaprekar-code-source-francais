#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/*----- declaration des variables --------*/
string str=" ";
int compteur1(0), compteur2(0);

int fn_difference(int nombreInt)
{

            /*----- declaration des variables --------*/
        string a="";
        int limite(0), i(0), j(0), tableau[4], inverseur(0), diff(0), desc(0), crst(0);

            if(nombreInt<9)
            {limite = 1;}
            if(nombreInt>9 && nombreInt<100)
            {limite = 2;}
            if(nombreInt>99 && nombreInt<1000)
            {limite = 3;}
            if(nombreInt>999)
            {limite = 4;}

        string nombre{to_string(nombreInt)};
        if(nombre=="6174")
        {
            cout<<"\t\t\t\t\t\t\t     |"<<endl;
            cout<<"\t\t\t\t\t\t\t     |"<<endl;
            cout<<"TERMINER                                                     |"<<endl;
            cout<<"TOUTE LES DIFFERENCES ONT ETE EFFECTUER CI HAUT.             |"<<endl;
            return 0;
        }

        else
        {
    /*-------------------####################-----------------------
        conversion du nbr recuperer sous type string en int
    ---------------------####################-----------------------*/
            for(i=0; i<limite; i++)
            {
                a=nombre[i];
                //cout<<a<<endl;
                tableau[i]=stoi(a);
                //cout<<tableau[i]<<endl;
            }

    /*-----####################------------
            TRI DECROISSANT
    -------####################--------------*/
            for(i=0; i<limite; i++)
            {
                for(j=i; j<limite; j++)
                {
                    if(tableau[i]<tableau[j])
                    {
                        inverseur=tableau[i];
                        tableau[i]=tableau[j];
                        tableau[j]=inverseur;

                    }
                }
            }

    /*-----###########################################################------------
                RECONSTRUCTION DU NOMBRE TRIER DE MANIERE DECROISSANT
    -------###########################################################--------*/
            for(int i=0; i<limite; i++)
            {
                if(i==0)
                    desc+=tableau[i]*1000;
                if(i==1)
                    desc+=tableau[i]*100;
                if(i==2)
                    desc+=tableau[i]*10;
                if(i==3)
                    desc+=tableau[i]*1;
            }

    /*-----####################------------
            TRI CROISSANT
    -------####################--------------*/
            for(int i=0; i<limite; i++)
            {
                for(int j=i; j<limite; j++)
                {
                    if (tableau[i]>tableau[j])
                    {
                        inverseur=tableau[i];
                        tableau[i]=tableau[j];
                        tableau[j]=inverseur;

                    }
                }
            }

    /*-----###########################################################------------
                    RECONSTRUCTION DU NOMBRE TRIER DE MANIERE CROISSANT
    -------###########################################################--------*/
            for(int i=0; i<limite; i++)
            {
                if(i==0)
                    crst+=tableau[i]*1000;
                if(i==1)
                    crst+=tableau[i]*100;
                if(i==2)
                    crst+=tableau[i]*10;
                if(i==3)
                    crst+=tableau[i]*1;
            }

    /*-----###########################################################------------
                                OPERATION DE DIFFERENCE
    -------###########################################################------------*/
            diff=desc-crst;
            cout<<desc<<"-"<<crst<<"="<<diff<<"\t                                             |\n";
            //string nbre{to_string(diff)};
            return fn_difference(diff);
        }
}






/*--------###########################------------
                FONCTION PRINCIPALE MAIN
----------###########################--------------*/
int main(){
cout<<
       "---------------------#################-----------------------------\n"
                                     "\t\t\tBIENVENU !!\n"
       "---------------------#################-----------------------------\n"
       "Le principe est simple: Saisisez un nombre constituer de 4 chiffres\n"
       "j'effecturais un tri decroissant et croissant de votre nombre\n"
       "ensuite j'effecturais la difference des 2 tri \n"
       "et cette operation sera repeter successivemetn et continuellement...\n"
       "Au final j'affiche le resultat et je vous montre que la derniere difference sera = 6174\n"<<endl;
//-------- declartion variable pour une demande d'arret ou de continuation du prog a l'utilisateur ----------
string questionPourContinuerAExecuterLeProg="";
// ----- utilisation d'une boucle DO WHILE --------'
do{

    cout<<"SAISISER VOTRE NOMBRE ICI : ";
    int n;
    cin>>n;
    while(n==0000 || n==1111 || n==2222 || n==3333 || n==4444 || n==5555 || n==6666 || n==7777 || n==8888 || n==9999 || n==111 || n==222 || n==333 || n==444 || n==555 || n==666 || n==777 || n==888 || n==999 || n==11 || n==22 || n==33 || n==44 || n==55 || n==66 || n==77 || n==88 || n==99 || n==1 || n==2 || n==3 || n==4 || n==5 || n==6 || n==7 || n==8 || n==9 || n==1000 )
    {
        cout<<"\n ATTENTION:: VOtre nombre est exclu de la liste des nobres tester par kaprekar "<<endl;
        cout<<"Essayer a nouveau :"<<endl;
        cin>>n;
    }
    cout<<endl;

    //APPEL DE LA FONCTION DE KAPREKAR NOMMER fn_difference
    cout<<"-------------------------------------------------------------|\n";
    fn_difference(n);
    cout<<"-------------------------------------------------------------|\n";

    cout<<"\nVoulez executer le programme de nouveau ? oui/non :";
    cin>>questionPourContinuerAExecuterLeProg;
}
while(questionPourContinuerAExecuterLeProg=="oui"|| questionPourContinuerAExecuterLeProg=="OUI");


cout<<"\n\n\n\n\n\n\n\n";
return 0;
}
/* NB : CE PROGRAMME NE TRAITE QUE LES NOMBRES A 4 CHIFFRES TOUT EN EXCLUANT LE NOMBRE DONT TOUS SES 4 CHIFFRES SONT IDENTIQUE  D'OU NOTRE PROGRAMME EST INCOMPLET DANS UN SENS PLUS LARGE*/
