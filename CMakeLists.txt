cmake_minimum_required(VERSION 3.0)
project(NORTHENGINE)

include_directories(
	src
	contrib/windows-cl-amd64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/windows-cl-amd64/lib
)


add_library(rend
	src/rend/rend.h
	src/rend/Animation.cpp
	src/rend/Buffer.cpp
	src/rend/Mesh.cpp
	src/rend/Model.cpp
	src/rend/ModelRenderer.cpp
	src/rend/RenderTexture.cpp
	src/rend/Renderer.cpp
	src/rend/Shader.cpp
	src/rend/Texture.cpp
	src/rend/rendmath.cpp
)

target_link_libraries(rend glew32 OpenGL32)

add_library(northengine
	src/northengine/northengine.h

	src/northengine/Core.h
	src/northengine/Core.cpp

	src/northengine/Entity.h
	src/northengine/Entity.cpp

	src/northengine/Component.h
	src/northengine/Component.cpp

	src/northengine/TriangleRenderer.h
	src/northengine/TriangleRenderer.cpp

	src/northengine/Transform.h
	src/northengine/Transform.cpp

	src/northengine/MeshRenderer.h
	src/northengine/MeshRenderer.cpp

	src/northengine/BoxCollider.h
	src/northengine/BoxCollider.cpp

	src/northengine/Keyboard.h
	src/northengine/Keyboard.cpp

	src/northengine/Rigidbody.h
	src/northengine/Rigidbody.cpp

	src/northengine/Camera.h
	src/northengine/Camera.cpp

	src/northengine/Resource.h
	src/northengine/Resource.cpp
	
	src/northengine/Resources.h
	src/northengine/Resources.cpp

	src/northengine/Texture.h
	src/northengine/Texture.cpp

	src/northengine/Model.h
	src/northengine/Model.cpp
)

target_link_libraries(northengine SDL2 SDL2main rend openal32)

add_executable(game 
	src/game/main.cpp
)

target_link_libraries(game northengine)
