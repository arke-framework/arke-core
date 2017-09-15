//
// Created by dami on 15/09/17.
//

#ifndef ARKE_JSONDECODER_HXX
#define ARKE_JSONDECODER_HXX

#include <memory>
#include <istream>
#include "json.hpp"

namespace arke {

    using json = nlohmann::json;

    /// \brief JSON decoder
    struct JSONDecoder {

        /// \brief Decode a json stream to object
        /// \param stream Input stream
        /// \return Object pointer
        template <class Decoder, class Object>
        static std::shared_ptr<Object> decode(std::istream & stream) {
            json object;
            stream >> object;
            return Decoder{}.decode(object);
        }
    };

}

#endif //ARKE_JSONDECODER_HXX
