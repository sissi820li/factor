#include <iostream>
#include <iomanip>

using namespace std;

// -------------- FUNCTIONS USED FOR THE ASSIGNMENT -----------------------
//function that factors the user number, and also determines prime number and perfect sqaure 
int factoring (int start_range, int end_range)
{ 
    int x = start_range;
    int remainder = 0; 
    int factor_counter = 0; 
    
    // While loop tests all the numbers up to user end range 
    while (x != end_range + 1) {

        // Prints the number thats being factored 
        cout << '\n'<< setw(3) << x; 

        // Starts factoring number 
        for (int y = 1; y <= x; ++y){
            remainder = x % y;

            // if the remainder is 0, it means that it is a factor 
            if (remainder ==  0)
                cout << setw(4) << y;
            if (remainder == 0 )
                // takes note of how many factors there are everytime it loops
                factor_counter = factor_counter + 1;
        }

        // prints how many factors there are or if it is a prime number
        cout << setw(3) << "(" << factor_counter << ")";
        if (factor_counter == 2)
            cout << " **prime**";
        else if (factor_counter % 2 != 0)
            cout << " **perfect square**";
            
        factor_counter = 0;
        x = x + 1;
    }
    return 0; 
}

//function that finds sum of digits from user number 
int adding_digits(int user_number)
{
    int remainder; 
    int sum_of_digits = 0; 

    while (user_number != 0)
    {
    //finds what last digit is 
    remainder = user_number % 10; 
    //add digits to sum 
    sum_of_digits = sum_of_digits + remainder;
    user_number = (user_number - remainder)/10; 
    }
    
    return sum_of_digits;   
}

//function that finds product of digits from user number 
int multiplying_digits(int user_number)
{
    int remainder; 
    int product_of_digits = 1; 

    while (user_number != 0)
    {
    //finds what last digit is
    remainder = user_number % 10; 
    //multiply digits with product
    product_of_digits = product_of_digits * remainder;
    user_number = (user_number - remainder)/10; 
    }
    
    return product_of_digits; 
}

//  -------------- ASSIGNMENT AND USING THE ABOVE FUNCTIONS -----------------------
int main()
{   
    //declares variables
    int user_range = 0;
    int second_user_range = 0;
    int start_range = 0; 
    int end_range = 0; 

    cout << fixed;

    //asks user for first range between 1 and 999, if out of range asks for new number 
    while (user_range < 1 || user_range > 999){
        cout << "Enter a number between 1 and 999: " ; 
        cin >> user_range;
    }
    
    //asks user for second range between 1 and 999, if out of range asks for new number 
    while (second_user_range < 1 || second_user_range > 999){
        cout << "\nEnter a second number between 1 and 999: " ; 
        cin >> second_user_range;
        if (second_user_range == user_range)
        {
           second_user_range = 0; 
        }
    }
    
    //compares both numbers from user makes the smaller number the start range
    if (user_range < second_user_range){
        start_range = user_range;
        end_range = second_user_range; 
    }
    else{
        start_range = second_user_range;
        end_range = user_range; 
    }
 
    // runs factoring function and finds all factors, determines if perfect square or prime number by using 'factoring' function
    int a; 
    a = factoring (start_range, end_range);

    //finds the sum of the digits of first user number by using 'adding_digits' function
    int sum_of_digit1; 
    sum_of_digit1 = adding_digits(start_range);
    cout <<"\n\n" << setw(3) << start_range << ": sum of digits = "<< sum_of_digit1;

    //finds the products of the digits of first user number by using 'multiplying_digits' function
    int product_of_digit1; 
    product_of_digit1 = multiplying_digits(start_range); 

    //determines if first user number is interesting or not 
    if (sum_of_digit1 + product_of_digit1 == start_range){ 
        cout << " --interesting--";
    }

    //finds the sum of the digits of second user number by using 'adding_digits' function
    int sum_of_digit2; 
    sum_of_digit2 = adding_digits(end_range);
    cout <<"\n" << setw(3) << end_range << ": sum of digits = "<< sum_of_digit2;

    //finds the products of the digits of second user number by using 'multiplying_digits' function
    int product_of_digit2; 
    product_of_digit2 = multiplying_digits(end_range);  

    //determines if second user number is interesting or not 
    if (sum_of_digit2 + product_of_digit2 == end_range){
        cout << " --interesting--"; 
    }
    return 0;
}