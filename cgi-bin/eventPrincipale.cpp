#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

int main(){
	/*string nomEvent = ["ACK", "mesure", "status", "matrice"];*/

	cout << "Content-Type: text/event-stream\r\n\r\n";
	cout << "Cache-Control: no-cache\r\n\r\n";

	
			cout << "Event: ACK\r\n\r\n";
			cout << "data : "<<endl;
		
			cout << "Event: mesure\r\n\r\n";
			cout << "data : "<<endl;			
		
			cout << "Event: status\r\n\r\n";
			cout << "data : "<<endl;

			cout << "Event: etat\r\n\r\n";
			cout << "data : " << "{\"stockage\": { "

				// Stockage libre en Mo(Valeur comprise entre 0 et 100) 
				<<"\"stockLibreMo\" :"<<rand()%101 << ","				

				//Stockage libre en pourcentage(Valeur comprise entre 0 et 100)
				<<"\"stockLibreEnP\" :"<<rand()%101 << "},"			


			//Ouverture de l'objet batterie dans le JSON
			<<"\"batterie\" : {"

				//Le niveau de charge de la batterie en pourcentage(Valeur comprise entre 0 et 100)
				<<"\"niveauDeCharge\" : "<<rand()%101<<","				

				//La tension de sortie de la batterie (Valeur comprise entre 0 et 100)
				<<"\"tension\" : "<<rand()%101<<","				

				//Le courant en sortie de batterie(Valeur comprise entre 0 et 100)
				<<"\"courant\" : "<<rand()%101
				<<"},"


			//Ouverture de l'objet memoire
			<<"\"memoire\" : { "

				//RAM disponible en Mo(Valeur comprise entre 0 et 100) 
				<<"\"memoireDispoMo\" : " 
				<<rand()%101<<","

				//Occupation de la RAM en pourcentage(Valeur comprise entre 0 et 100)
				<<"\"occupMemoire\" : "
				<<rand()%101<<"},"

			//Ouverture de l'objet magneto dans le JSON
			<<"\"magneto\" : {"

				//Le niveau de charge de la batterie en pourcentage(Valeur comprise entre 0 et 100)
				//Magnetomètre
            <<"\"ValeurMagnetoBX\":"
            <<premiereValeurMagneto<<","

            //Magnetomètre
            <<"\"ValeurMagnetoBY\":"
            <<deuxiemeValeurMagneto<<","

            //Magnetomètre
            <<"\"ValeurMagnetoBZ\":"
            <<troisiemeValeurMagneto<<"},"

				//Ouverture de l'objet camera
			<<"\"camera\" : { "

				<<"\"InfoCamera1\" : "<<rand()%101<<","

            	//Caméra
            	<<"\"InfoCamera2\" : "<<rand()%101
            	<<"},"

			//température0
			<< "\"temp\":"
			<< rand()%61<<","

			//température1
			<<"\"temp1\":"
			<<rand()%61<<","

			//température2
			<<"\"temp2\":"
			<<rand()%61<<","

			//temperature3
			<<"\"temp3\":"
			<<rand()%61<<","

			//temperature4
			<<"\"temp4\":"
			<<rand()%61<<","

			//camera
			<<"\"cameraIR\":"
			<<rand()%2

     << "}"<<endl;;		
}