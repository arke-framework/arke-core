//
// Created by dami on 15/09/17.
//

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
