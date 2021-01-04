#  Vous vous croyez fort ? Prouvez-le.

Vous pensez pouvoir faire mieux que le prof ?
Voici votre chance.
J'ai écrit un programme pour résoudre le problème posé.
Écrivez un programme qui affiche la bonne réponse plus rapidement que le mien par une marge de 20% et c'est gagné.
Si vous réussissez, ce sera *votre* programme que les étudiants auront à battre l'année prochaine !

# Le problème

Ce problème est tiré du livre «[Doctor Ecco's cyberpuzzles](https://www.goodreads.com/book/show/82492.Doctor_Ecco_s_Cyberpuzzles)» de Dennis E. Shasha.

Nous avons aujourd'hui les dénominations suivantes pour les pièces de monnaie de moins d'un euro : 1¢, 2¢, 5¢, 10¢, 20¢ et 50¢.
Ces dénominations sont intuitives pour les humains.
En effet, il nous est facile de calculer mentalement les pièces requises pour «donner le change».
Seulement... ces dénominations ne sont pas optimales.
En effet, pour tout les prix compris entre 1¢ et 99¢ le nombre de pièces que nous auront à débourser en moyenne sera de 3,434343 pièces.

Il existe une suite de dénominations qui donne un meilleur résultat : 1¢, 2¢, 5¢, 11¢, 25¢ et 62¢.
Pour ces dénominations, le nombre de pièces à donner en moyenne pour tout les prix compris entre 1¢ et 99¢ est de 3,1616 pièces.
Évidement moins intuitifs à calculer pour des humains mais nous, nous  sommes des *programmeurs !*

La question est la suivante : pour un ensemble D de N dénominations {D<sub>1</sub>, ..., D<sub>N</sub>} quelles sont les dénominations qui donnent en moyenne le plus petit nombre de pièces pour tout les prix compris entre 1¢ et 99¢ ?

Le calcul du nombre de pièces requises est fait de façon simple.
Pour un prix P, le nombre de pièces requises R est calculé par R(P, D) = P / D<sub>N</sub> + (P - P / D<sub>N</sub>) / D<sub>N-1</sub> + ... .
Par exemple :

<img src="https://render.githubusercontent.com/render/math?math=%5Clarge%0A%5Cbegin%7Balign*%7D%0AR(96%2C%20%5Cleft%5C%7B1%2C2%2C5%2C10%2C20%2C50%5Cright%5C%7D)%26%3D96%2F50%2B46%2F20%2B6%2F5%2B1%2F1%5C%5C%0A%26%3D1%2B2%2B1%2B1%5C%5C%0A%26%3D5%0A%5Cend%7Balign*%7D" >

## La réponse au problème

Comme mentionné, j'ai déjà écrit un programme qui résout le problème.
Voici les meilleurs candidats pour N allant de 3 à 6 :

| N | Dénominations | Moyenne | Combinaisons possibles |
|:-:|:-:|:- | -:|
| 3 | {1¢, 5¢, 22¢} | 5,313131 | 4753 |
| 4 | {1¢, 3¢, 11¢, 37¢} | 4,141414 | 152096 |
| 5 | {1¢, 3¢, 7¢, 16¢, 40¢} | 3,49495 | 3612280 |
| 6 | {1¢, 2¢, 5¢, 11¢, 25¢, 62¢} | 3,161616 | 67910864 |

Pour obtenir tout ces résultats, mon programme s'exécute sur mon ordinateur pendant environ trois minutes et trente secondes.

# L'objectif

Mon programme se trouve dans le fichier `champion.c`.
Le votre sera dans le fichier `challenger.c`.

La cible `make compete` va compiler les deux programmes et comparer leur temps d'exécution.
Si votre temps d'exécution est en deçà du mien par 20% (T<sub>challenger</sub> / T<sub>champion</sub> < 0,8), contactez-moi vite !
Bien sur, je vais aussi vérifier l'intégrité de votre programme...

Il n'y pas de limites à ce que vous pouvez faire, en autant que votre programme puisse se compiler avec `gcc`.
Je désire voir aussi une amélioration substantielle de la performance, pas seulement un programme qui «rogne» quelques millisecondes par-ci par-là, d'où le 20%. Mais sachez que je n'ai pas particulièrement optimisé mon programme, seulement écrit de façon plutôt naïve.

