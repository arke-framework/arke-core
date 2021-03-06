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
 * DependencyDecoder.cxx
 *
 *  Created on: 16/09/2017
 *      Author: dami@creabox.net
 */

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