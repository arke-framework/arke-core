//
// Created by dami on 16/09/17.
//

#ifndef ARKE_DEPENDENCYDECODER_HXX
#define ARKE_DEPENDENCYDECODER_HXX

#include "json/JSONDecoder.hxx"
#include "Dependency.hxx"

namespace arke {

    /// \brief Json decoder for dependency
    class DependencyDecoder {

    public:

        /// \brief Decode a dependency
        /// \param json JSON containing dependency informations
        /// \return Decoded dependency
        DependencyPtr decode(const json & json);
    };

}

#endif //ARKE_DEPENDENCYDECODER_HXX
