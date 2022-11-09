
#ifndef ORDINAL_ENGINE_I_WINDOW_HPP_
#define ORDINAL_ENGINE_I_WINDOW_HPP_

#include "Glew/glew.h"
#include "Glfw/glfw3.h"

namespace Ge{

    struct WindowInfo{
        int window_width;
        int window_height;
        const char* p_window_title;
    };

    class IWindow {
    public:

        virtual ~IWindow() = default;
        virtual void Initialize(WindowInfo window_create_info) = 0;
        virtual void Release() = 0;

        GLFWwindow* GetHandle();

    protected:

        bool m_initialized = true;
        GLFWwindow* mp_window = nullptr;

    };


}

#endif

