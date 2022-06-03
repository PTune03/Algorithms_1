#include <stdio.h>
#include "IntVector.h"
#include "DoubleVector.h"
#include "ComplexVector.h"
#include "test.h"

//char errors[][30] = {"Wrong input. Try again.", "Overflow. Reset Program", "Different types. Reset program"};
struct Errors{
    char *wrong_input;
    char *overflow;
    char *dif_type;


};

int get_selected_point(int point)
{
    int variant = 0;
    char s[10];
    scanf("%s", s);
    while (sscanf(s, "%d", &variant) < 1 || variant > point)
    {
        printf("Incorrect input. Don't try to break my program!\n");
        printf("Try again: ");
        scanf("%s", s);
    }

    return variant;
}

void Main_Page()
{
    printf("What do you want to do:\n 1. Add two vectors\n 2. Subtract two vectors\n");
    printf(" 3. Get a scalar product\n 4. Multiply vector by scalar\n 5. Get Vector product\n 6. Exit\n");
    printf("Your choice: ");
}

void TypeData_Page()
{
    printf("Which type of data do you want to use:\n");
    printf(" 1. Int\n 2. Double\n 3. Complex\n");
    printf("Your choice: ");
}

int  ContinueVector_Page()
{
    int choice = 0;
    printf("Do you want to continue with this vector?\n");
    printf("1. Yes\n 2. No\n");
    printf("Your choice: ");
    choice = get_selected_point(2);
    return choice;

}

int ContinueType_Page()
{
    int choice;
    printf("Do you want to continue with this type of data?\n");
    printf("1. Yes\n 2. No\n");
    printf("Your choice: ");
    choice = get_selected_point(2);
    return choice;
}

int Test_Page()
{
    int choice;
    printf("Which type of data do you want to test:\n 1. Int\n 2. Double\n 3. Complex\n Your choice:");
    choice = get_selected_point(3);
    return choice;
}


