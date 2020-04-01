#include "Lib.h"
using namespace std;

int newValue(int max, int min, int a[]);

int main(){

	int premiereValeurMagneto=(rand() % (4800 - (-4800) + 1)) - 4800;
	int deuxiemeValeurMagneto=(rand() % (4800 - (-4800) + 1)) - 4800;
	int troisiemeValeurMagneto=(rand() % (4800 - (-4800) + 1)) - 4800;
	int number = 0;
	int arr[64];
	int min = 0;
	int max = 10;
	arr = newValue(max, min, arr[]);

	cout << "Content-Type: text/event-stream\r\n\r\n";
	cout << "Cache-Control: no-cache\r\n\r\n";

	
			/*cout << "Event: ACK\r\n\r\n";
			cout << "data : "<<endl;
		
			cout << "Event: mesure\r\n\r\n";
			cout << "data : "<<endl;*/			
	for (int i = 0; i < 10 ;i++){	
		cout << "event: matrice"<<"\n";
		cout << "data : "<<"{\"matrice\":[" << arr[0]<<","<< arr[1]<<","<< arr[2]<<","<< arr[3]<<","<< arr[4]<<","<< arr[5]<<","<< arr[6]<<","<< arr[7]<<","
		<< arr[8]<<","<< arr[9]<<","<< arr[10]<<","<< arr[11]<<","<< arr[12]<<","<< arr[13]<<","<< arr[14]<<","<< arr[15]<<","
		<< arr[16]<<","<< arr[17]<<","<< arr[18]<<","<< arr[19]<<","<< arr[20]<<","<< arr[21]<<","<< arr[22]<<","<< arr[23]<<","
		<< arr[24]<<","<< arr[25]<<","<< arr[26]<<","<< arr[27]<<","<< arr[28]<<","<< arr[29]<<","<< arr[30]<<","<< arr[31]<<","
		<< arr[32]<<","<< arr[33]<<","<< arr[34]<<","<< arr[35]<<","<< arr[36]<<","<< arr[37]<<","<< arr[38]<<","<< arr[39]<<","
		<< arr[40]<<","<< arr[41]<<","<< arr[42]<<","<< arr[43]<<","<< arr[44]<<","<< arr[45]<<","<< arr[46]<<","<< arr[47]<<","
		<< arr[48]<<","<< arr[49]<<","<< arr[50]<<","<< arr[51]<<","<< arr[52]<<","<< arr[53]<<","<< arr[54]<<","<< arr[55]<<","
		<< arr[56]<<","<< arr[57]<<","<< arr[58]<<","<< arr[59]<<","<< arr[60]<<","<< arr[61]<<","<< arr[62]<<","<< arr[63]<<"," << "]}"<<"\r\n\r\n";
		arr = newValue(max, min, arr[]);
		min += 10;
		max += 10;
	}
		
	for (int i = 0; i < 10 ;i++){
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
}

	return 0;		
}

int newValue(int max, int min, int a[]){
	if(max < 90){
	int number = rand()%(max-min + 1) + min;
		for (int i = 0; i < 64; i++){
			a[i] = number;
			number = rand()%(max-min + 1) + min;
		}
	}else {
		return a*;
	}
}