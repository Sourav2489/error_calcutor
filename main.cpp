#include <iostream>
#include <string>
#include <vector>
#include <cmath>


int main()
{
    using namespace std;

    string command;

    cout << "Welcome to Error Calculator.\n";
    cout << "Enter 'start' to begin. Or type 'stop' to exit:\n";

    while (command != "start" && command != "stop")
    {
        cin >> command;

        if (command != "start" && command != "stop")
        {
            cout << "Invalid command, please try again. "
            << "Or type 'stop' to exit.\n";
        }
    }

    if (command == "stop")
    {
        cout << "Exiting the program.\n";
        return 0;
    }
    string input;
    cout << "starting....\n";
    cout << "Calculator started...\n";
    string answer;
    do
    {
        input = "";
        cout << "Please enter the values of the measurement "
        << "and type 'done' when finished:\n";

        vector<double> numbers;

        while (input != "done" && input != "stop")
        {
            cin >> input;

            if (input == "done" || input == "stop")
                continue;

            bool value = true;
            for(int i = 0; i < input.size(); i++)
            {
                if(!isdigit(input[i]) && input[i] != '.')
                {
                    value = false;
                    cout << "invalid value, enter a valid value\n";
                    break;
                }
            }
            if(value)
            {
                double number = stod(input);
                numbers.push_back(number);
            }
        }   

        if (input == "stop")
        {
            cout << "Exiting the program.\n";
            return 0;
        }
        if (input == "done")
        {
            cout << "Finished entering values.\n";
            cout << "You entered the following values:\n";

            for (int i = 0; i < numbers.size(); i++)
            {
                cout << "Value " << i + 1 << " = " << numbers[i] << "\n";
            }
            string question;
            cout << "Do you want to change any value (yes/no)?\n";
            cin >> question;
            while (question != "yes" && question != "no")
            {
                cout << "Invalid command, please try again.\n";
                cin >> question;
            }
            while (question == "yes")
            {
                cout << "Enter the serial no of the value you want "
                << "to change (1 to " << numbers.size() << "):\n";

                int index;
                string list;
                cin >> list;
                bool tells = true;
                for(int i = 0; i < list.size(); i++)
                {
                    if (!isdigit(list[i]))
                    {
                        tells = false;
                        cout << "invalid value, enter correct value\n";
                        break;
                    }
                }
                if(tells)
                {
                    index = stoi(list);
                }

                if (index >= 1 && index <= numbers.size())
                {
                    string input2;
                    double newvalue;
                    cout << "Enter the new value:\n";
                    cin >> input2;
                    bool value2 = true;
                    for(int i =0; i < input2.size(); i++)
                    {
                        if(!isdigit(input2[i]) && input2[i] != '.')
                        {
                        value2 = false;
                        cout << "invalid command, enter a valid value";
                        break;
                        }
                    }
                    if(value2)
                    {
                        newvalue = stod(input2);
                    

                        numbers[index - 1] = newvalue;
                        cout << "The value is changed from "<< index << " to " << newvalue<< " successfully.\n";
                        cout << "The new values are:\n";
                        for (int i = 0; i < numbers.size(); i++)
                            {
                                cout << "Value " << i + 1 << " = "<< numbers[i] << "\n";
                            }
                        cout << "Do you want to change any value (yes/no)?\n";
                        cin >> question;
                    }
                }
            }
            if (question == "no")
            {
                cout << "The final values are:\n";

                for (int i = 0; i < numbers.size(); i++)
                {
                    cout << "Value " << i + 1 << " = "<< numbers[i] << "\n";
                }
            }
                    cout<<"\n";
        }
        cout << "calcuting...\n" << "\n";
        double sum = 0;
        for (int i = 0; i < numbers.size(); i++)
        {
            sum = sum + numbers[i];
        }
        cout << "The results of the calculation is:\n";
        cout << "Sum of all number : " << sum << "\n";

        double avrage = sum / numbers.size();
        cout << "avrage :" << avrage << "\n";

        double sumabsoluteerror = 0;

        for(int i =0; i < numbers.size();i++)
        {
            double absoluteerror = abs(numbers[i]-avrage);
            sumabsoluteerror = sumabsoluteerror + absoluteerror;
        }
        double maximumabsoluteerror = sumabsoluteerror / numbers.size();
        cout << "maximum absolute error : " << maximumabsoluteerror << "\n";

        double relativeerror = maximumabsoluteerror / avrage ;
        double percentageerror = relativeerror * 100 ;
        cout << "relative error : " << relativeerror << "\n";
        cout << "precentage error : " << percentageerror << "%\n";
        cout << "do you want to start again (yes/no)\n";
        cin >> answer;
        while(answer != "yes" && answer != "no")
        {
            cout << "invalid command, try again.\n";
            cin >> answer ;
        }
    } while ( answer == "yes");
    if(answer == "no")
    {
        cout << "excting the program";
    }
    
 return 0;

}

