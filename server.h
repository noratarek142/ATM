#ifndef SERVER_HEADER
#define SERVER_HEADER

#include "card.h"
#include "terminal.h"

typedef enum en_server
{
    server_done,saving_is_failed,transaction_lost,account_lost,low_balance,DECLINED_INSUFFECIENT_FUND
}en_server;
typedef enum en_transaction
{
    Approved, stolen_card, server_error
}en_transaction;


typedef struct account_t
{
    float balance;
    char P_A_N[20];

}account_t;

typedef struct transaction_t
{
    carddata_t card_Holder_Data;
    terminaldata_t terminal_Data;
    en_transaction transaction_State;
    unsigned int T_S_N;

}transaction_t;





en_transaction recieveTransactionData(transaction_t*ptd);
en_server isValidAccount(carddata_t*pcd);
en_server isAmountAvailable(terminaldata_t*ptd , account_t* ar);
en_server saveTransaction(transaction_t* ptd);
en_server getTransaction(unsigned int Transaction_SN,transaction_t*ptd);
//en_transaction updateBalance(transaction_t*ptd);





# endif // SERVER_HEADER
