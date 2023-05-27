# projet-cy-shop

Le code est une implémentation d'un système de gestion de magasin. Il comprend des définitions de structures pour les produits et les clients, ainsi que des fonctions pour la création de compte client, l'identification du client, le remplissage du panier, la diminution du stock, le calcul du total du panier, l'affichage des produits en stock, la recherche de produits, la suppression du compte client, l'affichage des derniers produits achetés, l'achat de produits, le mode d'achat et l'affichage des produits critiques.

Le programme principal utilise une boucle while pour afficher le menu principal et attendre les choix de l'utilisateur. Selon le choix de l'utilisateur, différentes fonctions sont appelées pour effectuer les opérations correspondantes.


Dans le mode gestion : 

Le code fourni représente la partie qui gère les stocks de produits du magasin . Il permet de rechercher des produits ( grâce aux fonctions "rechercheProduit" et "recherche_produit" , d'augmenter les stocks de produits et d'afficher les produits dont le stock est critique. 
explication de chaque fonctionnalité :

1. Afficher les produits en stock "afficherStocksProduits":
   Cette fonction ouvre le fichier spécifié "stock" et affiche son contenu, qui représente les informations des produits en stock.

2. Rechercher un produit "rechercheProduit"
 Fonction qui  recherche un produit spécifique par son nom dans le fichier "stock". Elle extrait les informations du produit et les compare au produit recherché. Si le produit est trouvé, ses informations sont affichées. Sinon, un message indiquant que le produit recherché n'existe pas apparait. 

3. Rechercher un produit par son nom "recherche_produit":
 Elle demande à l'utilisateur d'entrer le nom d'un produit qu'il souhaite rechercher. Elle appelle ensuite la fonction "rechercheProduit" évoquée plus haut en lui fournissant le nom du produit recherché et le nom du fichier "stock".

4. Afficher les produits critiques "afficherProduitsCritiques":
Cette fonction s'occupe d'afficher les produits dont le tsock est à zero puis les 5 produits ayant les tsocks les plus bas. Pour cela          ouvre le fichier "stock" et lit chaque ligne pour extraire les informations des produits. 
   
5. Augmenter le stock d'un produit "augmenterStock":
Fonction qui permet d'augmenter le stock d'un produit par son nom. Elle ouvre le fichier "stock" en mode lecture et écriture. Elle       lit chaque ligne du fichier, extrait les informations du produit et les compare au produit en question . Si le produit est trouvé, son stock est augmenté de la quantité requise. Les informations du produit sont ensuite mises à jour dans le fichier.

6. Afficher le menu de gestion des stocks "afficher_mode_gestion":
  Elle a pour but d' afficher un menu contenant les options disponibles pour la gestion des stocks. 
  (appelée lorsque l'utilisateur sélectionne l'option de menu "Menu gestion".)

7. Afficher le menu principal "afficher_menu":
   Cette fonction affiche le menu principal du programme, donnant accès aux différentes fonctionnalités. 
   (appelée à chaque itération de la boucle principale du programme.)


Limitations fonctionnelles / bugs connus :
- Le code ne gère pas les cas d'erreurs liés à l'ouverture ou à la lecture du fichier "stock".
- Certaines entrées utilisateur ne sont pas validées ou vérifiées, ce qui peut conduire à des comportements inattendus.
- Le code ne gère pas la modification d'autres informations des produits, telles que le prix ou la taille. Il se concentre principalement sur la gestion des stocks.




