#pragma once
#include "token.h"
typedef struct
{
    Token_t *back;
    int length;
    int back_size;
} Tokens_t;

Tokens_t *new_tokens();
int push(Tokens_t *tokens, Token_t token);
Token_t *tokens_get(Tokens_t *tokens, int idx);
void clean_tokens(Tokens_t *tokens);