//
// Created by dami on 15/09/17.
//

#include "DesignationEncoder.hxx"

namespace arke {

    // Encode designation
    json DesignationEncoder::encode(DesignationPtr designation) {

        json object;

        if (designation) {

            // Set organization name
            object["organization"] = designation->organization();

            // Set package name
            object["name"] = designation->name();
        }

        return object;
    }
}