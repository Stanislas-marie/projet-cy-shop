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




