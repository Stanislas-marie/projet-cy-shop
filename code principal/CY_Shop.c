
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nom[50];
    int ref;
    int taille;
    int prix;
    int stock;
} produits;


typedef struct {
    char historique[100];
} client;




//fonction qui permet de créer un compte client
void create_client() {
    char clientName[100];
    printf("Veuillez entrer votre nom (PrenomNom) pour créer votre compte : ");
    scanf("%s", clientName);

    char filePath[100] = "clients/";
    strcat(filePath, clientName);
    strcat(filePath, ".txt");
    

    FILE *file = fopen(filePath, "w");

    if (file != NULL) {
        printf("%s, votre compte a été créé avec succès.\n", clientName);
        fclose(file);
    } else {
        printf("Impossible de créer le compte. Veuillez réessayer.\n");
        perror("Erreur");
    }
}




// Fonction qui identifie le client
void identification_client(client *clientinfo) {
    char identifiant[100];
    printf("Merci de vous connecter\n");
    printf("Saisissez votre prenom et votre nom sous la forme prenom nom\n");
    scanf("%s", identifiant);
    char filePath[100] = "clients/";
    strcat(filePath, identifiant);
    strcat(filePath, ".txt");

    FILE* fichier = fopen(filePath, "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", filePath);
        exit(1);
    }

    char ligne[1000];
    char historique[1000] = "";

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        strcat(historique, ligne);
    }

    fclose(fichier);

    strcpy(clientinfo->historique, historique);

    printf("Vous êtes connecté.\n");
}




//fonction qui rempli le panier 
void remplissage_panier ( char produits[] , int quantite ){
    const char* panier="panier.txt";
  FILE* fichier = fopen("panier.txt", "a");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", panier);
        return;
    }
 
   fprintf(fichier, " %s %d",produits , quantite);
   fclose(fichier);
  
}




//fonction qui vide le panier et mets a jour l'historique clients 
void copierPanierDansHistorique(client* client) {
    FILE* fichierPanier = fopen("panier.txt", "r");
    if (fichierPanier == NULL) {
        printf("Impossible d'ouvrir le fichier panier.\n");
        return;
    }

    FILE* fichierHistorique = fopen("historique.txt", "a");
    if (fichierHistorique == NULL) {
        printf("Impossible d'ouvrir le fichier historique.\n");
        fclose(fichierPanier);
        return;
    }

    char ligne[1000];
    while (fgets(ligne, sizeof(ligne), fichierPanier) != NULL) {
        fprintf(fichierHistorique, "%s", ligne);
    }

    fclose(fichierPanier);
    fclose(fichierHistorique);

    remove("panier.txt");

    printf("Le contenu du panier a été copié dans l'historique du client et le panier a été vidé.\n");
}




//fonction qui affiche les 5 produits aves les stocks les plus bas
void afficherProduitsCritiques(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    char ligne[100]; // Supposons que chaque ligne contient au maximum 100 caractères
    produits produits[100]; // Supposons qu'il y a au maximum 100 produits dans le fichier
    int nbProduits = 0;

    // Lire les produits du fichier et stocker les informations dans le tableau
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        char nom[50];
        
        int stock , taille , ref , prix;

        sscanf(ligne, "%s %d %d %d %d", nom, &ref, &taille, &prix, &stock);

        strcpy(produits[nbProduits].nom, nom);
        produits[nbProduits].ref = ref;
        produits[nbProduits].taille = taille;
        produits[nbProduits].prix = prix;
        produits[nbProduits].stock = stock;

        nbProduits++;
    }

    fclose(fichier);

    int i;

    printf("Produits avec un stock à zéro :\n");
    for (i = 0; i < nbProduits; i++) {
        if (produits[i].stock == 0) {
            printf("- Nom: %s, Référence: %d\n", produits[i].nom, produits[i].ref);
        }
    }

    printf("Produits avec les stocks les plus bas :\n");
    for (i = 0; i < 5; i++) {
        int indiceMin = 0;
        int stockMin = produits[0].stock;

        // Recherche de l'indice du produit avec le stock le plus bas
        for (int j = 1; j < nbProduits; j++) {
            if (produits[j].stock < stockMin) {
                indiceMin = j;
                stockMin = produits[j].stock;
            }
        }

        // Affichage du produit avec le stock le plus bas
        printf("- Nom: %s, Référence: %d, Stock: %d\n", produits[indiceMin].nom, produits[indiceMin].ref, produits[indiceMin].stock);

        // Mettre à jour le stock du produit avec une valeur élevée pour ne pas le sélectionner à nouveau
        produits[indiceMin].stock = 999999;
    }
}




