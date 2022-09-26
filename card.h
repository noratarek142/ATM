#ifndef card_header
#define card_header
#define size 30
#define size1 20
typedef struct carddata_t
{
	unsigned char holder_Name[size];
	unsigned int P_A_N[size1];
	unsigned char expiration_Date[8];

}carddata_t;

typedef enum en_card
{
	wrong_name,wrong_date,wrong_PAN,done
}en_card;

en_card getCardHolderName(carddata_t* pcd);
en_card getCardExpiryDate(carddata_t* pcd);
en_card getCardPAN(carddata_t* pcd);

#endif
