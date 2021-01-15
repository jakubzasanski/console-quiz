#include <iostream>
#include <limits>
#include <fstream>
#include <string>

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

        cout << endl << "Dziekujmy za podejscie! Twoje wyniki zostaly zapisane." << endl << endl;

//        for(i=0; i<array_size; i++ ){
//            cout << array[i] << endl;
//        }

        //TUTAJ tutaj powinno dodawać wpis do results_list i tworzyc plik z wynikami tego podejscia
        // nick - nick
        // quiz_name - nazwa pliku z quizem
        // nazwa nowego pliku trzeba wygnerować

        // nowy plik nazwany wczesniej wygnerowana nazwa
        // correct_answer - ilosc poprawnych
        // bad_answer - niepoprawnych
        // array_size - wielkosc tablicy
        // array - tablica z udzielonymi odpowiedziami

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

        while(!(cin >> nav) || (nav != 1 && nav != 2 && nav != 3)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(nav){
            case 1:
                quiz_list();
                break;
            case 2:

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