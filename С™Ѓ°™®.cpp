#include <iostream>
#include <string>
using namespace std;

void match_arr_print(int array[], int size) {
  string brack = "({[<)}]>";
  for (int i = 0; i < 4; i++) {
    if(array[i] == array[i+4]) { //если число открывающх = числу закрывающих
      cout << "Brackets " << brack[i] << " " << brack[i+4] << " : Normal" << endl;
    } else { //если не равно
      cout << "Brackets " << brack[i] << " " << brack[i+4] << " : False" << endl;
    }
  } cout << endl;
}

int error_match(string brackets, int array[], int B) {
  string brack = "({[<)}]>"; //все скобочки(для проверки)
  string brack_order = ""; //хронология нужной последовательности
  int count = 0, error_index;

  for (int i = 0; i < brackets.length(); i++) { //пробег по каждому символу текста
      for (int j = 0; j < B; j++) { //пробег по массиву всех скобок с поиском соответствия
          if (brackets[i] == brack[j]) { //скобка ли это?
            if(j < B/2) { //если открывающая
              brack_order += brackets[i];
              count++;
            } else { //если закрывающая
              if(brackets[i] == brack[brack.find(brack_order[count-1])+4]) { //та ли скобка закрывается
                count--;
                brack_order.pop_back(); //удаляет открывающую скобку из хронологии
              } else { //если нет - возвращает проблемный индекс
                cout << "Error in index " << i << endl;
                return error_index;
              }
            }
            array[j]++; //счетчик
          }
      }
      error_index = i; //счетчик индекса ошибки
  }

  return error_index;
}

void print_text(string brackets, int error) {
  cout << "Correct text: ";
  for(int i = 0; i <= error; i++) { //печать до проблемного места
    cout << brackets[i];
  }
  cout << endl;
}

int main() {
    string brackets; //изначальнй текст
    const unsigned int B = 8; //количество скобочек
    int array[B]{}; //подсчет количества

    cout << "Enter text/expression: ";
    getline(cin, brackets, ';');

    int error_index = error_match(brackets, array, B); //индекс сбоя в расстановке(если все правильно - индекс будет соответствовать размеру)

    match_arr_print(array, B); //сначала соответствие по количеству
    print_text(brackets, error_index); //печатает до индекса сбоя
}
