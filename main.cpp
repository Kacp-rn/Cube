#include"src/window.h"
#include"src/shader.h"

int main()
{
    Window win("Cube", 800, 600);
    win.init();
    win.create();
    Shader shader;
    shader.setProgramID();
    shader.VertexShaderCompile(shader.ReadShader("src/shaders/vertex.glsl"));
    shader.FragmentShaderCompile(shader.ReadShader("src/shaders/fragment.glsl"));
    shader.createProgram();

     while (!win.ShouldClose())
    {
        shader.use();
        // Obsługa zdarzeń
        win.pollEvents();

        // Aktualizacja stanu gry (np. pozycja gracza, logika gry)
        win.update();

        // Zamiana buforów
        win.swapBuffers();
    }

    return 0;
}