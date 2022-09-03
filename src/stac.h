/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */
#ifndef STAC_H
#define STAC_H

#include <string>
#include "ddb_export.h"
#include "dbops.h"
#include <vector>

namespace ddb{

DDB_DLL std::string generateStac(const std::string &ddbPath,
                                 const std::string &entry = "",
                                 const std::string &stacRoot = ".",
                                 const std::string &stacEndpoint = "./stac",
                                 const std::string &downloadEndpoint = "./download",
                                 const std::string &id = "");

}

#endif // STAC_H
