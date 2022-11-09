#include <stdexcept>
#include <iostream>
#include "IWindow.hpp"
#include "COpenGL33Window.hpp"

namespace Ge{

    void ErrorCallBack(int error, const char* descritpion){
        std::cerr << "Erreur : " << std::endl;
    }

    COpenGL33Window::~COpenGL33Window(){
        Release();
    }

    void COpenGL33Window::Initialize(const Ge::WindowInfo window_create_info) {

        //Test de l'initialisation de GLFW
        if (!glfwInit()){
            throw std::runtime_error("Echec de l'initialisation de GLFW");
        }

        glfwSetErrorCallback(ErrorCallBack);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        mp_window = glfwCreateWindow(window_create_info.window_width,
                                     window_create_info.window_height,
                                     window_create_info.p_window_title,
                                     nullptr,
                                     nullptr);

        //Test de l'initialisation de la fenêtre
        if(!mp_window){
            glfwTerminate();
            throw std::runtime_error("Echec de la création de la fenêtre.");
        }

        glfwMakeContextCurrent(mp_window);
        glewExperimental = GL_TRUE;

        //Test de l'initialisation de GLEW
        if (glewInit() != GLEW_OK){
            glfwTerminate();
            throw std::runtime_error("Echec de l'initialisation de GLEW");
        }

        glfwSetInputMode(mp_window, GLFW_STICKY_KEYS, GLFW_TRUE);
        std::cout << "Initialisation de OpenGL reussi" << std::endl;


    }

    void COpenGL33Window::Release() {

        if (m_initialized){
            glfwTerminate();
            mp_window = nullptr;

            m_initialized = false;
            std::cout << "La fenetre est ferme" << std::endl;
        }



    }

}
