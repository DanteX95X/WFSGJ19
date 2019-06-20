source_folder="source/"
native_script_path="demo/native_scripts/"
dlibrary_path="res://bin/gdexample.gdnlib"
class_register="register.cpp"

qtcreator_files_list="GodotProject.files"
header_template="generator_templates/header_template"
source_template="generator_templates/source_template"
class_register_template="generator_templates/class_register"
native_script_template="generator_templates/native_script"

from argparse import ArgumentParser
import re
import os

def convert_to_underscore(name, upper):
    s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    if(not upper):
        return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()
    return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).upper()

parser = ArgumentParser()
parser.add_argument("-c", "-class", dest="classname", help="Provides a name for the generated class.")
parser.add_argument("-d", "-directory", dest="directory", help="Provides directory in which generated files will be placed. Relative to source and native script directories.")
parser.add_argument("-n", "-namespace", dest="namespace", help="Provides a namespace wrapping generated class.")

args = parser.parse_args()

if(args.namespace == None):
    args.namespace="godot"
if(args.directory == None):
    args.directory="."

filename=convert_to_underscore(args.classname, False)
include_guard=convert_to_underscore(args.classname, True)

with open(header_template) as t:
    s=t.read()
    with open(source_folder + args.directory + "/" + filename +".h", "w") as h:
        s=s.replace("$class$", args.classname)
        s=s.replace("$namespace$", args.namespace)
        s=s.replace("$include_guard$", include_guard)
        h.write(s)

with open(source_template) as t:
    s=t.read()
    with open(source_folder + args.directory + "/" + filename + ".cpp", "w") as cpp:
        s=s.replace("$class$", args.classname)
        s=s.replace("$namespace$", args.namespace)
        s=s.replace("$include$", filename)
        cpp.write(s)

r_exists = os.path.isfile(source_folder + class_register)
if(not r_exists):
    with open(class_register_template) as t:
        s=t.read();
        with open(source_folder + class_register, "w") as cr:
            cr.write(s)

    qt_exists = os.path.isfile(qtcreator_files_list)
    if(qt_exists):
        line=source_folder + class_register
        with open(qtcreator_files_list) as qt:
            s=qt.read()
        if(s.find(line) == -1):
            with open(qtcreator_files_list, "a+") as qt:
                qt.write(line + "\n")
                print("added register to project")

qt_exists = os.path.isfile(qtcreator_files_list)
if(qt_exists):
    with open(qtcreator_files_list) as qt:
        s=qt.read()
        line=source_folder + args.directory + "/" + filename + ".h"
        if(s.find(line) == -1):
            with open(qtcreator_files_list, "a+") as qt:
                qt.write(line + "\n")
        line=source_folder + args.directory + "/" + filename + ".cpp"
        if(s.find(line) == -1):
            with open(qtcreator_files_list, "a+") as qt:
                qt.write(line + "\n")
    

with open(source_folder + class_register) as cr:
    s = cr.read()
    include_line = '#include "' + args.directory + "/" + filename + '.h"'
    register_line = "godot::register_class<" + args.namespace + "::" + args.classname + ">();"
    i = s.find("//$include$")
    il = s.find(include_line)
    if(i != -1 and il == -1):
        s = s[:i] + include_line + '\n' + s[i:]

    i = s.find("//$register$")
    il = s.find(register_line)
    if(i != -1 and il == -1):
        s = s[:i] + register_line + "\n\t" + s[i:]
        
with open(source_folder + class_register, "w") as cr:
    cr.write(s)

with open(native_script_template) as t:
    s=t.read()
    with open(native_script_path + args.directory + "/" + args.classname + ".gdns", "w") as ns:
        s=s.replace("$class$", args.classname)
        s=s.replace("$resource$", filename)
        s=s.replace("$dlib_path$", dlibrary_path)
        ns.write(s)
