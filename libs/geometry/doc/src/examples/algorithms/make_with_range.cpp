// Boost.Geometry (aka GGL, Generic Geometry Library)
//
// Copyright Barend Gehrels 2011, Geodan, Amsterdam, the Netherlands
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// Quickbook Example

//[make_with_range
//` Using make to construct a linestring with two different range types

#include <iostream>

#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/adapted/c_array_cartesian.hpp> /*< Necessary to register a C array like {1,2} as a point >*/


int main()
{
    using boost::geometry::make;

    typedef boost::geometry::model::d2::point_xy<double> point;
    typedef boost::geometry::model::linestring<point> linestring;

    double coordinates[][2] = {{1,2}, {3,4}, {5, 6}}; /*< Initialize with C array points >*/
    linestring ls = make<linestring>(coordinates);
    std::cout << boost::geometry::dsv(ls) << std::endl;

    point points[3] = { make<point>(9,8), make<point>(7,6), make<point>(5,4) }; /*< Construct array with points, using make which should work for any point type >*/
    std::cout << boost::geometry::dsv(make<linestring>(points)) << std::endl; /*< Construct linestring with point-array and output it as Delimiter Separated Values >*/

    return 0;
}

//]


//[make_with_range_output
/*`
Output:
[pre
((1, 2), (3, 4), (5, 6))
((9, 8), (7, 6), (5, 4))
]
*/
//]