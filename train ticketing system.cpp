#include <iostream>
#include <string>

using namespace std;

int main()
{
    int destinationcode, totalusers, requestedseats, totalseatsavailable = 40;
    char tickettype, decision;
    double age, ticketcost, price, discount;
    string destination;


    cout << "Welcome to ERL Ticketing System" << endl;
    cout << "Destination options: " << endl;
    cout << "1. Kuala Lumpur          RM2.00" << endl;
    cout << "2. Putrajaya             RM2.80" << endl;
    cout << "3. Cyberjaya             RM2.50" << endl;

    cout << "Please enter your destination code [1,2,3]: ";
    cin >> destinationcode;

    cout << "Do you want to purchase a two-way ticket? [y/n]: ";
    cin >> tickettype;

    switch (destinationcode)
    {
        case 1:
            ticketcost = 2.00;
            destination = "KUALA LUMPUR";
            break;
        case 2:
            ticketcost = 2.80;
            destination ="PUTRAJAYA";
            break;
        case 3:
            ticketcost = 2.50;
            destination ="CYBERJAYA";
            break;
        default:
            ticketcost = 0.00;
            break;
    }

    cout << "Please enter the number of seats you want to book [1-40]: ";
    cin >> requestedseats;

    if (totalseatsavailable < 0 || requestedseats < 0)
    {
        cout << "Invalid input. Please enter positive numbers." << endl;
        return 0;
    }

    if (requestedseats > totalseatsavailable)
    {
        cout << "Sorry, there are not enough seats available." << endl;
    }
    else
    {
        cout << "Enter your age: ";
        cin >> age;

        if (age <= 12)
        {
            discount = 0.35;
        }

        else if (age >= 13 && age <= 49)
        {
            discount = 0.50;
        }

        else
        {
            discount = 0.05;
        }

        if (tickettype == 'y' || tickettype == 'Y')
        {
            price = (2 * ticketcost) - (2 * ticketcost * discount);
        }

        else
        {
            price = ticketcost - (ticketcost * discount);
        }

        totalseatsavailable -= requestedseats;

        cout << "----------------------------------------------------" << endl;
        cout << "             Express Rail Link                      " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "        This is a ticket to "<< destination <<endl;
        cout << "               Price: RM " << price << endl;
        cout << "                 Thank you!                         " << endl;
    }

    cout << "Do you want to continue using the system? [y/n]: ";
    cin >> decision;

    if (decision == 'y' || decision == 'Y')
    {
        main();
    }
    else
    {
        cout << "Total user is: " << ++totalusers << endl;
        cout << "Total sales of the day : RM " << price << endl;

    }
    return 0;
}



