#include <stdio.h>
#include <ctype.h>

void run_quiz() 
{
    char questions[][100] = 
    {
        "1. What is the size of an int data type in C (usually)?",
        "2. Which keyword is used to prevent modification of a variable?",
        "3. Which function is used to read a character from the console?"
    };

    char options[][4][50] = 
    {
        {"A) 1 Byte", "B) 2 Bytes", "C) 4 Bytes", "D) 8 Bytes"},
        {"A) static", "B) constant", "C) const", "D) stable"},
        {"A) printf()", "B) scanf()", "C) getchar()", "D) gets()"}
    };

    char answers[] = {'C', 'C', 'C'};
    int total_questions = sizeof(answers) / sizeof(answers[0]);
    int score = 0;
    char guess;

    printf("--- Welcome to the C Programming Quiz ---\n\n");

    for (int i = 0; i < total_questions; i++) 
    {
        printf("%s\n", questions[i]);
        
        for (int j = 0; j < 4; j++) 
        {
            printf("%s\n", options[i][j]);
        }

        printf("Enter your answer (A, B, C, or D): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        if (guess == answers[i]) 
        {
            printf("Correct!\n\n");
            score++;
        } 
        else 
        {
            printf("Wrong. The correct answer was %c.\n\n", answers[i]);
        }
    }

    printf("--- Quiz Finished ---\n");
    printf("Your final score is: %d/%d\n", score, total_questions);
}

int main() 
{
    run_quiz();
    return 0;
}
