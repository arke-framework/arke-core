//
// Created by dami on 16/09/17.
//

#include <designation/DesignationEncoder.hxx>
#include "DependencyEncoder.hxx"

namespace arke {

    json DependencyEncoder::encode(DependencyPtr dependency) {

        if (dependency) {

            // Encode designation
            auto object = DesignationEncoder{}.encode(dependency->designation());

            // Encode version
            object["version"] = dependency->version();

            return object;

        } else {
            return json{};
        }
    }
}