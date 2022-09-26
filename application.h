
#ifndef APPLICATION_HEADER
#define APPLICATION_HEADER

#include "card.h"
#include "terminal.h"
#include "server.h"


typedef enum app_module_t
{
    finish_card,finish_terminal
}app_module_t;

void appstart(void);

#endif // APPLICATION_HEADER
