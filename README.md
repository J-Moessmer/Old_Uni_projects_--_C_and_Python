# Old University Projects
All my Old Projects I wrote when I visited both the HSD and HHU universities in germany
They are written in C and Python and are uploaded here as backup.
The university specific libraries are missing, so they currently dont run.

## Projects in C at the HSD School (2018-2019)

### HSD 01 - Uni ID to Pharma check number Converter | C
A basic programm to convert the Uni-ID into a phamaceutic-Check-Number (PZN in german)

### HSD 02 - Calculator for natural Logarithm | C
A basic programm to calculate the natural Logarithm ln(x)

### HSD 03 - Cafeteria Programm | C
This is a basic programm to search a Weekly Menu of a cafeteria based on the date and then calculate the price depending if the costumer is student, teacher or guest.

### HSD Bonus Task: Search machine for Pixels in a image and Hue calculation.c | C

This Project was the Final Bonus excercise in the 1 semester C course I visited at the HSD in Düsseldorf
The Goal of the project was to create a programm that can display and find Pixel RGB values along the left, upper and right border of a image

In our case where where supposed to create a Self-portrait and compress that image down to 5x3px in size.
that image then was loaded into the programm and we had to scan the apropiate pixels to display our University ID as colour values using this Matrix:


| 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|
| 1 | x | x | x | x | 8 |
| 0 | x | x | x | x | 9 |


My Uni-ID was 789749, so I had to search the coordinates of the pixels below these numbers in a [x|y] system and output the RGB values of them
after that I had to scan the entire image file and display the average RGB value of all pixels
the same basic principle is nowadays common with modern TVs that are able to "extend" the image to the wall behind using LEDs

the programm was then uploaded to a Arduino that had some display modules added.


## Projects in Python at the Heinrich Heine-University

### PA01
