#pragma once

typedef struct
{
    char *input;
    int position;
} StringReader;

StringReader *new_string_reader(char *string);

// return the char it is on
char reader_get(StringReader *reader);

// return the char it was on
char advance(StringReader *reader);

// peek next char without advancing
char peek(StringReader *reader);

// deallocate
char clean(StringReader *reader);