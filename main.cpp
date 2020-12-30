#include <iostream>
#include <limits>

using namespace std;

void run_program(){
    cout << "Hello world!" << endl << endl;
}

bool close(){
    char close;

    cout << "Napewno chcesz zamknac program? (y/n):";
    while(!(cin >> close) || (close != 89 && close != 121 && close != 78 && close != 110)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if(close == 89 || close == 121){
        return true;
    }
    else{
        return false;
    }
}

void author(){
    cout << "Quiz z plikow tekstowych." << endl;
}

int main() {

    author();

    int nav;
    bool loop = true;
    while (loop){
        cout << "*********************************************" << endl;
        cout << "* [1] - Wykonaj program." << endl;
        cout << "* [2] - Zamknij program." << endl;
        cout << "*********************************************" << endl << endl;

        cout << "Wybierz opcje:";

        while(!(cin >> nav) || (nav != 1 && nav != 2)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(nav){
            case 1:
                run_program();
                break;
            case 2:
                if(close()){
                    loop = false;
                }
                break;
            default:
                cout << "Podaj opcje z menu" << endl;
                break;
        }
    }
 cout << "test";
    return 0;
}