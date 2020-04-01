#include "Lib.h"
using namespace std;

int main(){

	int premiereValeurMagneto=(rand() % (4800 - (-4800) + 1)) - 4800;
	int deuxiemeValeurMagneto=(rand() % (4800 - (-4800) + 1)) - 4800;
	int troisiemeValeurMagneto=(rand() % (4800 - (-4800) + 1)) - 4800;
	int number = 0;

	cout << "Content-Type: text/event-stream\r\n\r\n";
	cout << "Cache-Control: no-cache\r\n\r\n";

	
			/*cout << "Event: ACK\r\n\r\n";
			cout << "data : "<<endl;
		
			cout << "Event: mesure\r\n\r\n";
			cout << "data : "<<endl;*/			
		
			cout << "event: matrice"<<"\n";
			for (int i=0 ; i<10;i++)
       		{
                cout << "data:" << "{\"temp\":"<<number++<<",\"matrice\":["<<number++<<","<<number+2<<","<<number+3<<","<<number+4<<","<<number+5<<","<<number+6<<","<<number+7<<","<<number+8<<","<<number++<<","<<number+2<<","<<number+3<<","<<number+4<<","<<number+5<<","<<number+6<<","<<number+7<<","<<number+8<<","<<number++<<","<<number+2<<","<<number+3<<","<<number+4<<","<<number-5<<","<<number+6<<","<<number+7<<","<<number+8<<","<<number++<<","<<number+2<<","<<number+8<<","<<number+10<<","<<number+15<<","<<number+6<<","<<number+7<<","<<number+8<<","<<number++<<","<<number+2<<","<<number+3<<","<<number+4<<","<<number+5<<","<<number+6<<","<<number+7<<","<<number+8<<","<<number++<<","<<number+2<<","<<number+3<<","<<number+4<<","<<number-5<<","<<number+6<<","<<number+7<<","<<number+8<<","<<number++<<","<<number+2<<","<<number+3<<","<<number+4<<","<<number+5<<","<<number+6<<","<<number+7<<","<<number+8<<","<<number++<<","<<number+2<<","<<number+3<<","<<number+4<<","<<number+5<<","<<number+6<<","<<number+7<<","<<number+8<<"]}" "\r\n\r\n" <<endl;

                usleep(1000000);
        	}

			cout << "event: etat"<<"\n";
			cout << "data: " << "{\"stockage\": { "

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

			//cameraIR
			<<"\"cameraIR\":"
			<<rand()%2

     << "}"<<"\r\n\r\n";

	return 0;		
}