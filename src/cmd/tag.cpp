/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <iostream>
#include "fs.h"
#include "tag.h"
#include "dbops.h"

namespace cmd {

void Tag::setOptions(cxxopts::Options &opts) {
    // clang-format off
    opts
    .positional_help("[args]")
    .custom_help("tag [tag]")
    .add_options()
    ("t,tag", "New tag", cxxopts::value<std::string>()->default_value(""));

    // clang-format on
    opts.parse_positional({"tag"});
}

std::string Tag::description() {
    return "Shows or sets the tag.\nShow: ddb tag.\nSet: ddb tag <org>/<dataset>\nor: ddb tag <server>/<org>/<dataset>";
}

void Tag::run(cxxopts::ParseResult &opts) {

    auto tag = opts["tag"].as<std::string>();

    std::cout << "Tag: " << tag << std::endl;
    
}

}

