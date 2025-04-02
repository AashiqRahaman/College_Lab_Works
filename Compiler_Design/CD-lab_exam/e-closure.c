#include <stdio.h>
#include <stdlib.h>
#define MAX_STATES 100

// Structure to represent a transition
typedef struct {
    int from;
    char symbol;
    int to;
} Transition;

// Function to find epsilon closure
void epsilonClosure(int state, Transition transitions[], int numTransitions, int closure[], int *closureSize) {
    int stack[MAX_STATES], top = -1;
    int visited[MAX_STATES] = {0};
    
    // Initialize the closure with the state itself
    closure[(*closureSize)++] = state;
    stack[++top] = state;
    visited[state] = 1;
    
    while (top >= 0) {
        int currentState = stack[top--];
        
        // Iterate through transitions
        for (int i = 0; i < numTransitions; i++) {
            if (transitions[i].from == currentState && transitions[i].symbol == 'e') { // epsilon transition
                int nextState = transitions[i].to;
                if (!visited[nextState]) {
                    closure[(*closureSize)++] = nextState;

                    stack[++top] = nextState;
                    visited[nextState] = 1;
                }
            }
        }
    }
}

int main() {
    int numTransitions, state;
    Transition transitions[MAX_STATES];
    
    // Input number of transitions
    printf("Enter the number of transitions: ");
    scanf("%d", &numTransitions);
    
    // Input transitions
    printf("Enter transitions (from symbol to):\n");
    for (int i = 0; i < numTransitions; i++) {
        scanf("%d %c %d", &transitions[i].from, &transitions[i].symbol, &transitions[i].to);
    }
    
    // Input the state whose epsilon closure needs to be found
    printf("Enter the state: ");
    scanf("%d", &state);
    
    int closure[MAX_STATES];
    int closureSize = 0;
    
    // Compute epsilon closure
    epsilonClosure(state, transitions, numTransitions, closure, &closureSize);
    
    // Output the epsilon closure
    printf("Epsilon Closure of state %d: ", state);
    for (int i = 0; i < closureSize; i++) {
        printf("%d ", closure[i]);
    }
    printf("\n");
    
    return 0;
}