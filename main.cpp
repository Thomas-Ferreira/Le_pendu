#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool tant_que=true;
    bool compt_lifepoint=false;
    string lifepoint = "||||||||||" ;
    string result;
    char lettre;
    char mot_a_trouver[2][4];
    int found=0;
    int vie=9;
    int limite = lifepoint.length();

    mot_a_trouver[0][0]='c';    //la 1ere ligne du tabmleau correspondera au mot
    mot_a_trouver[0][1]='h';
    mot_a_trouver[0][2]='a';
    mot_a_trouver[0][3]='r';

    for(int z=0; z<4; z++)
    {
        mot_a_trouver[1][z]='0';    //on rempli la 2eme ligne du tableau de 0
    }

    while(tant_que = true)
    {

        for(int k=0; k<4; k++)
        {
            if(mot_a_trouver[1][k]=='1')    // on regarde la deuxieme ligne du tableau
            {
                cout << mot_a_trouver[0][k] << " ";     // si on a 1, on affiche le caractere
            }
            else
            {
                cout << "_ ";       // si on a 0 on affiche un underscore
            }
        }
        cout <<"  entrez une lettre" << "           " ;

        for(int x=0;x<lifepoint.length();x++)
        {
            cout << lifepoint[x] ;      // affiche les points de vie
        }
        cin >> lettre;

        for(int i=0; i<4; i++)      //on execute la boucle sur toute la longueur du tableau
        {
            if(lettre==mot_a_trouver[0][i])     //on compare la lettre avec les differents caractere du tableau
            {
                mot_a_trouver[1][i]='1';        // Si c'est vrai on change dans la 2�me ligne du tableau le 0 par un 1
                found++;        // on increment found pour compter le nombre de lettre trouv�
                compt_lifepoint = true;     // on change la valeur de compt_lifepoint pour plus tard ne pas perdre de vie si on a une bonne lettre
            }
        }
            lifepoint.replace(vie,1," ");     //on enleve une vie a chaque fois
            vie=vie-1;

        if(compt_lifepoint==true)       //boucle qui c'execute seulement si ona trouv� un bonne lettre
        {
            lifepoint.replace(vie+1,1,"|");   //on rajoute une vie ainsi si on a une bonne lettre on fait -1 vie +1 vie
            vie=vie+1;
            compt_lifepoint=false;      //on remet compt_lifepoint a false
        }

        if(found == 4)      //Si on a trouv� toute ls lettres
        {
            cout << "mot trouve, il s'agissait de : ";

            for(int i=0;i<4;i++)
            {
                cout << mot_a_trouver[0][i];        //On affiche le mot
            }
            tant_que=false;     //on arrete le programme
            break;
        }

        if (vie==-1)        //Si on a plus de vie
        {
            cout <<"perdu"<<endl;       //on met fin au programme
            break;
        }

    }

}
