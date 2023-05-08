import pybind11_beispiel as bsp

point_a = bsp.Point(4.5, 3)
point_b = bsp.Point(8.2, 4.6)
rectangle = bsp.Rectangle(point_a, point_b)

print("Punkt A:\nx = "   + str(rectangle.point_a.x_coordinate) + "\ny= " + str(rectangle.point_a.y_coordinate) + 
      "\nPunkt B:\nx = " + str(rectangle.point_b.x_coordinate) + "\ny= " + str(rectangle.point_b.y_coordinate) +
      "\nHöhe = "        + str(rectangle.get_height()) + "\nBreite = "   + str(rectangle.get_width()))

# Python-Funktion, die bei Aktualisierung der Daten in C++ aufgerufen wird
def callback(data):
    print("Aktualisiere Daten in Python mit folgenden Werten:", data)

# Erstelle ein DataUpdater-Objekt und setze die Callback-Funktion
updater = bsp.DataUpdater()
updater.set_callback(callback)

# Aktualisiere die Daten in C++
#data = [1.0, 2.0, 3.0]
#updater.update_data(data)
bsp.generate_data()