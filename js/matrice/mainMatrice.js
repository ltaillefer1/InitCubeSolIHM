var camerA;
var matrice;
var nbFrame;
var cnv;
var source;
var arr;


function setup() {
    camerA = new CCamera();
    matrice = new CMatrice2(camerA);
    source = new Source();
    /*console.log(camerA.getArray());*/
    /*console.log(matrice.getArray());*/
    
    cnv = createCanvas(600, 600);
    cnv.parent('matriceP5');
    cnv.position(300,0,'z-index', '-2');
    frameRate(30);
    nbFrame = 0;
    camerA.setPixel(source.getMatrice());
    matrice.update();    
}

function draw() {
    matrice.show();
    if(frameCount == nbFrame + 30){
    	/*update();*/
    	nbFrame = frameCount;
    }
}

function update() { 
    
}