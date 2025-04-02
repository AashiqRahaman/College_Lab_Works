#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STATES 10
#define MAX_SYMBOLS 3

// Transition table representation
typedef struct {
    int transitions[MAX_STATES][MAX_SYMBOLS + 1][MAX_STATES]; // +1 for ε (epsilon)
    int numTransitions[MAX_STATES][MAX_SYMBOLS + 1]; // Number of transitions for each state and symbol
} NFA;

// Stores visited states
typedef struct {
    int states[MAX_STATES];
    int count;
} StateSet;

// Add a state to the set if it's not already present
void addState(StateSet *set, int state) {
    for (int i = 0; i < set->count; i++) {
        if (set->states[i] == state) return;
    }
    set->states[set->count++] = state;
}

// Compute epsilon-closure using DFS
void epsilonClosure(NFA *nfa, int state, StateSet *closure, bool visited[MAX_STATES]) {
    if (visited[state]) return;
    visited[state] = true;
    addState(closure, state);
    
    for (int i = 0; i < nfa->numTransitions[state][MAX_SYMBOLS]; i++) { // MAX_SYMBOLS index represents ε
        epsilonClosure(nfa, nfa->transitions[state][MAX_SYMBOLS][i], closure, visited);
    }
}

// Wrapper function to compute ε-closure of a given state
StateSet getEpsilonClosure(NFA *nfa, int startState) {
    StateSet closure = {{0}, 0};
    bool visited[MAX_STATES] = {false};
    epsilonClosure(nfa, startState, &closure, visited);
    return closure;
}

// Display the state set
void printStateSet(StateSet set) {
    printf("{ ");
    for (int i = 0; i < set.count; i++) {
        printf("q%d ", set.states[i]);
    }
    printf("}\n");
}

int main() {
    NFA nfa = {0}; // Initialize NFA transition table
    int numStates, numTransitions, state, symbol, nextState;
    
    printf("Enter number of states (max %d): ", MAX_STATES);
    scanf("%d", &numStates);
    
    printf("Enter number of transitions: ");
    scanf("%d", &numTransitions);
    
    printf("Enter transitions in format: state symbol nextState (-1 for epsilon)\n");
    for (int i = 0; i < numTransitions; i++) {
        scanf("%d %d %d", &state, &symbol, &nextState);
        if (symbol == -1) symbol = MAX_SYMBOLS; // Map ε to the last index
        nfa.transitions[state][symbol][nfa.numTransitions[state][symbol]++] = nextState;
    }
    
    int startState;
    printf("Enter start state for epsilon-closure: ");
    scanf("%d", &startState);
    
    StateSet closure = getEpsilonClosure(&nfa, startState);
    printf("Epsilon-closure of q%d: ", startState);
    printStateSet(closure);
    
    return 0;
}
