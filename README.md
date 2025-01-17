#  Vous vous croyez fortiche ? Prouvez-le.

Vous pensez pouvoir écrire du meilleur code que le prof ?
Voici votre chance.
J'ai écrit un programme pour résoudre le problème posé.
Écrivez un programme qui affiche les bons résultats 10% plus rapidement que le mien et c'est gagné.
Si vous réussissez, ce sera *votre* programme que les étudiants auront à battre l'année prochaine !

# Le problème

Ce problème est tiré du livre «[Doctor Ecco's cyberpuzzles](https://www.goodreads.com/book/show/82492.Doctor_Ecco_s_Cyberpuzzles)» de [Dennis E. Shasha](https://en.wikipedia.org/wiki/Dennis_Shasha).

Nous avons aujourd'hui les dénominations suivantes pour les pièces de monnaie de moins d'un euro : 1¢, 2¢, 5¢, 10¢, 20¢ et 50¢.
Ces dénominations sont intuitives pour les humains.
En effet, il nous est facile de calculer mentalement les pièces requises pour rendre la monnaie.
Seulement... ces dénominations ne sont pas optimales.
En effet, pour tous les prix compris entre 1¢ et 99¢ le nombre de pièces que nous auront à débourser en moyenne sera de 3,434343 pièces.

Il existe un ensemble de dénominations qui donne un meilleur résultat : 1¢, 2¢, 5¢, 11¢, 25¢ et 62¢.
Pour ces dénominations, le nombre de pièces à donner en moyenne pour tous les prix compris entre 1¢ et 99¢ est de 3,1616 pièces.
Évidement moins intuitifs à calculer pour des humains mais nous, nous  sommes des *programmeurs !*

La question est la suivante : pour un ensemble de N dénominations {D<sub>1</sub>, ..., D<sub>N</sub>}, quelles sont les dénominations qui donnent en moyenne le plus petit nombre de pièces pour tous les prix compris entre 1¢ et 99¢ ?
Calculez les ensembles D optimaux pour N = 3, 4, 5 et 6.

Le calcul du nombre de pièces requises est fait de façon simple.
Pour un prix P, le nombre de pièces requises R est calculé par R(P, D) = P / D<sub>N</sub> + (P - P / D<sub>N</sub>) / D<sub>N-1</sub> + ... .
Par exemple :

<img src="https://render.githubusercontent.com/render/math?math=%5Clarge%0A%5Cbegin%7Balign*%7D%0AR(96%2C%20%5Cleft%5C%7B1%2C2%2C5%2C10%2C20%2C50%5Cright%5C%7D)%26%3D96%2F50%2B46%2F20%2B6%2F5%2B1%2F1%5C%5C%0A%26%3D1%2B2%2B1%2B1%5C%5C%0A%26%3D5%0A%5Cend%7Balign*%7D" >

[//]: # (Generated with: https://jsfiddle.net/8ndx694g/)

## La réponse au problème

Comme mentionné, j'ai déjà écrit un programme qui résout le problème.
Voici les meilleurs ensembles pour N allant de 3 à 6 :

| N | Dénominations | Moyenne | Combinaisons possibles |
|:-:|:-:|:- | -:|
| 3 | {1¢, 5¢, 22¢} | 5,313131 | 4753 |
| 4 | {1¢, 3¢, 11¢, 37¢} | 4,141414 | 152096 |
| 5 | {1¢, 3¢, 7¢, 16¢, 40¢} | 3,49495 | 3612280 |
| 6 | {1¢, 2¢, 5¢, 11¢, 25¢, 62¢} | 3,161616 | 67910864 |

Pour obtenir tous ces résultats, mon programme s'exécute sur mon ordinateur pendant environ une minute trente secondes.
Mais ce qui importe c'est le temps relatif entre votre programme et le mien.

# L'objectif

Mon programme se trouve dans le fichier `champion.c`.
Le votre sera dans le fichier `challenger.c`.

La cible `make compete` va compiler les deux programmes et comparer leur temps d'exécution.
Si votre temps d'exécution est en deçà du mien par au moins 10% (T<sub>challenger</sub> / T<sub>champion</sub> < 0,9), contactez-moi vite !
Bien sur, je vais aussi vérifier l'intégrité de votre programme...

Il n'y pas de limites à ce que vous pouvez faire, tant que votre programme puisse être compilé avec un compilateur C.
Je désire voir aussi une amélioration substantielle de la performance, pas seulement un programme qui «rogne» quelques millisecondes par-ci par-là, d'où le 10%.
Sachez cependant que je n'ai pas particulièrement optimisé mon programme.
