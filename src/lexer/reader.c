#include "reader.h"
#include "malloc.h"
StringReader *new_string_reader(char *string)
{
    StringReader *out = malloc(sizeof(StringReader));
    out->input = string;
    out->position = 0;
}

char reader_get(StringReader *reader)
{
    return reader->input[reader->position];
}

char advance(StringReader *reader)
{
    reader->position += 1;
    return reader->input[reader->position - 1];
}

char peek(StringReader *reader)
{
    return reader->input[reader->position + 1];
}

void clean_reader(StringReader *reader)
{
    free(reader->input);
    free(reader);
}