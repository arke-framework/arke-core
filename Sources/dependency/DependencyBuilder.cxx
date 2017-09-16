/*
 * Copyright 2017 dami@creabox.net
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * DependencyBuilder.cxx
 *
 *  Created on: 16/09/2017
 *      Author: dami@creabox.net
 */

#include "DependencyBuilder.hxx"

namespace arke {

    DependencyBuilder &DependencyBuilder::designation(DesignationPtr designation) {
        this->designation_ = designation;
        return *this;
    }

    DependencyBuilder &DependencyBuilder::version(const std::string &version) {
        this->version_ = version;
        return *this;
    }

    DependencyPtr DependencyBuilder::build() {

        if (!designation_) {
            throw std::invalid_argument{"Unable to create a dependency without designation"};
        }

        // Normalize version
        if (version_.empty()) {
            version_ = "*";
        }

        return std::make_shared<Dependency>(designation_, version_);
    }
}