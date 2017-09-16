//
// Created by dami on 16/09/17.
//

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
