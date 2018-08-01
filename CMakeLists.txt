project(PCB-Autorouter-EE273)


add_executable(autorouter
  CImg.cpp Components.cpp Interface.cpp Neighbour.cpp Node.cpp Path.cpp
  #source.cpp
  #main.cpp 
  )
target_link_libraries(autorouter X11 pthread)
