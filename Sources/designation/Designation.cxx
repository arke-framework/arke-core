//
// Created by dami on 15/09/17.
//

#include "Designation.hxx"

namespace arke {

    // Constructor
    Designation::Designation(const std::string &organization, const std::string &name) :
            organization_(organization), name_(name) {

    }

    // Organization name
    const std::string &Designation::organization() const {
        return organization_;
    }

    // Package name
    const std::string &Designation::name() const {
        return name_;
    }

    // Override ==
    bool Designation::operator==(const Designation &designation) {

        if (name_ != designation.name_) {
            return false;
        }

        if (organization_ != designation.organization_) {
            return false;
        }

        return true;
    }

    // Override operator
    std::ostream &operator<<(std::ostream &ostream, const Designation &designation) {

        ostream << "{";
        ostream << "'organization':'" << designation.organization_ << "',";
        ostream << "'name':'" << designation.name_;
        ostream << "'}";

        return ostream;
    }

}