# include <cmath>
# include <iostream>
# include <vector>
# include <array>

double calculate_norm(const std:: vector<double>&amplitudes){
    double squared_sum{};

    for(double amplitude : amplitudes){
        squared_sum += amplitude * amplitude;
    }

    return std::sqrt(squared_sum);
}

bool is_normalized(
        const std:: vector<double>& amplitudes,
        double tolerance
    ){
        double state_norm = calculate_norm(amplitudes);
        return std:: abs(state_norm-1.0)<tolerance;

    }

bool contains_negative(
    const std::vector <double>& amplitudes
){
    for (double amplitude : amplitudes){
        if (amplitude < 0){
            return true;
        } else {
            return false;
        }
    }
}
    
int main (){

    std:: vector <double> amplitudes{};

    int count{};
    std:: cin >> count;

    if ( count <= 0){
        std:: cout << "Count must be greater than zero\n";
        return 1;
    }

    for (int i = 0; i < count; ++i){
        double amplitude{};
        std::cin >> amplitude;
        amplitudes.push_back(amplitude);
        
    }
    
    if (contains_negative(amplitudes)){
            std::cout <<"Negative amplitude found\n";
        } else {
            std:: cout << "No negative amplitudes\n";
        }

    double state_norm = calculate_norm(amplitudes);
    std::cout << "State Norm : " << state_norm;

    const double tolerance{1e-9};

    if (is_normalized(amplitudes, tolerance)){
        std::cout << "\nState is normalized";
    }else {
        std::cout << "\nState is not normalized\n";
    }

    return 0;
}