// fonction pour augmenter le stocks d'un produit 
void augmenterStock(const char* nomProduit , int quantite, const char*  nomFichier){
    FILE* fichier = fopen(nomFichier, "r+");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    char ligne[100]; // Supposons que chaque ligne contient au maximum 100 caractères
    int produitTrouve = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Extraire les informations du produit de la ligne
        char nom[50];
        
        int stock, ref , taille , prix;

        sscanf(ligne, "%s %d %d %d %d", nom, &ref, &taille, &prix, &stock);
           // Vérifier si le produit correspond à celui recherché
          if (strcmp(nom, nomProduit) == 0) {
            // Augmenter le stock du produit
            stock += quantite;

            // Retourner au début de la ligne et mettre à jour le stock dans le fichier
            fseek(fichier, -strlen(ligne), SEEK_CUR);
            fprintf(fichier, "%s %d %d %d %d\n", nom, ref, taille, prix, stock);
            fflush(fichier);

            produitTrouve = 1;
            break;
        }
    }
}




// fonction pour diminuer le stocks d'un produit 
void diminuer_stock(const char* nomProduit , int quantite, const char*  nomFichier){
    FILE* fichier = fopen(nomFichier, "r+");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    char ligne[100]; // Supposons que chaque ligne contient au maximum 100 caractères
    int produitTrouve = 0;

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Extraire les informations du produit de la ligne
        char nom[50];
        
        int stock, ref , taille , prix;

        sscanf(ligne, "%s %d %d %d %d", nom, &ref, &taille, &prix, &stock);
           // Vérifier si le produit correspond à celui recherché
          if (strcmp(nom, nomProduit) == 0) {
            // Augmenter le stock du produit
            stock -= quantite;

            // Retourner au début de la ligne et mettre à jour le stock dans le fichier
            fseek(fichier, -strlen(ligne), SEEK_CUR);
            fprintf(fichier, "%s %d %d %d %d\n", nom, ref, taille, prix, stock);
            fflush(fichier);

            produitTrouve = 1;
            break;
        }
    }
}




// Fonction qui affiche les produits
void afficherStocksProduits(const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    char ligne[100]; // Supposons que chaque ligne contient au maximum 100 caractères

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }
    printf("\n");
    fclose(fichier);
}




// Fonction qui permet de rechercher les infos d'un produits recherché 
void rechercheProduit(const char* nomProduitRecherche, const char* nomFichier) {
    FILE* fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    char ligne[100]; // Supposons que chaque ligne contient au maximum 100 caractères

    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Extraire les informations du produit de la ligne
        char nom[50];
        int stock, ref, taille, prix;

        sscanf(ligne, "%s %d %d %d %d", nom, &ref, &taille, &prix, &stock);

        // Vérifier si le produit correspond à celui recherché
        if (strcmp(nom, nomProduitRecherche) == 0) {
            printf("Informations du produit :\n");
            printf("Nom : %s\n", nom);
            printf("Référence : %d\n", ref);
            printf("Taille : %d\n", taille);
            printf("Prix : %d\n", prix);
            printf("Stock : %d\n", stock);
            fclose(fichier);

            return;
        }
    }

    printf("Produit non trouvé.\n");
    fclose(fichier);
}



// Fonction qui permet d'initialiser la fonctions de recherche d'un produit
void recherche_produit() {
    const char* nomFichier = "stock.txt";
    char recherche[50];
    printf("\nQuel produit recherchez-vous ?\n");
    scanf("%s", recherche);
    rechercheProduit(recherche, nomFichier);
}




//fonction qui permet de supprimer un compte client
void delete_client_account() {
    char clientName[100];
    printf("Veuillez entrer votre nom (PrenomNom) pour supprimer votre compte: ");
    scanf("%s", clientName);

    char filePath[100] = "clients/";
    strcat(filePath, clientName);
      strcat(filePath, ".txt");


    int status = remove(filePath);

    if( status == 0 )
        printf("%s, votre compte a été supprimé avec succès.\n", clientName);
    else {
        printf("Impossible de supprimer le compte. Assurez-vous que votre nom est correct et réessayez.\n");
        perror("Erreur");
    }
}




// Fonction qui permet d'écrire des commentaires

void laisserCommentaire() {
    const char *nomFichier="commentaires.txt";
    char commentaire[1000];
    
    
    
    printf("Veuillez entrer votre commentaire (max. 1000 caractères) : ");
    scanf(" %[^\n]", commentaire);

    FILE* fichier = fopen(nomFichier, "a+");
    
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }
    
    fprintf(fichier, "%s\n", commentaire);
    fflush(fichier);

    printf("Votre commentaire a été enregistré avec succès dans le fichier %s.\n", nomFichier);
}




