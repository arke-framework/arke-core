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
 * DesignationEncoder.hxx
 *
 *  Created on: 15/09/2017
 *      Author: dami@creabox.net
 */

#ifndef ARKE_DESIGNATIONENCODER_HXX
#define ARKE_DESIGNATIONENCODER_HXX

#include "Designation.hxx"
#include "json/JSONEncoder.hxx"

namespace arke {

    /// \brief Designation encoder
    struct DesignationEncoder {

        json encode(DesignationPtr designation);
    };

}

#endif //ARKE_DESIGNATIONENCODER_HXX
