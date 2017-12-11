# ProjectL2inVADE-Explorateur
Deuxième itération du projet L2 - Explorateur de fichiers en C/SDL

Groupe inVADE - Emrick DONADEI, Damien CLAEYMAN, Arnaud BOUGES, Vincent NOMISISCIO

--------

Le but du projet était de faire coincider un système de tags, un calendrier et une base de données pour proposer à l'élève des pistes de révision en fonction son calendrier de cours et des documents présents sur son disque dur:

- base de données générée par un fichier .txt (arbre.txt)
- liste d'échéances générée dans le main
- Des tags ajoutés à chaque maillon de l'arbre et/ou de la liste d'échéance

Tout est fonctionnel en console, mais nous avons raté le coche pour le passage à la SDL.

Dans la partie console:
- La liste d'échéance s'affiche et vous présente les matières à réviser de manière urgente (un système de score calcule cela en fonction de l'éloignement de l'échéance, de l'importance de l'échéance, et du niveau d'importance, 1 pour cours, 3 pour CE, 5 pour DE)

- Vous choisissez les tags que vous souhaitez mettre en avant

- La liste d'échéance se recalcule en fonction des tags choisis et met en avant vos préférences

Dans la partie SDL:
- La liste d'échéance s'affiche et vous présente les matières à réviser de manière urgente (un système de score calcule cela en fonction de l'éloignement de l'échéance, de l'importance de l'échéance, et du niveau d'importance, 1 pour cours, 3 pour CE, 5 pour DE)

- Vous choisissez les tags que vous souhaitez mettre en avant

- Le recalcul de la liste d'échéance ne s'effectue pas car nous n'avons pas réussi à reboucler des exécutions de SDL

- L'affichage se fait mal pour des raisons que nous n'avons pas compris !! 

-------

Notre Github pour vérifier l'agencement des commits et l'évolution du code:
https://github.com/edonadei/ProjectL2inVADE-Explorateur/commits/master

------- 

Voici le manuel d'installation pour exécuter le programme et la SDL:

Installateur: 
https://github.com/Augustin-FL/Compilateurs-C-EFREI

Suivre les étapes présentes sur le site.

Puis: 
clic-droit sur projet -> build options -> linker settings -> other linkers : -lmingw32 -lSDLmain -lSDL -lm -lSDL_image -lSDL_net -lSDL_gfx -lSDL_mixer -lSDL_ttf