void Menu()
{
    struct Errors errors = {"Wrong input. Try again.",
            "Overflow. Reset Program",
            "Different types. Reset program"};
    int user_choice = 0;
    int type_choice = 0;
    int continue_type = 1;
    int exit = 1;
    printf("If you want to run tests, print 1\n");
    int test, test_t;
    scanf("%d", &test);
    if (test == 1)
    {
        test_t = Test_Page();
        if (test_t == 1)
            test_int();

        if (test_t == 2)
            test_double();

        if (test_t == 3)
            test_complex();
    }
    while (exit == 1)
    {
        TypeData_Page();
        type_choice = get_selected_point(3);

        while (continue_type == 1)
        {

            if (type_choice == 1)
            {
                printf("Input Vector: ");
                Vector *vector = Make_Int_Vector();
                printf("\nYour Vector: ");
                print_vector(vector);

                int continue_vector = 1;
                while (continue_vector == 1)
                {
                    Main_Page();
                    user_choice = get_selected_point(6);
                    if (user_choice == 1)
                    {
                        printf("Input second vector: ");
                        Vector *vector2 = Make_Int_Vector();
                        Vector *result = Sum(vector, vector2);
                        print_vector(result);
                        vector = result;

                    }
                    if (user_choice == 2)
                    {
                        printf("Input second Vector: ");
                        Vector *vector2 = Make_Int_Vector();
                        Vector *result = Subtract(vector, vector2);
                        if (result == NULL)
                        {
                            printf("%s\n", errors.dif_type);
                            scanf("%*C");
                        }
                        else {
                            print_vector(result);
                            vector = result;
                        }
                    }
                    if (user_choice == 3)
                    {
                        printf("Input second Vector: ");
                        Vector *vector2 = Make_Int_Vector();
                        void *result = Multiply_vectors(vector, vector2);
                        vector->ringInfo->print(result);
                    }
                    if (user_choice == 4)
                    {
                        printf("Input scalar: ");
                        void *scalar = malloc(vector->ringInfo->size);
                        scalar = vector->ringInfo->input();
                        if (scalar == (void *) -1) {
                            printf("%s\n", errors.wrong_input);
                            scanf("%*c");
                        }
                        else{
                            Vector *result = Multiply_on_scalar(vector, scalar);
                            print_vector(result);
                            vector = result;
                            }
//                        Vector *result = Multiply_on_scalar(vector, scalar);
//                        print_vector(result);
//                        vector = result;
                    }
                    if (user_choice == 5)
                    {
                        printf("Input second vector: ");
                        Vector *vector2 = Make_Int_Vector();
                        Vector_Product(vector, vector2);

                    }
                    if (user_choice == 6)
                    {
                        //exit = 1;
                        break;
                    }
                    continue_vector = ContinueVector_Page();
                }
            }

            if (type_choice == 2)
            {
                printf("Input Vector: ");
                Vector *vector = Make_Double_Vector();
                printf("\nYour Vector: ");
                print_vector(vector);

                int continue_vector = 1;
                while (continue_vector == 1)
                {
                    Main_Page();
                    user_choice = get_selected_point(6);

                    if (user_choice == 1)
                    {
                        printf("Input second Vector: ");
                        Vector *vector2 = Make_Double_Vector();
                        Vector *result = Sum(vector, vector2);
                        vector = result;
                        print_vector(result);
                    }

                    if (user_choice == 2)
                    {
                        printf("Input second Vector: ");
                        Vector *vector2 = Make_Double_Vector();
                        Vector *result = Subtract(vector, vector2);
                        if (result == NULL)
                        {
                            printf("%s\n", errors.dif_type);
                            scanf("%*C");
                        }
                        else {
                            print_vector(result);
                            vector = result;
                        }
                    }

                    if (user_choice == 3)
                    {
                        printf("Input second Vector: ");
                        Vector *vector2 = Make_Double_Vector();
                        void *result = Multiply_vectors(vector, vector2);
                        vector->ringInfo->print(result);
                    }

                    if (user_choice == 4)
                    {
                        printf("Input scalar: ");
                        void *scalar = malloc(vector->ringInfo->size);
                        scalar = vector->ringInfo->input();
                        if (scalar == (void *) -1) {
                            printf("%s\n", errors.wrong_input);
                            scanf("%*c");
                        }
                        else {
                            Vector *result = Multiply_on_scalar(vector, scalar);
                            print_vector(result);
                            vector = result;
                        }
                    }

                    if (user_choice == 5)
                    {
                        printf("Input second vector: ");
                        Vector *vector2 = Make_Double_Vector();
                        Vector_Product(vector, vector2);
                    }

                    if (user_choice == 6)
                    {
                        //exit = 1;
                        break;
                    }
                    continue_vector = ContinueVector_Page();
                }
            }

            if (type_choice == 3)
            {
                printf("Input Vector: ");
                Vector *vector = Make_Complex_Vector();
                printf("\nYour Vector: ");
                print_vector(vector);

                int continue_vector = 1;
                while (continue_vector == 1)
                {
                    Main_Page();
                    user_choice = get_selected_point(6);

                    if (user_choice == 1)
                    {
                        printf("Input second Vector: ");
                        Vector *vector2 = Make_Complex_Vector();
                        Vector *result = Sum(vector, vector2);
                        print_vector(result);
                        vector = result;
                    }

                    if (user_choice == 2)
                    {
                        printf("Input second Vector: ");
                        Vector *vector2 = Make_Complex_Vector();
                        Vector *result = Subtract(vector, vector2);
                        if (result == NULL)
                        {
                            printf("%s\n", errors.dif_type);
                            scanf("%*c");
                        }
                        else {
                            print_vector(result);
                            vector = result;
                        }
                    }

                    if (user_choice == 3)
                    {
                        printf("Input 2nd vector: ");
                        Vector *vector2 = Make_Complex_Vector();
                        void *result = Multiply_vectors(vector, vector2);
                        vector->ringInfo->print(result);
                    }

                    if (user_choice == 4)
                    {
                        printf("Input scalar: ");
                        void *scalar = malloc(vector->ringInfo->size);
                        scalar = vector->ringInfo->input();
                        if (scalar == (void *) -1) {
                            printf("%s\n", errors.wrong_input);
                            scanf("%*c");
                        }
                        else {
                            Vector *result = Multiply_on_scalar(vector, scalar);
                            print_vector(result);
                            vector = result;
                        }
                    }

                    if (user_choice == 5)
                    {
                        printf("Input second vector: ");
                        Vector *vector2 = Make_Complex_Vector();
                        Vector_Product(vector, vector2);
                    }
                    if (user_choice == 6)
                    {
                        break;
                    }
                    continue_vector = ContinueVector_Page();
                }
            }
            continue_type = ContinueType_Page();
        }
        printf("Do you want to exit?\n 1. No\n 2.Yes\n Your choice: ");
        exit = get_selected_point(2);
    }
//    Main_Page();
//    scanf("%d", &user_choice);
//    printf("%d", user_choice);
}