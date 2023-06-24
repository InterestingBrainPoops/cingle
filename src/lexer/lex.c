#include "lex.h"
#include "reader.h"

Tokens_t *lex(char *text)
{
    Tokens_t *out = new_tokens();
    StringReader *reader = new_string_reader(text);

    while (reader_get(reader))
    {
        switch (reader_get(reader))
        {
        case '=':
            if (peek(reader) == '=')
            {
                push(out, new_symbol_token(EqualsEquals));
            }
            else
            {
                push(out, new_symbol_token(Equals));
            }
            break;
        case '>':
            if (peek(reader) == '=')
            {
                push(out, new_symbol_token(GreaterEquals));
            }
            else
            {
                push(out, new_symbol_token(Greater));
            }
            break;
        case '<':
            if (peek(reader) == '=')
            {
                push(out, new_symbol_token(LessEquals));
            }
            else
            {
                push(out, new_symbol_token(Less));
            }
            break;
        case '+':
            push(out, new_symbol_token(Plus));
        case '-':
            push(out, new_symbol_token(Minus));
        case '/':
            push(out, new_symbol_token(ForwardSlash));
        case '\\':
            push(out, new_symbol_token(BackSlash));
        case '*':
            push(out, new_symbol_token(Asterisk));
        default:
            break;
        }
    }
}