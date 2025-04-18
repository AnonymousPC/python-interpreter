#pragma once

/// Class pair

// Core

template < class type1, class type2 >
constexpr pair<type1,type2>::pair ( type1 init_x, type2 init_y )
    extends x ( std::forward<decltype(init_x)>(init_x) ),
            y ( std::forward<decltype(init_y)>(init_y) )
{

}

template < class type1, class type2 >
constexpr type1& pair<type1,type2>::key ( )
{
    return x;
}


template < class type1, class type2 >
constexpr const type1& pair<type1,type2>::key ( ) const
{
    return x;
}

template < class type1, class type2 >
constexpr type2& pair<type1,type2>::value ( )
{
    return y;
}

template < class type1, class type2 >
constexpr const type2& pair<type1,type2>::value ( ) const
{
    return y;
}

// Conversion

template < class type1, class type2 >
template < class type3, class type4 >
constexpr pair<type1,type2>::pair ( const pair<type3,type4>& cvt )
    requires ( std::is_convertible<type3,type1>::value and std::is_convertible<type4,type2>::value but not ( std::is_same<type1,type3>::value and std::is_same<type2,type4>::value ) )
    extends x ( type1 ( cvt.key()   ) ),
            y ( type2 ( cvt.value() ) )
{

}

template < class type1, class type2 >
template < class type3, class type4 >
constexpr pair<type1,type2>::pair ( const pair<type3,type4>& cvt )
    requires ( std::is_constructible<type1,type3>::value and std::is_constructible<type2,type4>::value but ( not std::is_convertible<type3,type1>::value or not std::is_convertible<type4,type2>::value ) )
    extends x ( type1 ( cvt.key()   ) ),
            y ( type2 ( cvt.value() ) )
{

}




// For map_pair

template < class type1, class type2 >
template < class type3, class type4 >
constexpr pair<type1,type2>::pair ( pair<type3,type4>&& cvt )
    requires ( ( ( std::is_const<type1>::value and std::is_same<typename std::decay<type1>::type,typename std::decay<type3>::type>::value ) or
                 ( std::is_const<type2>::value and std::is_same<typename std::decay<type2>::type,typename std::decay<type4>::type>::value ) ) and
                 ( not std::is_lvalue_reference<type3>::value and not std::is_lvalue_reference<type4>::value ) )
    extends x ( std::move ( cvt.key  () ) ),
            y ( std::move ( cvt.value() ) )
{

}














