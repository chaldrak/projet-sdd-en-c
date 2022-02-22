#include "entete.h"

//initialiser la liste................................................
Liste* InitialiserListe(){
	Liste *liste = malloc(sizeof(*liste));//allouer un espace mémoire pour la variable *liste qui est de type Liste
	Entier *entier = malloc(sizeof(*entier));//allouer un espace mémoire pour le pointeur entier sur Entier
	if(liste == NULL || entier == NULL)
		exit(EXIT_FAILURE);
	entier->nombre = 0;
	entier->suivant = NULL;
	liste->premier = entier;
	return liste;
}

//afficher la liste....................................................
void AfficherListe(Liste* liste){
	if(liste == NULL)
		exit(EXIT_FAILURE);
	Entier *actuel = liste->premier;//actuel est un pointeur de type Entier qui pointe sur le premier enregistrement
	printf("\n******************* VOICI LA LISTE *******************\n");
	while(actuel != NULL){
		printf("[%d]  ",actuel->nombre);
		actuel = actuel->suivant;//on met dans actuel l'adresse de l'enregistrement
	}
	printf("\n******************************************************\n");
}

//inserer en queue...................................................
void InsererEnQueue(Liste *liste){
	int nombreAAjouter = 0;
	if(liste == NULL)
		exit(EXIT_FAILURE);
	printf("Entrer l'élément à ajouter en queue : ");
	scanf("%d",&nombreAAjouter);
	Entier *nouveau = malloc(sizeof(*nouveau));
	if(nouveau == NULL)
		exit(EXIT_FAILURE);
	nouveau->nombre = nombreAAjouter;
	nouveau->suivant = NULL;
	Entier *actuel = liste->premier;
	while(actuel->suivant != NULL)//parcourir les enregistrements jusqu'au dernier
		actuel = actuel->suivant;
	actuel->suivant = nouveau;//on pointe suivant du dernier vers nouveau
}

//inserer en tete....................................................
void InsererEnTete(Liste* liste){
	int nombreAAjouter = 0;
	printf("Entrer l'élément à ajouter en tete : ");
	scanf("%d",&nombreAAjouter);
	Entier *nouveau = malloc(sizeof(*nouveau));
	if(liste == NULL || nouveau == NULL)
		exit(EXIT_FAILURE);
	nouveau->nombre = nombreAAjouter;
	nouveau->suivant = liste->premier;//On pointe suivant de nouveau vers la tete de liste
	liste->premier = nouveau;//On pointe tete de liste vers nouveau
}

//supprimer un élément donné de la liste.............................
void SupprimerElement(Liste* liste){
	int elementASupprimer = 0;
	printf("Entrer l'élément à supprimer : ");
	scanf("%d",&elementASupprimer);
	Entier *actuel = liste->premier;
	if(actuel->nombre == elementASupprimer){
		liste->premier = actuel->suivant;
		free(actuel);
	}
	/*else{
		Entier *adresseCourante = NULL, *parcours = actuel;
		while(parcours->suivant != NULL){
			adresseCourante = actuel->suivant;
			if(adresseCourante->nombre == elementASupprimer){
				actuel = adresseCourante->suivant;
				free(adresseCourante);
			}
			parcours = parcours->suivant;
		}
	}*/
}

//supprimer le dernier element de la liste
void SupprimerDernier(Liste *liste){
	Entier *actuelPrecedent;
	Entier *actuel = liste->premier;
	if(actuel->suivant == NULL){
		liste->premier = actuel->suivant;
		free(actuel);
	}
	else{
		while(actuel->suivant != NULL){
			actuelPrecedent = actuel;
			actuel = actuel->suivant;
		}
		actuelPrecedent->suivant = NULL;
		free(actuel);
	}
}

//palindrome..........................................................
void Palindrome(Liste* liste){
	Entier *actuel = liste->premier;
	int taille = 0, comp = 0, i = 0;
	while(actuel != NULL){
		taille++;
		actuel = actuel->suivant;
	}
	int tableau[taille];
	actuel = liste->premier;
	for(i=0;i<taille;i++){
		tableau[i] = actuel->nombre;
		actuel = actuel->suivant;
	}
	for(i=0;i<taille;i++){
		if(tableau[i] == tableau[taille-i-1])
				comp++;
	}
	if(comp == taille)
		printf("\nLa liste est un palindrome\n");
	else
		printf("\nLa liste n'est pas un palindrome\n");
}

// fonction echanger.....................................................
void Echanger(int *pointeur1, int *pointeur2){
	int tampon=0;
	tampon=*pointeur2;
	*pointeur2=*pointeur1;
	*pointeur1=tampon;
}

