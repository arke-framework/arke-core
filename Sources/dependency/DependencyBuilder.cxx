//
// Created by dami on 16/09/17.
//

#include "DependencyBuilder.hxx"

namespace arke {

    DependencyBuilder &DependencyBuilder::designation(DesignationPtr designation) {
        this->designation_ = designation;
        return *this;
    }

    DependencyBuilder &DependencyBuilder::version(const std::string &version) {
        this->version_ = version;
        return *this;
    }

    DependencyPtr DependencyBuilder::build() {

        if (!designation_) {
            throw std::invalid_argument{"Unable to create a dependency without designation"};
        }

        // Normalize version
        if (version_.empty()) {
            version_ = "*";
        }

        return std::make_shared<Dependency>(designation_, version_);
    }
}