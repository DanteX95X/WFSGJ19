# GodotTemplate
Godot project template along with script generator for C++ files.

Generator script creates both header and source for new class. It also registers genereted class in Godot framework and creates native script object.
User can provide class name, path to generated class and namespace wrapping it over. Generated classes derive from Node2D by default.

Templates for each generated file can be changed to better suit your needs. All templates are located in generator_template folder.

Author: Daniel Lewiński

# Install Instructions


```console
$ git clone https://github.com/DanteX95X/GodotTemplate.git --recursive
$ cd GodotTemplate/godot-cpp/
$ scons platform=<platform> generate_bindings=yes
$ cd ..
$ python generate_script.py -c=<your class> -n=<your namespace> -d=<directory>
$ scons platform=<platform> -j8
```
