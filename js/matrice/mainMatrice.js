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
    /*console.log(camerA.getArray());*/
    /*console.log(matrice.getArray());*/
    update();
}

function draw() {
    matrice.show();
    if(frameCount == nbFrame + 30){
    	update();
    	nbFrame = frameCount;
    }
}

function update() { 
    document.addEventListener("DOMContentLoaded" ,function(event) { 
        camerA.setPixel(document.getElementById("arrMatrice").innerHTML);
        matrice.update();
    });
}