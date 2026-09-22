#include <iostream>
#include <cmath>
#include <vector>
#include <array> 

//basic syntax
/*int main() {
    int num_qupit{};
    std::cin >> num_qupit;

    long long num_states = 1LL << num_qupit;
    std::cout << "States:"<< num_states << '\n';

  return 0;
}*/

// if else and for loop
    /*double real{};
    double imag{};
    double norm_outcome{};

    std::cout << "Enter real values:";
    std::cin >> real ;
    std::cout << "Enter imaginary values:";
    std::cin >> imag;

    norm_outcome = norm(real , imag);

    std::cout << "Norm : " << norm_outcome << '\n';

    if (norm_outcome == 0.0){
        std::cout << "zero vector";
    }
    else if (norm_outcome>1.0){
        std::cout << "Magnitude is greater than 1";
    }
    else {
        std::cout <<"Magnitude is between 0 and 1";
    }*/

 /*   int count{};
    std::cin >> count;

    for (int i = 0; i < count; ++i){
        double real{};
        double imag {};

        std::cin >> real >> imag;

        double result = norm(real,  imag);
        std::cout << "Norm : "<< result << '\n';
        
    }*/
   /* std::vector<double> values{};

    values.push_back(1.5);
    values.push_back(2.5);
    values.push_back(3.5);
    values.push_back(5.5);

    double total{};

    for (double value : values){
        total += value;
    }

    std::cout << "Total : " << total << '\n';
    std::cout << "Count : " << values.size() << '\n';*/

    //test for loop vector

    /*std::vector<double> values{};
    
    int count {};

    std::cin >> count;

    for ( int i =0; i < count; i++){
        double value{};
        std::cin >> value;
        values.push_back(value);

    }

    if (values.empty()) {
        std::cout <<"End program"<<'\n';
    }
    double total{};
    double max = values[0];
    double min = values[0];
    for ( double value : values){
        total += value;
        if (value > max){
            max = value;
        }

        if(value < min){
            min = value;
        }
    }

    double  average = total / values.size();

    std::cout <<"Total : " <<total<<'\n';
    std::cout << "Average : " << average << '\n';
    std::cout << "Maximum : " << max << '\n';
    std::cout << "Minimum : "  << min <<'\n';*/

    /*std::vector <double>values{};

    int count{};
    std::cin >> count;

    for (int i =0; i<count; i++){
        double error{};
        std::cin >> error;
        values.push_back(error);
    }

    if (values.empty()){
        std::cout << "End program" << '\n';
        return 0;
    }

    const double threshold {0.01};

    double total{};
    double max = values[0];
    int number_below_threshold {};

    for (double value : values){
        total += value;
        if (value > max){
            max = value;

        }
        if (value < threshold){
            number_below_threshold +=1;
        }
    }

    double average = total / values.size();

    std:: cout << "Average : " << average << '\n';
    std::cout << "Error max : " << max << '\n';
    std::cout << "Count of number less than 0.01 : " << number_below_threshold << '\n';

    if ( average > threshold){
        std:: cout << "Not Converged" << '\n';
    }
    else {
        std:: cout << "Converged" << '\n';
    }*/
double norm(double real, double imag){
    return std::sqrt( real * real + imag * imag);
}

int main(){
    
    //std:: array and fixed size data

    int x {};
    std::cin >> x;
   
    std::vector<double> amplitudes{};

    for( int i= 0; i< x; i++){
        double amplitude{};
        std::cin >> amplitude;
        amplitudes.push_back(amplitude);
    }

    const double tolerance{1e-9};
    double squared_sum{};

    std::array angle_amplitude {0.5,0.25,0.1,0.01};

    for(double amplitude : amplitudes){
        squared_sum += amplitude * amplitude;
    }
    double state_norm = std::sqrt(squared_sum);

    std::cout << "Norm : "<< state_norm << '\n';

    if(std::abs(state_norm-1.0)<tolerance){
        std::cout << "State is normalize\n";
    } else {
        std::cout << "State is not normalize\n";
    }

    for (double amplitude : amplitudes){
            
        std::cout << "Amplitude : " << amplitude << '\n';

        if (amplitude >= angle_amplitude[0]){
                std::cout <<  "0.5 or above\n";
            }
        else if (amplitude >= angle_amplitude[1]) {
                std::cout << "[0.25, 0.5)\n";
            }
        else if (amplitude >= angle_amplitude[2]) {
                std::cout << "[0.1, 0.25)\n";
            }
        else if (amplitude >= angle_amplitude[3]) {
                std::cout << "[0.01, 0.1)\n";
            }
        else {
                std::cout << "Below than 0.001\n";
            }
        }

    return 0;
}