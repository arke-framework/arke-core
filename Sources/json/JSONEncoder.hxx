//
// Created by dami on 15/09/17.
//

#ifndef ARKE_JSONENCODER_HXX
#define ARKE_JSONENCODER_HXX

#include <memory>
#include <ostream>
#include "json.hpp"

namespace arke {

    using json = nlohmann::json;

    /// \brief JSON encoder
    struct JSONEncoder {

        /// \brief Decode a json stream to object
        /// \param stream Output stream
        /// \return Object pointer
        template <class Encoder, class Object>
        static void encode(std::shared_ptr<Object> object, std::ostream & stream) {

            if (!object) {
                json jsonObject;
                stream << jsonObject;
            } else {
                stream << Encoder{}.encode(object);
            }
        }
    };

}

#endif //ARKE_JSONENCODER_HXX
