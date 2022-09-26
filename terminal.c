#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "card.h"


en_terminal getTransactiondate(terminaldata_t *ptd)
{
    unsigned char transaction_date[11];
    printf("enter transaction date: ");
    scanf("%s",transaction_date);

    if(transaction_date==NULL || strlen(transaction_date) !=10)
    {
        return wrong_date;

    }
    strcpy(ptd->transaction_Date,transaction_date);
    return done;
}

en_terminal isCardEXpired(carddata_t cd ,terminaldata_t td )
{
    int cardmonth=((cd.expiration_Date[0])*10) + cd.expiration_Date[1];
    int cardyear=((cd.expiration_Date[3])*10) + cd.expiration_Date[4];
    int transactionmonth=((td.transaction_Date[3])*10) + td.transaction_Date[4];
    int transactionyear=((td.transaction_Date[8])*10)  +td.transaction_Date[9];
    if(cardyear<transactionyear || (transactionyear==cardyear && transactionmonth>cardmonth))

    {
        printf("this card is expired \n");
        return expired_Card;
    }
    else
        {
        printf("done \n");
        return done;
    }
}

en_terminal getTransactionAmount(terminaldata_t *ptd)
{
    float amount;
    printf("enter transaction amount: ");
    scanf(" %f",&amount);

    if(amount<=0)
    {
        return invalid_Amount;
    }
    ptd->transaction_Amount=amount;
    return done;
}

en_terminal isBelowMaxAmount (terminaldata_t* ptd )
{
    if(ptd->max_Transaction_Amount < ptd->max_Transaction_Amount)
    {
        printf("transaction declined\n exceeded amount\n");
        return exceed_Max_Amount;
    }
    else
    {
        printf(" valid amount");
        return done;
    }
}

en_terminal setMaxAmount (terminaldata_t *ptd )
{
    float max_amount;
    printf("please enter max amount: ");
    scanf(" %f",&max_amount);
    if(max_amount<=0)
    {
        return invalid_Max_Amount;
    }
    ptd->max_Transaction_Amount=max_amount;
    return done;
}






