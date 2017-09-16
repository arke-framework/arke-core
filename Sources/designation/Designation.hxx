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
 * Designation.hxx
 *
 *  Created on: 15/09/2017
 *      Author: dami@creabox.net
 */

#ifndef ARKE_DESIGNATION_HXX
#define ARKE_DESIGNATION_HXX

#include <memory>
#include <ostream>
#include <string>

namespace arke {

    class Designation;

    using DesignationPtr = std::shared_ptr<Designation>;

    /// \brief Designation
    class Designation {

        friend std::ostream &operator<<(std::ostream &, const Designation &);

    private:

        /// \brief Organization name
        std::string organization_;

        /// \brief Package name
        std::string name_;

    public:

        /// \brief Constructor
        /// \param name Package name
        /// \param organization Organization name
        explicit Designation(const std::string &organization, const std::string &name);

        /// \return Organization name
        const std::string &organization() const;

        /// \return Package name
        const std::string &name() const;

    public:

        /// \brief Override operator==
        /// \param rhs other object
        /// \return boolean
        bool operator==(const Designation &designation);

        /// \brief Override operator!=
        /// \param rhs other object
        /// \return boolean
        bool operator!=(const Designation &designation) {
            return !(*this == designation);
        }
    };

    // Override operator
    std::ostream &operator<<(std::ostream &ostream, const Designation &designation);
}

#endif //ARKE_DESIGNATION_HXX
