#include "deck.h"

/**
 * get_card_value - gets the numeric value of the card
 *
 * @value: Value of the card
 *
 * Return: numeric value of the card
 */
int get_card_value(const char *value)
{
	if (!strcmp(value, "Ace"))
		return (1);
	else if (!strcmp(value, "2"))
		return (2);
	else if (!strcmp(value, "3"))
		return (3);
	else if (!strcmp(value, "4"))
		return (4);
	else if (!strcmp(value, "5"))
		return (5);
	else if (!strcmp(value, "6"))
		return (6);
	else if (!strcmp(value, "7"))
		return (7);
	else if (!strcmp(value, "8"))
		return (8);
	else if (!strcmp(value, "9"))
		return (9);
	else if (!strcmp(value, "10"))
		return (10);
	else if (!strcmp(value, "Jack"))
		return (11);
	else if (!strcmp(value, "Queen"))
		return (12);
	else if (!strcmp(value, "King"))
		return (13);
	else
		return (-1);
}

/**
 * compare_cards - Desc
 *
 * @card1: Value of the card
 * @card2: Value of the card
 *
 * Return: diff
 */
int compare_cards(const void *card1, const void *card2)
{
	const deck_node_t *c1 = *(const deck_node_t **)card1;
	const deck_node_t *c2 = *(const deck_node_t **)card2;

	int value1 = get_card_value(c1->card->value);
	int value2 = get_card_value(c2->card->value);

	if (value1 != value2)
		return (value1 - value2);
	else
		return (c1->card->kind - c2->card->kind);
}

/**
 * sort_deck - Desc
 *
 * @deck: Value of the card
 */
void sort_deck(deck_node_t **deck)
{
	int i;
	deck_node_t *temp;
	deck_node_t **array;

	temp = *deck;
	array = malloc(52 * sizeof(*array));

	while (temp != NULL)
	{
		array[i] = temp;
		temp = temp->next;
		i++;
	}

	qsort(array, 52, sizeof(*array), compare_cards);

	for (i = 0; i < 51; i++)
	{
		array[i]->next = array[i + 1];
	}

	array[51]->next = NULL;

	for (i = 51; i > 0; i--)
	{
		array[i]->prev = array[i - 1];
	}

	array[0]->prev = NULL;
	*deck = array[0];
	free(array);
}
