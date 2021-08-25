#include "polynomial_discretizer.hpp"

namespace tf_core
{
    PolynomialDiscretizer::DiscretizedPolynomial PolynomialDiscretizer::Discretize(const Polynomial & continuous,
        const float discretization_time,
        const DiscretizationMethod discretization_method) {
        auto discrete_polynomial = std::make_tuple(Polynomial({1.0f}) * continuous.GetCoefficients().at(0), Polynomial({1.0f}));

        // TODO: implement higher orders
        
        return discrete_polynomial;
    }
}   // namespace tf_core
