// Implement ε-closure to convert input string into set of states in given transision table there are maximum 3 symbols and ε , and maximum 10 state. write the c code as per compiler design subjectively.


#include <stdio.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 4 // 3 symbols + ε
#define MAX_SET_SIZE 10 // Max states in a closure set

// Structure to hold a set of states
typedef struct {
    int states[MAX_SET_SIZE];
    int size;
} StateSet;

// Function to initialize a set
void initSet(StateSet *set) {
    set->size = 0;
    for (int i = 0; i < MAX_SET_SIZE; i++) {
        set->states[i] = -1;
    }
}

// Function to add a state to a set if not already present
void addState(StateSet *set, int state) {
    if (state < 0 || state >= MAX_STATES) return; // Invalid state check
    for (int i = 0; i < set->size; i++) {
        if (set->states[i] == state) return; // Already present
    }
    if (set->size < MAX_SET_SIZE) {
        set->states[set->size++] = state;
    }
}

// Function to print a set of states
void printSet(StateSet *set) {
    printf("{ ");
    for (int i = 0; i < set->size; i++) {
        printf("%d ", set->states[i]);
    }
    printf("}\n");
}

// Recursive function to compute ε-closure for a single state
void epsilonClosure(int transition[MAX_STATES][MAX_SYMBOLS][MAX_SET_SIZE], 
                    int state, int epsilonCol, StateSet *closure, int visited[MAX_STATES]) {
    if (visited[state]) return; // Avoid cycles
    visited[state] = 1;
    addState(closure, state);

    // Check all ε-transitions from this state
    for (int i = 0; i < MAX_SET_SIZE && transition[state][epsilonCol][i] != -1; i++) {
        int nextState = transition[state][epsilonCol][i];
        epsilonClosure(transition, nextState, epsilonCol, closure, visited);
    }
}

// Function to compute ε-closure for a set of states
void getEpsilonClosure(int transition[MAX_STATES][MAX_SYMBOLS][MAX_SET_SIZE], 
                       StateSet *inputSet, int epsilonCol, StateSet *result) {
    initSet(result);
    int visited[MAX_STATES] = {0};
    for (int i = 0; i < inputSet->size; i++) {
        epsilonClosure(transition, inputSet->states[i], epsilonCol, result, visited);
    }
}

// Function to process a symbol transition and compute next states
void move(int transition[MAX_STATES][MAX_SYMBOLS][MAX_SET_SIZE], 
          StateSet *currentSet, int symbolCol, StateSet *nextSet) {
    initSet(nextSet);
    for (int i = 0; i < currentSet->size; i++) {
        int state = currentSet->states[i];
        for (int j = 0; j < MAX_SET_SIZE && transition[state][symbolCol][j] != -1; j++) {
            addState(nextSet, transition[state][symbolCol][j]);
        }
    }
}

int main() {
    // Example NFA transition table: states 0-4, symbols 'a', 'b', 'c', ε
    // Format: transition[state][symbol][next_states], -1 indicates end of list
    int transition[MAX_STATES][MAX_SYMBOLS][MAX_SET_SIZE] = {
        // State 0: {a: 1}, {ε: 2}
        {{1, -1}, {-1}, {-1}, {2, -1}},
        // State 1: {b: 3}
        {{-1}, {3, -1}, {-1}, {-1}},
        // State 2: {ε: 4}
        {{-1}, {-1}, {-1}, {4, -1}},
        // State 3: {c: 4}
        {{-1}, {-1}, {4, -1}, {-1}},
        // State 4: {}
        {{-1}, {-1}, {-1}, {-1}},
        // Remaining states unused
        {{-1}, {-1}, {-1}, {-1}},
        {{-1}, {-1}, {-1}, {-1}},
        {{-1}, {-1}, {-1}, {-1}},
        {{-1}, {-1}, {-1}, {-1}},
        {{-1}, {-1}, {-1}, {-1}}
    };

    // Symbol mapping: 0=a, 1=b, 2=c, 3=ε
    char symbols[MAX_SYMBOLS] = {'a', 'b', 'c', 'e'}; // 'e' represents ε
    int epsilonCol = 3; // Column for ε transitions

    // Input string to process
    char input[100];
    printf("Enter input string (max 3 symbols: a, b, c): ");
    scanf("%s", input);

    // Initial state set (start at state 0)
    StateSet currentSet;
    initSet(&currentSet);
    addState(&currentSet, 0);

    // Compute initial ε-closure
    StateSet closure;
    getEpsilonClosure(transition, &currentSet, epsilonCol, &closure);
    printf("Initial ε-closure: ");
    printSet(&closure);

    // Process each symbol in the input string
    for (int i = 0; i < strlen(input); i++) {
        char sym = input[i];
        int symbolCol = -1;
        for (int j = 0; j < MAX_SYMBOLS - 1; j++) { // Exclude ε
            if (symbols[j] == sym) {
                symbolCol = j;
                break;
            }
        }
        if (symbolCol == -1) {
            printf("Invalid symbol: %c\n", sym);
            return 1;
        }

        // Move to next states based on symbol
        StateSet nextSet;
        move(transition, &closure, symbolCol, &nextSet);

        // Compute ε-closure of the new set
        getEpsilonClosure(transition, &nextSet, epsilonCol, &closure);
        printf("After '%c', ε-closure: ", sym);
        printSet(&closure);
    }

    printf("Final set of states: ");
    printSet(&closure);

    return 0;
}


}