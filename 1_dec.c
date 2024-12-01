#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {

    //FILE* file = fopen("inputs/test_input.txt", "r");
    FILE* file = fopen("inputs/1_dec_input.txt", "r");
    char line[16];
    int left[1024];
    int right[1024];
    int rightCount[100000] = {0};
    int i = 0;
    if(file != NULL){
        while(fgets(line, sizeof(line), file)){
            const char *standard_white_space = " \f\n\r\t\v";
            left[i] = atoi(strtok(line, standard_white_space));
            right[i] = atoi(strtok(NULL, standard_white_space));
            rightCount[right[i]] += 1;
            i++;
        };
    };

    fclose(file);

    qsort(left, i, sizeof(int), compare);
    qsort(right, i, sizeof(int), compare);

    int sum = 0;
    int similarity = 0;

    for(int j = 0; j < i; j++){
        similarity += left[j] * rightCount[left[j]];
        sum += abs(left[j] - right[j]);
    };

    printf("The total sum is: %d\n", sum);
    printf("The similarity score is: %d", similarity);

    return 0;
}