//
// Created by dami on 15/09/17.
//

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
        DesignationBuilder & name(const std::string & name);

        /// \brief Set organization
        /// \param name Organization name
        /// \return Current builder
        DesignationBuilder & organization(const std::string & name);

        /// \return Designation
        DesignationPtr build();
    };

}

#endif //ARKE_DESIGNATIONBUILDER_HXX
