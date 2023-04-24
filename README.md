# pybind11_beispiel

## Buildprozess

pybind11 Submodul einbinden:<br>
```bash
git submodule update --init
```

Verzeichnis erstellen:<br>
```bash
mkdir build
cd build
cmake ..
```

Mathe lib erstellen:<br>
```bash
make math-lib
```

Target erstellen:<br>
```bash
make pybind11_beispiel
```

Python Module erstellen:<br>
```bash
python3 setup.py bdist_wheel
```

Module in Python-Umgebung installieren<br>
```bash
pip install ../pybind11_beispiel/dist/<Name der .whl Datei>
```

## Test ausführen
 Im Hauptverzeichnis:<br>
```bash
python3 test.py
```
