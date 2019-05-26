#include "lem_in.h"

/*
** Exemple :
** 13 fourmis
** Itineraires :
**               A->B->Z                   (3)
**               A->C->D->E->F->Z          (6)
**               A->G->H->I->J->Z          (6)
**               A->K->L->M->N->O->P->Q->Z (9)
**
**  1: L1-B L2-C L3-G L4-K
**  2: L1-Z L2-D L3-H L4-L L5-B L6-C L7-G L8-K
**  3:      L2-E L3-I L4-M L5-Z L6-D L7-H L8-L L9-B L10-C L11-G L12-K
**  4:      L2-F L3-J L4-N      L6-E L7-I L8-M L9-Z L10-D L11-H L12-L L13-B
**  5:      L2-Z L3-Z L4-O      L6-F L7-J L8-N      L10-E L11-I L12-M L13-Z
**  6:                L4-P      L6-Z L7-Z L8-O      L10-F L11-J L12-N
**  7:                L4-Q                L8-P      L10-Z L11-Z L12-O
**  8:                L4-Z                L8-Q                  L12-P
**  9:                                    L8-Z                  L12-Q
** 10:                                                          L12-Z
**
**   1 par 8
** + 4 par 5    + 1 par 5
** + 4 par 5    + 1 par 5
** + 7 par 2    + 4 par 2
** = 16 > 13    = 6 <= 13
**              -> La combinaison de chemins la plus opti'
**              -> 3 chemins
**              -> steps_to_add = (nb de fournmis
**                                 - nb de fourmis pouvant traverser
**                                   pendant que la fourmi empruntant
**                                   le chemin le plus long traverse la
**                                   fourmiliere)
**                                / nb de chemins
**                              = (13 - 6) / 3
**                              = 7 / 3
**                              = 2 (euclidienne : reste 1)
**                              -> prendre la partie superieure
**                              -> a = (b % c == 0) ? b / c : (b / c) + 1;
**
** Nombre total d'etapes :
** longueur du chemin le plus long a emprunter + steps_to_add = 5 + 3
**                                                            = 8
**
** 13 - 6 = 7 est le nombre de fourmis devant encore entrer dans la fourmiliere
** apres que la premiere fourmis ayant emprunte le chemin le plus long
** soit arrive
** 7 - 3 = 4 > 0  -> 4 + 3 = 7 fourmis passeront par le plus court chemin
** 4 - 3 = 1 > 0  -> 1 + 3 = 4 fourmis passeront par le 2e plus court chemin
** 1 - 3 = -2 <=0 -> 1 + 1 = 2 fourmis passeront par le 3e plus court chemin
**
**  1: L1-B L2-C L3-G
**  2: L1-Z L2-D L3-H L4-B L5-C L6-G
**  3:      L2-E L3-I L4-Z L5-D L6-H L7-B L8-C
**  4:      L2-F L3-J      L5-E L6-I L7-Z L8-D L9-B L10-C
**  5:      L2-Z L3-Z      L5-F L6-J      L8-E L9-Z L10-D L11-B
**  6:                     L5-Z L6-Z      L8-F      L10-E L11-Z L12-B
**  7:                                    L8-Z      L10-F       L12-Z L13-B
**  8:                                              L10-Z             L13-Z
**  9:
** 10:
**
*/



size_t	li_eval_steps(t_data *data, size_t index)
{
	size_t	i;

	i = 0;
	while (i < data->size)
	{

