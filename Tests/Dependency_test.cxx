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
 * Dependency_test.cxx
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
#include <dependency/DependencyBuilder.hxx>
#include <dependency/DependencyEncoder.hxx>
#include <dependency/DependencyDecoder.hxx>

using namespace arke;

TEST_CASE("Dependency simple", "[dependency]") {

    // Designation builder
    auto designation = arke::DesignationBuilder{}
            .organization("org")
            .name("package")
            .build();

    REQUIRE("*" == arke::DependencyBuilder{}.designation(designation).build()->version());

    // Create dependency
    auto dependency = arke::DependencyBuilder{}.designation(designation).version("1.2.*").build();

    REQUIRE(*designation == *dependency->designation());
    REQUIRE("package" == designation->name());

    std::stringstream ss1;

    // Encode object
    JSONEncoder::encode<DependencyEncoder, Dependency>(dependency, ss1);

    // Decode object
    auto decoded = JSONDecoder::decode<DependencyDecoder, Dependency>(ss1);

    std::stringstream ss2;
    ss2 << *dependency;

    REQUIRE("{'designation':{'organization':'org','name':'package'},'version':'1.2.*'}" == ss2.str());

    REQUIRE(*dependency == *decoded);
    REQUIRE(*designation == *decoded->designation());
    REQUIRE("1.2.*" == decoded->version());
}
