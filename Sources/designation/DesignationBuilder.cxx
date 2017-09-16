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
 * DesignationBuilder.cxx
 *
 *  Created on: 15/09/2017
 *      Author: dami@creabox.net
 */

#include "DesignationBuilder.hxx"

namespace arke {

    // Set name
    DesignationBuilder &DesignationBuilder::name(const std::string &name) {
        this->name_ = name;
        return *this;
    }

    // Set organization
    DesignationBuilder &DesignationBuilder::organization(const std::string &organization) {
        this->organization_ = organization;
        return *this;
    }

    DesignationPtr DesignationBuilder::build() {

        // Test organization name
        if (organization_.empty()) {
            throw std::invalid_argument{"Create package without organization"};
        }

        // Test package name
        if (name_.empty()) {
            throw std::invalid_argument{"Create package without name"};
        }

        // Create designation
        return std::make_shared<Designation>(organization_, name_);
    }
}