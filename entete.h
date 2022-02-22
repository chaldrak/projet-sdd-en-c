// Définition des structures...................

typedef struct Entier Entier;
struct Entier{
	int nombre;
	Entier *suivant;
};

typedef struct Liste Liste;
struct Liste{
	Entier *premier;
};

// Prototypes des fonctions....................

Liste* InitialiserListe();//initialise la liste
void AfficherListe(Liste*);//affiche la liste
void InsererEnQueue(Liste *);//insérer un element en queue de liste
void InsererEnTete(Liste *);//insérer un element en tete de liste
void SupprimerElement(Liste*);//supprimer un element de la liste
void SupprimerDernier(Liste*);//supprimer le dernier element
void Palindrome(Liste*);
void InverserListe(Liste*);
Liste* CreerListe();
void TrierListe(Liste*);
void Echanger(int *, int *);
void AfficherMenu();//affichage du menu
int Choisir();//operer un choix dans le menu
void Executer();//execution du programme
