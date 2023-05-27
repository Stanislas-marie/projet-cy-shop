# projet-cy-shop

Le code est une implémentation d'un système de gestion de magasin. Il comprend des définitions de structures pour les produits et les clients, ainsi que des fonctions pour la création de compte client, l'identification du client, le remplissage du panier, la diminution du stock, le calcul du total du panier, l'affichage des produits en stock, la recherche de produits, la suppression du compte client, l'affichage des derniers produits achetés, l'achat de produits, le mode d'achat et l'affichage des produits critiques.

Le programme principal utilise une boucle while pour afficher le menu principal et attendre les choix de l'utilisateur. Selon le choix de l'utilisateur, différentes fonctions sont appelées pour effectuer les opérations correspondantes.


Dans le mode gestion : 

Le code fourni représente la partie qui gère les stocks de produits du magasin . Il permet de rechercher des produits ( grâce aux fonctions "rechercheProduit" qui vérifie si un produit recherché existe dans le fichier stock  et "recherche_produit" qui fait appel à la fonction précédente en lui fournissant le nom du fichier dnas lequel elle doit chercher le produit et son nom)  , d'augmenter les stocks de produits (la fonction "augmenterStock"permet d'augmenter le stock d'un produit par son nom en ouvrant le fichier stock). et d'afficher les produits dont le stock est critique(Pour cela le fonction "afficher_mode_gestion" ouvre le fichier "stock" et lit chaque ligne pour extraire les informations des produits.)


Pour  afficher le menu de gestion des stocks c'est la fonction "afficher_mode_gestion" qui est appelée lorsque l'utilisateur sélectionne l'option de menu "Menu gestion".

Pour afficher le menu principal on a besoin de la fonctio "afficher_menu" qui affiche le menu principal du programme, donnant accès aux différentes fonctionnalités elle appelée à chaque itération de la boucle principale du programme.


Limitations fonctionnelles / bugs connus :
- Le code ne gère pas les cas d'erreurs liés à l'ouverture ou à la lecture du fichier "stock".
- Certaines entrées utilisateur ne sont pas validées ou vérifiées, ce qui peut conduire à des comportements inattendus.
- Le code ne gère pas la modification d'autres informations des produits, telles que le prix ou la taille. Il se concentre principalement sur la gestion des stocks.


Dans le mode achat : 
Le code  permet aux utilisateurs de créer des comptes clients, de se connecter, de parcourir et d'acheter des produits, ainsi que d'effectuer d'autres opérations.

cette partie du code est composée de plusieurs fonctions telles que "create_client()" qui créée un fichier texte correspondant dans le répertoire "clients" après avoir demande à l'utilisateur son nom. ou la fonction "identification_client(client *clientinfo)" (qui récupère des  informations du compte du client  à partir du fichier texte correspondant à son nom.)` la fonction "delete_client_account()" quant à elle supprime un compte client en supprimant le fichier texte correspondant dans le répertoire "clients".

3. `remplissage_panier(char produits[], int quantite)`: Ajoute un produit et une quantité au panier en ajoutant les informations à un fichier "panier.txt".

4. `diminuer_stock(const char* nomProduit, int quantite, const char* nomFichier)`: Réduit le stock d'un produit d'une quantité spécifiée dans le fichier spécifié.

5. `calculerSommeTotal()`: Calcule le prix total des produits dans le panier en récupérant les informations à partir des fichiers "panier.txt" et "stock.txt".

6. `afficherStocksProduits(const char* nomFichier)`: Lit et affiche les informations sur tous les produits à partir du fichier spécifié.

7. `rechercheProduit(const char* nomProduitRecherche, const char* nomFichier)`: Recherche un produit spécifique par son nom dans le fichier spécifié et affiche ses informations s'il est trouvé.

la fonction recherche_produit() et rechercheProduit() sont également utilisées dans ce mode 

10. `afficher_derniers_produits(client client)`: Récupère les trois derniers produits achetés à partir de l'historique d'achats du client et les affiche.

11. `achat_produit(produits *produits, int taille)`: Permet à l'utilisateur d'acheter un produit en sélectionnant le produit et la quantité, en mettant à jour le stock et en calculant le prix total.

12. `validation_achat()`: Gère le processus d'achat en affichant les produits disponibles, en permettant à l'utilisateur de sélectionner un produit et une quantité, et en validant l'achat.

13. `mode_achat()`: Met en œuvre le mode d'achat, où l'utilisateur peut rechercher des produits, consulter le stock et effectuer des achats.

14. `afficherProduitsCritiques(const char* nomFichier)`: Lit et affiche les informations sur les produits ayant des niveaux de stock bas à partir du fichier spécifié.

Ce sont les principales fonctions du code. Il semble qu'il puisse y avoir certaines parties manquantes ou des fonctions non incluses dans l'extrait de code fourni, mais cela devrait vous donner un aperçu de la fonctionnalité.