// Fonction qui permet de lire les commentaires 
void lireCommentaires() {
    const char * nomFichier="commentaires.txt";
    char commentaire[1000];

   

    FILE* fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", nomFichier);
        return;
    }

    printf("===== Commentaires =====\n");

    while (fgets(commentaire, sizeof(commentaire), fichier) != NULL) {
        printf("%s", commentaire);

        // Ignorer les deux retours à la ligne entre les commentaires
        if (strcmp(commentaire, "\n") == 0) {
            fgets(commentaire, sizeof(commentaire), fichier);
        }
    }
    printf("\n");
    printf("========================\n");

    fclose(fichier);
}





// Fonction qui affiche les "derniers produits du client"
void afficher_derniers_produits(client *client) {
    int produits_achetes = 0;
    char *token;
    char *historique_copie = strdup((*client).historique);

    // Récupérer le dernier produit acheté
    token = strtok(historique_copie, ",");
    char dernier_produit[100];
    strcpy(dernier_produit, token);

    // Parcourir l'historique pour récupérer les 3 derniers produits
    while (token != NULL) {
        strcpy(dernier_produit, token);
        token = strtok(NULL, ",");
        produits_achetes++;
    }

    // Afficher les 3 derniers produits achetés
    printf("Les 3 derniers produits achetés :\n");
    for (int i = 0; i < 3 && produits_achetes > 0; i++) {
        printf("%d. %s\n", produits_achetes, dernier_produit);
        token = strtok(NULL, ",");
        if (token != NULL) {
            strcpy(dernier_produit, token);
        }
        produits_achetes--;
    }

    free(historique_copie);
}




//fonction qui permet a l'utilsateur de choisir un produits sa quantité et de valider son panier
void achat_produit(produits *produits, int taille, client * a) {
    int i, quantite;
    char nom[50];
    float total = 0.0;
    char validation;
  

    for (i = 0; i < taille; i++) {
        printf("%s / %d / %d / %d / %d\n", produits[i].nom, produits[i].ref, produits[i].taille, produits[i].prix, produits[i].stock);
    }

    printf("Entrez le nom du produit que vous souhaitez acheter : ");
    scanf("%s", nom);

    printf("Entrez la quantité que vous souhaitez acheter : ");
    scanf("%d", &quantite);

    for (i = 0; i < taille; i++) {
        if (strcmp(nom, produits[i].nom) == 0) {
            if (quantite <= produits[i].stock) {
                total += quantite * produits[i].prix;
                produits[i].stock -= quantite;
              remplissage_panier(nom,  quantite);
              diminuer_stock(nom, quantite, "stock.txt");
                printf("Vous avez ajouté %d %s(s) à votre panier. Le total actuel est : %.2f\n", quantite, produits[i].nom, total);
            } else {
                printf("Nous sommes désolés, mais nous n'avons pas assez de stock pour votre demande.\n");
            }
        }
    }

    printf("Voulez-vous valider votre panier ? (O/N) : ");
    scanf(" %c", &validation);

    switch(validation) {
        case 'O':
        case 'o':
            printf("Merci pour votre achat. Votre total est : %.2f\n", total);
          copierPanierDansHistorique(a);
            break;
        case 'N':
        case 'n':
            printf("Votre panier a été annulé.\n");
            break;
        default:
            printf("Réponse non reconnue.\n");
    }
}




// fonction qui permet d'initaialiser la fonction d'achat_produits
void validation_achat(client * a){
produits produits[15];
    FILE *file = fopen("stock.txt", "r");

    if (file == NULL){
        printf("Impossible d'ouvrir le fichier\n");
        
    }

    int i = 0;
    while(fscanf(file, "%s %d %d %d %d", produits[i].nom, &produits[i].ref, &produits[i].taille, &produits[i].prix, &produits[i].stock) != EOF && i < 15) {
        i++;
    }
    fclose(file);

    char reponse;
    printf("Voulez-vous acheter un de nos produits ? (O/N) : ");
    scanf(" %c", &reponse);

    switch(reponse) {
        case 'O':
        case 'o':
            achat_produit(produits, i,a);
            break;
        case 'N':
        case 'n':
            printf("Merci et à bientôt.\n");
            break;
        default:
            printf("Réponse non reconnue.\n");
}
}




