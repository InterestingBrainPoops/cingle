#include "token.h"
Token_t new_string_token(char *string)
{
    Token_t out = {
        .type = String,
        .string = string};
}
Token_t new_integer_token(int integer)
{
    Token_t out = {
        .type = Integer,
        .integer = integer};
}
Token_t new_float_token(float float_num)
{
    Token_t out = {
        .type = Float,
        .Float = float_num};
}
Token_t new_symbol_token(Symbol_t symbol)
{
    Token_t out = {
        .type = Symbol,
        .symbol = symbol};
}