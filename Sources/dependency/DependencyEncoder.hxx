//
// Created by dami on 16/09/17.
//

#ifndef ARKE_DEPENDENCYENCODER_HXX
#define ARKE_DEPENDENCYENCODER_HXX

#include "json/JSONEncoder.hxx"
#include "Dependency.hxx"

namespace arke {

    /// \brief Json encoder for dependency
    class DependencyEncoder {

    public:

        /// \brief Encode a dependency
        /// \param dependency Dependency to encode
        /// \return Json containing encoded dependency
        json encode(DependencyPtr dependency);
    };

}


#endif //ARKE_DEPENDENCYENCODER_HXX
