#include <math.h>
#include <stdio.h>

typedef struct {
    double one_match;
    double none_match;
} bday_struct;

void calculate_days(bday_struct days[], int upto);
void print_days(bday_struct days[], int upto);

int main(){
    int upto    = 40;
    bday_struct days[upto+1];
    calculate_days(days, upto);
    print_days(days, upto);
    return 0;
}

void calculate_days(bday_struct days[], int upto){
  int ct;
  days[-1].none_match = 1;
  for (ct=2; ct<=upto; ct ++){
      days[ct].one_match = 1 - pow(364/365., ct-1);
      days[ct].none_match = days[ct-1].none_match * (1 - (ct-1)/365.);
    }
}

void print_days(bday_struct days[], int upto){
  int ct;
    printf("People\t Matches me\t Any match\n");
    for (ct=2; ct<=upto; ct ++){
        printf("%i\t %.3f\t\t %.3f\n", ct, days[ct].one_match, 1-days[ct].none_match);
    }
}
