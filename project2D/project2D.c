#include <stdio.h>
#include <stdlib.h>
#define UNUSED __attribute__((unused))

typedef enum{
   ADD,
   MULT,
   SUBTRACT,
   DIV,
   UNSUPPORTED
} MathOperation;

void IssueBadNumberError(){
    printf("The string does not represent a floating point number.\n");
    exit(EXIT_FAILURE);
}

void IssueBadOperationError(){
    printf("The string does not represent a valid operation.\n");
    exit(EXIT_FAILURE);
}

int myStringLength(char *op){
    int length = 0;
    while (*op != '\0'){
        length++;
        op++;
    }
    return length;
}

MathOperation GetOperation(char *op){
    int op_count = 0;
    int length = myStringLength(op);

    for (int i = 0; i < length; i++)
        op_count++;
    if (op_count > 1){
        IssueBadOperationError();
    }
    if (*op == '+'){
        return ADD;
    } else if (*op == 'x'){
        return MULT;
    } else if (*op == '-'){
        return SUBTRACT;
    } else if (*op == '/'){
        return DIV;
    } else {
        return UNSUPPORTED;
    }
}

double CalculateFrac(char *str){
    double decimalPlace = 0.1;
    double fraction = 0;
    
    while (*str != '\0'){
        if (*str < '0' || *str > '9'){
                IssueBadNumberError();
        }
        fraction = fraction + (double) ((*str - '0') * decimalPlace);
        decimalPlace *= 0.1;
        str++;
    }
    return fraction;
}

double StringToDouble(char *str){
    int neg = 0;
    int isFrac = 0;
    double result = 0.0;
    
    if (*str == '-'){
        neg = 1;
        str++;
    }

    while (*str != '\0'){
        if (*str == '.'){
            isFrac = 1;
            str++;
        }
        if (isFrac){
            if (*str < '0' || *str > '9'){
                IssueBadNumberError();
            }
            result = result + CalculateFrac(str);
            str++;
            break;
        }
        else{
            if (*str < '0' || *str > '9'){
                IssueBadNumberError();
            }
            result = (result * 10) + ((double) (*str - '0'));
            str++;
        }
    }

    if (neg == 1){
        result = (0 - result);
    }
    return result;
}

int main(UNUSED int argc, char *argv[]){
    double v = StringToDouble(argv[1]);
    MathOperation op = GetOperation(argv[2]);
    double v2 = StringToDouble(argv[3]);
    double result = 0.0;
    switch (op)
    {
       case ADD:
         result = v+v2;
         break;
       case MULT:
         result = v*v2;
         break;
       case SUBTRACT:
         result = v-v2;
         break;
       case DIV:
         result = v/v2;
         break;
       case UNSUPPORTED:
         IssueBadOperationError();
         break;
    }
    printf("%d\n", (int) result);
 
    return 0;
}


