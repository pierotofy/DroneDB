﻿/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include <mio.h>
#include <registryutils.h>

#include <algorithm>
#include <optional>
#include <utility>
#include <vector>

#include "dbops.h"
#include "exceptions.h"

namespace ddb {


void clone(const TagComponents& tag, const std::string& folder) {
    std::cout << "Registry = " << tag.registryUrl << std::endl;
    std::cout << "Dataset = " << tag.dataset << std::endl;
    std::cout << "Organization = " << tag.organization << std::endl;
    std::cout << "Folder = " << folder << std::endl;

    auto reg = Registry(tag.registryUrl);

    try {
        reg.clone(tag.organization, tag.dataset, folder);
    } catch (const ddb::AuthException&) {
        // Try logging-in
        const auto username = utils::getPrompt("Username: ");
        const auto password = utils::getPass("Password: ");

        if (reg.login(username, password).length() > 0) {
            reg.clone(tag.organization, tag.dataset, folder);
            
        } else {
            throw AuthException("Cannot authenticate with " +
                                reg.getUrl());
        }
    } catch (const AppException& e) {
        throw e;
    }

}

}  // namespace ddb
