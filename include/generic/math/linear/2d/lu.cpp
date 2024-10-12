#pragma once

constexpr tuple_type auto lu ( const array_type auto& matrix )
    requires ( matrix.dimension() == 2 ) and ( number_type<matrix_value_type> or complex_type<matrix_value_type> )
{
    if constexpr ( int_type<matrix_value_type> or complex_int_type<matrix_value_type> )
        return lu ( matrix.template as_type<int_to_float_type<matrix_value_type>>() );
    else
        try
        {
            let solver = Eigen::PartialPivLU<decltype(aux::to_eigen(matrix))>(aux::to_eigen(matrix));
            return tuple ( aux::from_eigen(Eigen::Matrix<typename decltype(aux::to_eigen(matrix))::Scalar,Eigen::Dynamic,Eigen::Dynamic>(solver.matrixLU().template triangularView<Eigen::Lower>())),
                           aux::from_eigen(Eigen::Matrix<typename decltype(aux::to_eigen(matrix))::Scalar,Eigen::Dynamic,Eigen::Dynamic>(solver.matrixLU().template triangularView<Eigen::Upper>())),
                           aux::from_eigen(solver.permutationP().toDenseMatrix()) );
        }
        catch ( const std::runtime_error& e )
        {
            throw math_error("cannot lu-decompose matrix: [[from {}]] {}", "eigen", e.what());
        }
}
