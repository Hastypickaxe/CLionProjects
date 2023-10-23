#include <iostream>

using namespace std;

class MonthError : public invalid_argument{
public:
    MonthError() : invalid_argument("Wrong Month"){}
};

class DayError : public invalid_argument{
public:
    DayError() : invalid_argument("Wrong Day"){}
};

string dateConversion(string date){
    try{
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
        string monthName;

        if(month < 1||month > 12){
            throw MonthError();
        }
        else if((month == 4||month == 6||month == 9||month == 11)&&(day < 1 || day > 30)){
            throw DayError();
        }
        else if(month == 2 && (day < 1||day > 28)){
            throw DayError();
        }
        else if((day < 1||day > 31)){
            throw DayError();
        }

        switch(month){
            case 1: monthName = "January";
            break;
            case 2: monthName = "Febuary";
            break;
            case 3: monthName = "March";
            break;
            case 4: monthName = "April";
            break;
            case 5: monthName = "May";
            break;
            case 6: monthName = "June";
            break;
            case 7: monthName = "July";
            break;
            case 8: monthName = "August";
            break;
            case 9: monthName = "September";
            break;
            case 10: monthName = "October";
            break;
            case 11: monthName = "November";
            break;
            case 12: monthName = "December";
            break;
        }

        return monthName + " " + to_string(day);
    }
    catch (MonthError& e){
        cout<<"Error: "<<e.what()<<endl;
        return "";
    }
    catch (DayError& e){
        cout<<"Error: "<<e.what()<<endl;
        return "";
    }
}

int main() {
    string date;
    bool select = true;
while(select) {
    cout << "Enter Date : ";
    cin >> date;
    string convertedDate = dateConversion(date);
    if (!convertedDate.empty()) {
        cout << convertedDate << endl;
    }

    cout<<endl;

    char rerun;
    cout<<"Again (y/n) ? ";
    cin >> rerun;
    rerun = (rerun == 'Y' || rerun == 'y');
}
    return 0;
}
