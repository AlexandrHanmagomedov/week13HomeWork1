//Домашнее задание 1
//Задание 1. Дана шахматная доска размером 8×8 и шахмат -
//ный конь.Программа должна запросить у пользователя
//координаты клетки поля и поставить туда коня.Задача
//программы найти и вывести путь коня, при котором он
//обойдет все клетки доски, становясь в каждую клетку
//только один раз. (Так как процесс отыскания пути для
//    разных начальных клеток может затянуться, то реко -
//    мендуется сначала опробовать задачу на поле размером
//    6×6).В программе необходимо использовать рекурсию.

#include <iostream>
using namespace std;

const int SIZE = 5;
int doska[SIZE][SIZE];
const int SIZE1 = 64;
int row[64], col[64];
int kmvRow[8] = {  1,  2, 2, 1,-1,-2, -2, -1 };
int kmvCol[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int i, j, s4et4ik = 1, d = 0;

void vivod() {
    for (int k = 0; k <= SIZE - 1; k++)
    {
        for (int l = 0; l <= SIZE - 1; l++) {
            cout << "  " << doska[k][l];
        }
        cout << endl;
    }
}
int KonHod(int x, int y) {
    int a, b, с;
    //cout << x << y;
   // cout << endl;
    vivod();
    /* пометить клетку как посещенную и запомнить координаты клетки */
    doska[x][y] = s4et4ik;
    row[s4et4ik] = x;
    col[s4et4ik] = y;
    s4et4ik++;
    cout << s4et4ik << "   move num";
    cout << endl;
    /* проверить 8 возможных перемещений коня */
    for (a = 0; a <= 7; a++) {

        /* если все ходы сделаны, печатаем их */
        if (s4et4ik >= SIZE1 - 1) {
            vivod();
            exit(0);
        }
        /* определяем колонку и строку для следующего хода */
        b = x + kmvRow[a];
        с = y + kmvCol[a];

        /* проверяем, что после выполенения хода конь остается на шахматной доске */
        if (b < 0 || b > SIZE - 1 || с < 0 || с > SIZE - 1)
            continue;
        x = b; y = с;
       /* cout << a << "   a aaaaaaaaaaaaa";
        cout << endl;
        cout << b << "   b bbbbbbbbbbbbbbbbb";
        cout << endl;
        cout << с << "   ccccccccccccccccccccc";
        cout << endl;*/
        /* проверяем, были ли мы уже в этой клетке */
        if (doska[b][с] >= 1) {
            continue;
        }
        x = b; y = с;
        KonHod(x, y);
        /* уменьшить счетчик ходов и попробовать сделать следующий ход */
        s4et4ik--;

        /* освобождаем клетку, ранее занятую конем */
        doska[row[s4et4ik]][col[s4et4ik]] = 1;
        x = row[s4et4ik]; y = col[s4et4ik];
        s4et4ik++;
        //s4et4ik--;  /* пробуем сделать следующий ход */
        
    }
   


}
int main()
{
    for (int l = 0; l <= SIZE - 1; l++)
    {
        for (int k = 0; k <= SIZE - 1; k++) {
            doska[l][k] = 0;
        }
    }
    cout << endl << "pustaya doska";
    KonHod(0, 0);
    vivod();
}