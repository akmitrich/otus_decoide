#include <stdio.h>
#include <unistd.h>
#include <string.h>

enum encodings_e
{
    CP1251,
    KOI8R,
    ISO_8859_5
};

int main(int argc, const char *argv[])
{
    FILE *input;
    enum encodings_e encoding;
    FILE *output;

    const char *program = argv[0];
    printf("%s -- converts a FILE from one of the three encoding into UTF-8\n", program);
    if (argc < 2)
    {
        printf("Usage: %s FILE [ENC] [OUTPUT]\n", program);
        printf("FILE -- input file encoded in\n");
        printf("ENC -- one of three encodings: CP1251 | KOI8-R | ISO-8859-5. Default is CP1251\n");
        printf("OUTPUT -- path to save decoded file, default is stdout\n");
        return 1;
    }

    input = fopen(argv[1], "rb");

    if (argc > 2)
    {
        if (strncmp(argv[2], "cp", 2) == 0 || strncmp(argv[2], "CP", 2))
            encoding = CP1251;
        if (strncmp(argv[2], "koi", 3) == 0 || strncmp(argv[2], "KOI", 3))
            encoding = KOI8R;
        if (strncmp(argv[2], "iso", 3) == 0 || strncmp(argv[2], "ISO", 3))
            encoding = ISO_8859_5;
    }
    else
        encoding = CP1251;

    if (argc == 4)
        output = fopen(argv[3], "wb");
    else
        output = NULL;

    printf("SINOPSIS: Take file %p encoded with %d and save it to the %p\n", (void *)input, encoding, (void *)output);

    if (output)
        fclose(output);
    fclose(input);

    return 0;
}