# pybind11_beispiel

Buildprozess

Verzeichnis erstellen:
mkdir build
cd build
cmake ..

Mathe lib erstellen:
make math-lib

Target erstellen:
make pybind11_beispiel

Python Module erstellen:
python3 setup.py bdist_wheel

Module in Python-Umgebung installieren
pip install ../pybind11_beispiel/dist/<Name der .whl Datei>
 

