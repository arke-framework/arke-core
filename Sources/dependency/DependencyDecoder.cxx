//
// Created by dami on 16/09/17.
//

#include <designation/DesignationDecoder.hxx>
#include "DependencyDecoder.hxx"
#include "DependencyBuilder.hxx"

namespace arke {

    DependencyPtr DependencyDecoder::decode(const json &json) {

        DependencyBuilder builder{};

        // Decode designation
        builder.designation(
                DesignationDecoder{}.decode(json)
        );

        // Decode version
        builder.version(json["version"]);

        return builder.build();
    }
}