
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    
    //variable declarations
    int N, X, T;
    int* A;
   
    //constraint checker
    int correct = 0;

    //the sum of N over all tests
    int sum = 0;

    //enter number of tests T
    do {
        correct++;
        if (correct > 1) { cout << "You entered a wrong number." << endl; };
        cout << "Enter number of tests: ";
        cin >> T;
    } while (T < 1 || T >= pow(10, 4));

    //test entry 
    
    for (int i = 0; i < T; i++) {

        //checking if sum exceeded the constraint 5*10^5
        
            correct = 0;

            //enter numbers of N and X
            do {

                correct++;
                if (correct > 1) { cout << "You entered wrong numbers." << endl; };
                cout << "Enter 2 numbers(test" << i+1 << "): ";
                cin >> N >> X;

            } while (N < 1 || N >= pow(10, 5) || X < 0 || X >= pow(10, 9));

            correct = 0;

            A = new int[N];
            //enter array values A[N]

            int sum_count = 0;

            do {             
                correct++;
                bool test_sum = false;
                if (correct > 1) { cout << "Number exceeded the limit!" << endl; };
                cout << "Enter number/s N of A: ";
                for (int arr_ind = 0; arr_ind < N; arr_ind++) {
                    cin >> A[arr_ind];
                    sum += A[arr_ind];
                    sum_count += A[arr_ind];
                }
                if (sum > 5 * pow(10, 5)) {
                    sum -= sum_count;
                    test_sum = true;
                }
                else {
                    sum_count = false;
                }

            } while (sum_count == true);

            int count_equal = 0;
            int count_op = 0;
          
            //loop for picking N
           for (int ind = 0; ind < N; ind++) {

               if (A[ind] < 0) continue;

                int ceq = 1;
                int xor_ceq = 0;

                //checking if A[N] is equal to anything
                for (int eq_ind = ind+1; eq_ind < N; eq_ind++) {
                  
                    if (A[ind] == A[eq_ind]) {
                        ceq++;
                        A[eq_ind] = -1;
                    }
                    else if ((A[ind] ^ X) == A[eq_ind]) {
                        xor_ceq++;
                        A[eq_ind] = -1;
                    }
                                       
                }

                if (count_equal < ceq + xor_ceq) {
                    count_equal = ceq + xor_ceq;
                    if (xor_ceq > ceq) {
                        count_op = ceq;
                    }
                    else {
                        count_op = xor_ceq;
                    }
                }
                else if (count_equal == ceq + xor_ceq) {
                    int count_equal_op;
                    if (xor_ceq > ceq) count_equal_op = ceq;
                    else count_equal_op = xor_ceq;
                    if (count_equal_op < count_op) count_op = count_equal_op;
                }
               
                           
            }

           if (count_equal == 0) count_equal = 1;
           cout << count_equal << " " << count_op << endl;

           delete[] A;       
    }
                          
    return 0;
}

