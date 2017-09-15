//
// Created by dami on 15/09/17.
//

#include "DesignationDecoder.hxx"
#include "DesignationBuilder.hxx"

namespace arke {

    // Decode dependency from json object
    DesignationPtr DesignationDecoder::decode(json object) {
        if (!object.is_object()) {
            return DesignationPtr{};
        }

        // Create builder
        DesignationBuilder builder{};

        builder.organization(object["organization"]);
        builder.name(object["name"]);

        return builder.build();
    }
}