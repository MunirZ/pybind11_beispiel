#include <pybind11/pybind11.h>
#include "math.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(pybind11_beispiel, m) {
    m.def("add", &add, "A function which adds two numbers");

    m.def("subtract", [](int i, int j) { return i - j; }, "Lambda Expression to subtract numbers");

    py::class_<Point>(m, "Point")
        .def(py::init<const double, const double>())
        .def_readwrite("x_coordinate", &Point::x_coordinate)
        .def_readwrite("y_coordinate", &Point::y_coordinate);

    py::class_<Rectangle>(m, "Rectangle")
        .def(py::init<const Point&, const Point&>())
        .def_readwrite("point_a", &Rectangle::point_a)
        .def_readwrite("point_b", &Rectangle::point_b)
        .def("get_height", &Rectangle::get_height)
        .def("get_width", &Rectangle::get_width);

    m.attr("__version__") = "0.0.1";
}