// Soft.cpp : Определяет точку входа для приложения.
//

#include <iostream>
#include "framework.h"
#include "Soft.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместить код здесь.
    int[][]mines; // вход 1 Для наличия мины и 0 для отсутствия
    bool[][]flags; // вход 1, если вы отметили это место
    bool[][]revealed; // вход 1, если это пятно обнаружено

    int gridW = 16; // ширина сетки
    int gridH = 16; // высота сетки
    int cellSize = 50; // размер ячейки
    int numMines = 40; // количество мин

    // Переменная cellSize определяет количество пикселей в каждом квадрате.
    void settings() {
        size(gridW * cellSize, gridH * cellSize);
    }
    // Конец

    // Возврат переменных в изначальное состояние.
    void setup() {
        mines = new int[gridW][gridH];
        flags = new boolean[gridW][gridH];
        revealed = new boolean[gridW][gridH];

        for (int x = 0; x < gridW; x++) {
            for (int y = 0; y < gridH; y++) {
                mines[x][y] = 0;
                flags[x][y] = false;
                revealed[x][y] = false;
            }
        }
    }
    // Конец

    // Инициализация поля
    // помещаем numMines мины на сетку
    void placeMines() {
        int i = 0;
        while (i < numMines) { // Для того чтобы мины не перекрывались
            int x = int(random(gridW));
            int y = int(random(gridH));
            if (mines[x][y] == 1)continue;
            mines[x][y] = 1;
            i++;
        }
    }
    // очистить мины
    void clearMines() {
        for (int x = 0; x < gridW; x++) {
            for (int y = 0; y < gridH; y++) {
                mines[x][y] = 0;
            }
        }
    }
    // конец

    // Включаем реакцию на клики мышью
    // исключаем попадание на мину при первом клике
    bool firstClick = true;
    void mousePressed() {
        int x = int(mouseX / cellSize);
        int y = int(mouseY / cellSize);
        // щелчок правой кнопкой мыши-это пометка или удаление пометки квадрата
        if (mouseButton == RIGHT) {
            flags[x][y] = !flags[x][y];
            return;
        }
        else {
            // избегаем превращения первого щелчка в мину
            if (firstClick) {
                firstClick = false;
                do {
                    clearMines();
                    placeMines();
                } while (mines[x][y] != 0);
            }
            // проверка на проигрыш в игре
            if (mines[x][y] != 0) {
                println("Dang!");
                exit();
            }
            else {
                reveal(x, y);
            }
        }
    }
    
    // Код ниже определяет, сколько мин находится рядом с определенным участком.
    bool outBounds(int x, int y) {
        return x < 0 || y < 0 || x >= gridW || y >= gridH;
    }
    int calcNear(int x, int y) {
        if (outBounds(x, y))return 0;
        int i = 0;
        for (int oX = -1; oX <= 1; oX++) {
            for (int oY = -1; oY <= 1; oY++) {
                if (outBounds(oX + x, oY + y))continue;
                i += mines[oX + x][oY + y];
            }
        }
        return i;
    }
    // конец

    /*
    Алгоритм ниже:
    1) Если позиция за пределами поля, end;
    2) Если позиция раскрыта, end;
    3) Раскрываем текущую позицию;
    4) Если у нас бомба рядом с текущей позицией, end;
    5) Если мы дошли до этого пункта во время выполнения функции, 
    текущая позиция в пределах игрового поля была обнаружена и рядом с ней нет бомб, 
    открываем смежные квадраты.
    */
    void reveal(int x, int y) {
        if (outBounds(x, y))return;
        if (revealed[x][y])return;
        revealed[x][y] = true;
        if (calcNear(x, y) > 0)return;

        reveal(x - 1, y - 1);
        reveal(x - 1, y + 1);
        reveal(x + 1, y - 1);
        reveal(x + 1, y + 1);

        reveal(x - 1, y);
        reveal(x + 1, y);
        reveal(x, y - 1);
        reveal(x, y + 1);
    }
    //Конец

    // Функция отображения, вызываем ее один раз для каждого кадра.
    void draw() {
        background(0);
        // для каждой ячейки
        for (int x = 0; x < gridW; x++) {
            for (int y = 0; y < gridH; y++) {
                // цвета чередуются для текстуры
                color col1 = color(2 * 255 / 5);
                color col2 = color(3 * 255 / 5);

                color txtColor = color(0);

                int near = calcNear(x, y);

                if (flags[x][y]) {
                    col1 = color(255, 0, 0);
                    col2 = color(4 * 255 / 5, 255 / 5, 255 / 5);
                }
                else if (revealed[x][y]) {
                    col1 = color(255 / 2);
                    col2 = color(255 / 2);
                }

                if (near == 1)txtColor = color(255 * 1 / 4, 255 * 1 / 4, 255 * 3 / 4);
                if (near == 2)txtColor = color(255 * 1 / 4, 255 * 3 / 4, 155 * 1 / 4);
                if (near == 3)txtColor = color(255, 0, 0);
                if (near == 4)txtColor = color(0, 0, 255);
                if (near == 5)txtColor = color(255, 0, 0);

                bool alternate = (x + y) % 2 == 0;
                if (alternate) {
                    fill(col2);
                    stroke(col2);
                }
                else {
                    fill(col1);
                    stroke(col1);
                }

                rect(x * cellSize, y * cellSize, cellSize, cellSize);
                // если рядом с этим местом есть мина и она обнаружена
                if (near > 0 && revealed[x][y]) {
                    fill(txtColor);
                    noStroke();
                    textAlign(LEFT, TOP);
                    textSize(cellSize);
                    text("" + near, x * cellSize, y * cellSize);
                }

            }
        }
    }

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SOFT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SOFT));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SOFT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SOFT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
