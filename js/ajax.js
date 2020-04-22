// Exécute un appel AJAX POST

// Prend en paramètres l'URL cible, la donnée à envoyer et la fonction callback appelée en cas de succès

function ajaxPost(url, data, callback) {

    var req = new XMLHttpRequest();

    req.open("GET", url);

    req.addEventListener("load", function () {

        if (req.status >= 200 && req.status < 400) {

            // Appelle la fonction callback en lui passant la réponse de la requête

            callback(req.status);
            

        } else {

            console.error(req.status + " " + req.statusText + " " + url);

        }

    });

    req.addEventListener("error", function () {

        console.error("Erreur réseau avec l'URL " + url);

    });

    req.send(data);

}

/*function callOtherDomain(){
    if(req){

    }
}*/

//Access-Control-Allow-Origin: https://www.mocky.io/v2/5185415ba171ea3a00704eed;
