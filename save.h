#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED
#include "structure.h"

void sizeFile(int *size_x,int *size_y); //Taille du fichier
void sizeId(int *size_x, int *size_y); //Taille du tableau ID
char** tabTree(); //Ajout du de l'intégralité du fichier texte dans un tableau 2D de caractères
int** tabId(); //Ajout des ID du fichier dans un tab 2D d'entiers
int counterLSC(Idlist a); //Compte la longueur de la structure d'ID
int* convertLSCtoTab(Idlist a, int size); //Convertisseur une LSC dans un tableau de int
int posIdTab(int *tab_new_tree, int **tab_id, int x_id, int size_new_tree); //Donne la position du nouveau élément à ajouter dans le fhicher de sauvegarde
int sizeTabChar1D(char *tab); //Taille d'une chaine de caractère
void counterCharLSC(taglist a, int *c_size, int *t_size); //Compteur du nombre de caractère dans toute une LSC
int sizeInfoNewTree(tree a); //Taille de toutes les infos du nouvel arbre
char** addNewId(tree a, int pos, int *tab_id, int size_id, char **tab_tree, int x_tree, int y_tree); //Ajout le nouvel arbre dans le tableau 2D du fichier en le mettant à la bonne position
void insertTreeToFile(char **tab_tree, int size_x); //Insertion du nouveau arbre dans le fichier texte
void sortFolderTree(tree a); //Fonction qui regroupe toutes les étapes pour sauvegarder un nouvel arbre dans le fichier de sauvegarde

#endif // SAVE_H_INCLUDED
