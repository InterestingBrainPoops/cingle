#include "tokens.h"
#include "malloc.h"
Tokens_t *new_tokens()
{
    Tokens_t *out = (Tokens_t *)malloc(sizeof(Tokens_t));

    out->back = (Token_t *)malloc(sizeof(Token_t) * 50);
    out->length = 0;
    out->back_size = 50;
    return out;
}
int push(Tokens_t *tokens, Token_t token)
{
    if (tokens->length == tokens->back_size)
    {
        tokens->back_size += 50;
        tokens->back = realloc(tokens->back, tokens->back_size * sizeof(Token_t));
    }
    if (tokens->back == NULL)
    {
        return 1;
    }
    else
    {
        tokens->length += 1;
        tokens->back[tokens->length] = token;
        return 0;
    }
}
Token_t *tokens_get(Tokens_t *tokens, int idx)
{
    return &tokens->back[idx];
}

void clean_tokens(Tokens_t *tokens)
{
    free(tokens->back);
    free(tokens);
}
