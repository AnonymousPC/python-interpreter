#pragma once

constexpr number_type auto cross ( const array_type auto& left, const array_type auto& right )
    requires ( left. dimension() == 1 ) and number_type<left_value_type > and
             ( right.dimension() == 1 ) and number_type<right_value_type>
{
    #if debug
        if ( left.size() != 3 or right.size() != 3 )
            throw value_error("cannot cross vector of size {} and vector of size {}: size must be 3", left.size(), right.size());
    #endif

    return array { left[2] * right[3] - left[3] * right[2],
                   left[3] * right[1] - left[1] * right[3],
                   left[1] * right[2] - left[2] * right[1] };
}
