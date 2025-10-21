#include <iostream>
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cmath>


bool is_prime(size_t n){
    size_t sq = std::sqrt(n);
    for(size_t i = 2; i <= sq; i++){
        if(n % i == 0) return false;
    }
    return true;
}


int main(int argc, char** argv){
    if(argc < 3){
        std::cerr << "Usage: <num> <base>\n";
        return 1;
    }
    size_t a = 0;
    size_t p = 0;
    a = atoi(argv[1]);
    p = atoi(argv[2]);

    if(a == 0){
        std::cerr << "Element odwrotny nie istnieje dla a = 0\n";
        return 1;
    }
    if(p == 0){
        std::cerr << "p musi być większe od 0\n";
        return 1;
    }
    if(!is_prime(p)){
        std::cerr << "p musi być liczbą pierwszą\n";
        return 1;
    }

    for(size_t i = 0; i < p; i++){
        if((p * i + 1) % a == 0){
            std::cout << a << "^(-1) = " << (p * i + 1) / a << "\n";
            break;
        }
    }

    return 0;
}
