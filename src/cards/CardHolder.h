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
    void SetupCards();
    void DrawCards();
    void HoldCard(Card& card);
    void ReleaseCard(Card& card);
    bool IsCardBeingHeld() const;
    void SetCardBeingHeld(bool value);

    private:
    std::vector<Card> cards;
    bool isCardBeingHeld;
    Rectangle preHeldCardRect;

};


#endif //INC_2D_CITY_BUILDER_CARDHOLDER
