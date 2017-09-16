//
// Created by dami on 16/09/17.
//

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
        explicit Dependency(DesignationPtr designation, const std::string version);

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
