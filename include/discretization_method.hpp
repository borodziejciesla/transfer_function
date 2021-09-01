#ifndef TRANSFER_FUNCTION_INCLUDE_DISCRETIZATION_METHOD_HPP_
#define TRANSFER_FUNCTION_INCLUDE_DISCRETIZATION_METHOD_HPP_

namespace tf_core
{
    enum class DiscretizationMethod
    {
        Forward = 0u,
        Backward = 1u,
        Tustin = 2u
    };
}   //  namespace tf_core

#endif // !TRANSFER_FUNCTION_INCLUDE_DISCRETIZATION_METHOD_HPP_
