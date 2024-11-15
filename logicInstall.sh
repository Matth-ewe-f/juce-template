#!/bin/bash
project_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
dest_path="/Users/matth/Library/Audio/Plug-Ins/Components"
cd build/plugin
dir_regex='.*_artefacts'
for dir in ./*; do
    if [[ $dir =~ $dir_regex ]]; then
        cd $dir/AU
        file_regex='.*\.component'
        for file in ./*; do
            if [[ $file =~ $file_regex ]]; then
                rm -rf $dest_path/${file:2}
                cp -r $file $dest_path/
            fi
        done
    fi
done