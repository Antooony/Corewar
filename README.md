# Corewar
Ce projet a pour objectif de créer une arène virtuelle et à y faire s’affronter des programmes codés dans un langage simpliste. cela comprend la conception d’une VM (avec les instructions qu’elle reconnait, les registres, etc), et un compilateur d’un langage assembleur en bytecode.  

### Compilation
un appel au makefile a l'aide de la commande ```$> make``` créera les programme asm et corewar, qui sont respectivement le compilateur et la vm
## l'ASM
L'asm est un compilateur qui transcrit du langage assembleur en bytecode.
L'objectif concret est de compiler les champions qui vont etre executés dans la VM.
les Champions ont le format suivant :
- Un 'magic number', defini dans les fichiers header 
- un header 
  ```
  .name "[nom de taille PROG_NAME_LENGTH]"
  .comment "[commentaire de taille COMMENT_LENGTH]"
  ```
- la taille du programme en octets
- le code du champion

#### Usage:
```
$> ./asm Champion.s
Writting output to Champion.cor
```
## la VM
La VM crée un zone memoire, dans laquelle elle va charger des "champions" qui vont se battre à l’aide de "processus", dans le but, entre autres, de faire en sorte qu’on dise d’eux qu’ils sont "en vie".
Les processus s’exécutent séquentiellement au sein de la même machine virtuelle, et du même espace mémoire. Ils peuvent donc, entre autre chose, s’écrire les uns sur les autres afin de se corrompre mutuellement, de forcer les autres à exécuter des instructions qui leur font du mal,

#### Usage:
```
Usage: ./corewar [-d N -s N -v N | -ncurse --stealth --sound] [-a] | -n N <champion1.cor> <...>
	-a        : Prints output from "aff" (Default is to hide it)
#### TEXT OUTPUT MODE ##########################################################
	-d N      : Affiche l'état de la memoire apres N cycles et quitte
	-s N      : Execute N cycles, affiche l'état de la mémoire, se met en pause, le tout en boucle
	-v N      : mode verbose, avec N Niveaux de verbose
		- 0 : Montre uniquement l'essentiel
		- 1 : Affiche les lives
		- 2 : Affiche les cycles
		- 4 : Affiche les operations (Params are NOT litteral ...)
		- 8 : Affiche les deaths
		- 16 : Affiche les ouvements du PC (Except for jumps)
#### NCURSES OUTPUT MODE #######################################################
	-ncurses        : lance le visualisateur en Ncurses
	--stealth       : Cache le contenu de la memoire
	--sound         : Ajout des effets sonnores
################################################################################
```

Un exemple d'execution du Corewar (demo incomplete):
``` ./corewar ressources/champs/Car.cor ressources/champs/Gagnant.cor -ncurses ```
![Alt Text](http://g.recordit.co/kt6BplOw47.gif)
