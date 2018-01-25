cmake_minimum_required(VERSION 3.8)
project(Task_07)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_subdirectory(src/client/gtest_src/googletest-release-1.8.0)
include_directories(src/client/gtest_src/googletest-release-1.8.0/googletest/include)
include_directories(src/client/gtest_src/googletest-release-1.8.0/googlemock/include)

set(CLIENT_FILES src/client/include/Player.h src/client/src/Position.cpp src/client/include/Position.h src/client/include/Player.h src/client/src/HumanPlayer.cpp src/client/include/HumanPlayer.h src/client/src/Board.cpp src/client/include/Board.h src/client/src/Logic.cpp src/client/include/Logic.h src/client/src/ClassicLogic.cpp src/client/include/ClassicLogic.h src/client/src/ReversiGame.cpp src/client/include/ReversiGame.h src/client/include/Printer.h src/client/src/ConsolePrinter.cpp src/client/include/ConsolePrinter.h src/client/include/PlayerColor.h src/client/src/AIPlayer.cpp src/client/include/AIPlayer.h src/client/src/LocalPlayer.cpp src/client/include/LocalPlayer.h src/client/src/ClientConfigParser.cpp src/client/include/ClientConfigParser.h src/client/src/RemotePlayer.cpp src/client/include/RemotePlayer.h src/client/src/Convert.cpp src/client/include/Convert.h src/client/src/Client.cpp src/client/include/Client.h)
set(SERVER_FILES src/server/src/Game.cpp src/server/include/Game.h src/server/include/ServerPrinter.h src/server/src/ConsoleServerPrinter.cpp src/server/include/ConsoleServerPrinter.h src/server/src/ServerConfigParser.cpp src/server/include/ServerConfigParser.h src/server/include/Command.h src/server/src/Server.cpp src/server/include/Server.h src/server/src/CommandStart.cpp src/server/include/CommandStart.h src/server/src/CommandListGames.cpp src/server/include/CommandListGames.h src/server/src/CommandJoin.cpp src/server/include/CommandJoin.h src/server/src/GameManager.cpp src/server/include/GameManager.h src/server/src/Convert.cpp src/server/include/Convert.h src/server/src/Communication.cpp src/server/include/Communication.h src/server/src/CommandManager.cpp src/server/include/CommandManager.h src/server/src/ClientHandler.cpp src/server/include/ClientHandler.h src/server/include/Task.h src/server/src/ThreadPool.cpp src/server/include/ThreadPool.h)
set(TEST_FILES src/client/test/BoardTest.cpp src/client/test/BoardStates.h src/client/test/ClassicLogicTest.cpp  src/client/test/AIPlayerTest.cpp)

add_definitions(-DCLION_RUN)

add_executable(Client ${CLIENT_FILES} src/client/src/main.cpp)

add_executable(Tests ${CLIENT_FILES} ${TEST_FILES} src/client/test/main.cpp)
target_link_libraries(Tests gtest gtest_main gmock)

add_executable(Server ${SERVER_FILES} src/server/src/main.cpp)
