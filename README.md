Reprise du projet du premier semestre de Ei en RV. 

Ie : tracking optique d'un point d'intéret choisi par l'utilisateur.via webcam

Raisonnement :	      - pas à pas
	     	      - prendre n points autours du point d'intéret
		      - calculer homographies de ces points
		      - trouver les positions de ces points dans la nouvelle image
		      -calculer interpolation de ces points pour retrouver le point d'interet
		      - vérifier cohérence par rapport à ce qu'on aurait trouvé de façon brute ->critère d'évaluation + d'arret !

Objectif : stabilité par rapport à la méthode naive/brute