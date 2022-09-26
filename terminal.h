#ifndef TERMINAL_H
#define TERMINAL_H

#include "card.h"
typedef struct terminaldata_t{

    unsigned char transaction_Date[12];
    float transaction_Amount;
    float max_Transaction_Amount;

}terminaldata_t;

typedef enum en_terminal
{
	expired_Card, invalid_Amount,exceed_Max_Amount,invalid_Max_Amount
}en_terminal;

en_terminal getTransactiondate(terminaldata_t *ptd);
en_terminal isCardEXpired(carddata_t cd ,terminaldata_t td );
en_terminal getTransactionAmount(terminaldata_t* ptd );
en_terminal isBelowMaxAmount (terminaldata_t* ptd );
en_terminal setMaxAmount (terminaldata_t *ptd );




#endif // TERMINAL_H
