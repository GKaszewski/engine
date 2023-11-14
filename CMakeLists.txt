cmake_minimum_required(VERSION 3.26)
project(engine)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG main
        CMAKE_ARGS -DBOX2D_BUILD_UNIT_TESTS=OFF -DBOX2D_BUILD_TESTBED=OFF -DBOX2D_BUILD_EXAMPLES=OFF
)
FetchContent_MakeAvailable(box2d)

FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_TAG 454f36d2af9d92a0f8ffe8536c218247df732edc
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
        imgui-sfml
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml
        GIT_TAG ba22e6ce8a2231e63031891fb08d625e7f84bd71
)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_SFML_IMGUI_DEMO ON)
FetchContent_MakeAvailable(imgui-sfml)

FetchContent_Declare(
        entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG 344e03ac64a1f78424ab1150e2d4778e8df8431d
)
FetchContent_MakeAvailable(entt)

add_executable(engine src/main.cpp
        src/core/Application.cpp
        src/core/Application.h
        src/core/states/StateBase.h
        src/core/utils/NonCopyable.h
        src/core/utils/NonMoveable.h
        src/core/utils/FpsCounter.cpp
        src/core/utils/FpsCounter.h
        src/core/resource_manager/ResourceHolder.cpp
        src/core/resource_manager/ResourceHolder.h
        src/core/resource_manager/ResourceManager.h
        src/core/Physics.cpp
        src/core/Physics.h
        src/game/states/DemoScene.cpp
        src/game/states/DemoScene.h
        src/game/components/TransformComponent.h
        src/game/components/InputComponent.h
        src/game/components/ShapeComponent.h
        src/game/components/RigidbodyComponent.h
        src/game/systems/InputSystem.cpp
        src/game/systems/InputSystem.h
        src/game/systems/RenderSystem.cpp
        src/game/systems/RenderSystem.h
        src/game/systems/SyncPhysicsToGraphicsSystem.cpp
        src/game/systems/SyncPhysicsToGraphicsSystem.h
        src/game/entities/Player.h
        src/game/entities/Box.h
        src/game/systems/LogSystem.cpp
        src/game/systems/LogSystem.h
        src/game/states/GameScene.cpp
        src/game/states/GameScene.h
        src/game/components/AnimationComponent.h
        src/game/systems/AnimationSystem.cpp
        src/game/systems/AnimationSystem.h
        src/game/entities/Bird.h
        src/game/components/PlayerInputComponent.h
        src/game/systems/PlayerInputSystem.cpp
        src/game/systems/PlayerInputSystem.h
        src/game/systems/BirdMovementSystem.cpp
        src/game/systems/BirdMovementSystem.h
        src/game/components/BirdMovementComponent.h
        src/game/components/CollisionComponent.h
        src/game/systems/CollisionSystem.cpp
        src/game/systems/CollisionSystem.h
        src/game/physics/ContactListener.cpp
        src/game/physics/ContactListener.h
)
target_include_directories(${PROJECT_NAME} PRIVATE ${entt_SOURCE_DIR}/src)
target_link_libraries(${PROJECT_NAME} ImGui-SFML::ImGui-SFML box2d sfml-audio)
