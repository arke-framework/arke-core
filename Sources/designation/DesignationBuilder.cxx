//
// Created by dami on 15/09/17.
//

#include "DesignationBuilder.hxx"

namespace arke {

    // Set name
    DesignationBuilder &DesignationBuilder::name(const std::string &name) {
        this->name_ = name;
        return *this;
    }

    // Set organization
    DesignationBuilder &DesignationBuilder::organization(const std::string &organization) {
        this->organization_ = organization;
        return *this;
    }

    DesignationPtr DesignationBuilder::build() {

        // Test organization name
        if (organization_.empty()) {
            throw std::invalid_argument{"Create package without organization"};
        }

        // Test package name
        if (name_.empty()) {
            throw std::invalid_argument{"Create package without name"};
        }

        // Create designation
        return std::make_shared<Designation>(organization_, name_);
    }
}