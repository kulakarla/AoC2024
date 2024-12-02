#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    //FILE* file = fopen("inputs/test_input.txt", "r");
    FILE* file = fopen("inputs/2_dec_input.txt", "r");
    char line[128];
    char* split;
    int count = 0;
    int totalcount = 0;
    if(file != NULL){
        while(fgets(line, sizeof(line), file)){

            int prev, current;
            int direction = 0;
            totalcount++;
            split = strtok(line, " ");
            if(split != NULL) {
                prev = atoi(split);
            }
            int j = 0;
            while((split = strtok(NULL, " ")) != NULL) {
                current = atoi(split);
                if (j == 0){
                    direction = current - prev;
                }

                int difference = abs(prev-current);
                if (
                    !((direction > 0 && current - prev > 0 || 
                    direction < 0 && current - prev < 0)
                    && (difference < 4 && difference > 0))
                    )
                {
                    totalcount--;
                    break;
                };
                j++;
                prev = current;
            }
        };
    };

    fclose(file);

    printf("The total count is: %d\n", totalcount);
    //printf("The similarity score is: %d", similarity);

    return 0;
}
