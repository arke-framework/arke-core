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
 * Dependency.hxx
 *
 *  Created on: 16/09/2017
 *      Author: dami@creabox.net
 */

#ifndef ARKE_DEPENDENCY_HXX
#define ARKE_DEPENDENCY_HXX

#include <string>
#include <memory>
#include <designation/Designation.hxx>

namespace arke {

    class Dependency;

    using DependencyPtr = std::shared_ptr<Dependency>;

    /// \brief Dependency
    class Dependency {

        friend std::ostream &operator<<(std::ostream &, const Dependency &);

    private:

        /// \brief Designation
        DesignationPtr designation_;

        /// \brief Version pattern
        std::string version_;

    public:

        /// Constructor
        /// \param designation Correct designation
        /// \param version Correct pattern
        explicit Dependency(DesignationPtr designation, const std::string &version);

    public:

        /// \return Designation
        DesignationPtr designation() const;

        /// \return Version pattern
        const std::string &version() const;

    public:

        /// \brief Override operator==
        /// \param rhs other object
        /// \return boolean
        bool operator==(const Dependency &rhs) const;

        /// \brief Override operator!=
        /// \param rhs other object
        /// \return boolean
        bool operator!=(const Dependency &rhs) const;
    };

    // Override operator
    std::ostream &operator<<(std::ostream &ostream, const Dependency &dependency);
}

#endif //ARKE_DEPENDENCY_HXX
