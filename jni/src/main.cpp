#include "draw.h"    // Render kit
#include "AndroidImgui.h"     // Create render kit
#include "GraphicsManager.h" // Get current render mode



int main(int argc, char *argv[]) {
    ::graphics = GraphicsManager::getGraphicsInterface(GraphicsManager::VULKAN);

    // Get screen info    
    ::screen_config(); 

    ::native_window_screen_x = (::displayInfo.height > ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);
    ::native_window_screen_y = (::displayInfo.height < ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);
    ::abs_ScreenX = (::displayInfo.height > ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);
    ::abs_ScreenY = (::displayInfo.height < ::displayInfo.width ? ::displayInfo.height : ::displayInfo.width);

    ::window = android::ANativeWindowCreator::Create("AImGui", native_window_screen_x, native_window_screen_y, permeate_record);
    if (::window == nullptr) {
        return -1;
    }
    graphics->Init_Render(::window, native_window_screen_x, native_window_screen_y);
    
    Touch::Init({(float)::abs_ScreenX, (float)::abs_ScreenY}, false); // Change last param to true for listen-only mode
    Touch::setOrientation(displayInfo.orientation);

    
    ::init_My_drawdata(); // Init render data

    static bool flag = true;
    while (flag) {
        drawBegin();
        if (permeate_record == false) {
            android::ANativeWindowCreator::ProcessMirrorDisplay();
        }
        graphics->NewFrame();
        
        Layout_tick_UI(&flag);

        graphics->EndFrame();        
    }
    
    // graphics->DeleteTexture(image);
    graphics->Shutdown();
    android::ANativeWindowCreator::Destroy(::window);
    android::ANativeWindowCreator::Cleanup();
    return 0;
}
