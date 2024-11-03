#include "nlohmann/json.hpp"
#include <memory>

NLOHMANN_JSON_NAMESPACE_BEGIN

// Allows serializing and deserializing contents behind a std::unique_ptr.
// See also: https://github.com/nlohmann/json/issues/975
template <typename T> struct adl_serializer<std::unique_ptr<T>> {
    template <typename BasicJsonType> static void to_json(BasicJsonType& json_value, const std::shared_ptr<T>& ptr)
    {
        if (ptr.get()) {
            json_value = *ptr;
        } else {
            json_value = nullptr;
        }
    }

    template <typename BasicJsonType> static void from_json(const BasicJsonType& json_value, std::shared_ptr<T>& ptr)
    {
        T inner_val = json_value.template get<T>();
        ptr = std::make_unique<T>(std::move(inner_val));
    }
};

NLOHMANN_JSON_NAMESPACE_END