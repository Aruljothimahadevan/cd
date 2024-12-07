#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTIONS 100
#define MAX_SYMBOLS 100

typedef struct {
    char nonTerminal;
    char production[10];
} Production;

typedef struct {
    char nonTerminals[MAX_SYMBOLS];
    char terminals[MAX_SYMBOLS];
    char parsingTable[MAX_SYMBOLS][MAX_SYMBOLS][10];
    int numNonTerminals;
    int numTerminals;
} Parser;

void addTerminal(Parser *parser, char terminal) {
    parser->terminals[parser->numTerminals++] = terminal;
}

void addNonTerminal(Parser *parser, char nonTerminal) {
    parser->nonTerminals[parser->numNonTerminals++] = nonTerminal;
}

void addProduction(Parser *parser, char nonTerminal, const char *production, int pos) {
    strcpy(parser->parsingTable[nonTerminal - 'A'][pos], production);
}

int findTerminal(Parser *parser, char terminal) {
    for (int i = 0; i < parser->numTerminals; i++) {
        if (parser->terminals[i] == terminal) {
            return i;
        }
    }
    return -1;
}

void createParsingTable(Parser *parser, Production productions[], int numProductions) {
    for (int i = 0; i < numProductions; i++) {
        char nonTerminal = productions[i].nonTerminal;
        char firstSymbol = productions[i].production[0];
        int pos = findTerminal(parser, firstSymbol);
        if (pos != -1) {
            addProduction(parser, nonTerminal, productions[i].production, pos);
        }
    }
}

void printParsingTable(Parser *parser) {
    printf("Parsing Table:\n  ");
    for (int i = 0; i < parser->numTerminals; i++) {
        printf("  %c", parser->terminals[i]);
    }
    printf("\n");
    for (int i = 0; i < parser->numNonTerminals; i++) {
        printf("%c ", parser->nonTerminals[i]);
        for (int j = 0; j < parser->numTerminals; j++) {
            printf(" %s", parser->parsingTable[parser->nonTerminals[i] - 'A'][j]);
        }
        printf("\n");
    }
}

int main() {
    Parser parser = {0};

    addTerminal(&parser, 'a');
    addTerminal(&parser, 'b');
    addTerminal(&parser, '$');

    addNonTerminal(&parser, 'S');
    addNonTerminal(&parser, 'A');

    Production productions[MAX_PRODUCTIONS] = {
        {'S', "aA"},
        {'A', "b"}
    };

    createParsingTable(&parser, productions, 2);

    printParsingTable(&parser);

    return 0;
}
