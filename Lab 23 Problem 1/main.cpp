#include <iostream>
#include <string>

using namespace std;

string conversionTime(string time){
    try{
        int hour = stoi(time.substr(0,2));
        int minute = stoi(time.substr(3,2));
        if(hour >= 24){
            throw invalid_argument("Hour must be less than 24");
        }
        if(minute >= 60){
            throw invalid_argument("Minute must be less than 60");
        }

        string AMPM = hour < 12 ? "AM" : "PM";
        hour = hour % 12;
        if(hour == 0){
            hour = 12;
        }

        return to_string(hour) + ":" + to_string(minute) + " " + AMPM;
    }
    catch(invalid_argument& e){
        cout<<"Error: "<<e.what()<<endl;
        return "";
    }
}

int main(){
string time;
bool select = true;
while(select) {
    cout << "Enter time in 24-hour notation: ";
    cin >> time;
    string finalTime = conversionTime(time);
    if (!finalTime.empty()) {
        cout << finalTime;
    }

    cout<<endl;

    char rerun;
    cout<<"Again (y/n) ? ";
    cin >> rerun;
    rerun = (rerun == 'Y'||rerun == 'y');
}
return 0;
}
