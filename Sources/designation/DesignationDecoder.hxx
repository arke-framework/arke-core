//
// Created by dami on 15/09/17.
//

#ifndef ARKE_DESIGNATIONDECODER_HXX
#define ARKE_DESIGNATIONDECODER_HXX

#include "Designation.hxx"
#include "json/JSONDecoder.hxx"

namespace arke {

    /// \brief Designation decoder
    struct DesignationDecoder {

        /// \brief Decode dependency from json object
        /// \param object JSON object
        /// \return Decoded object
        DesignationPtr decode(json object);
    };

}

#endif //ARKE_DESIGNATIONDECODER_HXX