// Fonction mode achat qui affiche les possibilités du mode achat
void mode_achat(client* client) {
  
    int a=0;
    afficher_derniers_produits(client);
    while (a != 4) {
        printf("====Menu Achat====\n");
        printf("Que voulez-vous faire ?\n");
        printf("1. Rechercher un produit en particulier\n");
        printf("2. Afficher le stock de tous les produits\n");
        printf("3. Laisser un commentaire\n");
        printf("4. Retourner au menu principal");
        scanf("%d", &a);
        switch (a) {
            case 1:
                printf("Rechercher un produit\n");
                recherche_produit(); // Connaître le stock d'un produit
                break;
            case 2:
                printf("Afficher tous les produits\n");
                const char* nomFichier = "stock.txt";
                afficherStocksProduits(nomFichier);
                break;
            case 3:
                laisserCommentaire();
                mode_achat(client);
                break;
            case 4:
                printf("Retour au menu principal\n");
                main(); // Sortir du mode achat et retourner au menu
                break;
            default:
                printf("Choix invalide.\n");
                break;
      }
    validation_achat(client );
    }
}




// Fonction pour afficher le menu de gestion des stocks
void afficher_mode_gestion() {
    printf("=====Menu gestion=====\n");
    printf ("Que voulez-vous faire?\n");
    printf("1. Rechercher un produit\n");
    printf("2. augmenter un stock un produit\n");
    printf("3. lire les commentaires\n");
    printf("4. Retour au menu principal\n");
}

int main();
// Fonction pour afficher le menu principal
void afficher_menu() {
    printf("Menu principal :\n");
    printf("1. Menu gestion\n");
    printf("2. Menu achats\n");
    printf("3. Retourner au menu principal\n");
    printf("4. Quitter\n");
}

int main() {
    int choix = 0;
    const char* nomFichier = "stock.txt";
    // Boucle principale du programme
    while (choix != 4) {
        afficher_menu();
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        fflush(stdin);

        switch (choix) {
           int choixa,choixb; 
          int codeSaisi;
            case 1:
                // menu gestion
                // Code PIN valide 1234
    
              
              while (codeSaisi!=1234){
              printf("Entrez le code PIN : ");
              scanf("%d", &codeSaisi);
              if (codeSaisi!=1234){printf("code incorrect\n");}
              }
              choixa=0;
                while (choixa != 4) {
              afficherProduitsCritiques(nomFichier);
             
              afficher_mode_gestion();
              scanf("%d", &choixa);
              switch( choixa ){
                case 1: printf("Rechercher un produit\n");
                  
                    recherche_produit();// connaitre le stock d'un produit 
                    break;
                
                case 2: 
                    printf("1. augmenter un stock un produit\n");
                    const char* nomFichier = "stock.txt";
                    char nomProduit[50];
                    int quantite;
                    afficherStocksProduits(nomFichier);
                    printf("Entrez le nom du produit : ");
                    scanf("%s", nomProduit);
                    printf("Entrez la quantité à ajouter au stock : ");
                    scanf("%d", &quantite);
                    augmenterStock( nomProduit , quantite , nomFichier);
                    break;
                
                case 3:
                    lireCommentaires();
                    int retour=0;
                    while(retour!=1){
                    printf("appuyez sur 1 pour revenir sur le menu principal\n");
                    
                    scanf("%d",&retour);
                    if(retour==1){main();}
                    }
                    break;
                case 4: 
                    printf("4. Retour au menu principal\n");
                    main();   // sortir mode gestion des stocks retour au menu 
                    break;
                
                default:
                    printf("Choix invalide.\n");
                    break;
              }
                
          }

  break;

          
            case 2:
                // menu achat
              choixb=0;
              client *clientinfo = malloc(sizeof(client));
                while (choixb != 4) {
                    fflush(stdin);
                    
                        printf("Menu achat\n");
                        printf("Avez-vous un compte client ?\n");
                        printf("1. Non\n");
                        printf("2. Oui\n");
                        printf("3. Supprimer un compte\n");
                        printf("4. Retour Menu\n");
                        scanf("%d", &choixb);
                  switch (choixb) {
                        case 1:
                            create_client();
                            break;
                        case 2: 
                            break;
                    
                        case 3:
                            delete_client_account();
                            main();
                            break;
                    
                        case 4:
                            main();
                            break;
                    
                        default:
                            printf("Choix invalide.\n");
                            main();   
                            break;
                    }
                    
              
                identification_client(clientinfo);
              
                 
                mode_achat(clientinfo);
              }
                
              
                break;

            case 3:
                main(); // retour menu principal
                break;

            case 4:
                // Quitter le programme
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide.\n");
                break;
        }
    }

    return 0;
}  
