#include"src/window.h"

int main()
{
    Window win("Cube", 800, 600);
    win.init();
    win.create();


     while (!win.ShouldClose())
    {
        // Obsługa zdarzeń
        win.pollEvents();

        // Aktualizacja stanu gry (np. pozycja gracza, logika gry)
        win.update();

        // Zamiana buforów
        win.swapBuffers();
    }

    return 0;
}