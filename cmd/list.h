/* Copyright 2019 MasseranoLabs LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */
#ifndef LIST_H
#define LIST_H

#include <map>
#include "build.h"
#include "init.h"
#include "add.h"
#include "remove.h"
#include "sync.h"
#include "geoproject.h"

namespace cmd {

std::map<std::string, Command*> commands = {
    {"build", new Build()},
    {"init", new Init()},
    {"add", new Add()},
    {"remove", new Remove()},
    {"sync", new Sync()},
    {"geoproject", new GeoProject()}
};

std::map<std::string, std::string> aliases = {
    {"rm", "remove"},
    {"r", "remove"},
    {"i", "init"},
    {"a", "add"},
    {"s", "sync"},
    {"gp", "geoproject"}
};

}

#endif // LIST_H
