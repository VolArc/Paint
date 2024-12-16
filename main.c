#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define uint unsigned int

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
    #define CLEAR "cls"
    #define PAUSE system("pause");
    #define GETCHAR getch()
#else
    #define CLEAR "clear"
    #define PAUSE getchar()
    #include <termios.h>
    #define GETCHAR getchar()
#endif

void PrintImage (char board[17][17], uint x, uint y, bool noPauses, char message[], uint highlightX, uint highlightY) {
    system (CLEAR);
    printf ( "   ");
    for (uint i = 0; i < 17; i++) {
        if (i == x) printf("\x1B[42m%02d\033[0m", i);
        else printf("%02d", i);
    }
    printf("\n");
    for (int i = 0; i < 17; i ++){
        if (y == i) printf("\x1B[42m%02d\033[0m|", i);
        else printf("%02d|", i);
        for (int j = 0; j < 17; j ++){
            if (i == highlightY && j == highlightX) {
                printf( "\x1B[47m  \033[0m");
                continue;
            }
            switch (board[i][j]) {
                case ' ': {
                    printf( "  ");
                    break;
                }
                case '#': {
                    printf ("\x1B[41m  \033[0m");
                    break;
                }
                case '@': {
                    printf ("\x1B[44m  \033[0m");
                    break;
                }
                case '^': {
                    printf ("\x1B[42m  \033[0m");
                    break;
                }
                default: break;
            }
        }
        printf("|\n");
        if (i == 16) {
            if (y != -1 && x != -1)
                printf("X : %02d; Y : %02d\n", x, y);
            printf ("%s", message);
        }
    }

    if (!noPauses) PAUSE;
}

void Fill (uint x, uint y, char board[17][17]) {
    if (x == 0 || y == 0 || x == 16 || y == 16) {
        board[y][x] = '#';
        return;
    }
    char c = board[y][x];
    if (c != '#' && c != '@'){
        board[y][x] = '@';
        PrintImage(board, x , y, false, "", -1, -1);
        Fill (x - 1, y, board);
        Fill (x + 1, y, board);
        Fill (x, y - 1, board);
        Fill (x, y + 1, board);
    }
}

void Paint1 () {
    char board[17][17] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    Fill (10, 3, board);
}

void Paint2 () {
    char board[17][17] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' '},
        {' ', ' ', '#', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    Fill (2, 5, board);
    PrintImage (board, -1, -1, false, "", -1, -1);
}

void UserImage () {
    printf ("\nВВОД РИСУНКА.\nИнструкция:\n1. Введите # чтобы создать границу\n2. Нажмите ^ чтобы обозначить стартовую точку\n3. Стартовая точка не может быть расположена на границе рисунка\n4. Стартовая точка может быть только одна\n");
    PAUSE;
    const char _template[17][17] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    char board[17][17] = {};
    memcpy(board, _template, 17 * 17 * sizeof (char));

    int startPointX = -1, startPointY = -1;
    bool startPaint = false;
    int y = 0, x = 0;

    while (!startPaint) {
        PrintImage(board, x, y, true, "r - Стереть рисунок\nf - Стереть строку\nq - Вернуться в меню\nb - Начать закраску\nw, s, a, d - Вверх, вниз, влево, вправо", x, y);
        switch (GETCHAR) {
            case '#': {
                if (board[y][x] == '^') {
                    startPointX = -1;
                    startPointY = -1;
                }
                board[y][x++] = '#';
                break;
            }
            case ' ': {
                if (board[y][x] == '^') {
                    startPointX = -1;
                    startPointY = -1;
                }
                board[y][x++] = ' ';
                break;
            }
            case '^': {
                if (y != 0 && x != 0 && y != 16 && x != 16) {
                    if (startPointX != -1 && startPointY != -1) board[startPointY][startPointX] = ' ';
                    board[y][x] = '^';
                    startPointX = x ++;
                    startPointY = y;
                }
                break;
            }
            case 'r': {
                y = 0;
                x = 0;
                memcpy(board, _template, 17 * 17 * sizeof(char));
                break;
            }
            case 'f': {
                x = 0;
                memcpy(board[y], _template[y], 17 * sizeof(char));
                break;
            }
            case 'b': {
                if (startPointX == -1 && startPointY == -1) {
                    printf ("\n\033[37m\033[41mНет стартовой точки!!!\033[0m\n");
                    PAUSE;
                }
                else startPaint = true;
                break;
            }
            case 'w': {
                y --;
                break;
            }
            case 's': {
                y ++;
                break;
            }
            case 'a': {
                x --;
                break;
            }
            case 'd': {
                x ++;
                break;
            }
            case 'q': {
                return;
            }
            default: break;
        }
        if (y == 16 && x == 16) {
            y = 0;
            x = -1;
        }
        if (x == 17) y ++;
        else if (x == -1) y --;
        x = (x + 17) % 17;
        y = (y + 17) % 17;
    }
    Fill(startPointX, startPointY, board);
    PrintImage(board, 17, 17, true, "", -1, -1);
}

int Menu(char options[][1024], int numOptions, char message[]) {
    int chosenOption = 0;

    while (true) {
        system(CLEAR);

        for (int i = 0; i < numOptions; i++) {
            if (i == chosenOption) {
                printf("\x1b[36m%d. %s\n\x1b[0m", i, options[i]);
            } else {
                printf("%d. %s\n", i, options[i]);
            }
        }

        printf ("%s", message);

        switch (GETCHAR) {
            case 'w': {
                chosenOption = (chosenOption - 1 + numOptions) % numOptions;
                break;
            }
            case 's': {
                chosenOption = (chosenOption + 1) % numOptions;
                break;
            }
            case 'e':
                return chosenOption;
            default: break;
        }
    }
}

int main () {
#if defined _WIN32
    SetConsoleOutputCP(65001);
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
#endif

    char options[][1024] = {"Пример 1", "Пример 2", "Ввод рисунка", "Выход"};
    char message[] = "Для перемещения между пунктами использовать w и s. Для выбора пункта нажмите e (латинскую). Если не работает, попробуйте поменять раскладку.";
    bool isRunning = true;

    while (isRunning) {
        switch (Menu(options, 4, message)) {
            case 0: {
                Paint1();
                break;
            }
            case 1: {
                Paint2();
                break;
            }
            case 2: {
                UserImage();
                break;
            }
            default: {
                isRunning = false;
                break;
            }
        }

        system(CLEAR);
    }

#if !defined _WIN32
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
	return 0;
}
