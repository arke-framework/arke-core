//
// Created by dami on 15/09/17.
//

#ifndef ARKE_DESIGNATIONENCODER_HXX
#define ARKE_DESIGNATIONENCODER_HXX

#include "Designation.hxx"
#include "json/JSONEncoder.hxx"

namespace arke {

    /// \brief Designation encoder
    struct DesignationEncoder {

        json encode(DesignationPtr designation);
    };

}

#endif //ARKE_DESIGNATIONENCODER_HXX
