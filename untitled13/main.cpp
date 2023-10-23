#include "iostream"
#include "cstdlib"
#include "ctime"

using namespace std;

int pickNumber(int size)
{
    srand(time(NULL));
    int n =rand() % size;
    return n;
}

int main()
{
    string guessWords[] =
            {
            "algorithm",
            "university",
            "programming",
            "windows",
            "computer",
            "pasadena",
            "science"
            };

    int size = (sizeof(guessWords) / sizeof(guessWords[0]));
    int n = pickNumber(size);
    int wordLength = guessWords[n].length();
   int guessCount = 0;
   int miss = 0;
   char guess = '\0';
   string sol = guessWords[n];
   string myWord(wordLength, '-');
   bool solve = false;
   bool find = false;

    do{
       if(miss == wordLength)
       {
           solve = false;
           break;
       }
       else if(myWord == sol)
       {
           solve = true;
           break;
       }
       cout << "Guess a word : " << myWord << endl;
       cout << "The number of correct guesses : " << guessCount << endl;
       cin >> guess;
       cout << "Letter entered : " << guess << endl;

       find = false;
       for(int i = 0; i < wordLength; i++)
       {
           if(guess == sol[i])
           {
               myWord[i] = guess;
               find = true;
           }
       }

       if(find)
       {
           cout << "Correct guess :)" << endl;
           guessCount++;
       }
       else
       {
           cout << "Sorry, wrong guess :(" << endl;
           miss++;
       }

   }while (!solve);

    if(solve == true)
    {
        cout << "YOU WIN!!";
    }
    else
    {
        cout << "sad loser :(";
    }

    return 0;
}

