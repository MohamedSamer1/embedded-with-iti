#!/bin/bash

mkdir -p source_directory
mkdir -p organizedDirectory/images
mkdir -p organizedDirectory/documents
mkdir -p organizedDirectory/others

touch source_directory/image1.png
touch source_directory/image2.jpg
touch source_directory/image3.gif
touch source_directory/file1.txt
touch source_directory/file2.pdf
touch source_directory/file3.doc
touch source_directory/file4.docx
touch source_directory/file5.ppt
touch source_directory/file6.pptx
touch source_directory/file7.xls
touch source_directory/file8.xlsx
touch source_directory/data.xml
touch source_directory/archive.zip
touch source_directory/backup.tar

ls source_directory

echo
echo "Organizing files..."

for file in source_directory/*; do
    case "${file##*.}" in
        png|jpg|jpeg|gif)
            mv "$file" organizedDirectory/images/
            ;;
        txt|pdf|doc|docx|ppt|pptx|xls|xlsx)
            mv "$file" organizedDirectory/documents/
            ;;
        *)
            mv "$file" organizedDirectory/others/
            ;;
    esac

    echo "$(basename "$file") moved successfully."
done