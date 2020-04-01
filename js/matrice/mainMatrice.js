var camerA;
var matrice;
var nbFrame;
var cnv;

function setup() {
    cnv = createCanvas(600, 600);
    cnv.parent('matriceP5');
    cnv.position(300,0,'z-index', '-2');
    frameRate(30);
    nbFrame = 0;

    camerA = new CCamera();
    matrice = new CMatrice2(camerA);
}

function draw() {
    matrice.show();
    if(frameCount == nbFrame + 30){
    	update();
    	nbFrame = frameCount;
    }
}

function update() {
    $(document).ready(function() { // lancé quand le DOM est initialisé (prêt)  

        //à chaque fois que la valeur du slider change, on modifie la couleur de fond de la barre
        //en fonction de la valeur du slider.
        var source = new EventSource("../cgi-bin/cubeEventServer.cgi");
        source.addEventListener("matrice", function(event) {
            var obj = JSON.parse(event.data);
            document.getElementById("temp").innerHTML = obj.temp;
            //document.getElementById("matrice").innerHTML = obj.matrice;
            camerA.setPixel(obj.matrice);
            matrice.update();
            matrice.show();
        });
    });
}q<