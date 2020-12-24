cmake_minimum_required(VERSION 3.15)
project(chat_system C)

set(CMAKE_C_STANDARD 99)

add_executable(chat_system service/controller/monitor.c service/controller/listen.c service/controller/include/listen.h service/common/common.c service/include/common.h service/common/controller.c service/include/controller.h service/common/persistence.c service/include/persistence.h service/main.c service/main.h service/persistence/account_sql.c service/persistence/include/account_sql.h service/controller/account_ctl.c service/controller/include/account_ctl.h)
#add_executable(chat_system client/view/home_view.c client/view/include/home_view.h client/view/account_view.c client/view/include/account_view.h client/common/view.c client/include/view.h client/include/common.h client/include/server.h client/main.c client/main.h client/service/connect_srv.c client/service/include/connect_srv.h client/view/friend_view.c client/view/include/friend_view.h client/service/friend_srv.c client/service/include/friend_srv.h client/service/account_srv.c client/service/include/account_srv.h client/common/common.c client/common/server.c client/service/listens.c client/service/include/listens.h)