//Trier tableau.......................................................
void TrierListe(Liste* liste){
	Entier *actuel = liste->premier;
	int taille = 0, comp = 0, k = 0, i=0, j=0;;
	while(actuel != NULL){
		taille++;
		actuel = actuel->suivant;
	}
	int tableau[taille];
	actuel = liste->premier;
	for(k=0;k<taille;k++){
		tableau[k] = actuel->nombre;
		actuel = actuel->suivant;
	}
	for(j=taille-1;j>1;j--){
		for(i=0;i<=j;i++){
			if(tableau[i]>tableau[i+1])
				Echanger(&tableau[i],&tableau[i+1]);
		}
	}
	actuel = liste->premier;
	for(i=0;i<taille;i++){
		actuel->nombre = tableau[i];
		actuel = actuel->suivant;
	}

}


//inverser une liste..................................................
void InverserListe(Liste* liste){
	Entier *actuel = liste->premier;
	int taille = 0, i = 0;
	while(actuel != NULL){
		taille++;
		actuel = actuel->suivant;
	}
	int tableau[taille];
	actuel = liste->premier;
	for(i=0;i<taille;i++){
		tableau[i] = actuel->nombre;
		actuel = actuel->suivant;
	}
	actuel = liste->premier;
	for(i=0;i<taille;i++){
		actuel->nombre = tableau[taille-1-i];
		actuel = actuel->suivant;
	}
}


//affichage menu......................................................
void AfficherMenu(){

	printf("\n...................MENU..................................\n\n");
	printf("1. Créer une liste chainée d’entier\n2. Ajouter un élément en tête de liste\n3. Ajouter un élément en queue de liste\n");
	printf("4. Trier une liste\n5. Supprimer un élément donné de la liste\n6. Supprimer les doublons de la liste\n");
	printf("7. Supprimer le dernier élément de la liste\n8. Fusionner deux listes\n9. Inverser une liste\n");
	printf("10. Vérifier si une liste est un palindrome\n11. Quitter\n");
	printf("..........................................................\n\n");
}

//faire un choix.......................................................
int Choisir(){
	int choix = 1;
	do{
		printf("Faites un choix (un entier compris entre 1 et 11) : ");
		scanf("%d",&choix);
		if(choix<1 || choix>11)
			printf("Saisie erronnée !!!!!!!!\n");
	}while(choix<1 || choix>11);
	return choix;
}

//creer de fonction.....................................................
Liste* CreerListe(){
    Liste *liste = malloc(sizeof(*liste));
	Entier *entier = NULL;
	Entier *tempo = malloc(sizeof(*liste));
	int nbElement = 0,donnee = 0;
	printf("Entrez le nombre d'elements à enregistrer : ");
    scanf("%d",&nbElement);
    if(nbElement > 0) {
        printf("Veuillez entrer le nombre n°1 : ");
        scanf("%d",&donnee);
        tempo->nombre = donnee;
        tempo->suivant = NULL;
        liste->premier = tempo;
        for(int i = 1; i < nbElement ; i++){
            printf("Veuillez entrer le nombre n°%d : ", i+1);
            scanf("%d",&donnee);
            entier = malloc(sizeof(*entier));
            entier->nombre = donnee;
            tempo->suivant = entier;
            tempo = entier;
        }
    }
	return liste;
}

//exécution du programme................................................
void Executer(){
	int choix, balise = 0;
	Liste* maListe;
	do{
		int choix = Choisir();
		switch(choix){

		case 1  : if(balise == 1){
						printf("\nvotre liste est déjà créée !!!\nPour créer une nouvelle, veuillez quitter et revenir\n\n");
					 	break;
					 }
					 balise = 1;
					 maListe = CreerListe();
					 AfficherListe(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 2  : if(balise == 0){
						printf("\n*** Veuillez creer une liste en premier ***\n");
						AfficherMenu();break;
					 }
					 InsererEnTete(maListe);
					 AfficherListe(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 3  : if(balise == 0){
						printf("\n*** Veuillez creer une liste en premier ***\n");
						AfficherMenu();break;
					 }
					 InsererEnQueue(maListe);
					 AfficherListe(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 4  : if(balise == 0){
						printf("\n*** Veuillez creer une liste en premier ***\n");
						AfficherMenu();break;
					 }
					 TrierListe(maListe);
					 AfficherListe(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 5  : if(balise == 0){
						printf("\n*** Veuillez creer une liste en premier ***\n");
						AfficherMenu();break;
					 }
					 SupprimerElement(maListe);
					 AfficherListe(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 7  : if(balise == 0){
						printf("\n*** Veuillez creer une liste en premier ***\n");
						AfficherMenu();break;
					 }
					 SupprimerDernier(maListe);
					 AfficherListe(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 9  : if(balise == 0){
						printf("\n*** Veuillez creer une liste en premier ***\n");
						AfficherMenu();break;
					 }
					 InverserListe(maListe);
					 AfficherListe(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 10 : if(balise == 0){
						printf("\n*** Veuillez creer une liste en premier ***\n");
						AfficherMenu();break;
					 }
					 Palindrome(maListe);
					 printf("\n");
					 AfficherMenu();break;

		case 11 : printf("\nAu revoir !!!!\n");
					 exit(0);break;
		}
	}while(choix != 11);
}
