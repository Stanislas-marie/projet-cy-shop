# projet-cy-shop

Le code comprend des définitions de structures pour les produits et les clients, ainsi que des fonctions pour la création de compte client, l'identification du client, le remplissage du panier, la diminution du stock, le calcul du total du panier, l'affichage des produits en stock, la recherche de produits, la suppression du compte client, l'affichage des derniers produits achetés, l'achat de produits, le mode d'achat et l'affichage des produits critiques.

Le programme principal utilise une boucle while pour afficher le menu principal et attendre les choix de l'utilisateur. Selon le choix de l'utilisateur, différentes fonctions sont appelées pour effectuer les opérations correspondantes.


Dans le mode gestion : 

Le code fourni représente la partie qui gère les stocks de produits du magasin . Il permet de rechercher des produits ( grâce aux fonctions "rechercheProduit" qui vérifie si un produit recherché existe dans le fichier stock  et "recherche_produit" qui fait appel à la fonction précédente en lui fournissant le nom du fichier dans lequel elle doit chercher le produit et son nom)  , d'augmenter les stocks de produits (la fonction "augmenterStock"permet d'augmenter le stock d'un produit par son nom en ouvrant le fichier stock). et d'afficher les produits dont le stock est critique(Pour cela le fonction "afficher_mode_gestion" ouvre le fichier "stock" et lit chaque ligne pour extraire les informations des produits.)


Pour  afficher le menu de gestion des stocks c'est la fonction "afficher_mode_gestion" qui est appelée lorsque l'utilisateur sélectionne l'option de menu "Menu gestion".

Pour afficher le menu principal on a besoin de la fonction "afficher_menu" qui affiche le menu principal du programme, donnant accès aux différentes fonctionnalités elle est appelée à chaque itération de la boucle principale du programme.


Limitations fonctionnelles et bugs possibles :
- Certaines entrées utilisateur ne sont pas vérifiées. 
- Le code ne gère pas la modification d'autres informations des produits, telles que le prix ou la taille. Il se concentre principalement sur la gestion des stocks.


Dans le mode achat : 
Le code  permet aux utilisateurs de créer des comptes clients, de se connecter, de parcourir et d'acheter des produits, ainsi que d'effectuer d'autres opérations.

cette partie du code est composée de plusieurs fonctions telles que "create_client()" qui créée un fichier texte correspondant dans le répertoire "clients" après avoir demande à l'utilisateur son nom. ou la fonction "identification_client(client *clientinfo)" (qui récupère des  informations du compte du client  à partir du fichier texte correspondant à son nom).La fonction "delete_client_account()" quant à elle supprime un compte client en supprimant le fichier texte correspondant dans le répertoire "clients".

la fonction "mode_achat()": Met en œuvre le mode d'achat, où l'utilisateur peut rechercher des produits, consulter le stock et effectuer des achats.
"achat_produit(produits *produits, int taille)" Permet à l'utilisateur d'acheter un produit en sélectionnant le produit et la quantité, puis en mettant à jour le stock et en calculant le prix total de la commade.
"validation_achat()": s'occupe du processus d'achat en affichant les produits disponibles, en permettant à l'utilisateur de sélectionner un produit et une quantité, et en validant l'achat.
 "afficherProduitsCritiques(const char* nomFichier)"  affiche les informations sur les produits ayant des niveaux de stock bas à partir du fichier precis. 
 
Si on regarde en détails différentes fonctionnalités sont requises pour que l'achat se déroule correctement   lorsque le client réalise un achat et remplit son panier la fonction "remplissage_panier(char produits[], int quantite"  ajoute un produit et une quantité au panier en ajoutant les informations à un fichier "panier.txt". Le prix a payer s'affiche alors grâce à "calculerSommeTotal()" qui calcule le prix total des produits dans le panier. une fois son achat validé son panier se vide grâce à la fonction 
la fonction recherche_produit() et rechercheProduit() sont également utilisées dans ce mode.Enfin, "afficher_derniers_produits(client client)" Récupère les trois derniers produits achetés à partir de l'historique d'achats du client et les affiche.


Ce sont les principales fonctions du code qui donnent un apercu de la fonctionnalité finale. 

Limitations fonctionnelles et bugs possibles :
- Le programme ne vérifie pas l'identité du client qui se connecte, pour corriger ca on pourrait ajouter un code pin choisi par le client qu'il devrait utiliser pour se connecter. 
- Le code ne gère pas la modification d'autres informations des produits, telles que le prix ou la taille. Il se concentre principalement sur la gestion des stocks.
- Certaines fonctions comme la fonctionne de recherche de produits ne sont pas optimisés si on augmente fortments le nombre de produits.

Pour prendre en main rapidement l'outils Cy_Shop voici des consignes d'utilisation :

CONSIGNE D'UTILISATION :
Pour pouvoir se servir correctements de L'outils Cy shop vous devez avoir telechargez tout les fichiers contenu dans le code principal : 
le dossier clients , les fichiers texte clients a l'intérieur , le fichier stock.txt , le fichier texte commentaires.txt et le fichier make file.

Pour ce servir de l'outils Cy shop en mode gestion vous devez rentrer un code pin qui est : "1234"
Le programme vous demandera de saisir des ombres ou des lettres en fonctions de ce que vous foudrez faire.
Utilisez "o" ou "O" pour répondre oui et "n" ou "N" pour réponde non.

Dans le fichiers stock.txt les produits sont enregistrer sous la forme: nomduproduits références taille prix stock.
Le fichier de chaque client est juste au nom du client sous la forme PrenomNom et contient l'historique d'achat de ce dernier.



Vous pouvez vous servir du lien replit suivant pour une experience plus optimisée :




