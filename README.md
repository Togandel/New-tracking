Reprise du projet du premier semestre de Ei en RV. 

Ie : tracking optique d'un point d'int�ret choisi par l'utilisateur.via webcam

Raisonnement :	      - pas � pas
	     	      - prendre n points autours du point d'int�ret
		      - calculer homographies de ces points
		      - trouver les positions de ces points dans la nouvelle image
		      -calculer interpolation de ces points pour retrouver le point d'interet
		      - v�rifier coh�rence par rapport � ce qu'on aurait trouv� de fa�on brute ->crit�re d'�valuation + d'arret !

Objectif : stabilit� par rapport � la m�thode naive/brute