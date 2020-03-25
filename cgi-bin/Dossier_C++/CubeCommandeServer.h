#include "Communication.h"
#ifndef CUBECOMMANDESERVER_H
#define CUBECOMMANDESERVER_H

class CubeCommandeServer { 
public:
    void transmettreEnTete();
    void traiterEvenement();
    void envoieMessage(const char* m);
    CubeCommandeServer(string adresse,string port);
    virtual ~CubeCommandeServer();
private:
    Communication* com ;
};

#endif