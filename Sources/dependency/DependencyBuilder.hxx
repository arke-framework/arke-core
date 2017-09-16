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
 * DependencyBuilder.hxx
 *
 *  Created on: 16/09/2017
 *      Author: dami@creabox.net
 */

#ifndef ARKE_DEPENDENCYBUILDER_HXX
#define ARKE_DEPENDENCYBUILDER_HXX

#include <string>
#include "Dependency.hxx"

namespace arke {

    /// \brief Object used to create a valid dependency
    class DependencyBuilder {

    private:

        /// \brief Designation to use
        DesignationPtr designation_;

        /// \brief Version pattern
        std::string version_;

    public:

        /// \brief Designation to use
        /// \param designation Designation (may be invalid)
        /// \return Current builder
        DependencyBuilder & designation(DesignationPtr designation);

        /// \brief Version pattern to use
        /// \param version Pattern (may be empty for *)
        /// \return Current builder
        DependencyBuilder & version(const std::string &version);

        /// \return Build dependency
        DependencyPtr build();
    };

}

#endif //ARKE_DEPENDENCYBUILDER_HXX
