#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void file_load_error(){
    cout << "ERROR! Nie mozna zaladowac pliku." << endl;
}

void name(){
    cout << "* Quiz z plikow tekstowych. v 1.0" << endl;
}

void author(){
    cout << "*********************************************" << endl;
    name();
    cout << "* MIT License" << endl;
    cout << "* Copyright (c) 2020 Krzysztof Karkowski && Jakub Zasanski" << endl;
    cout << "*********************************************" << endl;
}

void user_results(){
    string nick;

    cout << "Podaj nick: " << endl ;

    while(!(cin >> nick)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    fstream result_list;
    result_list.open("result_list.txt", ios::in);

    if (result_list.good()){
        string fileLine;
        string tab[3];
        int quiz_exist = 0;
        int i;
        while(getline(result_list,fileLine)){


                for( i=0; i < 3; i++ )
                {

                    switch (i) {
                        case 0:
                            tab[i] = fileLine;
                            break;
                        case 1:
                            getline(result_list, fileLine);
                            tab[i] = fileLine;
                            break;
                        case 2:
                            getline(result_list, fileLine);
                            tab[i] = fileLine;
                            getline(result_list, fileLine);
                            break;
                    }

                }

                if(tab[0] == nick) {
                    quiz_exist = 1;
                    cout << endl << "\t" << "Autor:" << tab[0] << endl;
                    cout << "\t" << "Nazwa quizu:" << tab[1] << endl;
                    cout << "\t" << "Wynik:" << tab[2] << endl;
                }

        }
        if(quiz_exist == 0){
            cout << endl << "\t" << "Brak takiego nicku lub nie ma zapisanego wyniku!" <<  endl;
        }
    }
    else{
        file_load_error();
    }
    result_list.close();
}

void quiz_results(){
    string quiz_name;

    cout << "Podaj nazwe quizu: " << endl ;

    while(!(cin >> quiz_name)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    fstream result_list;
    result_list.open("result_list.txt", ios::in);
    if (result_list.good()){
        string fileLine;
        string tab[3];
        int quiz_exist = 0;
        int i;
        while(getline(result_list,fileLine)){

                 for ( i = 0; i < 3; i++) {

                     switch (i) {
                         case 0:
                             tab[i] = fileLine;
                             break;
                         case 1:
                             getline(result_list, fileLine);
                             tab[i] = fileLine;
                             break;
                         case 2:
                             getline(result_list, fileLine);
                             tab[i] = fileLine;
                             getline(result_list, fileLine);
                             break;
                     }
                 }

            if(tab[1] == quiz_name) {
                     quiz_exist = 1;
                     cout << endl << "\t" << "Autor:" << tab[0] << endl;
                     cout << "\t" << "Nazwa quizu:" << tab[1] << endl;
                     cout << "\t" << "Wynik:" << tab[2] << endl;
             }
        }
        if(quiz_exist == 0){
            cout << endl << "\t" << "Brak takiego quizu lub nie ma wyniku!" <<  endl;
        }
    }
    else{
        file_load_error();
    }
    result_list.close();
}


void best_results(){
    string quiz_name;

    cout << "Podaj nazwe quizu: " << endl ;


    while(!(cin >> quiz_name)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    fstream result_list;
    result_list.open("result_list.txt", ios::in);
    if (result_list.good()){
        string best_value;
        string fileLine;
        string tab[1];
        string save_tab;
        int i;
        vector<string>percent;

        while(getline(result_list,fileLine)){

            for(i = 0; i < 2; i++ ){

                switch (i) {
                    case 0:
                        getline( result_list, fileLine );
                        tab[i]= fileLine;

                        break;
                    case 1:
                        getline( result_list, fileLine );
                        getline( result_list, fileLine );
                        tab[i]= fileLine;

                        break;

                }
            }

            if(quiz_name == tab[0]){
                save_tab = tab[1];
                percent.push_back(save_tab);
            }

        }

        if(percent.size()>0) {
            for (int z = 0; z < percent.size(); z++) {
                if (percent[z] > best_value) {
                    best_value = percent[z];
                }
            }
            cout << "\t" << "Nazwa quizu: " << quiz_name << endl;
            cout << "\t" << "Najlepszy wynik: " << best_value << "% poprawnych odpowiedzi" << endl;
        }else{
            cout << "\t" << "Brak takiego quizu lub nie ma wyniku!" << endl;
        }
    }
    else{
        file_load_error();
    }
    result_list.close();
}

void  first_results(){
    fstream result_list;
    result_list.open("result_list.txt", ios::in);
    if (result_list.good()){
        string fileLine;
        int counter = 1;
        while(getline(result_list,fileLine)){
            if(counter<11) {
                cout << endl << counter <<'.';
                for (int i = 0; i < 3; i++) {

                    switch (i) {
                        case 0:
                            cout << endl << "\t" << "Nick: " << fileLine << endl;
                            break;
                        case 1:
                            getline(result_list, fileLine);
                            cout << "\t" << "Nazwa quizu: " << fileLine << endl;

                            break;
                        case 2:
                            getline(result_list, fileLine);
                            cout << "\t" << "Wynik: " << fileLine << endl;
                            getline(result_list, fileLine);

                            break;
                    }

                }

             counter++;
            }
            else{
                return;
            }
        }
    }else{
        file_load_error();
    }
    result_list.close();
}




void result_menu(){
    cout << "*********************************************" << endl;
    cout << "* [0] - Powrot do menu glownego" << endl;
    cout << "* [1] - Wyniki dla uzytkownika" << endl;
    cout << "* [2] - Wyniki dla quizu" << endl;
    cout << "* [3] - Najlepszy wynik w quizie" << endl;
    cout << "* [4] - 10 pierwszych wynikow" << endl;
    cout << "*********************************************" << endl;

    cout << "Wybierz opcje:";

    int result_menu;

    while(!(cin >> result_menu) || (result_menu < 0) || result_menu > 4 ){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch(result_menu){
        case 1:
          user_results() ;
            break;
        case 2:
            quiz_results();
            break;
        case 3:
            best_results();
            break;
        case 4:
            first_results();
            break;
    }
}


void start_quiz(string quiz_name){
    fstream quiz;
    quiz.open(quiz_name + ".txt", ios::in);

    if (quiz.good()){
        int number_of_line = 2;
        string content;
        char answer;
        int answer_number = 0;

        //to save start
        int correct_answer = 0;
        int bad_answer = 0;
        string nick;

        int i = 0;
        getline(quiz, content);
        int array_size = stoi(content);
        char *array = new char[array_size];
        //to save end

        while(getline(quiz,content)){
            switch(number_of_line){
                case 2:
                    cout << endl << "Temat: " << content << endl;
                    break;
                case 3:
                    cout << "Autor: " << content << endl;
                    break;
                case 4:
                    cout << "Poziom trudnosci: " << content << endl;
                    cout << "Podaj nick: ";

                    while(!(cin >> nick)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    cout << endl;

                    break;
                case 5:
                    cout << endl << ++answer_number << ". " << content << endl;
                    break;
                case 6:
                    cout << "A - " << content << endl;
                    break;
                case 7:
                    cout << "B - " << content << endl;
                    break;
                case 8:
                    cout << "C - " << content << endl;
                    break;
                case 9:
                    cout << "D - " << content << endl << endl;
                    break;
                case 10:
                    cout << "Odpowiedz:";

                    while(!(cin >> answer) || (answer != 97 && answer != 98 && answer != 99 && answer != 100 && answer != 65 && answer != 66 && answer != 67 && answer != 68)){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    if(tolower(answer) == tolower(content.front())){
                        correct_answer++;
                    }
                    else{
                        bad_answer++;
                    }

                    array[i] = answer;
                    i++;

                    cout << endl;
                    break;
            }

            number_of_line++;

            if (number_of_line > 10) {
                number_of_line = 5;
            }
        }
        quiz.close();

        fstream results_list;
        results_list.open("result_list.txt", ios::out | ios::app);
        if (results_list.good()){
            double percent = (float (correct_answer) / float((correct_answer + bad_answer))) * 100;
            results_list << nick << endl;
            results_list << quiz_name << endl;
            results_list << correct_answer << '/' << correct_answer + bad_answer << "p."  << endl;
            results_list << percent << endl ;

            cout << endl << "Dziekujmy za podejscie! Twoje wyniki zostaly zapisane." << endl << endl;

        }
        else{
            file_load_error();
        }

        delete [] array;
    }
    else{
        file_load_error();
    }
}

void quiz_list(){
    cout << endl << endl;

    fstream quiz_list;
    quiz_list.open("quiz_list.txt", ios::in);

    if (quiz_list.good()){
        int number_of_line = 1;
        string content;
        int quiz_position = 0;

        while(getline(quiz_list,content)){
            switch(number_of_line){
                case 1:
                    cout << "[" << ++quiz_position << "] - ";
                    break;
                case 2:
                    cout << content << " ";
                    break;
                case 3:
                    cout << "- " << content;
                    break;
                case 4:
                    cout << ", poziom trudnosci: " << content << endl;
                break;
            }

            number_of_line++;

            if (number_of_line > 4) {
                number_of_line = 1;
            }
        }

        cout << "[0] - Cofnij do menu glownego" << endl << endl;
        cout << "Wybierz quiz:";
        int menu;
        while(!(cin >> menu) || ( menu < 0 || menu > quiz_position)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(menu){
            number_of_line = 1;
            quiz_position = 0;
            quiz_list.clear();
            quiz_list.seekg(0);
            string quiz;
            while(getline(quiz_list,content)){
                if(number_of_line == 1 && ++quiz_position == menu){
                    quiz = content;
                    continue;
                }

                number_of_line++;

                if (number_of_line > 4) {
                    number_of_line = 1;
                }
            }

            quiz_list.close();

            start_quiz(quiz);
        }
        else{
            quiz_list.close();
        }
    }
    else{
        file_load_error();
    }
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

int main() {

    name();

    int nav;
    bool loop = true;
    while (loop){
        cout << "*********************************************" << endl;
        cout << "* [1] - Quizy" << endl;
        cout << "* [2] - Wyniki" << endl;
        cout << "* [3] - Tworcy" << endl;
        cout << "* [4] - Zamknij program" << endl;
        cout << "*********************************************" << endl << endl;

        cout << "Wybierz opcje:";

        while(!(cin >> nav) || (nav != 1 && nav != 2 && nav != 3 && nav != 4)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(nav){
            case 1:
                quiz_list();
                break;
            case 2:
                result_menu();
                break;
            case 3:
                author();
                break;
            case 4:
                if(close()){
                    loop = false;
                }
                break;
            default:
                cout << "Podaj opcje z menu" << endl;
                break;
        }
    }

    return 0;
}