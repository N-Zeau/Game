
#ifndef ORDINAL_ENGINE_I_WINDOW_HPP_
#define ORDINAL_ENGINE_I_WINDOW_HPP_

#include "Glew/glew.h"
#include "Glfw/glfw3.h"

namespace Ge{

    struct SWindowCreateInfo{
        int window_width;
        int windiw_height;
        const char* p_window_title;
    };

    class IWindow {
    public:

        virtual ~IWindow() = default;
        virtual void Initialize(const SWindowCreateInfo window_create_info) = 0;
        virtual void Release() = 0;

        GLFWwindow* GetHandle();

    protected:

        GLFWwindow* mp_window = nullptr;

    };


}

#endif

