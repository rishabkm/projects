#include <iostream>
#include<random>
using namespace std;
int main(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distr(1,100);
    int random_num = distr(gen);
    cout<<random_num;
    return 0;
}