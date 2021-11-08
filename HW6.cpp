#include <iostream>
#include <sstream>

using namespace std;


long numericValidation(void)
{
    string userInput = "";

    int numCount = 0;
    long userConvertedNum;

    bool isIntNumber = false;
    bool isFloatNumber = false;
    bool isExit = false;

    do
    {
        cin >> userInput;
        if (userInput[0] == '#')
        {
            isExit = true;
            numCount = 0;
            break;
        }
        else
        {
            for (size_t i = 0; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
                else if (isalnum(userInput[i]))
                {
                    isIntNumber = false;
                    numCount = 0;
                    break;
                }
                if (userInput[i] == '.')
                {
                    isFloatNumber = true;
                    numCount = 0;
                }
            }
        }
        if (userInput[0] == '-')
        {
            numCount++;
            for (size_t i = numCount; i < userInput.size(); i++)
            {
                if (isdigit(userInput[i]))
                {
                    numCount++;
                    isIntNumber = true;
                }
            }
        }
        if (numCount == userInput.size())
        {
            stringstream ssInput(userInput);
            ssInput >> userConvertedNum;
        }
        else
        {
            if (isFloatNumber == true)
                cout << "It's float-point number!\nEnter the integer number: ";
            else if (isIntNumber == false && numCount == 0)
                cout << "It's not a number!\nEnter the number (only digits without letters, symbols): ";
            else if (isExit == true)
                break;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            numCount = 0;
            isIntNumber = false;
            isFloatNumber = false;
        }

    } while (isIntNumber == false && isExit == false);

    if (isExit == true)
        userConvertedNum = 0;

    return userConvertedNum;

}

ostream& endll(ostream& stream)
{
    stream.put(stream.widen('\n'));
    stream.put(stream.widen('\n'));
    stream.flush();
    return stream;
}

int main()
{
    long yourNumber;
    cout << "Enter the integer number ('#' to terminate): ";

    yourNumber = numericValidation();
    while (yourNumber != 0)
    {
        cout << "Your number is " << yourNumber << endl;
        cout << "Enter the next number ('#' to terminate):\n";
        yourNumber = numericValidation();
    }

}
