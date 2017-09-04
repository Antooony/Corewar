#!/bin/bash

liste_fichiers=`ls ressources/champs/*.s`

for fichier in $liste_fichiers
do
        ./asm $fichier
done
