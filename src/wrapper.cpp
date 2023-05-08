#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <pybind11/stl.h>
#include <iostream>
#include <vector>
#include <thread>

#include "math.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

class DataUpdater {
public:
    using CallbackFunction = std::function<void(const std::vector<double>&)>;

    void set_callback(const CallbackFunction& callback) {
        callback_ = callback;
    }

    void update_data(const std::vector<double>& data) {
        std::cout << "Aktualisiere Daten in C++..." << std::endl;
        data_ = data;
        if (callback_) {
            callback_(data_);
        }
    }

private:
    CallbackFunction callback_;
    std::vector<double> data_;
};

void generate_data() 
{
    DataUpdater updater;

    // Registriere den Callback
    updater.set_callback([](const std::vector<double>& data) {
        std::cout << "Received data from Python: ";
        for (auto d : data) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    });

    // Generiere und aktualisiere die Daten
    double var1, var2, var3;
    int counter = 0;
    for (size_t i; i < 10; i++) {
        var1 += 1.8;
        var2 += 2.4;
        var3 += 3.2;
        std::vector<double> data{ var1, var2, var3 };
        updater.update_data(data);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

PYBIND11_MODULE(pybind11_beispiel, m) {
    py::class_<DataUpdater>(m, "DataUpdater")
        .def(py::init<>())
        .def("set_callback", &DataUpdater::set_callback, "Setzt die Callback-Funktion")
        .def("update_data", &DataUpdater::update_data, "Aktualisiert die Daten");

    m.def("python_callback", [](const std::vector<double>& data) {
        std::cout << "Python-Funktion aufgerufen mit folgenden Daten:";
        for (const auto& value : data) {
            std::cout << " " << value;
        }
        std::cout << std::endl;
    }, "Python-Funktion, die von C++ aufgerufen wird");

    m.def("generate_data", &generate_data, "Python-Funktion, die von C++ aufgerufen wird");

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