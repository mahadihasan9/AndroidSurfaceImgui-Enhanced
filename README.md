# AndroidSurfaceImgui C++17 Enhanced

## Project Introduction

This project is modified and enhanced based on [AndroidSurfaceImgui](https://github.com/Bzi-Han/AndroidSurfaceImgui). It can be compiled into an Android executable that creates a Surface via Android APIs and renders Dear ImGui on it.

### Main Improvements

- ✅ **C++17 compatibility**: Fully compatible with the C++17 standard with better modern C++ support
- ✅ **Enhanced Surface management**: New Surface cleanup function to ensure resources are released correctly
- ✅ **Fixed re-creation issue**: Fixed the problem where the root Surface could not be re-created after being closed
- ✅ **Screen-capture protection**: Supports toggling screen-capture protection to protect sensitive content
- ✅ **Wide system support**: Supports all versions from Android 5.0 to Android 16.0
- ✅ **NDK build system**: Uses ndk-build for compilation, simplifying the build process

## Supported Android Versions

| Version Range | Support Status | Notes |
|---------|---------|------|
| Android 5.0 - 5.1 | ✅ Fully supported | API Level 21-22 |
| Android 6.0 | ✅ Fully supported | API Level 23 |
| Android 7.0 - 7.1 | ✅ Fully supported | API Level 24-25 |
| Android 8.0 - 8.1 | ✅ Fully supported | API Level 26-27 |
| Android 9.0 | ✅ Fully supported | API Level 28 |
| Android 10.0 | ✅ Fully supported | API Level 29 |
| Android 11.0 | ✅ Fully supported | API Level 30 |
| Android 12.0 - 12.1 | ✅ Fully supported | API Level 31-32 |
| Android 13.0 | ✅ Fully supported | API Level 33 |
| Android 14.0 | ✅ Fully supported | API Level 34 |
| Android 15.0 | ✅ Fully supported | API Level 35 |
| Android 16.0 | ✅ Fully supported | API Level 36 |

## Requirements

### Development Environment
- **Android NDK**: r21e or higher
- **Compiler**: GCC/Clang with C++17 support
- **Minimum API Level**: 22 (Android 5.1)
- **Target ABIs**: arm64-v8a, armeabi-v7a, x86, x86_64

### Runtime Environment
- **Android device**: Android 5.0 and above
- **Permission requirements**: System-level permission or root permission required
- **Hardware requirements**: Device supporting OpenGL ES 3.0 or Vulkan

## Quick Start

### 1. Clone the project

```bash
git clone https://github.com/AFan4724/AndroidSurfaceImgui-Enhanced.git
cd AndroidSurfaceImgui-Enhanced
```

### 2. Build the project

Build with ndk-build:

```bash
# Set NDK path (if env variable is not set)
export NDK_ROOT=/path/to/your/ndk

# Build all architectures
ndk-build

# Or build a specific ABI
ndk-build APP_ABI=arm64-v8a
```

### 3. Deploy to device

```bash
# Push to device
adb push libs/arm64-v8a/imgui_chain_v2-1.0 /data/local/tmp/

# Set execute permission
adb shell chmod 755 /data/local/tmp/imgui_chain_v2-1.0

# Run the program
adb shell su -c "/data/local/tmp/imgui_chain_v2-1.0"
```

## Project Structure

```
AndroidSurfaceImgui-Enhanced/
├── jni/                          # NDK source directory
│   ├── src/                      # Source code
│   │   ├── main.cpp             # Program entry point
│   │   ├── Android_draw/        # Rendering related
│   │   ├── Android_Graphics/    # Graphics/rendering manager
│   │   ├── Android_my_imgui/    # ImGui Android adapter
│   │   ├── Android_touch/       # Touch event handling
│   │   ├── ImGui/              # Dear ImGui library
│   │   └── My_Utils/           # Utility functions
│   ├── include/                 # Header files
│   ├── Android.mk              # NDK build config
│   └── Application.mk          # App config
├── libs/                        # Build output directory
└── README.md                   # Project documentation
```

## Core Features

### Surface management

```cpp
// Create Surface
::window = android::ANativeWindowCreator::Create("test", width, height, permeate_record);

// Cleanup Surface (new feature)
android::ANativeWindowCreator::Cleanup();

// Destroy Surface
android::ANativeWindowCreator::Destroy(::window);
```

### Screen-capture protection

```cpp
// Enable screen-capture protection
bool permeate_record = false;  // false = block capture, true = allow capture

// Set it when creating the Surface
::window = android::ANativeWindowCreator::Create("test", width, height, permeate_record);
```

## Contributing

Issues and Pull Requests are welcome!

1. Fork this project
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is open-sourced under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Thanks to [Bzi-Han/AndroidSurfaceImgui](https://github.com/Bzi-Han/AndroidSurfaceImgui) for the original project base
- Thanks to the [Dear ImGui](https://github.com/ocornut/imgui) team for the excellent GUI library
- Thanks to all contributors and testers



**Note**: This project requires system-level permission to run properly. Please make sure to use it in an environment with appropriate permissions.
