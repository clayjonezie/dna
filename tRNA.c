#include <stdio.h>
#include <strings.h>

int acid_to_index(char c) {
    switch (c) {
        case 'U':
            return 0;
        case 'T':
            return 0;
        case 'C':
            return 1;
        case 'A':
            return 2;
        case 'G':
            return 3;
    }
    return -1;
}

int amino_acid(char c1, char c2, char c3, char *buf) {
    short i1, i2, i3;
    i1 = acid_to_index(c1);
    i2 = acid_to_index(c2);
    i3 = acid_to_index(c3);

    if (i1 < 0 || i2 < 0 || i3 < 0)
        return 0;

    char *protiens[][4][4]
                    = {{{"Phenylalanine", "Phenylalanine", "Leucine", "Leucine"},
                       {"Serine", "Serine", "Serine", "Serine"},
                       {"Tyrosine", "Tyrosine", "Stop", "Stop"},
                       {"Cystenine", "Cysteine", "Stop", "Tryptophan"}},
                      {{"Leucine", "Leucine", "Leucine", "Leucine"},
                       {"Proline", "Proline", "Proline", "Proline"},
                       {"Histidine", "Histidine", "Glutamine", "Glutamine"},
                       {"Arginine", "Arginine", "Arginine", "Arginine"}},
                      {{"Isoleucine", "Isoleucine", "Isoleucine", "Methionine"},
                       {"Threonine", "Threonine", "Threonine", "Threonine"},
                       {"Asparagine", "Asparagine", "Lysine", "Lysine"},
                       {"Serine", "Serine", "Arginine", "Arginine"}},
                      {{"Valine", "Valine", "Valine", "Valine"},
                       {"Alanine", "Alanine", "Alanine", "Alanine"},
                       {"Aspartate", "Aspartate", "Glutamate", "Glutamate"},
                       {"Glycine", "Glycine", "Glycine", "Glycine"}}};
    strcpy(buf, protiens[i1][i2][i3]);
    return 1; // status
}

int transcribe() {
    char c1, c2, c3;
    char buf[100];
    while(scanf("%c%c%c", &c1, &c2, &c3) == 3) {
        if(amino_acid(c1, c2, c3, &buf))
            printf("%s\n", buf);
    }

    return 1;
}


int main(int argc, char **argv) {
    transcribe();
}
