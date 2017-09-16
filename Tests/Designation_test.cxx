//
// Created by dami on 15/09/17.
//

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