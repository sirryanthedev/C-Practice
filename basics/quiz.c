#include <stdio.h>
#include <ctype.h>

int main(){

    char questions[][100] = {
    "1. What is the longest that an elephant has ever lived? (That we know of)\n",
    "2. How many rings are on the Olympic flag?\n",
    "3. What is a tarsier?\n",
    "4. In darts, what's the most points you can score with a single throw?\n"
    };
    
    char options[][100] = {
    "A. 49 years\nB. 17 years\nC. 86 years\nD. 142 years\n", 
    "A. 4\nB. 5\nC. 7\nD. None\n",
    "A. A lizzard\nB. A bird\nC. A dog\nD. A primate\n",
    "A. 50\nB. 20\nC. 60\nD. 100\n"
    };
    
    char answers[] = {'C', 'B', 'D', 'A'};

    int question_count = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    char guess = '\0';

    printf("*** QUIZ ***\n\n");

    for(int i = 0; i < question_count; i++){
    printf("%s\n", questions[i]);
    printf("%s\n", options[i]);
    printf("Enter: ");
    scanf(" %c", &guess);

    guess = toupper(guess);

    if(guess == answers[i]){
        score += 1;
        printf("That's correct!\n\n");
    }
    else{
        printf("That's wrong!\n\n");
    }
    }
    printf("You got %d out of %d questions correct", score, question_count);

    return 0;
}