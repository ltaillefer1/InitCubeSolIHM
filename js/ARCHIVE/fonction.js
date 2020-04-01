$(document).ready(function () {
function popup(reponse) {
	$( "#dialog_nok" ).dialog();
	//$( "#dialog_nok" ).css('width','800px');
	$( "#dialog_nok" ).html($( "#dialog_nok" ).text()+"<br>"+reponse);
	$( "#dialog_nok" ).dialog("open");
};


    $( function() {
        $( "#datepicker" ).datepicker();
      });
        
    $( function () {
        $( "#sortable" ).sortable({
              revert: true
          });
    });
    
    $( "#Commande0" ).draggable({
          connectToSortable: "#sortable",
          helper: "clone",
          revert: "invalid"
      });
    
    $( "#Commande1" ).draggable({
          connectToSortable: "#sortable",
          helper: "clone",
          revert: "invalid"
      });

    $( "#Commande2" ).draggable({
          connectToSortable: "#sortable",
          helper: "clone",
          revert: "invalid"
      });
    
    $( "#Commande3" ).draggable({
          connectToSortable: "#sortable",
          helper: "clone",
          revert: "invalid"
      });

    $( "#Commande4" ).draggable({
          connectToSortable: "#sortable",
          helper: "clone",
          revert: "invalid"
      });
    
    $( "#droppable" ).droppable({
          drop: function( event, ui ) {
            $( this )
                .addClass( "ui-state-highlight" )
                .find( "p" )
                .html( "Dropped!" );
          }
      });


    function c_envoi(cmd) {
        $.ajax({
            url  : ("cgi-bin/Commande.cgi"),
            type : 'GET',                          
            data : "cmd="+cmd,
            dataType: "html",
        success : function(reponse){popup(reponse);}
        });
    }
    
        $( "#dialog_nok" ).dialog({
          	autoOpen: false,
          	show: {
				effect: "blind",
				duration: 1000
			},
			hide: {
				effect: "blind",
				duration: 1000
			},
			close: function() {  
                // On supprime le contenu de la popup lorsqu'on la ferme (pour le prochain envoi de commandes)
                $("#dialog_nok").empty();
                $( this ).dialog( "close" );
            }
        });


	//Lors de l'appui sur le bouton "envoyer commande"
    $( "#envoiCommande" ).on("click",function(){
		var trame;
		//Pour chaque élément de la liste (éléments ajoutés par l'utilisateur)
		$("ul#sortable li").each(function(){
			//On récupère le texte de la commande			
			const txt = $(this).text();
			//Suivant le texte de l'émément de la liste et donc suivant la commande,
			//On génère la trame correspondante
			switch (txt) {
 				case "MEASURE":
					trame = "Trame_MEASURE";
  				break;
 				case "STATUS":
					trame = "Trame_STATUS" ;
  				break;
				case "MISSION":
					trame = "Trame_MISSION";
				break;
				case "EMPTY":
					trame = "Trame_EMPTY";
				break;
				case "DEPLOY":
					trame = "Trame_DEPLOY";
				break;
				default:
					trame="NULL";
			}
			//On envoie la commande
			if (trame !== "NULL")
				c_envoi(trame);
		});
    });
});


