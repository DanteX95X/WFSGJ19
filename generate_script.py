###############################################################################################################
###	Configurable parameters                                                 ###############################
###############################################################################################################

source_folder="source/"                                       ### root folder of your source
native_script_path="project/scripts/"                     ### path to native script objects
dlibrary_path="res://bin/wfsgj19.gdnlib"                    ### path to library config file
class_register="register.cpp"                                 ### name of your class register file
default_namespace="godot"                                     ### default namespace

qtcreator_files_list="GodotProject.files"                     ### path to your qtcreator project list of files
header_template="generator_templates/header_template"         ### path to header template
source_template="generator_templates/source_template"         ### path to source template
class_register_template="generator_templates/class_register"  ### path to class register template
native_script_template="generator_templates/native_script"    ### path to native script object template

###############################################################################################################
###############################################################################################################
###############################################################################################################

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
parser.add_argument("-d", "-directory", dest="directory", default='.', help="Provides directory in which generated files will be placed. Relative to source and native script directories.")
parser.add_argument("-n", "-namespace", dest="namespace", default=default_namespace, help="Provides a namespace wrapping generated class.")

args = parser.parse_args()

if(args.classname == None):
	print('Please provide a class name (-c argument).')
	quit()

filename=convert_to_underscore(args.classname, False)
include_guard=convert_to_underscore(args.classname, True)

# generating header file
with open(header_template) as t:
    s=t.read()
    with open(source_folder + args.directory + "/" + filename +".h", "w") as h:
        s=s.replace("$class$", args.classname)
        s=s.replace("$namespace$", args.namespace)
        s=s.replace("$include_guard$", include_guard)
        h.write(s)

# generating source file
with open(source_template) as t:
    s=t.read()
    with open(source_folder + args.directory + "/" + filename + ".cpp", "w") as cpp:
        s=s.replace("$class$", args.classname)
        s=s.replace("$namespace$", args.namespace)
        s=s.replace("$include$", filename)
        cpp.write(s)

# copying class register file
r_exists = os.path.isfile(source_folder + class_register)
if(not r_exists):
    with open(class_register_template) as t:
        s=t.read();
        with open(source_folder + class_register, "w") as cr:
            cr.write(s)

    # adding register to QtCreator project if it exists
    qt_exists = os.path.isfile(qtcreator_files_list)
    if(qt_exists):
        line=source_folder + class_register
        with open(qtcreator_files_list) as qt:
            s=qt.read()
        if(s.find(line) == -1):
            with open(qtcreator_files_list, "a+") as qt:
                qt.write(line + "\n")
                print("added register to project")

# adding source and header files to QtCreator project if it exists
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
    

# adding entries to class register
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

# generating native script object representing generated class
with open(native_script_template) as t:
    s=t.read()
    with open(native_script_path + args.directory + "/" + args.classname + ".gdns", "w") as ns:
        s=s.replace("$class$", args.classname)
        s=s.replace("$resource$", filename)
        s=s.replace("$dlib_path$", dlibrary_path)
        ns.write(s)
