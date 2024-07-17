#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char id[5];    
    int deadline; 
    int profit; 
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return (jobB->profit - jobA->profit);
}

int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }    }
    return max;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);
    int maxDeadline = findMaxDeadline(jobs, n);
    char result[maxDeadline][5];
    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }
    int totalProfit = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i;  
                totalProfit += jobs[i].profit; 
                break;
            }        }
    }

    printf("The sequence of jobs is:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("%s ", jobs[slot[i]].id);
        }
    }
    printf("\n");

    printf("Total profit: %d\n", totalProfit);
}

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter job ID, deadline, and profit for job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    jobSequencing(jobs, n);
    return 0;
}