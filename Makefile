rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

CPPSourceCode = $(call rwildcard,Source,*.cpp)
Objects = $(patsubst Source/%.cpp, Build/%.o, $(CPPSourceCode))
Directories = $(wildcard Source/*)

CCOptions = -pthread -std=c++2a -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl

Build/%.o: Source/%.cpp
	@mkdir -p $(@D)
	@g++ -c $^ $(CCOptions) -o $@

nmc: $(Objects)
	@g++ $(Objects) $(CCOptions) -o NMC

run:
	@./NMC