#include<stdio.h>

int main(void) {
  int number_of_scores = 0;
  printf("How many scores do you want to average?\n");
  printf("$: ");

  scanf("%i", &number_of_scores);
  
  int scores[number_of_scores];
  double sum = 0.0;
  for (int i = 0; i < number_of_scores; i++) {
    printf("Score: ");
    scanf("%i", &scores[i]);
    sum += scores[i];
  }
  printf("Average: %f\n", sum / number_of_scores);
  
}
