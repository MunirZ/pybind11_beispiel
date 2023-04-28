import pybind11_beispiel as bsp

point_a = bsp.Point(4.5, 3)
point_b = bsp.Point(8.2, 4.6)
rectangle = bsp.Rectangle(point_a, point_b)

print("Punkt A:\nx = "   + str(rectangle.point_a.x_coordinate) + "\ny= " + str(rectangle.point_a.y_coordinate) + 
      "\nPunkt B:\nx = " + str(rectangle.point_b.x_coordinate) + "\ny= " + str(rectangle.point_b.y_coordinate) +
      "\nHöhe = "        + str(rectangle.get_height()) + "\nBreite = "   + str(rectangle.get_width()))
