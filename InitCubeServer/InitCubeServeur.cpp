/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   InitCubeServeur.cpp
 * Author: snir2g1
 * 
 * Created on 28 mars 2019, 10:34
 */

#include "InitCubeServeur.h"

#define NB_CLIENT_MAX 20

using json = nlohmann::json;

InitCubeServeur::InitCubeServeur() {
    ecoute.sin_port=htons(9950);//port d'écoute.
	ecoute.sin_addr.s_addr=inet_addr("127.0.0.1");
	ecoute.sin_family=AF_INET;
	canal=socket(AF_INET, SOCK_STREAM,0);//Création de la socket
	if(canal<0){
		close(canal);
		perror("Erreur de creation de la socket.");
		exit(0);
	}

	if(bind(canal,(struct sockaddr*)&ecoute, sizeof(ecoute))<0){//Attachement de la socket
		close(canal);
		perror("Erreur d'attachement de la socket.");
		exit(0);
	}
}
void InitCubeServeur::attendreConnexion(){
    if(listen(canal, NB_CLIENT_MAX)<0){//Ecoute du canal de la socket
		close(canal);
		perror("Erreur d'ecoute de la socket.");
		exit(0);
	}
    cout+"En Attente De Connexion:"+endl;
    socklen_t taille_ecoute = sizeof(ecoute);//Taille de la socket
    sockAccept=accept(canal,(struct sockaddr*)&ecoute, &taille_ecoute);//bloque l'attente de connexion.
    cout+"Connexion du client:\r\n"+endl;

    if(sockAccept<0){
            close(canal);
            perror("Erreur d'acceptation de la socket.");
            exit(0);
    }
    connexions.push_back(sockAccept);

}


void InitCubeServeur::transmettre(char* message, int taille)
{
    for(int i=0; i<connexions.size(); i++)
    {
        int envoyer =send(connexions[i], message,taille,0);
        /*int reception = recv(connexions[i],taille, 0);
        if(reception==0)
        {
                close(connexions[i]);
                connexions.erase(connexions.begin()+i);
                i--;
        }*/
    }
}

string InitCubeServeur::genFakeTram(){
    int arr = [64];
    int max = 10;
    int min = 0;
    int number = rand()%(max-min + 1) + min;

    for (int i = 0; i < 64; i++){
        arr[i] = number;
        number = rand()%(max-min + 1) + min;
    } 

    string testInstru = "{\"instrument\" :{ \"matrice\" : [";

    for (int j = 0; j < 64; j++){
        testInstru += arr[j]+",";
        if (j == 63){
            testInstru += arr[j];
        }
    }

    testInstru += "]}}"+"\r\n\r\n";

    string testEtat =  "{\"etat\":{  \"stockage\": { " 

                    // Stockage libre en Mo(Valeur comprise entre 0 et 100) 
                    + "\"stockLibreMo\" :" + rand()%101 + ","               

                    //Stockage libre en pourcentage(Valeur comprise entre 0 et 100)
                    + "\"stockLibreEnP\" :"+ rand()%101 + "},"         


                //Ouverture de l'objet batterie dans le JSON
                +"\"batterie\" : {"

                    //Le niveau de charge de la batterie en pourcentage(Valeur comprise entre 0 et 100)
                    +"\"niveauDeCharge\" : "+rand()%101+","              

                    //La tension de sortie de la batterie (Valeur comprise entre 0 et 100)
                    +"\"tension\" : "+rand()%101+","             

                    //Le courant en sortie de batterie(Valeur comprise entre 0 et 100)
                    +"\"courant\" : "+rand()%101
                    +"},"


                //Ouverture de l'objet memoire
                +"\"memoire\" : { "

                    //RAM disponible en Mo(Valeur comprise entre 0 et 100) 
                    +"\"memoireDispoMo\" : " 
                    +rand()%101+","

                    //Occupation de la RAM en pourcentage(Valeur comprise entre 0 et 100)
                    +"\"occupMemoire\" : "
                    +rand()%101+"},"

                //Ouverture de l'objet magneto dans le JSON
                +"\"magneto\" : {"

                    //Le niveau de charge de la batterie en pourcentage(Valeur comprise entre 0 et 100)
                    //Magnetomètre
                    +"\"ValeurMagnetoBX\":"
                    +premiereValeurMagneto+","

                    //Magnetomètre
                    +"\"ValeurMagnetoBY\":"
                    +deuxiemeValeurMagneto+","

                    //Magnetomètre
                    +"\"ValeurMagnetoBZ\":"
                    +troisiemeValeurMagneto+"},"

                    //Ouverture de l'objet camera
                +"\"camera\" : { "

                    +"\"InfoCamera1\" : "+rand()%101+","

                    //Caméra
                    +"\"InfoCamera2\" : "+rand()%101
                    +"},"
                //ouverture de l'objet temperature Systeme
                +"\"temperatureSys\" : { "

                    //température0
                    + "\"temp\":"
                    + rand()%61+","

                    //température1
                    +"\"temp1\":"
                    +rand()%61+","

                    //température2
                    +"\"temp2\":"
                    +rand()%61+","

                    //temperature3
                    +"\"temp3\":"
                    +rand()%61+","

                    //temperature4
                    +"\"temp4\":"
                    +rand()%61
                    +"},"
         
                //cameraIR
                +"\"cameraIR\":"
                +rand()%2

            + "}}"+"\r\n\r\n";

    string repaire = "kohngdvbe";

    string fakeTram = testInstru+repaire+testEtat;

    return fakeTram;
}




InitCubeServeur::~InitCubeServeur() {
    close(canal);
}


