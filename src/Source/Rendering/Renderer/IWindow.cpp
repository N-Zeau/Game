#include "Rendering/Renderer/IWindow.hpp"

namespace Ge{

    GLFWwindow* IWindow::GetHandle(){
        return mp_window;
    }


}