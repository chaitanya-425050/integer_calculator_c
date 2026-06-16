/*
 * Integer Calculator
 * Language: C
 *
 * Features:
 * - Integer arithmetic
 * - Input validation
 * - Division by zero protection
 */


#include <stdio.h>

int get_integer(char *request, int num) //Asking the user to enter a valid integer
{
    while(1)
    {
        printf("%s", request);
        if(scanf("%d", &num) == 1)
        {
            while(getchar() != '\n');  
            return num;
        } printf("\nInvalid input please try again\n");
        while(getchar() != '\n');
    }
}

char get_operator() // Asking the user to enter a valid operator
{
    char op;
    while(1)
    {
       // while(getchar() != '\n');
        printf("Enter Operator(+, -, *, /, %%) / (Q/q) to Exit : ");
        if(scanf(" %c", &op) == 1)
        {

    
            if(op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == 'Q' || op == 'q')
            {
                while(getchar() != '\n');
                return op;
            } printf("Invalid Operator, please try again.\n");  
            while(getchar() != '\n');
        }
    }
}

int choice() // Asking the user to continue or Quit
{
    char choice;
    while(1)
    {
      //  while(getchar() != '\n');
        printf("\nEnter Q/q to Exit and C/c to Continue : ");
        if(scanf(" %c", &choice) == 1)
        {
            switch(choice)
            {
                case 'c' :
                case 'C' : 
                  //  while(getchar() != '\n');
                    return 1;
                case 'q' :
                case 'Q' : 
                  //  while(getchar() != '\n');
                    return 0;
                default : 
                    printf("Invalid choice, Please retry.\n");
                    while(getchar() != '\n');
                    break;
            }
        }
    }
}

void calculate(int a, int b, char op)  //Calculating and printing the result
{
    int result;
    switch(op)
    {
        case '+' : 
            result = a + b;
            printf("\n%d + %d = %d\n", a, b, result);
            break;
        case '-' : 
            result = a - b;
            printf("\n%d - %d = %d\n", a, b, result);
            break;
        case '*' :
            result = a * b;
            printf("\n%d * %d = %d\n", a, b, result);
            break;
        case '/' :
            if(b == 0)
            {
                printf("ERROR : Division with 0 is not possible.");
                break;
            } result = a / b;
            printf("\n%d / %d = %d (Quotient). \nRemainder = %d\n", a, b, result, a%b);
            break;
        case '%' : 
            if(b == 0)
            {
                printf("ERROR : Division with 0 is not possible.");
                break;
            } result = a % b;
            printf("\n%d %% %d = %d (Remainder). \nQuotient = %d\n", a, b, result, a/b);
            break;
        default :
            printf("ERROR : Invalid operator.");
            break;
    }
}


int main()
{
    while(1)
    {
        int a, b, flag;
        char operator;

        a = get_integer("Enter 1st integer a : ", a);
        b = get_integer("Enter 2nd integer b : ", b);

        operator = get_operator();

        if(operator == 'Q' || operator == 'q')
        {
            printf("Option Q/q entered, exiting the program....\n");
            return 0;
        }

        calculate(a, b, operator);
        flag = choice();
        if(flag == 1)
        {
            while(getchar() != '\n');
            continue;
        }  else if(flag == 0)
        {
            printf("Exiting the program.....\n");
            return 0;
        }
    }
}