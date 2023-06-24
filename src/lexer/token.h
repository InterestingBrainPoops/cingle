#include "stdint.h"
#pragma once
typedef enum
{
    String,
    Integer,
    Float,
    Symbol
} TokenType_t;

typedef enum
{
    Equals,
    EqualsEquals,
    Greater,
    GreaterEquals,
    Less,
    LessEquals,
    Plus,
    Minus,
    ForwardSlash,
    BackSlash,
    Asterisk,
} Symbol_t;

typedef struct
{
    TokenType_t type;
    union
    {
        char *string;
        int64_t integer;
        float Float;
        Symbol_t symbol;
    };

} Token_t;

Token_t new_string_token(char *string);
Token_t new_integer_token(int integer);
Token_t new_float_token(float float_num);
Token_t new_symbol_token(Symbol_t symbol);