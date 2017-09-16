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
 * Designation_test.cxx
 *
 *  Created on: 15/09/2017
 *      Author: dami@creabox.net
 */

#include "catch.hpp"

#include <sstream>

#include <json/JSONEncoder.hxx>
#include <json/JSONDecoder.hxx>

#include <designation/Designation.hxx>
#include <designation/DesignationBuilder.hxx>
#include <designation/DesignationEncoder.hxx>
#include <designation/DesignationDecoder.hxx>

using namespace arke;

TEST_CASE("Designation simple", "[designation]") {

    // Designation builder
    auto designation = arke::DesignationBuilder{}
            .organization("org")
            .name("package")
            .build();

    REQUIRE("org" == designation->organization());
    REQUIRE("package" == designation->name());

    std::stringstream ss1;

    // Encode object
    JSONEncoder::encode<DesignationEncoder, Designation>(designation, ss1);

    // Decode object
    auto decoded = JSONDecoder::decode<DesignationDecoder, Designation>(ss1);

    std::stringstream ss2;
    ss2 << *designation;

    REQUIRE("{'organization':'org','name':'package'}" == ss2.str());

    REQUIRE(*designation == *decoded);
    REQUIRE("org" == decoded->organization());
    REQUIRE("package" == decoded->name());
}