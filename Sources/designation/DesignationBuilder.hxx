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
 * DesignationBuilder.hxx
 *
 *  Created on: 15/09/2017
 *      Author: dami@creabox.net
 */

#ifndef ARKE_DESIGNATIONBUILDER_HXX
#define ARKE_DESIGNATIONBUILDER_HXX

#include "Designation.hxx"

namespace arke {

    /// \brief Designation builder
    class DesignationBuilder {

    private:

        /// \brief Organization name
        std::string organization_;

        /// \brief Package name
        std::string name_;

    public:

        /// \brief Set name
        /// \param name Package name
        /// \return Current builder
        DesignationBuilder &name(const std::string &name);

        /// \brief Set organization
        /// \param name Organization name
        /// \return Current builder
        DesignationBuilder &organization(const std::string &name);

        /// \return Designation
        DesignationPtr build();
    };

}

#endif //ARKE_DESIGNATIONBUILDER_HXX
