#pragma once

/// Class string_algo

template < class string_type,
           class char_type >
class string_algo
{
    private: // Traits
        constexpr static const bool is_view = not requires { &string_type::resize; };
        using views          = std::conditional<not aux::string_view_type<string_type>/*see string_global.cpp*/,basic_string_range_view<char_type>,basic_string_view<char_type>>::type;
        using string_view    = basic_string_view<char_type>;
        using regex          = basic_regex<char_type>;
        using array_of_views = array_line<views>;
        using encode_type    = std::text_encoding::id;

    public: // Abbreviation
        constexpr int            size        ( ) const;
        constexpr bool           empty       ( ) const;
        constexpr decltype(auto) begin       ( );
        constexpr decltype(auto) begin       ( ) const;
        constexpr decltype(auto) end         ( );
        constexpr decltype(auto) end         ( ) const;
        constexpr decltype(auto) operator [] ( int );
        constexpr decltype(auto) operator [] ( int ) const;

    public: // String algo
        constexpr       bool           begins_with     ( const string_view& )                     const;
        constexpr       string_type&   capitalize      ( );
        constexpr       string_type&   center          ( int,  char_type = ' ' )                        requires ( not is_view );
        constexpr       string_type&   encode          ( encode_type, encode_type )                     requires ( not is_view ) and std::same_as<char_type,char>;
        constexpr       bool           ends_with       ( const string_view& )                     const;
        constexpr       string_type&   expand_tabs     ( int = 8 )                                      requires ( not is_view );
        constexpr       string_type&   format          ( const auto&... args )                          requires ( not is_view ) and std::same_as<char_type,char> and ( ( std::formattable<decltype(args),char_type> or std::constructible_from<string_type,decltype(args)> ) and ... );
        constexpr       bool           is_alnum        ( )                                        const;
        constexpr       bool           is_alpha        ( )                                        const;
        constexpr       bool           is_ascii        ( )                                        const;
        constexpr       bool           is_decimal      ( )                                        const;
        constexpr       bool           is_digit        ( )                                        const;
        constexpr       bool           is_identifier   ( )                                        const;
        constexpr       bool           is_lower        ( )                                        const;
        constexpr       bool           is_space        ( )                                        const;
        constexpr       bool           is_title        ( )                                        const;
        constexpr       bool           is_upper        ( )                                        const;
        constexpr       string_type&   join            ( const auto& cont )                             requires ( not is_view and requires { string_view(*cont.begin()); } );
        constexpr       string_type&   left_justify    ( int,  const string_view& = ' ' )               requires ( not is_view );
        constexpr       string_type&   left_strip      ( const string_view& = ' ' )                     requires ( not is_view );
        constexpr       string_type&   lower           ( );
        constexpr       array_of_views partition       ( const string_view& );
        constexpr const array_of_views partition       ( const string_view& )                     const;
        constexpr       string_type&   right_justify   ( int,  const string_view& = ' ' )               requires ( not is_view );
        constexpr       array_of_views right_partition ( const string_view& );
        constexpr const array_of_views right_partition ( const string_view& )                     const;
        constexpr       array_of_views right_split     ( const string_view& = ' ', int = -1 );
        constexpr const array_of_views right_split     ( const string_view& = ' ', int = -1 )     const;
        constexpr       string_type&   right_strip     ( const string_view& = ' ' )                     requires ( not is_view );
        constexpr       array_of_views split           ( const string_view& = ' ', int = -1 );
        constexpr const array_of_views split           ( const string_view& = ' ', int = -1 )     const;
        constexpr       array_of_views split_lines     ( );
        constexpr const array_of_views split_lines     ( )                                        const;
        constexpr       bool           starts_with     ( const string_view& )                     const;
        constexpr       string_type&   strip           ( const string_view& = ' ' )                     requires ( not is_view );
        constexpr       string_type&   swap_case       ( );
        constexpr       string_type&   title           ( );
        constexpr       string_type&   translate       ( const map_type<char,string_view> auto& )       requires ( not is_view );
        constexpr       string_type&   upper           ( );
        constexpr       string_type&   zero_fill       ( int )                                          requires ( not is_view );

    public: // Array algo (update)
        constexpr       bool           contains        ( const string_view& )                     const;
        constexpr       int            count           ( const string_view& )                     const;
        constexpr       bool           exist           ( const string_view& )                     const;
        constexpr       int            find            ( const string_view& )                     const;
        constexpr       bool           none            ( const string_view& )                     const;
        constexpr       string_type&   replace         ( const string_view&, const string_view& )       requires ( not is_view );
        constexpr       string_type&   remove          ( const string_view& )                           requires ( not is_view );
        constexpr       int            right_find      ( const string_view& )                     const;
        constexpr       vector<int>    where           ( const string_view& )                     const;

    public: // Regex
        constexpr       bool           all             ( const regex& )                           const;
        constexpr       bool           contains        ( const regex& )                           const;
        constexpr       int            count           ( const regex& )                           const;
        constexpr       bool           exist           ( const regex& )                           const;
        constexpr       views          find            ( const regex& );
        constexpr const views          find            ( const regex& )                           const;
        constexpr       bool           match           ( const regex& )                           const;
        constexpr       bool           none            ( const regex& )                           const;
        constexpr       string_type&   replace         ( const regex&, const string_view& )             requires ( not is_view );
        constexpr       string_type&   remove          ( const regex& )                                 requires ( not is_view );
        constexpr       views          right_find      ( const regex& );
        constexpr const views          right_find      ( const regex& )                           const;
        constexpr       array_of_views split           ( const regex& );
        constexpr const array_of_views split           ( const regex& )                           const;
        constexpr       array_of_views where           ( const regex& );
        constexpr const array_of_views where           ( const regex& )                           const;

    protected: // Strlen
        constexpr static int strlen ( const char_type* );

    private: // Format Auxiliary
        constexpr static decltype(auto) make_const_ref   ( const auto& );
        constexpr static decltype(auto) make_formattable ( const auto& );
};


/// Global



constexpr bool is_alnum      ( char_type auto );
constexpr bool is_alpha      ( char_type auto );
constexpr bool is_ascii      ( char_type auto );
constexpr bool is_decimal    ( char_type auto );
constexpr bool is_digit      ( char_type auto );
constexpr bool is_identifier ( char_type auto ) = delete;
constexpr bool is_lower      ( char_type auto );
constexpr bool is_space      ( char_type auto );
constexpr bool is_title      ( char_type auto ) = delete;
constexpr bool is_upper      ( char_type auto );
constexpr auto lower         ( char_type auto );
constexpr auto upper         ( char_type auto );



constexpr bool is_alnum      ( const string_type auto& );
constexpr bool is_alpha      ( const string_type auto& );
constexpr bool is_ascii      ( const string_type auto& );
constexpr bool is_decimal    ( const string_type auto& );
constexpr bool is_digit      ( const string_type auto& );
constexpr bool is_identifier ( const string_type auto& );
constexpr bool is_lower      ( const string_type auto& );
constexpr bool is_space      ( const string_type auto& );
constexpr bool is_title      ( const string_type auto& );
constexpr bool is_upper      ( const string_type auto& );
constexpr auto lower         ( const string_type auto& );
constexpr auto upper         ( const string_type auto& );



#include "string_algo.cpp"

