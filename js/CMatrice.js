// Constructeur
function CMatrice(camera){
    
    // définition des attributs de la classe
    this.camera = camera;
    this.seuilHaut = 90;
 	this.seuilMilieu = 60;
    this.seuilBas = 30;
    this.seuilNull = 0;
   
	
}

CMatrice.prototype.rgbToHex = function (rgb) { 
  var hex = Number(rgb).toString(16);
  if (hex.length < 2) {
       hex = "0" + hex;
  }
  return hex;
};

CMatrice.prototype.fullColorHex = function(r,g,b) {   
  var red = this.rgbToHex(r);
  var green = this.rgbToHex(g);
  var blue = this.rgbToHex(b);
  return red+green+blue;
};

CMatrice.prototype.constrain = function(n, low, high) {
  return Math.max(Math.min(n, high), low);
};

CMatrice.prototype.map = function(n, start1, stop1, start2, stop2, withinBounds) {
  const newval = (n - start1) / (stop1 - start1) * (stop2 - start2) + start2;
  if (!withinBounds) {
    return newval;
  }
  if (start2 < stop2) {
    return this.constrain(newval, start2, stop2);
  } else {
    return this.constrain(newval, stop2, start2);
  }
};

CMatrice.prototype.modifPixelColor = function(pixel, valeur){
	$("#pixel"+pixel).css("color","white");
	$("#pixel"+pixel).html(valeur);

	var r;
	var g;
	var b;

	var temperature = parseFloat(valeur);

	r = this.map(temperature, 255, 0, this.seuilHaut, this.seuilMilieu);
	g = this.map(temperature, 255, 0, this.seuilMilieu, this.seuilBas);
	b = this.map(temperature, 255, 0, this.seuilBas, this.seuilNull);



	var couleur = this.fullColorHex(r,g,b);
	console.log(couleur);

	$("#pixel"+pixel).css("background-color",couleur);
}



/**
 * Modifie la couleur d'un pixel et affiche sa valeur
 * @param {Int} pixel : numéro du pixel à modifier
 * @param {Float} valeur de la température représentée par ce pixel
 * @returns {Void}
 */
CMatrice.prototype.setPixelColor = function(pixel,valeur) {
	//affichage de la valeur
	$("#pixel"+pixel).css("color","white");
	$("#pixel"+pixel).html(valeur);
	
	//modification de la couleur
	var R;
	var G;
	var B;
	var temperature = parseFloat(valeur);
	if ((temperature <= this.seuilHaut) && (temperature > this.seuilMilieu))
 	{
		//valeur du rouge        
		R = 255;
	
		//valeur du bleu
		//parseInt permet d'approximer à l'entier le plus proche
        B = parseInt(2*(this.seuilHaut - temperature)/(this.seuilHaut-this.seuilBas)*255);
	}
    if ((temperature <= this.seuilMilieu) && (temperature >= this.seuilBas))
	{
		B = 255;
		R = parseInt(255*(1-(this.seuilMilieu-temperature)/(this.seuilMilieu-this.seuilBas)));	
	}
	//Pour exprimer la quantité de rouge en hexa sur deux caractères, il faut créer 
	//une chaîne de caractère commençant par un zéro et utiliser la fonction slice() pour conserver 
	//les deux derniers caractères. Si toString() renvoie un caractère seul (de 0 à 9, de A à F),
	// un zéro sera ajouté, sinon ça sera transparent.	

	//génération de la couleur (toString(16) exporte la valeur en hexa)
	var couleur = '#'+('0'+R.toString(16)).slice(-2)+"00"+('0'+B.toString(16)).slice(-2);

	//modification de la couleur du pixel
	$("#pixel"+pixel).css("background-color",couleur);

};


//Sert a modfier toute les pixels de la matrice en fonction des valeurs de CCamera
	CMatrice.prototype.majMatrice = function() {
	 	for (var numPixel = 0; numPixel<64 ; numPixel++)
		{
			var valeur = this.camera.getPixel(numPixel);
			//getPixel=retourne valeur pixel ciblé
			matrice.modifPixelColor(numPixel,valeur);	
			//setPixelColor=défini couleur en fonction valeur de getPixel
		}
	}

//Sert a modfier toute les pixels de la matrice en fonction des valeurs de CCamera
	CMatrice.prototype.ExMatrice = function() {
	 	for (var numPixel = 0; numPixel<64 ; numPixel++)
		{
			var valeur = this.camera.ExGetPixel(numPixel);
			//getPixel=retourne valeur pixel ciblé
			matrice.setPixelColor(numPixel,valeur);
			//setPixelColor=défini couleur en fonction valeur de getPixel
		}
	}

	CMatrice.prototype.HotMatrice = function() {
	 	for (var numPixel = 0; numPixel<64 ; numPixel++)
		{
			var valeur = this.camera.HotGetPixel(numPixel);
			//getPixel=retourne valeur pixel ciblé
			matrice.setPixelColor(numPixel,valeur);
			//setPixelColor=défini couleur en fonction valeur de getPixel
		}
	}

	CMatrice.prototype.ColdMatrice = function() {
	 	for (var numPixel = 0; numPixel<64 ; numPixel++)
		{
			var valeur = this.camera.ColdGetPixel(numPixel);
			//getPixel=retourne valeur pixel ciblé
			matrice.setPixelColor(numPixel,valeur);
			//setPixelColor=défini couleur en fonction valeur de getPixel
		}
	}







