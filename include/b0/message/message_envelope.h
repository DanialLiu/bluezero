#ifndef B0__MESSAGE__MESSAGE_ENVELOPE_H__INCLUDED
#define B0__MESSAGE__MESSAGE_ENVELOPE_H__INCLUDED

#include <vector>
#include <string>
#include <utility>
#include <boost/optional.hpp>

#include <b0/message/message.h>

namespace b0
{

namespace message
{

/*!
 * \brief A message envelope used to wrap (optionally: compress) the real message payload
 */
class MessageEnvelope final
{
public:
    //! The payload
    std::string payload;

    //! Size of the uncompressed payload
    size_t content_length;

    //! Compression algorithm name, or blank if no compression
    std::string compression_algorithm;

    //! An optional string indicating the type of the payload
    std::string content_type;

    //! Additional customized headers with priority (most negative appears first)
    std::vector<std::pair<int, std::string> > headers;

public:
    //! \brief Get the value of some header
    boost::optional<std::string> getHeader(const std::string &name);

    //! \brief Parse from a string
    void parseFromString(const std::string &s);

    //! \brief Serialize to a string
    void serializeToString(std::string &s) const;
};

} // namespace message

} // namespace b0

#endif // B0__MESSAGE__MESSAGE_ENVELOPE_H__INCLUDED