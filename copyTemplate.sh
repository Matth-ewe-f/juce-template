#!/bin/bash
if [ $# -gt 1 ]; then
    parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
    dest_path=$1
    new_name=$2
    mkdir $dest_path
    mkdir $dest_path/cmake
    cp -r $parent_path/cmake $dest_path
    mkdir $dest_path/plugin
    cp -r $parent_path/plugin $dest_path
    cp $parent_path/CMakeLists.txt $dest_path
    cp $parent_path/.gitignore $dest_path

    sed -i '' "s/PluginTemplateREPL/$new_name/" $dest_path/CMakeLists.txt
    sed -i '' "s/PluginTemplateREPL/$new_name/" $dest_path/plugin/CMakeLists.txt
    sed -i '' "s/PluginTemplateREPL/$new_name/" $dest_path/plugin/source/PluginProcessor.cpp
else
    echo "Please specify a destination directory and plugin name"
fi