//
// Created by johnc on 28/08/2026.
//

#ifndef INC_2D_CITY_BUILDER_CARDHOLDER
#define INC_2D_CITY_BUILDER_CARDHOLDER
#include <vector>

#include "Card.h"


class CardHolder
{
    public:
    CardHolder();
    void DrawCards();
    void DrawCard(Card &card, int x);

    private:
    std::vector<Card> cards;

};


#endif //INC_2D_CITY_BUILDER_CARDHOLDER
