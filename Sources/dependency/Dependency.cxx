//
// Created by dami on 16/09/17.
//

#include "Dependency.hxx"

namespace arke {

    Dependency::Dependency(DesignationPtr designation, const std::string &version) :
            designation_(designation), version_(version) {

    }

    DesignationPtr Dependency::designation() const {
        return designation_;
    }

    const std::string &Dependency::version() const {
        return version_;
    }

    bool Dependency::operator==(const Dependency &rhs) const {
        
        if (*designation_ != *rhs.designation_) {
            return false;
        }

        if (version_ != rhs.version_) {
            return false;
        }

        return true;
    }

    bool Dependency::operator!=(const Dependency &rhs) const {
        return !(rhs == *this);
    }

    // Override operator
    std::ostream &operator<<(std::ostream &ostream, const Dependency &dependency) {

        ostream << "{";
        ostream << "'designation':" << *dependency.designation_ << ",";
        ostream << "'version':'" << dependency.version_;
        ostream << "'}";

        return ostream;
    }
}