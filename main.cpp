// #include"src/window.h"
// #include"src/shader.h"
// #include"src/model.h"

// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// // camera
// Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

// int main()
// {
//     Window win("Cube", 800, 600);
//     win.init();
//     win.create();
//     Shader shader;
//     shader.setProgramID();
//     shader.VertexShaderCompile(shader.ReadShader("src/shaders/vertex.glsl"));
//     shader.FragmentShaderCompile(shader.ReadShader("src/shaders/fragment.glsl"));
//     shader.createProgram();

//     stbi_set_flip_vertically_on_load(true);

//     glEnable(GL_DEPTH_TEST);

//     Model CubeModel("src/models/Untitled.obj");

//      while (!win.ShouldClose())
//      {
//          // Obsługa zdarzeń
//         win.pollEvents();

//         shader.use();

//          //view/projection transformations
//         glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//         glm::mat4 view = camera.GetViewMatrix();
//         shader.setMat4("projection", projection);
//         shader.setMat4("view", view);

//         // render the loaded model
//         glm::mat4 model = glm::mat4(1.0f);
//         model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
//         model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
//         shader.setMat4("model", model);

//         CubeModel.Draw(shader);
//         // Aktualizacja stanu gry (np. pozycja gracza, logika gry)
//         win.update();

//         // Zamiana buforów
//         win.swapBuffers();
//     }
//     //glfwTerminate();

//     return 0;
// }