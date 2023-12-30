# Fract-ol

## Le projet

Afficher et genere une general avec les ensembles de Julia et de Mandelbrot.

## Fonctions autorises

- open, close, read, write, malloc, perror, sterror, exit
- Toutes les fonctions de la bibliothèque mathématique
- fonctions de minilibx
- ftprinft, gnl, libft

## Les fractals

Des formes infiniments complexes, zoom infini, formes auto-similaires
-> Creer des fractals a partir des nombres complexes

Les nombres complexes : 
on peut placer les nombres sur un plan 2D, donc deux axes = les imaginaires, les reels 
exemple: 3 + 2i (le point est decale de 3 unites vers la droite et 2 unites vers le haut)

Pour generer une fractal, on a besoin de faire un calcul a partir d'un nb complexe et apres sur le resultat
(diverger ou boucler a l'infini)

-> colorier chaque point en fonction du comportement de la suite donne (blanc diverge et noir si non)


# Code

- Une fonction pour calculer mandelbrot
- Une fonction pour calculer julia
- Une fonction pour dessiner la fractal
- une fonction main qui regroupe
- une fonction de verif input user
- une fonction d'erreurs