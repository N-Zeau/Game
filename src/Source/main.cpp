#include <stdexcept>
#include <iostream>
#include "COpenGL33Window.hpp"


int main(int argc, char** argv) {

    Ge::COpenGL33Window window;
    Ge::WindowInfo window_create_info{};
    window_create_info.window_width = 1280;
    window_create_info.window_height = 720;
    window_create_info.p_window_title = "Game";

    try{
        window.Initialize(window_create_info);
    }
    catch (std::runtime_error& error){
        std::cout << "Exeption : " << std::endl;
        return -1;
    }

    GLFWwindow* p_window = window.GetHandle();
    while (!glfwWindowShouldClose(p_window) && glfwGetKey(p_window, GLFW_KEY_ESCAPE) != GLFW_PRESS){
        glfwSwapBuffers(p_window);
        glfwPollEvents();
    }


    return 0;
}