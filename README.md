# ATM_Simulation
Implementation of the ATM simulation.
You need to implement a simplified simulation of the ATM operation. The ATM can only store paper bills with a face value of 100 to 5000 rubles. At most, only 1000 bills can be stored in an ATM. All of them are written to a separate file. The ATM, as a device, has two main operations — the withdrawal of money by the user and the filling of money with bank collectors.

The ATM is filled if the plus symbol “+”is entered in the console at the start of the program. The number of bills is calculated so that the ATM is fully filled. All bills are randomly selected.

If a minus ( “ - ” ) is entered in the console at the start of the program, the user's withdrawal of money is simulated. The user specifies the amount with an accuracy of 100 rubles. We will assume that each client has an unlimited balance in the system and can theoretically withdraw any amount. In practice, if this amount cannot be withdrawn due to the lack of suitable money in the car, a message is displayed that
