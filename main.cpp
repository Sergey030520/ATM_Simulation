#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int const max_countBills = 1000;
int  count_allBill = 0, bills[6];
std::string const name_bills[] = {"100", "200", "500", "1000", "2000", "5000"};

void read_dataATM(){
    std::ifstream atm_file("C:\\Users\\Malip\\source\\repos\\Simulation_ATM\\ATM.bin");
    for (int numb = 0; numb < 6; ++numb){
        std::string billName;
        atm_file >> billName >> bills[numb];
        count_allBill += bills[numb];
    }
    atm_file.close();
}
void write_dataATM(){
    std::ofstream atm_file("C:\\Users\\Malip\\source\\repos\\Simulation_ATM\\ATM.bin", std::ios::binary);
    for (int numb = 0; numb < 6; ++numb) atm_file << name_bills[numb] << ": " << bills[numb] << std::endl;
    atm_file.close();
}
void filling_up_ATM(){
    if (count_allBill == 1000) return;
    std::srand(std::time(nullptr));
    for (int ind = 5, save_previous; ind >= 1; --ind) {
        save_previous = bills[ind];
        bills[ind] += (rand() % (max_countBills - count_allBill));
        count_allBill += (bills[ind] - save_previous);
    }
    if (count_allBill != max_countBills) {
        bills[0] += (max_countBills - count_allBill);
        count_allBill = 1000;
    }
    write_dataATM();
}
void withdrawal_money(int money){
    for (int numb_bill = 5, amountBill = bills[numb_bill]; numb_bill >= 0 && money > 0; --numb_bill){
        amountBill =  bills[numb_bill];
        if (bills[numb_bill] == 0 || std::stoi(name_bills[numb_bill]) > money) continue;
        if (std::stoi(name_bills[numb_bill]) * bills[numb_bill] > money)
                                amountBill = (money / std::stoi(name_bills[numb_bill]));
        money -= (std::stoi(name_bills[numb_bill]) * amountBill);
        bills[numb_bill] -= amountBill;
    }
    write_dataATM();
}

int main() {
    read_dataATM();
    char operation;
    std::cout << "Input the operation you want to make (\"- \"withdrawal,\" + \" fill the ATM): " << std::endl;
    std::cin >> operation;
    switch (operation) {
        case '+':
            filling_up_ATM();
            break;
        case '-':
            int money;
            std::cout << "Input the money you want to withdraw: ";
            std::cin >> money;
            withdrawal_money(money);
            break;
        default:
            break;
    }
}