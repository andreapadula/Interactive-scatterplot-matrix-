# Interactive-scatterplot-matrix


This project was done by using openFrameworks

In the first part of this assignment,a basic Scatterplot class is implemeted to plot bivariate (two attributes) of quantitative data. This will requite two key pieces:
  1.Reading/parsing data

  2.Drawing the scatterplot.

First,TableReader class should parse a tab-separated list of data all data values are floats.
Next a class Scatterplot, This basic scatterplot will accept (1) two columns of data, (2) a width and a height, (3) an x and a y position, and (4) any other metadata of your choosing.

The result should look like this 

![Alt text](A03P01/A03ReportImg02.png?raw=true "Title")

# The second part 

This part of the project is where actually some basic interactions are implemented.

1.A mouse rollover that displays the precise x- and y-value of the data 
![Alt text](A03P02/A03ReportImg02.png?raw=true "Title")
2.A zooming function 
![Alt text](A03P02/A03ReportImg03.png?raw=true "Title")
3.Right clicking anywhere on the Scatterplot should reset the view, removing the zoom.

# The thrid part 

Scatterplot Matrices an application for interactive scatterplot matrices. Given a table of data, the goal is to draw multiple scatterplots, appropriately sized, for all possible pairs of attributes

