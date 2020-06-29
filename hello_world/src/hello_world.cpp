//
// Created by admin on 2020/6/18.
//

#include "../inc/hello_world.h"

std::string hello_world::sayHelloWorld() {
    std::string result = hello::sayHello();
    return result.append(" ").append(world::sayWorld()).append("!");
}
